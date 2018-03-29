/*
 * Based on the work by Tim Medin
 * Port from his Pythonscript to John by Michael Kramer (SySS GmbH)
 *
 * This software is
 * Copyright (c) 2015 Michael Kramer <michael.kramer@uni-konstanz.de>,
 * Copyright (c) 2015 magnum
 * Copyright (c) 2016 Fist0urs <eddy.maaalou@gmail.com>
 *
 * Modified by Fist0urs to improve performances by proceeding known-plain
 * attack, based on defined ASN1 structures (then got rid of RC4 rounds
 * + hmac-md5)
 *
 * and it is hereby released to the general public under the following terms:
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted.
 */

#if FMT_EXTERNS_H
extern struct fmt_main fmt_krb5tgs;
#elif FMT_REGISTERS_H
john_register_one(&fmt_krb5tgs);
#else

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifdef _OPENMP
#include <omp.h>
#endif

#include "misc.h"
#include "formats.h"
#include "common.h"
#include "dyna_salt.h"
#include "md4.h"
#include "hmacmd5.h"
#include "rc4.h"
#include "unicode.h"
#include "memdbg.h"

#define FORMAT_LABEL         "krb5tgs"
#define FORMAT_NAME          "Kerberos 5 TGS etype 23"
#define FORMAT_TAG           "$krb5tgs$23$"
#define FORMAT_TAG_LEN       (sizeof(FORMAT_TAG)-1)
#define ALGORITHM_NAME       "MD4 HMAC-MD5 RC4"
#define BENCHMARK_COMMENT    ""
#define BENCHMARK_LENGTH     -1000
#define PLAINTEXT_LENGTH     125
#define BINARY_SIZE          0
#define BINARY_ALIGN         MEM_ALIGN_NONE
#define SALT_SIZE            sizeof(struct custom_salt *)
#define SALT_ALIGN           sizeof(struct custom_salt *)
#define MIN_KEYS_PER_CRYPT   1
#define MAX_KEYS_PER_CRYPT   64

#ifndef OMP_SCALE
#define OMP_SCALE            4 // Tuned w/ MKPC for core i7
#endif

/*
  assuming checksum == edata1

  formats are:
	 $krb5tgs$23$checksum$edata2
	 $krb5tgs$23$*user*realm*spn*$checksum$edata2
*/
static struct fmt_tests tests[] = {
	{"$krb5tgs$23$74809c4c83c3c8279c6058d2f206ec2f$78b4bbd4d229487d5afc9a6050d4144ce10e9245cdfc0df542879814ce740cebb970ee820677041596d7e55836a18cc95c04169e7c74a4a22ae94e66f3d37150e26cc9cb99e189ef54feb7a40a8db2cb2c41db80d8927c74da7b33b52c58742d2109036b8ab27184609e7adff27b8f17b2f2a7b7d85e4ad532d8a70d48685a4390a9fc7a0ab47fd17334534d795abf83462f0db3de931c6a2d5988ab5bf3253facfff1381afb192ce385511c9052f2915ffdb7ea28a1bbad0573d9071e79dc15068527d50100de8813793a15c292f145fa3797ba86f373a4f0a05e5f2ec7dbfd8c8b5139cc7fbb098ea1dd91a7440134ffe2aff7174d0df13dcad82c81c680a70127a3ec8792bdecd74a878f97ff2b21277dc8c9a2f7bbcd9f72560dd933d85585259067d45a46a6f505d03f188b62c37edf03f117503a26743ebd674d5b07324c15fc8418881613b365402e0176da97d43cf85e8239b69aee07791233a959bcaf83a7f492fa718dd0a1747eaf5ce626eb11bda89e8235a056e2721f45c3b61442d893ef32a8c192ea0dadb853f3c6f3c75e92f23c744605c6f55578f696b0f33a9586b8aae3e12e38a097692cd9a31d780d973eaaf62ef23b2fc9ae59a38bfd8ea14d3289b46910f61a90aa733e66382bc27f40ba634e55ef1bec0ca7f71546b79566d85664b92f9fae495fcef5cde4c4399a6798569a7e81b9cc4bdde7104f3fe181401f82bba944e3b0a406c7093c00ff9d5984a82517b1a64a8aa561bc1f0cbafbdbbc5654d375c91d4e485e17bb06838109fbc1504147481c91652f545086a84daa423a6286ea6bb13460c5ff3d865a7b37b9ce4e7b07fbe2f6897c12c1e4df2e875c1ec9cfbf84097a7f48b270baf3481263b21849ab93c231490d06a23461a5e00c23df76bca8e5a19256d859304e1f5752bf055ac7f4843e1ad174f1cbbf5c142958f9310025ce439d5979982fb0b8c2ea95e1a22ee8dc63423d9d364cb0b95bcdf89ec4ed485b9005326d728757d77aa3e020a4a61d7deb782bc5264dca350173609772cd6d003ee8104dd24d310c9a18a44f78e27d65095f5bb54f6118c8f0d79ad5a850cec8d40a19bd0134144e904c9eb7fdcff3293696071fc1118f6b2f934281a25bcd5ca7d567714b1e43bd6d09bfcc8744c0ca273a75938394ac2fb31957287093346078577c94a71dfa6ad4a63211f54f00ef7a9064d070aaff84116ee891728915c938a8a32e87aaa00ec18e2b4e9ae88f7e53f08d855052a995f92351be32d8df934eab487103b0f089828e5fb5f73af3a8a05b9fffd25c43a392994743de3de1a2a9b8bba27e02ae2341f09d63aafab291759c41b9635521ca02f08e21e7e5c3ce75c8c3515eaa99aeb9bf8e204663e8b6b8507ecf87230a131687b4770e250ba0ef29fa3ca3b47b34971e17c6a3ef785acdd7c90da9d2", "test123"},
	{"$krb5tgs$23$ee09e292a05e3af870417758b1cdfd04$a1a480b8505d2f2f0ff06ddce40c2f6e76bd06fa64dcd5b0646a68effcd686b2e41562ebda90da7e7b36d95cd16ca8a33b8d99184d6b7fa7a2efec3a05dcb63b3e815ffd38849dc69174d1efb3a871544b73a6da55d2331bd4b60743d1654873e3c1748ce155c35a1711695296ab944d158e374b67f43dd07eab2bcacec1be480e5c1338e3834f7133909f5c7970ece39e73bd96d40f696cb5a8575e5e1feab937b616d6180cc3258e22b9fc495017593e15fc10e674af8184c282a0d80902ea9dabda5fb0a56d7980bfd4b62b330155cd8e318dc5be55500cb8ddd691b629af371463c411f1c11d21811e1546477b85f0a85e296f5df737930aff5015111d2f01a236ab7c77e9dab001f52400cccbcdb31bb180db027bd0fa2f6000dce7c1e072c0effbdee23a401720b1fe54a09a75430497f42f6e047d62d1123866d6ed37e58f8e2c1e462acb1a97a44a5ccef49897af190a46b3ab057d18c1e47d717c7a63658357d58d9cd5b7672f0a946f95f6e2ec3aee549e20e3b11237ea59f87723f24e03a6fac9e51086bc84142631ed36ee6855920f3d3d1e85d0faaa0a8b04a2b050b17f94d44af7f48302fa70dcf43279415983924e5d874c59722b6fb87ad1006fcb51e4341bb2cc4caf8c4b7993269af219cf4efa12b1009961c22f123c35f982e4ca75a97cd37f7f16be111ad301637ffb1664ccb021d3cf6bf771e07dc42202dac079c6bd7559f8e7a939bc14e9ddb45fe1b88c5f83b1ff966342bb9211afd15772cf5f871d39d0b30776d51d84b046df30d250c1877d146047e784c4bc2e6745f357dd0b1c6aaa11e26a0e3c2772781695f6a3bc536ba19e2327ec8c0866bd78d3b5b067abcf6991eafc8b7a11ad4049711263f3c68b358f246da1308d5a0daac1d7efedbc237be3d6a4bafe5ce66e941f7227d2b869bda637dfd223a4546340c59e7d0e2b58f60a67590468a53a5d28cc35cec36a9c5610c70c0633767539640b42cff787f4782057ff70d0e64658413429347f5449c1360da4d0827c4197bbb0361c6d0e04bcaf6bba1233912f806772146c0e778ac06749bbd3d8819007d070ae912580ff11a41f71b0907b88fb585585ebe42b4cc4ecde8ff7b49a856dd70f316425e53feff3ee6ca1e44d9ba5e607a41cf26edf44bffe2796f94ea2d767fbf81f665a7fedf0291e76c6fa409dc99c56954f21edc77f6173c5a3a909c8756f3cc5cc6c2d2e405f333ee0b50284aacfb81f9dfc6058b78b282db4511580eb623dc393919befc250d224490936e5fb16c483f4bd00c8915288d0ddf3812eaa3d46ad5a24c56390076730d23b2de6558ddadddba725f9b4a73d13de3e1276fc285194e3a2f613d9b020d0485d7e26b36b7b917f4911024127320627066fabbd465b4cd5d5fdebae804d15db0f5b276659364bec32a13a8d9e11349f54bd", "bluvshop2"},
	{"$krb5tgs$23$*Fist0urs$MYDOMAIN$cifs/panda.com*$423cb47a258e5859c13381ae64de7464$8dd47d94e288a1b32af726d2eac33710fb1610e4c6f674907d7a74d26515a314173b2b531baa790b70467ebe538fc9e941bf4d7f7218a4ec17c1dc963b717d5837fcd5ae678189101a1b4831a53a1322ca6e8f5d644e4aa72e99bedb4a0e967c3e05ccdcc96137265612969a1214a71038dea845250cac45551963fe85f193d88aa39ed57b95b934295e17de04ebf0ad275df67f65fb1fc2ee3095c6af02c4c1b8efa570e1c2ac562601c5ac89bd6f59ca8b957660aa00787d4a0f9d9f29b15eb3b85823f7c9814eab9106210c37d863cf8413391c5941a994fdd52a44e4f8e8e4c9b8b520e62015fb5ed40e91e7a453b3ddcefb888fd896c187993a899b6a30d27a5b2b7847a410c0cce8b0fcf90367bfd8e6dfa7eb37676ecdf500c9a51ffb59792c13e222371e024f857134b7039931daa66a6902da37e71c41adf83846a9df1e75575696d7a6f1744d48e8215849773903c9475c29a1ec0fcc11257f9479467c2b65679a3da298e6806d619794dfc06b10b5e0a46e395c3ade3d750292f244cabb7172d83dbd42c6e3bd5a93a8c2d5fe84b23a3c60508733f5a087763f2fa514d18f891461b8ea22f7eaa847906182bd0415c28d197c06df8449cc2c6c2016c38672a67613a14ccac9025c4da85fc0825dcd9a1269e6064f80c0de445fbdd237d35ab0eb6ae468413c5b17c9955a8c8c34952c8a188bad7e5b18651a75b1c46cf116422378a94a19c31dfa634c8ab15f4f13e7e427741ab9e8f247b4a8fe2562986ee21f602b4fad45bd535718020b764da6f346e3b028db8a1af88419f3ea9141fcf0c622ed40d894814e5d60a9dcdfc8344f802c7b2f0089131e57ac0cc071af13c3b2b7302e9df4665c48b91f4ef0bb2a60a272e5841e0ee8da01a91773d41f295514b65ccb2190195f720d9838b3e7c701b51e813ef0262fbdbbe06391ba3fe4232e74523dfa933e6d3df2494ddd9f254afdf97623ceb5d32483a870cf72a57617bdbf97f0420c041edb5a884ff401dc21da0472d7a75d89dc9937fd65c3a422063ea44e3954435d38b8f34cec2c0360c8bef392f77fbab76a7b801e05b467d4980d20f0a7dbc1c39f50ce4429df1ec167c6be67d2fbd507a3f7b5d98cf214ae0510fac51e1075a06250d65a3a1179486bda5d982b7904682835079e3042f39a582492cd14dbafb5826e242c81998752043e2dd91b648f115900595f5191a01f187c4b6dea4917e4773a5fb28cb1d20508142a3905068c931a8c9a8fa291b92f8ece9884affd8787a5aa11858274879160e930587f3c32e2cabbd124c708641df09f82d05ab4db157ad24931dc36c616dbb778762ead6a8491ce8a48037106d382283ac69422c04af3ae2cbe22eff6dff21bc34b154a5fab666870c59aba65bd4e0ea0be3f394bb4901fd64a0e19293b8026188615c84601b7fecdb62b", "jlcirr."},
	// 1-40a00000-john@HTTP-adc1.toor.com-TOOR.COM.kirbi file
	{"$krb5tgs$23$e43ae991b15bbd11c19395c6c785f4d4$07ea84f4cf5ab2ad5a1a15c5776e7bc024d26451771e653c9cb0b87d8a5d73317f992913621a61039d143818585aee976b5273f53023d28a1da22c8a2f79e47956da4221bd10809fb777b4684cbbc102bda46dc816eb5a5315196f1b2cd47fee6ddc1adae753c96eefe77bf8e8e54e33489595f0c3cb47db9bef77438f666c15de4ee9893839c5280daebd81d476a00944f8282eed61af43578fc6f68dbb47ad9106ea1f58125355506016ccf997d35d8ccad169ba7eebe27e76d19188a227158172b405c7e053da1e3bafae4cd39594e7a03e7a96bdbc63a793fba6c26135d6d1789395f0155341e04f80097540ffb1f299f61960a34db3ea14b95b4633b7eea3a552140e7e42708009fdda3d1b42b3297142bfc036abd3d28f07ba1c8362e1c5b346f55af7214314a92fa412733825f55fe4a56b56859af00eb4f69cc7ad339b7bc8032ff1057be3e73c5533f4f546e599ecbf60305569c9b87b22971ef012ff92f582688b001ad23901dae743c46cae6603f7b6b88db78fcfd59997e8a1078f8a27e28a6628bc59d78674d9d16a6413da369ab58cb702dba01c710fbfed87f4665dfb3cc4a8f83ebf960435ae96973e699cd419324ddf115825c99890b2bb8e35ce0005a2adf95ce691b135358c63aa87088ed615c5a9667927e691bf7135677893abc41c038d25ff9091c14e3d1da85c7f0edaed32c9b3b56d2c473b2363b93aae5cc9b02db47e7a22a639a951e2edce7580f691c2ee0f8ebdfb02cdc6de8d1028e34085d1a69cdebb00a430b5ddce223bd1cc9c66b746a46584c098f051b97180ee8db4268a3a838504884df45227cac6fe9e73704877f04558c9640ac2ed33b3216b2e17805863a955285f4633407097f439d7063faeacdcee0d6d4e6c2adbe85df0e51eb3c08da1cedb4fa70ff74b2711a7294b499597c1f30c1dd3cc12751692311a16e22b3fa6af75eb0ace4170df497ba860445b1fc964771eafc034515918bb080a6d05ab1170708e6ce80bf9b00f808a2b814e89d0ac9b5d1a23686b48e99fdc50c71b5fef8a9bfc851e40bed59f69821109be0119151768e4d91b8b00c46b39af207ad4a2566ce7751ac124c3c5851cd1026052d34988272bf2851bd1a4536816a7635d83c1378b442eb04c15d5028763e0b189c8f45703c54d62aaea570c9e56b0e721d170cda74f91a4101c495fb565bb03f2ad635335c88db112dfb073bb4d1547de3214de5e371bfe9b440de3882f7b83593ca0fc60f4e6e2e3885b2a365a56b529904c74bc58ab38432f0dfbbd3f4d543f9d8685b0aa69aa807701e09e1253b6ed4948c7ceaaafdd0baed2663881d52a163101a5bb697a65b2bfcc54d0dd", "1qaz@WSX"},
	// http://www.openwall.com/lists/john-users/2017/02/24/1 (Kerberoasting, TGS-REP)
	{"$krb5tgs$23$*mssqlsvc/w2k8-sql.ville.com/65498*$0f5394cf9746bc8ff5b090f89971816d$2e86c9139cb881c784377c14abdbf4058eaeeb19476b0e54dcbd0599c6c349f96513419d80b73de389890ba1f67e94a1f5d9f29aa36d3cfc86c6b047afd57173c723388a1f88ec80e2575dee2a42f5a1c4fc39be69a303ce12328ce6b6e17cb7660312a93774c48ff972fdb29557c201126aebfd5f1d0ca116cc9f5a1b7f7a0847486a988663171441d9e0778ceb160fccd69e194bd6e350cd10f39628414a54629a0e3f170b7bec339ec4ee89db0eb558ad4afd086e0cb90f35b596fc89d81e4f18d75dba84246d2b5e446099f80714d88a251c4e1ce31682d2ec754ac0a2fb0ba56c93c075722318f1152041bc0a0ef558efa1a2b56043df12596f7f0880643787fde2db55a4153c183cda692b23b4ee796488d04bbd10b91e51a5f2d0753902e95534fd73433d1ad268f5caa67e2436e7a722451e8bb07e148928f4c8c416151e440fa99c03543bf21c30e5fd299c31ccb91a058b650aa07c89e84545a84a437bb215e68df7627f90ad1766e6f0ca31858d023376acf1cf06faca36e4054acceae001ab5ac96c8ba4e2a6d285ca837a2b9bbaa9ed4a92a27ae285b67f2198f0461697967826a916d2955707bde3af57e3c71330e3cef292c273ef274379aed1d9117c07c245c0054a3beb4e5dc3a4b960fae326d5f1a7fa517327c514ab4f33b9c2942f15a0b453fa8226ee6bdd2310da2da169724041dd3fce4baff594f37ee6c8d1b62da27d21e7492fe05e7f2c9e4a0d3a9540b9a50c1fa697c6311f2af31b6e743f01f499c2ece315ad74c861f379276b8d8a50c41eea5cb0b2eac7f011d759b09d2cf0aecae519ea5a25fac4cc726ae56ce76136049256e7375fdb2e3ee60f408e28657872514b63dcff78bf2840e71d9d318620409f2ba171a6cb8f05b56fa1f0c39fd91284faa497df8e1a053160fb48b75f4ddf94c9f67bb6a248cd5008931a5ba5768d51430b0a8f8f43c928d1a693725f4787999322c59fec3563fdc9bdae5981f1398a843bf4258433d4f79ad5fea293926de05dcb60668d349650e015ce3e17b1860dea3989bd87f698c5dc9dece7e4733ba069dfa86e8ddc02e13c6de02724dd7d6fa48f25984c1666341a61c4008dd66e6a072a278ed6f009a3a3c0a48946b8d7ce7c22e1009cb6d482a7f3b7105990a1770fae62b2e28281ee5ade79149a8e8a8efc77edfd1308f4ba7f1142f5fa0a73d08ec9a3391cbbfb30c586e001db0fbda98d3fdaf6751180674c8c097aed64ad870568fd4ec55ce9afbdb301954b14115df691213483825286b4c5f86f5bd71d99ae757e4d8c17420b73a4bf37e8584141c5055dc38ca76c16536e85c5b3e88fbac95e626391569de6b0d9da0cb0bce65926927fb37f892a059be16e064ec2fff275b976540b017f18553756cf3e6f2fe5a08bf8fd8cca8814ebae6124fc766bcc93eeb375c19e", "Compl3xP4ssw0rd"},
	// https://hashcat.net/wiki/doku.php?id=example_hashes
	{"$krb5tgs$23$*user$realm$test/spn*$63386d22d359fe42230300d56852c9eb$891ad31d09ab89c6b3b8c5e5de6c06a7f49fd559d7a9a3c32576c8fedf705376cea582ab5938f7fc8bc741acf05c5990741b36ef4311fe3562a41b70a4ec6ecba849905f2385bb3799d92499909658c7287c49160276bca0006c350b0db4fd387adc27c01e9e9ad0c20ed53a7e6356dee2452e35eca2a6a1d1432796fc5c19d068978df74d3d0baf35c77de12456bf1144b6a750d11f55805f5a16ece2975246e2d026dce997fba34ac8757312e9e4e6272de35e20d52fb668c5ed", "hashcat"},
	// 1-40a10000-luser@MSSQLSvc~example.net-EXAMPLE.NET.kirbi
	{"$krb5tgs$23$70c1576b3fec9b24ddb925efcbdc687c$ac33782f96977412999a6e1010f8b5e099da60c31603280188290bbd336d6a10b029bf5e3eb1218870e27170b704334f4e60b90e5ebcbe7ef102d06785a00c28f337d2995c347493548d854f7208abe4405430e42b6aca8b6d640068d5ab05c2c0176707dbdc096628925937345a9e4f67692773b0df58c36703bb738191681e7424fa85fe964b8a6bc4ef379da8af8513582ccfebf86dd2ec7bd91a702d2eda40d8882aa2042ccf5ca40b7eb370643b003e3909d08a433be7657b5d695ff3abca64191ead8433c2638e08bca64011406a3724aaf70d153a69cc84e8c24b98786ed24a57b4a312346ceef1f30c5a1e437049af054071fdef28747f786207ce7e085dcea3aeee31a7aca11022308fc7db549b0285565710422c9f4dba94090f8ea34113050f75e5e850303e18f29cc6fd8d45a87730bacc9258d179db9b98524f7c1041f7af71ed96f816c7cf73d3d8f8249d9a485fe56dda09f2ca41edda6cf3095f4aff036d9ca71cbed651a1f89bd5607962ff395a3398ef9e4ece1e9ecb59cacd41331c2971ff03f9016875dc03e96a4ade7d318a50af1724a95c8e2441ecd22f041d31f49cc461de3869f930240e02a1f7ff9af331dd48798acc45abf48d9d29caaeda467e4194df14b3dd5678abaf56fd092b9c8a6858d351ed14126e0a7e78970ba462d71a5afc50c544e64c5f708e63f34b6363c0d1921522959a1eda4f46096874b48d88b3fddbbf8984e2a1b836f6bec614806e41aa1b2ac3165942d371c208621ebf2dfe99cfe81367dffea3b3d7a7eaa1eed76d3f3bc9461e884cb3fc747ed344579ba7d803d6e775f80d71fba90535602c016b63d14f50ff8732e6f4f0eb4fdc47b7cf84346f21498d4fc2f3124ce16fcd41caedc5178ccc54cea6298c2e938d887991a84c4dfa71541ca0acb154a1603e24004648e5c81a87a7aababdb48c8cd091cea6cc7aeff2589efd2970cfa9fa073c26ed024fa2864c75058c135d3e1722cf6174169ea69dc346ccf3773ea6598f2597ba7840fc334bc7571c534384f3e4301cc430326c480d16defe7bab77960fdb939208a15445676a488f1cbb02e577cefb51b7bf465e73ded374b3224837d76a4163b8d05cfea83e216dcb6e6441c61f1d90f4c1f592b7538105a63af5843138406173eb3a1df3060312d420c0f360f1054c605019b77098cf8d6684c3c33280e3c15b2ffc776b11e08a417225ec92dbd25d05a8ffbc4662cae0cb14ccb157f36c84baea827cbd14e1d02b3f780d6339128c8ff8513e1a28006f8ffb531d798af6880bbea0044c5fbdbad3a17dfcd028ea334e2e4ac5b50819ac25e6386870105b2a9040324ad014041141898dd40e18f5a2acd7f0c8b8cd9d58975857f2df9582ba6d5a78ead595bbfae5451f7e6e261209c36c9aaaca4d2f53b0b9fa0afa2cfc5228a027599d816b8ee7", "openwall@123"},
	// AD-2012-luser-openwall@123-TGS-SPN.pcap -> extracttgsrepfrompcap.py -> kirbi2john.py, same hash (with better details) is generated by krb2john.py
	{"$krb5tgs$23$bdcb2559d28a8857a88102b8c131b861$2a02a3a7d75ecbdc2152588b64c1668a613e0d670cfecb723541096e34a5cf144d151422f3892b5392adffa0f26b03ef6378874e89dc950e395269eb2f114eaf13c61bdd02a2a4af594ab7d1743d7d33d3a9953262f173e61bed92bb097e3225128c9d1531d09cf940aafb9700d9245abb7c2b66479af3fbf9f022eaec9f80b3b7e497b7f25bd9ba796e0a9fb9aae3842d980fa511c0041b956f9f24a120a3a14135b47da44fe3a45c3177a55dc5b1986c1c279b96a5c63869733a61d12d141ca2b969a06ef6cb33597567e01165168a20ee3267ceb32a5553659e9c88d37ca6cce7ebbded80941868369238662f26b10d36e4f2a9426a84fc5abc905b8286cd8bc87bdda9c36a3902222f27e4007fb3d9fb29b7dcff1414584e5d142c35de02e2d3634539ccc787d374686ad67ea4f3aacbd4a418459a8d3d065e4ecdb3b270fafd8d48cd9022a9d9ca00a0d64bcd27046e4bf809f95a94dfcc9700c4c6921e46b1260023ee62c2b87b9873016b92c262385435015e23cfb3f4aa7821c2cabe9b376a1385a32c986dbd5b2466fe20d5358d228810e3b0532bfb6ce690feee3ec0b7ed9f9211ae2a34fe5cc24599d4d28668b869a3fba93b948d57a96da995402e37bf07a8d42cd0bde9b140496e6c53c072d44e28b958659697da4a396607950c5ed54640615ff0857e1148679366206153f5076b4ebf5f7a931335cc3afd0873eba1164400810c5de6cbaf04af5c2ef92ed616d57e14c8eeff1289dc9d53bd94ff0587653526147d1525b66a4012aa2dd67991a86d4b680458de43d22048a1486cc5142b85ebd2e1bbcca572fb155812cf4dc5c4dad7e1e3297185958f623f4e81d657108a2b4721e54fb4ea8806a6b9f0726a5ef2d9eb4a3e2eaeab1632666f20de1d57e58181a5f231a6b2862ca6b7cb33b79e918356b9a85f69de3854463c93150e291727ec6e82cd0a1bc284bc2101bedcd77d1ccf052b736b074e978baae93ec908ba924c445951b66605c05ede1eadc0595f14707aba99bb35ac222d3d34d9b1f59c5edecee434385f4a2a30d2aa8f4c339a23c91b943affd5c6bf51d9deb0116f323f1a3253bdede5e9297b2b202a227f3670073c7d29a6afb21814421d6923f99cb2fe976fd24169c2d97536df04e043e93ef8a81fd0579210d52503ad0cb4a4abae164b3520e9d540eab0d8c1cc88c5afc5bfb253bf0bd02e9c9f61427fa83340c5d1907cf00f6fe27e820544a55c6ba0d0ebeba96c8ad21ceeb0967b2fcea324269dd0b73d5cfdd1e568d9086d7ea93197cda743c7e90b9939fcbf3976a3aa01b4fbea4b849f3aeaf6c1a70ba6df98accbd0545d6abab6d0598e21d450731c68337780171bd440743548854e9643c8d1ae51580fab64d314d697628ace7616287d284f53831a3a831e75a0fbf7bfba917e2ade6f7f2fc78b3ed4000652", "openwall@123"},
	// From https://blog.xpnsec.com/kerberos-attacks-part-1/ by https://twitter.com/_xpn_
	{"$krb5tgs$23$*iis_svc$LAB.LOCAL$HTTP/iis.lab.local*$0f6fc474db169aa8ce9b5e626daacc9d$1a346ce3f66c52976f53831aa24a1b217cdf0d68a0eb87fee00cfd32f544bf83ebb6416732522b12232dd6935eac076b439f56e6cb7fa6c37d984d132e2d2cb65ca399cd5e44eb2eb41f12c40f9044b40e3ea914278c8a3098babacf49ab46e776d1413ef63abcdf6418d2db9241b2fdd9309346ec59af20a82fd6daea9510c1dfd1a9e8d99c59ff72e985057ba0d18394b0a7cb1bd74f8d436a3dd780175a0c6bcad9e46570a476ab9913b561ee481ad8c33a3c81ced055e959f08a52eba7a342f53183e1531be8ec2d28c7ecfa32f98dbc7ff87b4e5c79824f3868d38ce09010960726d58cfbfc88c9d34ab199169f39010aa4aab92b6ea40f875963d518311b3f079d97b65fe9768c9a4ee50f7c16d525fdc081ce359a0b0fe5fb18d8d8690d8f88b010bef4f28dc151a4137272ae9eaca9053406c0ddeae453196e3b6c28b8359724bfc089b772cbae093bf88abc070d12b0ff2e721d7b8b10b822bfb514091effaf3f5fa8c286a9e45bf76ba171e6cabeb3ddadc297185c51a295855b8cfa8062bd6770093355c32690fd184d6eae2b66ea1f553cbc7679681db5089fdb23329efe59de807e657a98ccc0c2d95eaac9f363d5b8c9b8a23aab680c328b019ae99440a5d8795014be22f6739a4f77874e94196f010c012f9a4a587570c38874ad7f8b9ec554fb865752a5f3dd4f785c9af54031100ce580dfadf4c70ff11839647fc288fce8d00bbcb680e02a46230ecb0530ba1771fb8485ba17f5218852c5cdfc769b89d77b37802cc6d22e6ba944f6e4b565d8d04418c44bf10e06294fd58913ca6d206bb6e46f15b3abfc09695f5fbab81d2e743ac19b24716d9d6cb6bae65674f5cdf1935d1413a4be6d96eafaf65cfa361decc0ab1e12998b5c26b6ad38c8077fd149cdeda227c4c68f19fbf22b23e7e84581a64a413c1c983e01b56c2000656b4aad8c67260fc0142eeccd96d624fa284b619d11e797af2d730a5998d9e6d9f4fef58a847d7d9b804be2925beae627a0a9f335072f97f214a24db58cf5e2e74f0eeff1a43f1ec1b88c0110f3c2abaac0d3e954a42b550c37cf84babe6e85ec4e0885eb8309a4c5e2a1bb473b332ff5c31c0b4c32db507c1eca5b7ae607d2423ee1e7f07361229e0ab2678cfbd07afffc5e989c5ab1821ac2f524083258d3f0ca7e7f8250be3f7cc72cf636b098a3c9b3f4e289fd81a9b3c33bfa63ed8813bbc12205134add9fb8548312b734c921a2cf8a1687af7ee022b0f57bbf0f8d8f17952614cb288b95df3fe4f03d20b83227328603dafb264537eb0cacda18de21aa99e07600030424edb41fc3c8161238971bf62af99db8e2d438af06f9d8feeff3edb6a4d4f0a6fb5dfdbe99b1ed454d6ff3dc508c45ed430923212a088e6200b2076da509888edd32fca946a215c8934db7a3b5ac6bed10e4a114f2f132608dbe236cba73cbcffc024fb500e96c3d766ca7f4083ded3666c2b7dcd290f65f7e80ff70fa575777a845fbf7af05b38dfb1ccd7accc0398f8dbf532e28dc6bc0ec49d18f2753caec5912693a0b6050f2bfce72f5160847dcfc78d580609007ddbdf1f338c61c13e7b62fcec6e51d1c0cd1ec0167e40042", "Passw0rd"},
	// ../run/ccache2john.py krb5cc_1000_linux-client-to-AD-server
	{"$krb5tgs$23$8bef2ad33c7d5d23c8693ccd868d9f84$f72688ca744f9634625c2dbd94ef6193644e08c4627839ce5fcf8bbfbd15ad7093fb3ecc24512ac161188a7ad2de127166f4f244f37527e15468d844efe6396756b8cf8341cbfe70e454e1f2b324f5ddee64f4f4947e1bb6776041e28e6261b57b1791677b35e1b4171ec5a05062b7bd7eb5558d6e4165ad916e790954f163a7f7e8390462295d74eff33fcbb442d4281f7cf68ddbb6ce27030015b2cf4f68e04793a9674e634663a68622e13a5a6d8c27bf8b90ee18033e754c95776d1dbd8d73ab292d27c445eb33b9b814945617f527678667b2d81adc57c7c62713d7826bc9ea918b330245a4d7fbcc33889901a63131be87a0d4e8f49d1259141677bfa27c284d8cfb1c94f4d4a602f30b774e58378710d0ad2a73c978c8c6470402c0cdbdf5d505fe07dc4250510836d5ec969b56790128aa75b292d71d4e6c77ffee261230fc7b11969e4701abc63f120420cc0f74f99e42d6613713fc0530842f77b7a45daadb296c744e0725cd2867492b5bc1cb6a4e3315e1f6b7e5b0299a9283235769d95ef63c885352b08176547f86a03ec323a2e5c84f66f3ab699fc7c5e8b2120659c963d5c98df9529939b250e0f1703f5a9859f8b00a5317aa92dc37093dc87984c0eb841cd2ce77b80510c79e8b5eb56c15f07eba936d257a4d78f82a6179ba7ed07fbeba68d43112e44f850a5034b9239c689828f7039b8c8efcbecbc34ab92d5fb869482456a92ce9201e6586458e1d7bd38b2251b1fb573dc1c6ce40a428448cfaf18e5251436aece6baa2356a06a50a6d4c011977233e7b38007cad4a869941fea1139ff4d2ce216166abf5dfa89dc85719b14eaa0d492b1d442b67cb10c81bb35e1a96ae4f62e8c4fbf604c916e2ac4a121620a2beb40cf7d43bbe7ddbb38435dacd7aba846915eb01b57d33d5dcc25082e79452416d86143e33608a8e279d396cca4a8cc5d02ad820868c4381f9f7f5bab23ba8440fd9ab5ae713cb1c20a82e0a0e93a83248b2a2a8a30aceed71a8e78526943b45f122f16ea004ffdea16005bb52e184b7498c8aefb26da2e8b43e98343e9bb364578deceee623656985fdb58dda60a112d9dc1f0e36230d43ab8d1f48ba2013fd641001f675b8918fb69826decefd742a3f3c02b49988b2b439db763db2d95744a2f2456f5b32ea64e8836873ecce085875b4e054e55700198642961560529bba800a683f149c63dd5f983477f415399f229f6f292327ebac73a6707da022e472f1081421c8549d21696db7fe7bdd2ad744a5afbada9a719c26e3962cd86f8e", "Passw0rd"},
	{NULL}
};

static char (*saved_key)[PLAINTEXT_LENGTH + 1];
static unsigned char (*saved_K1)[16];
static int any_cracked, *cracked;
static size_t cracked_size;
static int new_keys;

static struct custom_salt {
	dyna_salt dsalt;
	unsigned char edata1[16];
	uint32_t edata2len;
	unsigned char* edata2;
} *cur_salt;

static char *split(char *ciphertext, int index, struct fmt_main *self)
{
	static char *ptr, *keeptr;
	int i;

	if (strstr(ciphertext, "$SOURCE_HASH$"))
		return ciphertext;
	ptr = mem_alloc_tiny(strlen(ciphertext) + FORMAT_TAG_LEN + 1, MEM_ALIGN_NONE);
	keeptr = ptr;

	if (strncmp(ciphertext, FORMAT_TAG, FORMAT_TAG_LEN) != 0) {
		memcpy(ptr, FORMAT_TAG, FORMAT_TAG_LEN);
		ptr += FORMAT_TAG_LEN;
	}

	for (i = 0; i < strlen(ciphertext) + 1; i++)
		ptr[i] = tolower(ARCH_INDEX(ciphertext[i]));

	return keeptr;
}

static int valid(char *ciphertext, struct fmt_main *self)
{
	char *p;
	char *ctcopy;
	char *keeptr;
	int extra;

	if (strncmp(ciphertext, FORMAT_TAG, FORMAT_TAG_LEN))
		return 0;

	ctcopy = strdup(ciphertext);
	keeptr = ctcopy;

	ctcopy += FORMAT_TAG_LEN;
	if (ctcopy[0] == '*') {			/* assume account's info provided */
		ctcopy++;
		p = strtokm(ctcopy, "*");
		ctcopy  = strtokm(NULL, "");
		if (!ctcopy || *ctcopy != '$')
			goto err;
		++ctcopy;	/* set after '$' */
		goto edata;
	}
	if (ctcopy[0] == '$')
		ctcopy++;

edata:
	/* assume checksum */
	if (((p = strtokm(ctcopy, "$")) == NULL) || strlen(p) != 32)
		goto err;

	/* assume edata2 following */
	if (((p = strtokm(NULL, "$")) == NULL))
		goto err;
	if (!ishex(p) || (hexlen(p, &extra) < (64 + 16) || extra))
		goto err;

	if ((strtokm(NULL, "$") != NULL))
		goto err;
	MEM_FREE(keeptr);
	return 1;

err:
	MEM_FREE(keeptr);
	return 0;
}

static void init(struct fmt_main *self)
{
	omp_autotune(self, OMP_SCALE);

	saved_key = mem_alloc_align(sizeof(*saved_key) *
			self->params.max_keys_per_crypt,
			MEM_ALIGN_CACHE);
	saved_K1 = mem_alloc_align(sizeof(*saved_K1) *
			self->params.max_keys_per_crypt,
			MEM_ALIGN_CACHE);
	any_cracked = 0;
	cracked_size = sizeof(*cracked) * self->params.max_keys_per_crypt;
	cracked = mem_calloc(cracked_size, 1);
}

static void done(void)
{
	MEM_FREE(saved_K1);
	MEM_FREE(cracked);
	MEM_FREE(saved_key);
}

static void *get_salt(char *ciphertext)
{
	int i;
	static struct custom_salt cs;

	char *p;
	char *ctcopy;
	char *keeptr;
	static void *ptr;

	ctcopy = strdup(ciphertext);
	keeptr = ctcopy;

	memset(&cs, 0, sizeof(cs));
	cs.edata2 = NULL;

	if (strncmp(ciphertext, FORMAT_TAG, FORMAT_TAG_LEN) == 0) {
		ctcopy += FORMAT_TAG_LEN;
		if (ctcopy[0] == '*') {
			ctcopy++;
			p = strtokm(ctcopy, "*");
			ctcopy += strlen(p) + 2;
			goto edata;
		}
		if (ctcopy[0]=='$')
			ctcopy++;
	}

edata:
	if (((p = strtokm(ctcopy, "$")) != NULL) && strlen(p) == 32) {	/* assume checksum */
		for (i = 0; i < 16; i++) {
			cs.edata1[i] =
				atoi16[ARCH_INDEX(p[i * 2])] * 16 +
				atoi16[ARCH_INDEX(p[i * 2 + 1])];
		}

		/* skip '$' */
		p += strlen(p) + 1;

		/* retrieve non-constant length of edata2 */
		for (i = 0; p[i] != '\0'; i++)
			;
		cs.edata2len = i/2;
		cs.edata2 = (unsigned char*) mem_calloc_tiny(cs.edata2len + 1, sizeof(char));

		for (i = 0; i < cs.edata2len; i++) {	/* assume edata2 */
			cs.edata2[i] =
				atoi16[ARCH_INDEX(p[i * 2])] * 16 +
				atoi16[ARCH_INDEX(p[i * 2 + 1])];
		}
	}

	MEM_FREE(keeptr);

	/* following is used to fool dyna_salt stuff */
	cs.dsalt.salt_cmp_offset = SALT_CMP_OFF(struct custom_salt, edata1);
	cs.dsalt.salt_cmp_size = SALT_CMP_SIZE(struct custom_salt, edata1, edata2len, 0);
	cs.dsalt.salt_alloc_needs_free = 0;

	ptr = mem_alloc_tiny(sizeof(struct custom_salt), MEM_ALIGN_WORD);
	memcpy(ptr, &cs, sizeof(struct custom_salt));

	return (void *) &ptr;
}

static void set_salt(void *salt)
{
	cur_salt = *(struct custom_salt**)salt;
}

static void set_key(char *key, int index)
{
	strnzcpy(saved_key[index], key, strlen(key) + 1);
	new_keys = 1;
}

static char *get_key(int index)
{
	return saved_key[index];
}

static int crypt_all(int *pcount, struct db_salt *salt)
{
	const int count = *pcount;
	const unsigned char data[4] = {2, 0, 0, 0};
	int index;

	if (any_cracked) {
		memset(cracked, 0, cracked_size);
		any_cracked = 0;
	}

#ifdef _OPENMP
#pragma omp parallel for
#endif
	for (index = 0; index < count; index++) {
		unsigned char K3[16];
#ifdef _MSC_VER
		unsigned char ddata[65536];
#else
		unsigned char ddata[cur_salt->edata2len + 1];
#endif
		unsigned char checksum[16];
		RC4_KEY rckey;

		if (new_keys) {
			MD4_CTX ctx;
			unsigned char key[16];
			UTF16 wkey[PLAINTEXT_LENGTH + 1];
			int len;

			len = enc_to_utf16(wkey, PLAINTEXT_LENGTH,
					(UTF8*)saved_key[index],
					strlen(saved_key[index]));
			if (len <= 0) {
				saved_key[index][-len] = 0;
				len = strlen16(wkey);
			}

			MD4_Init(&ctx);
			MD4_Update(&ctx, (char*)wkey, 2 * len);
			MD4_Final(key, &ctx);

			hmac_md5(key, data, 4, saved_K1[index]);
		}

		hmac_md5(saved_K1[index], cur_salt->edata1, 16, K3);

		RC4_set_key(&rckey, 16, K3);
		RC4(&rckey, 32, cur_salt->edata2, ddata);

		 /*
			8 first bytes are nonce, then ASN1 structures
			(DER encoding: type-length-data)

			if length >= 128 bytes:
				length is on 2 bytes and type is
				\x63\x82 (encode_krb5_enc_tkt_part)
				and data is an ASN1 sequence \x30\x82
			else:
				length is on 1 byte and type is \x63\x81
				and data is an ASN1 sequence \x30\x81

			next headers follow the same ASN1 "type-length-data" scheme
		  */

		if (((!memcmp(ddata + 8, "\x63\x82", 2)) && (!memcmp(ddata + 16, "\xA0\x07\x03\x05", 4)))
			||
			((!memcmp(ddata + 8, "\x63\x81", 2)) && (!memcmp(ddata + 16, "\x03\x05\x00", 3)))) {

			/* check the checksum to be sure */
			RC4(&rckey, cur_salt->edata2len - 32, cur_salt->edata2 + 32, ddata + 32);
			hmac_md5(saved_K1[index], ddata, cur_salt->edata2len, checksum);

			if (!memcmp(checksum, cur_salt->edata1, 16)) {
				cracked[index] = 1;

#ifdef _OPENMP
#pragma omp atomic
#endif
				any_cracked |= 1;
			}
		}
	}
	new_keys = 0;

	return *pcount;
}

static int cmp_all(void *binary, int count)
{
	return any_cracked;
}

static int cmp_one(void *binary, int index)
{
	return cracked[index];
}

static int cmp_exact(char *source, int index)
{
	return cracked[index];
}

struct fmt_main fmt_krb5tgs = {
	{
		FORMAT_LABEL,
		FORMAT_NAME,
		ALGORITHM_NAME,
		BENCHMARK_COMMENT,
		BENCHMARK_LENGTH,
		0,
		PLAINTEXT_LENGTH,
		BINARY_SIZE,
		BINARY_ALIGN,
		SALT_SIZE,
		SALT_ALIGN,
		MIN_KEYS_PER_CRYPT,
		MAX_KEYS_PER_CRYPT,
		FMT_CASE | FMT_8_BIT | FMT_UNICODE | FMT_UTF8 | FMT_OMP | FMT_DYNA_SALT | FMT_HUGE_INPUT,
		{NULL},
		{ FORMAT_TAG },
		tests
	}, {
		init,
		done,
		fmt_default_reset,
		fmt_default_prepare,
		valid,
		split,
		fmt_default_binary,
		get_salt,
		{NULL},
		fmt_default_source,
		{
			fmt_default_binary_hash
		},
		fmt_default_dyna_salt_hash,
		NULL,
		set_salt,
		set_key,
		get_key,
		fmt_default_clear_keys,
		crypt_all,
		{
			fmt_default_get_hash
		},
		cmp_all,
		cmp_one,
		cmp_exact
	}
};

#endif
