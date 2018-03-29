#
# This file is part of John the Ripper password cracker,
# Copyright (c) 1996-2014 by Solar Designer
#
# ...with changes in the jumbo patch, by various authors
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted.
#
# There's ABSOLUTELY NO WARRANTY, express or implied.
#
# This file converted into autoconf format by JimF and
# magnum, in 2014. That is still a work in progress.
#


CC = gcc
PTHREAD_CC = gcc
ifdef PTHREAD_CC
CC = gcc
endif
AR = ar
AS = gcc
LD = gcc
CPP = gcc -E
CP = cp
LN = ln -s
MV = mv -f
RM = rm -f
MKDIR = /usr/bin/mkdir -p
TR = tr
SED = /usr/bin/sed
NULL = /dev/null
SORT = /usr/bin/sort
STRIP = strip
CPPCHECK=cppcheck

SHELL = /bin/sh


subdirs = aes secp256k1 escrypt 
top_srcdir = .
srcdir = .
prefix = ../run
F = ""

JTR_GIT_COMMIT = \"-$(shell git rev-parse --short HEAD 2>/dev/null)\"
ifeq ($(JTR_GIT_COMMIT), \"-\")
# this format string will be replaced by git archive:
JTR_ARCHIVE_VERSION_STRING = $Format:-%h %ci$
JTR_GIT_VERSION = JUMBO_VERSION "\"$(shell echo "$(JTR_ARCHIVE_VERSION_STRING)" | "$(SED)" 's/ormat:-%h %ci/-/g')\""
else
JTR_GIT_HEAD_TS = \" $(shell git show -s --format=%ci HEAD 2>/dev/null)\"
JTR_GIT_VERSION = JUMBO_VERSION "$(JTR_GIT_COMMIT) $(JTR_GIT_HEAD_TS)"
endif

CPPFLAGS =  -I/usr/local/include
CFLAGSX = -c -m64 -g -O2 -I/usr/local/include -DARCH_LITTLE_ENDIAN=1  -Wall -Wdeclaration-after-statement -fno-omit-frame-pointer --param allow-store-data-races=0 -Wno-deprecated-declarations -Wunused-but-set-variable -std=gnu89 -Wdate-time -D_POSIX_SOURCE -D_GNU_SOURCE -D_XOPEN_SOURCE=600   -fopenmp  -pthread -DHAVE_HT $(RELEASE_BLD) $(CPPFLAGS)
# CFLAGS for use on the main john.c file only
CFLAGS_MAIN = -DAC_BUILT -DJOHN_AVX2 $(CFLAGSX)
CFLAGS = -DAC_BUILT -mavx2 -DJOHN_AVX2 $(CFLAGSX)
ASFLAGS = -DAC_BUILT -m64  -DARCH_LITTLE_ENDIAN=1  -mavx2 -DJOHN_AVX2 -c -fopenmp   -DHAVE_HT
LIBS = 
LDFLAGS = -g -m64  -L/usr/local/lib -L/usr/lib64 -L/lib64 $(LIBS) 
#
OPT_NORMAL =  -funroll-loops
OPT_INLINE =  -Os -funroll-loops -finline-functions
#

PLUGFORMATS_OBJS = 7z_fmt_plug.o AzureAD_common_plug.o AzureAD_fmt_plug.o BFEgg_fmt_plug.o DMD5_fmt_plug.o DOMINOSEC8_fmt_plug.o DOMINOSEC_fmt_plug.o EPI_fmt_plug.o FGT_fmt_plug.o HDAA_fmt_plug.o IPB2_fmt_plug.o KRB4_fmt_plug.o KRB4_std_plug.o KRB5_fmt_plug.o KRB5_std_plug.o MSCHAPv2_bs_fmt_plug.o NETLM_fmt_plug.o NETLMv2_fmt_plug.o NETNTLM_bs_fmt_plug.o NETNTLMv2_fmt_plug.o NETSPLITLM_fmt_plug.o NS_fmt_plug.o PHPS2_fmt_plug.o PHPS_fmt_plug.o PO_fmt_plug.o SKEY_fmt_plug.o SKEY_jtr_plug.o SybaseASE_fmt_plug.o SybasePROP_fmt_plug.o XSHA512_fmt_plug.o XSHA_fmt_plug.o aes_ccm_plug.o agilekeychain_fmt_plug.o aix_smd5_fmt_plug.o aix_ssha_fmt_plug.o androidfde_fmt_plug.o argon2_core_plug.o argon2_encoding_plug.o argon2_fmt_plug.o argon2_opt_plug.o argon2_plug.o argon2_ref_plug.o as400_des_fmt_plug.o as400_ssha1_fmt_plug.o asaMD5_fmt_plug.o asn1_plug.o axcrypt_fmt_plug.o bcrypt_pbkdf_plug.o bestcrypt_fmt_plug.o bitcoin_fmt_plug.o bitlocker_common_plug.o bitlocker_fmt_plug.o bitwarden_common_plug.o bitwarden_fmt_plug.o bks_fmt_plug.o blackberry_ES10_fmt_plug.o blake2b-ref_plug.o blake2b_plug.o blf_plug.o blockchain_common_plug.o blockchain_fmt_plug.o chacha_plug.o chap_fmt_plug.o citrix_ns_fmt_plug.o clipperz_srp_fmt_plug.o cloudkeychain_fmt_plug.o cq_fmt_plug.o crc32_fmt_plug.o dahua_fmt_plug.o dashlane_common_plug.o dashlane_fmt_plug.o django_fmt_plug.o django_scrypt_fmt_plug.o dmg_common_plug.o dmg_fmt_plug.o dpapimk_fmt_plug.o dragonfly3_fmt_plug.o dragonfly4_fmt_plug.o drupal7_fmt_plug.o dynamic_compiler_fmt_plug.o ecryptfs_fmt_plug.o eigrp_fmt_plug.o electrum_fmt_plug.o encfs_common_plug.o encfs_fmt_plug.o enpass_common_plug.o enpass_fmt_plug.o episerver_fmt_plug.o ethereum_common_plug.o ethereum_fmt_plug.o feal8_plug.o formspring_fmt_plug.o fvde_common_plug.o fvde_fmt_plug.o geli_common_plug.o geli_fmt_plug.o gost3411-2012-sse41_plug.o gost3411-tables_plug.o gost_fmt_plug.o gpg_common_plug.o gpg_fmt_plug.o has160_fmt_plug.o has160_plug.o haval_fmt_plug.o hmacMD5_fmt_plug.o hmacSHA1_fmt_plug.o hmacSHA256_fmt_plug.o hmacSHA512_fmt_plug.o hmac_sha_plug.o hmailserver_fmt_plug.o hsrp_fmt_plug.o idea_plug.o ike_fmt_plug.o itunes_common_plug.o itunes_fmt_plug.o iwork_common_plug.o iwork_fmt_plug.o keepass_common_plug.o keepass_fmt_plug.o keychain_fmt_plug.o keyring_fmt_plug.o keystore_common_plug.o keystore_fmt_plug.o known_hosts_fmt_plug.o krb5_asrep_common_plug.o krb5_asrep_fmt_plug.o krb5_common_plug.o krb5_db_fmt_plug.o krb5_tgs_fmt_plug.o krb5pa-md5_fmt_plug.o krb5pa-sha1_fmt_plug.o kwallet_fmt_plug.o lastpass_cli_common_plug.o lastpass_cli_fmt_plug.o lastpass_common_plug.o lastpass_fmt_plug.o lastpass_sniffed_fmt_plug.o leet_cc_fmt_plug.o libreoffice_common_plug.o libreoffice_fmt_plug.o lotus5_fmt_plug.o lotus85_fmt_plug.o luks_fmt_plug.o md2_fmt_plug.o mdc2_fmt_plug.o mdc2dgst_plug.o mediawiki_fmt_plug.o money_fmt_plug.o mongodb_fmt_plug.o mongodb_scram_fmt_plug.o mozilla_ng_fmt_plug.o mscash1_fmt_plug.o mscash2_fmt_plug.o mscash_common_plug.o mssql-old_fmt_plug.o mssql05_fmt_plug.o mssql12_fmt_plug.o multibit_fmt_plug.o mysqlSHA1_fmt_plug.o mysql_fmt_plug.o mysql_netauth_fmt_plug.o net_ah_fmt_plug.o net_md5_fmt_plug.o net_sha1_fmt_plug.o notes_common_plug.o notes_fmt_plug.o nsec3_fmt_plug.o nt2_fmt_plug.o ntlmv1_mschapv2_fmt_plug.o nukedclan_fmt_plug.o o10glogon_fmt_plug.o o3logon_fmt_plug.o o5logon_fmt_plug.o office_common_plug.o office_fmt_plug.o oldoffice_fmt_plug.o openbsdsoftraid_common_plug.o openbsdsoftraid_fmt_plug.o openssl_code_plug.o openssl_enc_fmt_plug.o oracle11_fmt_plug.o oracle12c_fmt_plug.o oracle_fmt_plug.o osc_fmt_plug.o ospf_fmt_plug.o padlock_fmt_plug.o palshop_fmt_plug.o panama_fmt_plug.o pbkdf2-hmac-md4_fmt_plug.o pbkdf2-hmac-md5_fmt_plug.o pbkdf2-hmac-sha1_fmt_plug.o pbkdf2-hmac-sha512_fmt_plug.o pbkdf2_hmac_common_plug.o pbkdf2_hmac_sha256_fmt_plug.o pdf_fmt_plug.o pdfcrack_md5_plug.o pem_common_plug.o pem_fmt_plug.o pfx_common_plug.o pfx_fmt_plug.o pgpdisk_common_plug.o pgpdisk_fmt_plug.o pgpsda_common_plug.o pgpsda_fmt_plug.o pgpwde_common_plug.o pgpwde_fmt_plug.o phpassMD5_fmt_plug.o phpass_common_plug.o pixMD5_fmt_plug.o pkcs12_plug.o pkzip_fmt_plug.o plaintext_fmt_plug.o pomelo_fmt_plug.o pomelo_plug.o postgres_fmt_plug.o pst_fmt_plug.o putty_fmt_plug.o pwsafe_fmt_plug.o qnx_fmt_plug.o racf_fmt_plug.o radmin_fmt_plug.o rakp_fmt_plug.o rar5_fmt_plug.o rar_fmt_plug.o rawBLAKE2_512_fmt_plug.o rawKeccak_256_fmt_plug.o rawKeccak_512_fmt_plug.o rawMD4_fmt_plug.o rawMD5_fmt_plug.o rawMD5flat_fmt_plug.o rawSHA1_common_plug.o rawSHA1_fmt_plug.o rawSHA1_linkedIn_fmt_plug.o rawSHA1_ng_fmt_plug.o rawSHA224_fmt_plug.o rawSHA256_common_plug.o rawSHA256_fmt_plug.o rawSHA256_ng_fmt_plug.o rawSHA384_fmt_plug.o rawSHA512_common_plug.o rawSHA512_fmt_plug.o rawSHA512_ng_fmt_plug.o rawmd5u_fmt_plug.o ripemd_fmt_plug.o rsvp_fmt_plug.o salted_sha1_common_plug.o salted_sha1_fmt_plug.o sapB_fmt_plug.o sapG_fmt_plug.o sapH_fmt_plug.o securezip_common_plug.o securezip_fmt_plug.o serpent_plug.o sha1crypt_common_plug.o sha1crypt_fmt_plug.o sha256crypt_fmt_plug.o sha3_512_fmt_plug.o sha512crypt_fmt_plug.o siemens-s7_fmt_plug.o sip_fmt_plug.o skein_fmt_plug.o sl3_common_plug.o sl3_fmt_plug.o snefru_fmt_plug.o snefru_plug.o snmp_fmt_plug.o ssh_ng_fmt_plug.o ssha512_fmt_plug.o sspr_common_plug.o sspr_fmt_plug.o stribog_fmt_plug.o strip_fmt_plug.o sunmd5_fmt_plug.o syb-prop_repro_plug.o tacacs_plus_fmt_plug.o tcp_md5_fmt_plug.o tiger_fmt_plug.o truecrypt_fmt_plug.o twofish_plug.o vdi_fmt_plug.o vms_fmt_plug.o vnc_fmt_plug.o vtp_fmt_plug.o wbb3_fmt_plug.o whirlpool_fmt_plug.o wow_srp_fmt_plug.o wpapmk_fmt_plug.o wpapsk_fmt_plug.o xmpp_scram_fmt_plug.o xts_plug.o zip_fmt_plug.o zipmonster_fmt_plug.o

JOHN_OBJS = \
	jumbo.o john-mpi.o \
	DES_fmt.o DES_std.o DES_bs.o DES_bs_b.o \
	BSDI_fmt.o \
	MD5_fmt.o MD5_std.o md5crypt_common.o \
	BF_fmt.o BF_std.o BF_common.o \
	scrypt_fmt.o \
	escrypt/crypto_scrypt-best.o escrypt/crypto_scrypt-common.o \
	escrypt/sha256.o \
	AFS_fmt.o \
	LM_fmt.o \
	trip_fmt.o \
	NT_fmt.o \
	KeccakDuplex.o KeccakF-1600-opt64.o KeccakHash.o KeccakSponge.o \
	whirlpool.o haval.o skein.o md2.o panama.o \
	timer.o omp_autotune.o \
	md5.o \
	rc4.o \
	hmacmd5.o \
	base64_convert.o \
	md4.o sha2.o \
	dynamic_fmt.o dynamic_parser.o dynamic_preloads.o dynamic_utils.o dynamic_big_crypt.o \
	dynamic_compiler.o dynamic_compiler_lib.o \
	ripemd.o tiger.o \
	unrarcmd.o unrarfilter.o unrarhlp.o unrar.o unrarppm.o unrarvm.o \
	rar2john.o \
	zip2john.o pkzip.o \
	$(PLUGFORMATS_OBJS) \
	dyna_salt.o dummy.o \
	gost.o \
	common-gpu.o \
	batch.o bench.o charset.o common.o compiler.o config.o cracker.o crc32.o external.o \
	formats.o getopt.o idle.o inc.o john.o list.o loader.o logger.o mask.o mask_ext.o \
	memory.o misc.o options.o params.o path.o recovery.o rpp.o rules.o signals.o single.o status.o \
	tty.o  wordlist.o \
	mkv.o mkvlib.o \
	listconf.o \
	fake_salts.o \
	win32_memmap.o \
	uaf_encode.o \
	unicode.o \
	unshadow.o \
	unafs.o \
	undrop.o \
	regex.o pp.o \
	c3_fmt.o \
	lzma/LzmaDec.o lzma/Lzma2Dec.o \
	unique.o gpg2john.o memdbg.o

OCL_OBJS = common-opencl.o opencl_autotune.o bt.o bt_hash_type_64.o bt_hash_type_128.o bt_hash_type_192.o bt_twister.o

OPENCL_PLUGFORMATS_OBJS = opencl_7z_fmt_plug.o opencl_DES_bs_b_plug.o opencl_DES_bs_f_plug.o opencl_DES_bs_h_plug.o opencl_DES_bs_plug.o opencl_DES_fmt_plug.o opencl_agilekeychain_fmt_plug.o opencl_bf_fmt_plug.o opencl_bf_std_plug.o opencl_bitlocker_fmt_plug.o opencl_bitwarden_fmt_plug.o opencl_blockchain_fmt_plug.o opencl_dashlane_fmt_plug.o opencl_dmg_fmt_plug.o opencl_electrum_modern_fmt_plug.o opencl_encfs_fmt_plug.o opencl_enpass_fmt_plug.o opencl_ethereum_fmt_plug.o opencl_ethereum_presale_fmt_plug.o opencl_fvde_fmt_plug.o opencl_geli_fmt_plug.o opencl_gpg_fmt_plug.o opencl_hash_check_128_plug.o opencl_iwork_fmt_plug.o opencl_keychain_fmt_plug.o opencl_keyring_fmt_plug.o opencl_keystore_fmt_plug.o opencl_krb5_asrep_aes_fmt_plug.o opencl_krb5pa-md5_fmt_plug.o opencl_krb5pa-sha1_fmt_plug.o opencl_lastpass_cli_fmt_plug.o opencl_lastpass_fmt_plug.o opencl_libreoffice_aes_fmt_plug.o opencl_libreoffice_fmt_plug.o opencl_lm_b_plug.o opencl_lm_fmt_plug.o opencl_lm_plug.o opencl_lotus5_fmt_plug.o opencl_md5crypt_fmt_plug.o opencl_mscash2_fmt_plug.o opencl_mscash2_helper_plug.o opencl_mscash_fmt_plug.o opencl_mysqlsha1_fmt_plug.o opencl_notes_fmt_plug.o opencl_nt_fmt_plug.o opencl_ntlmv2_fmt_plug.o opencl_o5logon_fmt_plug.o opencl_office_fmt_plug.o opencl_oldoffice_fmt_plug.o opencl_openbsdsoftraid_fmt_plug.o opencl_pbkdf2_hmac_md4_fmt_plug.o opencl_pbkdf2_hmac_md5_fmt_plug.o opencl_pbkdf2_hmac_sha1_fmt_plug.o opencl_pbkdf2_hmac_sha256_fmt_plug.o opencl_pbkdf2_hmac_sha512_fmt_plug.o opencl_pem_fmt_plug.o opencl_pfx_fmt_plug.o opencl_pgpdisk_fmt_plug.o opencl_pgpsda_fmt_plug.o opencl_pgpwde_fmt_plug.o opencl_phpass_fmt_plug.o opencl_pwsafe_fmt_plug.o opencl_rakp_fmt_plug.o opencl_rar5_fmt_plug.o opencl_rar_fmt_plug.o opencl_rawmd4_fmt_plug.o opencl_rawmd5_fmt_plug.o opencl_rawsha1_fmt_plug.o opencl_rawsha256_fmt_plug.o opencl_rawsha512_fmt_plug.o opencl_rawsha512_gpl_fmt_plug.o opencl_salted_sha_fmt_plug.o opencl_sha1crypt_fmt_plug.o opencl_sha256crypt_fmt_plug.o opencl_sha2_common_plug.o opencl_sha512crypt_fmt_plug.o opencl_sl3_fmt_plug.o opencl_sspr_fmt_plug.o opencl_strip_fmt_plug.o opencl_tc_fmt_plug.o opencl_wpapmk_fmt_plug.o opencl_wpapsk_fmt_plug.o opencl_xsha512_fmt_plug.o opencl_zip_fmt_plug.o

ZTEX_OBJS = ztex_descrypt.o ztex_bcrypt.o

FUZZ_OBJS = fuzz.o

GENMKVPWD_OBJS = \
	genmkvpwd.o mkvlib.o memory.o miscnl.o path.o memdbg.o jumbo.o

PROJ = ../run/john ../run/unshadow ../run/unafs ../run/unique ../run/undrop \
	../run/rar2john ../run/zip2john \
	../run/genmkvpwd ../run/mkvcalcproba ../run/calc_stat \
	../run/tgtsnarf ../run/racf2john ../run/hccap2john \
	../run/raw2dyna ../run/keepass2john ../run/bitlocker2john \
	../run/dmg2john ../run/putty2john ../run/uaf2john \
	../run/wpapcap2john \
	../run/gpg2john ../run/cprepair ../run/base64conv

WITH_PCAP = -DHAVE_PCAP
ifdef WITH_PCAP
PROJ += ../run/SIPdump ../run/vncpcap2john ../run/eapmd5tojohn
endif

WITH_OPENCL=
ifdef WITH_OPENCL
CFLAGS += -DHAVE_OPENCL 
CFLAGS_MAIN += -DHAVE_OPENCL 
JOHN_OBJS += $(OCL_OBJS) $(OPENCL_PLUGFORMATS_OBJS)

# core OpenCL dependencies
CL_DEVICE_HEADER = opencl_device_info.h
CL_COMMON_HEADER = common-opencl.h common-gpu.h gpu_sensors.h
endif

WITH_ZTEX=
ifdef WITH_ZTEX
CFLAGS += -DHAVE_ZTEX
CFLAGS_MAIN += -DHAVE_ZTEX
JOHN_OBJS += $(ZTEX_OBJS)
endif

WITH_FUZZ=
ifdef WITH_FUZZ
CFLAGS += -DHAVE_FUZZ
CFLAGS_MAIN += -DHAVE_FUZZ
JOHN_OBJS += $(FUZZ_OBJS)
endif

WITH_LIBFUZZER=
ifdef WITH_LIBFUZZER
CFLAGS += -DHAVE_LIBFUZZER  -fsanitize=address -fsanitize-coverage=trace-pc-guard,trace-cmp,trace-gep,trace-div
CFLAGS_MAIN += -DHAVE_LIBFUZZER -fsanitize=address -fsanitize-coverage=trace-pc-guard,trace-cmp,trace-gep,trace-div
LDFLAGS += -fsanitize=fuzzer,address
endif

#########################################################
# this is what ./configure && make
# gets you.
#
#  also need to figure out -DUNDERSCORES and add to ASFLAGS
#  also need to figure out -mpreferred-stack-boundary=4 and add (or whatever the stack size is)
#
#########################################################
default:
	$(MAKE) find_version
	@$(MAKE) $(PROJ) \
		JOHN_OBJS="$(JOHN_OBJS) x86-64.o simd-intrinsics.o" \
		AESNI_ARCH=64
	@echo
	@echo Make process completed.

#########################################################
## This is the 'END' of the main default make target.
#########################################################

# Default build is always using -g (stripped when 'make install') but this
# target turns off optimizations for better debugging, and defines DEBUG
# so code can adopt.
debug:
	$(MAKE) default CFLAGS="-DDEBUG $(CFLAGS)  -Og" CFLAGS_MAIN="-DDEBUG $(CFLAGS_MAIN)  -Og"

# Similar but just turn memdbg on instead, and normal optimizations.
memdbg:
	$(MAKE) default CFLAGS="-DMEMDBG_ON $(CFLAGS)" CFLAGS_MAIN="-DMEMDBG_ON $(CFLAGS_MAIN)"
memdbg_ex:
	$(MAKE) default CFLAGS="-DMEMDBG_ON -DMEMDBG_EXTRA_CHECKS $(CFLAGS)" CFLAGS_MAIN="-DMEMDBG_ON -DMEMDBG_EXTRA_CHECKS $(CFLAGS_MAIN)"

help:
	@echo "The 'older' fat makefile can be done with make --file=Makefile.legacy [target]"

dynamic_big_crypt.c: dynamic_big_crypt_hash.cin dynamic_big_crypt_header.cin dynamic_big_crypt_generator.sh dynamic_big_crypt_chopper.pl unused/dynamic_big_crypt.c
	$(shell ./dynamic_big_crypt_generator.sh)
	@if [ ! -f dynamic_big_crypt.c ] ; then $(CP) unused/dynamic_big_crypt.c dynamic_big_crypt.c ; fi

# Digital/Compaq's cc and make use the .S suffix for a different purpose...
digipaq-alpha.o: alpha.S
	$(CPP) $(CPPFLAGS) alpha.S > tmp.s
	$(AS) $(ASFLAGS) tmp.s -o digipaq-alpha.o
	$(RM) tmp.s

7z_fmt_plug.o:	7z_fmt_plug.c arch.h johnswap.h common.h memory.h misc.h jumbo.h autoconfig.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h aes.h aes/aes_func.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h stdbool.h crc32.h unicode.h dyna_salt.h lzma/LzmaDec.h lzma/7zTypes.h lzma/Lzma2Dec.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h

AzureAD_common_plug.o:	AzureAD_common_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h base64_convert.h johnswap.h AzureAD_common.h memdbg.h os.h os-autoconf.h

AzureAD_fmt_plug.o:	AzureAD_fmt_plug.c arch.h md4.h pbkdf2_hmac_sha256.h sha2.h aligned.h openssl_local_overrides.h md5.h jtr_sha2.h johnswap.h common.h memory.h stdbool.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h formats.h params.h misc.h jumbo.h autoconfig.h omp_autotune.h base64_convert.h AzureAD_common.h unicode.h options.h list.h loader.h getopt.h memdbg.h os.h os-autoconf.h common-get-hash.h

BFEgg_fmt_plug.o:	BFEgg_fmt_plug.c misc.h jumbo.h arch.h autoconfig.h formats.h params.h omp_autotune.h common.h memory.h blowfish.c blowfish.h bf_tab.h johnswap.h memdbg.h os.h os-autoconf.h common-get-hash.h

DMD5_fmt_plug.o:	DMD5_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h md5.h common.h memory.h formats.h params.h omp_autotune.h memdbg.h os.h os-autoconf.h common-get-hash.h

DOMINOSEC8_fmt_plug.o:	DOMINOSEC8_fmt_plug.c misc.h jumbo.h arch.h autoconfig.h formats.h params.h omp_autotune.h common.h memory.h pbkdf2_hmac_sha1.h sha.h aligned.h md4.h md5.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h common-get-hash.h

DOMINOSEC_fmt_plug.o:	DOMINOSEC_fmt_plug.c misc.h jumbo.h arch.h autoconfig.h formats.h params.h omp_autotune.h common.h memory.h memdbg.h os.h os-autoconf.h common-get-hash.h

EPI_fmt_plug.o:	EPI_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h sha.h aligned.h md4.h md5.h memdbg.h os.h os-autoconf.h common-get-hash.h

FGT_fmt_plug.o:	FGT_fmt_plug.c common.h arch.h memory.h formats.h params.h misc.h jumbo.h autoconfig.h omp_autotune.h sha.h aligned.h md4.h md5.h base64_convert.h memdbg.h os.h os-autoconf.h common-get-hash.h

HDAA_fmt_plug.o:	HDAA_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h md5.h johnswap.h simd-intrinsics.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h common-get-hash.h

IPB2_fmt_plug.o:	IPB2_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h md5.h johnswap.h common.h memory.h formats.h params.h omp_autotune.h simd-intrinsics.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h common-get-hash.h

KRB4_fmt_plug.o:	KRB4_fmt_plug.c arch.h DES_std.h KRB4_std.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h memdbg.h os.h os-autoconf.h

KRB4_std_plug.o:	KRB4_std_plug.c autoconfig.h KRB4_std.h memdbg.h os.h os-autoconf.h jumbo.h arch.h memory.h

KRB5_fmt_plug.o:	KRB5_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h formats.h params.h omp_autotune.h memory.h KRB5_std.h memdbg.h os.h os-autoconf.h

KRB5_std_plug.o:	KRB5_std_plug.c KRB5_std.h memory.h arch.h misc.h jumbo.h autoconfig.h memdbg.h os.h os-autoconf.h

MSCHAPv2_bs_fmt_plug.o:	MSCHAPv2_bs_fmt_plug.c arch.h DES_std.h DES_bs.h common.h memory.h loader.h params.h list.h formats.h misc.h jumbo.h autoconfig.h omp_autotune.h options.h getopt.h sha.h aligned.h md4.h md5.h unicode.h memdbg.h os.h os-autoconf.h

NETLM_fmt_plug.o:	NETLM_fmt_plug.c misc.h jumbo.h arch.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h unicode.h options.h list.h loader.h getopt.h memdbg.h os.h os-autoconf.h common-get-hash.h

NETLMv2_fmt_plug.o:	NETLMv2_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h unicode.h md5.h hmacmd5.h aligned.h byteorder.h memdbg.h os.h os-autoconf.h common-get-hash.h

NETNTLM_bs_fmt_plug.o:	NETNTLM_bs_fmt_plug.c arch.h DES_std.h DES_bs.h common.h memory.h loader.h params.h list.h formats.h misc.h jumbo.h autoconfig.h omp_autotune.h options.h getopt.h md5.h unicode.h memdbg.h os.h os-autoconf.h

NETNTLMv2_fmt_plug.o:	NETNTLMv2_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h md5.h hmacmd5.h aligned.h unicode.h byteorder.h memdbg.h os.h os-autoconf.h

NETSPLITLM_fmt_plug.o:	NETSPLITLM_fmt_plug.c misc.h jumbo.h arch.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h unicode.h options.h list.h loader.h getopt.h memdbg.h os.h os-autoconf.h common-get-hash.h

NS_fmt_plug.o:	NS_fmt_plug.c autoconfig.h misc.h jumbo.h arch.h md5.h common.h memory.h formats.h params.h omp_autotune.h dynamic.h simd-intrinsics.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h base64_convert.h johnswap.h memdbg.h os.h os-autoconf.h

PHPS2_fmt_plug.o:	PHPS2_fmt_plug.c autoconfig.h common.h arch.h memory.h formats.h params.h misc.h jumbo.h omp_autotune.h dynamic.h simd-intrinsics.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h

PHPS_fmt_plug.o:	PHPS_fmt_plug.c autoconfig.h common.h arch.h memory.h formats.h params.h misc.h jumbo.h omp_autotune.h dynamic.h simd-intrinsics.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h options.h list.h loader.h getopt.h memdbg.h os.h os-autoconf.h

PO_fmt_plug.o:	PO_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h md5.h memdbg.h os.h os-autoconf.h common-get-hash.h

SKEY_fmt_plug.o:	SKEY_fmt_plug.c arch.h SKEY_jtr.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h memdbg.h os.h os-autoconf.h common-get-hash.h

SKEY_jtr_plug.o:	SKEY_jtr_plug.c arch.h SKEY_jtr.h misc.h jumbo.h autoconfig.h memdbg.h os.h os-autoconf.h memory.h md4.h md5.h sha.h aligned.h sph_ripemd.h sph_types.h

SybaseASE_fmt_plug.o:	SybaseASE_fmt_plug.c arch.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h johnswap.h common.h memory.h stdbool.h params.h formats.h misc.h jumbo.h autoconfig.h omp_autotune.h options.h list.h loader.h getopt.h unicode.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h common-get-hash.h

SybasePROP_fmt_plug.o:	SybasePROP_fmt_plug.c arch.h params.h common.h memory.h formats.h misc.h jumbo.h autoconfig.h omp_autotune.h options.h list.h loader.h getopt.h syb-prop_repro.h memdbg.h os.h os-autoconf.h common-get-hash.h

XSHA512_fmt_plug.o:	XSHA512_fmt_plug.c arch.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h johnswap.h common.h memory.h stdbool.h params.h formats.h misc.h jumbo.h autoconfig.h omp_autotune.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h rawSHA512_common.h memdbg.h os.h os-autoconf.h common-simd-getpos.h common-simd-setkey64.h

XSHA_fmt_plug.o:	XSHA_fmt_plug.c arch.h simd-intrinsics.h common.h memory.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h params.h formats.h misc.h jumbo.h autoconfig.h omp_autotune.h sha.h md4.h md5.h johnswap.h memdbg.h os.h os-autoconf.h common-simd-getpos.h common-get-hash.h common-simd-setkey32.h

aes_ccm_plug.o:	aes_ccm_plug.c aes.h autoconfig.h aes/aes_func.h aes_ccm.h

agilekeychain_fmt_plug.o:	agilekeychain_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h aes.h aes/aes_func.h johnswap.h pbkdf2_hmac_sha1.h sha.h aligned.h md4.h md5.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h

aix_smd5_fmt_plug.o:	aix_smd5_fmt_plug.c md5.h arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h memdbg.h os.h os-autoconf.h common-get-hash.h

aix_ssha_fmt_plug.o:	aix_ssha_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h pbkdf2_hmac_sha1.h sha.h aligned.h md4.h md5.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h pbkdf2_hmac_sha256.h sha2.h openssl_local_overrides.h jtr_sha2.h johnswap.h stdbool.h pbkdf2_hmac_sha512.h memdbg.h os.h os-autoconf.h common-get-hash.h

androidfde_fmt_plug.o:	androidfde_fmt_plug.c arch.h johnswap.h common.h memory.h misc.h jumbo.h autoconfig.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h pbkdf2_hmac_sha1.h sha.h aligned.h md4.h md5.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h aes.h aes/aes_func.h sha2.h openssl_local_overrides.h jtr_sha2.h stdbool.h memdbg.h os.h os-autoconf.h

argon2_core_plug.o:	argon2_core_plug.c argon2_core.h argon2.h blake2.h aligned.h jumbo.h arch.h blake2-impl.h memdbg.h os.h os-autoconf.h autoconfig.h memory.h

argon2_encoding_plug.o:	argon2_encoding_plug.c argon2_encoding.h argon2.h argon2_core.h memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h arch.h memory.h

argon2_fmt_plug.o:	argon2_fmt_plug.c arch.h params.h common.h memory.h formats.h misc.h jumbo.h autoconfig.h omp_autotune.h options.h list.h loader.h getopt.h argon2.h argon2_core.h argon2_encoding.h memdbg.h os.h os-autoconf.h common-get-hash.h

argon2_opt_plug.o:	argon2_opt_plug.c argon2.h argon2_opt.h argon2_core.h blake2.h aligned.h jumbo.h arch.h blamka-round-opt.h blake2-impl.h memdbg.h os.h os-autoconf.h autoconfig.h memory.h

argon2_plug.o:	argon2_plug.c argon2.h argon2_encoding.h argon2_core.h memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h arch.h memory.h

argon2_ref_plug.o:	argon2_ref_plug.c argon2.h argon2_core.h argon2_ref.h blamka-round-ref.h blake2.h aligned.h jumbo.h arch.h blake2-impl.h memdbg.h os.h os-autoconf.h autoconfig.h memory.h

as400_des_fmt_plug.o:	as400_des_fmt_plug.c arch.h crc32.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h memdbg.h os.h os-autoconf.h common-get-hash.h

as400_ssha1_fmt_plug.o:	as400_ssha1_fmt_plug.c autoconfig.h common.h arch.h memory.h formats.h params.h misc.h jumbo.h omp_autotune.h dynamic.h simd-intrinsics.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h options.h list.h loader.h getopt.h unicode.h base64_convert.h memdbg.h os.h os-autoconf.h

asaMD5_fmt_plug.o:	asaMD5_fmt_plug.c autoconfig.h common.h arch.h memory.h formats.h params.h misc.h jumbo.h omp_autotune.h dynamic.h simd-intrinsics.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h

asn1_plug.o:	asn1_plug.c asn1.h jumbo.h arch.h

axcrypt_fmt_plug.o:	axcrypt_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h dyna_salt.h sha.h aligned.h md4.h md5.h aes.h aes/aes_func.h memdbg.h os.h os-autoconf.h

bcrypt_pbkdf_plug.o:	bcrypt_pbkdf_plug.c blf.h sha2.h arch.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h johnswap.h common.h memory.h stdbool.h memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h

bestcrypt_fmt_plug.o:	bestcrypt_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h memory.h common.h formats.h params.h omp_autotune.h johnswap.h sha.h aligned.h md4.h md5.h loader.h list.h pkcs12.h aes.h aes/aes_func.h xts.h twofish.h serpent.h sph_whirlpool.h sph_types.h memdbg.h os.h os-autoconf.h

bitcoin_fmt_plug.o:	bitcoin_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h johnswap.h stdbool.h aes.h aes/aes_func.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h

bitlocker_common_plug.o:	bitlocker_common_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h bitlocker_common.h formats.h params.h omp_autotune.h hmac_sha.h johnswap.h memdbg.h os.h os-autoconf.h

bitlocker_fmt_plug.o:	bitlocker_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h unicode.h options.h list.h loader.h getopt.h johnswap.h aes.h aes/aes_func.h aes_ccm.h sha.h aligned.h md4.h md5.h bitlocker_common.h bitlocker_variable_code.h memdbg.h os.h os-autoconf.h

bitwarden_common_plug.o:	bitwarden_common_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h bitwarden_common.h formats.h params.h omp_autotune.h memdbg.h os.h os-autoconf.h

bitwarden_fmt_plug.o:	bitwarden_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h aes.h aes/aes_func.h pbkdf2_hmac_sha256.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h johnswap.h stdbool.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h bitwarden_common.h memdbg.h os.h os-autoconf.h

bks_fmt_plug.o:	bks_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h memory.h common.h formats.h params.h omp_autotune.h johnswap.h hmac_sha.h twofish.h sha.h aligned.h md4.h md5.h loader.h list.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h pkcs12.h memdbg.h os.h os-autoconf.h

blackberry_ES10_fmt_plug.o:	blackberry_ES10_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h johnswap.h stdbool.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h common-get-hash.h

blake2b-ref_plug.o:	blake2b-ref_plug.c arch.h blake2.h aligned.h jumbo.h blake2-impl.h memdbg.h os.h os-autoconf.h autoconfig.h memory.h

blake2b_plug.o:	blake2b_plug.c arch.h blake2.h aligned.h jumbo.h blake2-impl.h blake2b-round.h blake2b-load-sse41.h blake2b-load-sse2.h memdbg.h os.h os-autoconf.h autoconfig.h memory.h

blf_plug.o:	blf_plug.c blf.h memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h arch.h memory.h

blockchain_common_plug.o:	blockchain_common_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h aes.h aes/aes_func.h blockchain_common.h formats.h params.h omp_autotune.h

blockchain_fmt_plug.o:	blockchain_fmt_plug.c arch.h jumbo.h common.h memory.h formats.h params.h misc.h autoconfig.h omp_autotune.h options.h list.h loader.h getopt.h johnswap.h pbkdf2_hmac_sha1.h sha.h aligned.h md4.h md5.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h blockchain_common.h memdbg.h os.h os-autoconf.h

chacha_plug.o:	chacha_plug.c chacha.h

chap_fmt_plug.o:	chap_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h md5.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h memdbg.h os.h os-autoconf.h common-get-hash.h

citrix_ns_fmt_plug.o:	citrix_ns_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h common.h memory.h johnswap.h simd-intrinsics.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h sha.h md4.h md5.h memdbg.h os.h os-autoconf.h common-simd-getpos.h common-simd-setkey32.h common-get-hash.h

clipperz_srp_fmt_plug.o:	clipperz_srp_fmt_plug.c autoconfig.h sha2.h arch.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h johnswap.h common.h memory.h stdbool.h params.h formats.h misc.h jumbo.h omp_autotune.h memdbg.h os.h os-autoconf.h common-get-hash.h

cloudkeychain_fmt_plug.o:	cloudkeychain_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h johnswap.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h stdbool.h pbkdf2_hmac_sha512.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h

cq_fmt_plug.o:	cq_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h params.h common.h memory.h formats.h omp_autotune.h options.h list.h loader.h getopt.h memdbg.h os.h os-autoconf.h common-get-hash.h

crc32_fmt_plug.o:	crc32_fmt_plug.c arch.h common.h memory.h formats.h params.h misc.h jumbo.h autoconfig.h omp_autotune.h crc32.h loader.h list.h memdbg.h os.h os-autoconf.h common-get-hash.h

dahua_fmt_plug.o:	dahua_fmt_plug.c arch.h md5.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h johnswap.h options.h list.h loader.h getopt.h memdbg.h os.h os-autoconf.h common-get-hash.h

dashlane_common_plug.o:	dashlane_common_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h aes.h aes/aes_func.h openssl_code.h dashlane_common.h formats.h params.h omp_autotune.h memdbg.h os.h os-autoconf.h

dashlane_fmt_plug.o:	dashlane_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h aes.h aes/aes_func.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h johnswap.h stdbool.h pbkdf2_hmac_sha1.h sha.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h dashlane_common.h openssl_code.h hmac_sha.h memdbg.h os.h os-autoconf.h

django_fmt_plug.o:	django_fmt_plug.c arch.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h johnswap.h common.h memory.h stdbool.h misc.h jumbo.h autoconfig.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h base64_convert.h pbkdf2_hmac_sha256.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h common-get-hash.h

django_scrypt_fmt_plug.o:	django_scrypt_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h base64_convert.h escrypt/crypto_scrypt.h memdbg.h os.h os-autoconf.h common-get-hash.h

dmg_common_plug.o:	dmg_common_plug.c formats.h params.h arch.h misc.h jumbo.h autoconfig.h omp_autotune.h

dmg_fmt_plug.o:	dmg_fmt_plug.c autoconfig.h aes.h aes/aes_func.h hmac_sha.h os.h os-autoconf.h jumbo.h arch.h params.h johnswap.h common.h memory.h formats.h misc.h omp_autotune.h dmg_common.h pbkdf2_hmac_sha1.h sha.h aligned.h md4.h md5.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h loader.h list.h memdbg.h

dpapimk_fmt_plug.o:	dpapimk_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h memory.h common.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h unicode.h aes.h aes/aes_func.h sha.h aligned.h md4.h md5.h hmac_sha.h memdbg.h os.h os-autoconf.h pbkdf2_hmac_sha512.h sha2.h openssl_local_overrides.h jtr_sha2.h johnswap.h stdbool.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h pbkdf2_hmac_sha1.h

dragonfly3_fmt_plug.o:	dragonfly3_fmt_plug.c arch.h params.h common.h memory.h formats.h misc.h jumbo.h autoconfig.h omp_autotune.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h johnswap.h stdbool.h memdbg.h os.h os-autoconf.h common-get-hash.h

dragonfly4_fmt_plug.o:	dragonfly4_fmt_plug.c arch.h params.h common.h memory.h formats.h misc.h jumbo.h autoconfig.h omp_autotune.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h johnswap.h stdbool.h memdbg.h os.h os-autoconf.h common-get-hash.h

drupal7_fmt_plug.o:	drupal7_fmt_plug.c sha2.h arch.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h johnswap.h common.h memory.h stdbool.h misc.h jumbo.h autoconfig.h formats.h params.h omp_autotune.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h common-get-hash.h

dynamic_compiler_fmt_plug.o:	dynamic_compiler_fmt_plug.c arch.h common.h memory.h formats.h params.h misc.h jumbo.h autoconfig.h omp_autotune.h dynamic.h simd-intrinsics.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h dynamic_compiler.h dynamic_types.h options.h list.h loader.h getopt.h memdbg.h os.h os-autoconf.h

ecryptfs_fmt_plug.o:	ecryptfs_fmt_plug.c arch.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h johnswap.h common.h memory.h stdbool.h misc.h jumbo.h autoconfig.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h base64_convert.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h common-get-hash.h

eigrp_fmt_plug.o:	eigrp_fmt_plug.c arch.h md5.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h escrypt/sha256.h memdbg.h os.h os-autoconf.h

electrum_fmt_plug.o:	electrum_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h aes.h aes/aes_func.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h johnswap.h stdbool.h secp256k1.h secp256k1/secp256k1.h secp256k1/secp256k1_ecdh.h pbkdf2_hmac_sha512.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h hmac_sha.h memdbg.h os.h os-autoconf.h

encfs_common_plug.o:	encfs_common_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h encfs_common.h aes.h aes/aes_func.h formats.h params.h omp_autotune.h hmac_sha.h memdbg.h os.h os-autoconf.h

encfs_fmt_plug.o:	encfs_fmt_plug.c arch.h options.h autoconfig.h list.h loader.h params.h formats.h misc.h jumbo.h omp_autotune.h getopt.h common.h memory.h johnswap.h encfs_common.h aes.h aes/aes_func.h pbkdf2_hmac_sha1.h sha.h aligned.h md4.h md5.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h

enpass_common_plug.o:	enpass_common_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h enpass_common.h formats.h params.h omp_autotune.h aes.h aes/aes_func.h memdbg.h os.h os-autoconf.h

enpass_fmt_plug.o:	enpass_fmt_plug.c aes.h autoconfig.h aes/aes_func.h arch.h misc.h jumbo.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h johnswap.h enpass_common.h pbkdf2_hmac_sha1.h sha.h aligned.h md4.h md5.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h

episerver_fmt_plug.o:	episerver_fmt_plug.c arch.h sha.h aligned.h md4.h md5.h sha2.h openssl_local_overrides.h jtr_sha2.h johnswap.h common.h memory.h stdbool.h misc.h jumbo.h autoconfig.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h base64_convert.h unicode.h memdbg.h os.h os-autoconf.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h

ethereum_common_plug.o:	ethereum_common_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h ethereum_common.h formats.h params.h omp_autotune.h

ethereum_fmt_plug.o:	ethereum_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h pbkdf2_hmac_sha256.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h johnswap.h stdbool.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h ethereum_common.h escrypt/crypto_scrypt.h KeccakHash.h KeccakSponge.h KeccakF-1600-interface.h aes.h aes/aes_func.h memdbg.h os.h os-autoconf.h

feal8_plug.o:	feal8_plug.c feal8.h common.h arch.h memory.h johnswap.h memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h

formspring_fmt_plug.o:	formspring_fmt_plug.c autoconfig.h common.h arch.h memory.h formats.h params.h misc.h jumbo.h omp_autotune.h dynamic.h simd-intrinsics.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h options.h list.h loader.h getopt.h memdbg.h os.h os-autoconf.h

fvde_common_plug.o:	fvde_common_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h fvde_common.h formats.h params.h omp_autotune.h hmac_sha.h johnswap.h memdbg.h os.h os-autoconf.h

fvde_fmt_plug.o:	fvde_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h johnswap.h aes.h aes/aes_func.h pbkdf2_hmac_sha256.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h stdbool.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h fvde_common.h memdbg.h os.h os-autoconf.h

geli_common_plug.o:	geli_common_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h geli_common.h formats.h params.h omp_autotune.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h johnswap.h stdbool.h aes.h aes/aes_func.h hmac_sha.h

geli_fmt_plug.o:	geli_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h hmac_sha.h aes.h aes/aes_func.h pbkdf2_hmac_sha512.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h johnswap.h stdbool.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h geli_common.h memdbg.h os.h os-autoconf.h

gost3411-2012-sse41_plug.o:	gost3411-2012-sse41_plug.c gost3411-tables.h gost3411-2012-sse41.h arch.h memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h memory.h

gost3411-tables_plug.o:	gost3411-tables_plug.c gost3411-tables.h gost3411-2012-sse41.h memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h arch.h memory.h

gost_fmt_plug.o:	gost_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h gost.h johnswap.h memdbg.h os.h os-autoconf.h common-get-hash.h

gpg_common_plug.o:	gpg_common_plug.c twofish.h idea-JtR.h sha2.h arch.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h johnswap.h common.h memory.h stdbool.h formats.h params.h misc.h jumbo.h autoconfig.h omp_autotune.h gpg_common.h dyna_salt.h loader.h list.h memdbg.h os.h os-autoconf.h

gpg_fmt_plug.o:	gpg_fmt_plug.c arch.h params.h common.h memory.h formats.h misc.h jumbo.h autoconfig.h omp_autotune.h twofish.h md5.h rc4.h pdfcrack_md5.h sha.h aligned.h md4.h sha2.h openssl_local_overrides.h jtr_sha2.h johnswap.h stdbool.h gpg_common.h dyna_salt.h memdbg.h os.h os-autoconf.h

has160_fmt_plug.o:	has160_fmt_plug.c arch.h params.h common.h memory.h formats.h misc.h jumbo.h autoconfig.h omp_autotune.h options.h list.h loader.h getopt.h has160.h memdbg.h os.h os-autoconf.h common-get-hash.h

has160_plug.o:	has160_plug.c gost.h arch.h johnswap.h common.h memory.h has160.h memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h

haval_fmt_plug.o:	haval_fmt_plug.c arch.h sph_haval.h sph_types.h autoconfig.h misc.h jumbo.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h memdbg.h os.h os-autoconf.h common-get-hash.h

hmacMD5_fmt_plug.o:	hmacMD5_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h md5.h aligned.h johnswap.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h base64_convert.h memdbg.h os.h os-autoconf.h

hmacSHA1_fmt_plug.o:	hmacSHA1_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h sha.h aligned.h md4.h md5.h johnswap.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h

hmacSHA256_fmt_plug.o:	hmacSHA256_fmt_plug.c arch.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h johnswap.h common.h memory.h stdbool.h misc.h jumbo.h autoconfig.h base64_convert.h formats.h params.h omp_autotune.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h

hmacSHA512_fmt_plug.o:	hmacSHA512_fmt_plug.c arch.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h johnswap.h common.h memory.h stdbool.h misc.h jumbo.h autoconfig.h base64_convert.h formats.h params.h omp_autotune.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h

hmac_sha_plug.o:	hmac_sha_plug.c arch.h aligned.h sha.h md4.h md5.h sha2.h openssl_local_overrides.h jtr_sha2.h johnswap.h common.h memory.h stdbool.h

hmailserver_fmt_plug.o:	hmailserver_fmt_plug.c autoconfig.h sha2.h arch.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h johnswap.h common.h memory.h stdbool.h params.h formats.h misc.h jumbo.h omp_autotune.h dynamic.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h

hsrp_fmt_plug.o:	hsrp_fmt_plug.c arch.h md5.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h johnswap.h options.h list.h loader.h getopt.h memdbg.h os.h os-autoconf.h

idea_plug.o:	idea_plug.c idea-JtR.h memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h arch.h memory.h

ike_fmt_plug.o:	ike_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h ike-crack.h md5.h memdbg.h os.h os-autoconf.h

itunes_common_plug.o:	itunes_common_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h itunes_common.h formats.h params.h omp_autotune.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h johnswap.h stdbool.h aes.h aes/aes_func.h memdbg.h os.h os-autoconf.h

itunes_fmt_plug.o:	itunes_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h johnswap.h pbkdf2_hmac_sha1.h sha.h aligned.h md4.h md5.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h pbkdf2_hmac_sha256.h sha2.h openssl_local_overrides.h jtr_sha2.h stdbool.h itunes_common.h memdbg.h os.h os-autoconf.h

iwork_common_plug.o:	iwork_common_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h iwork_common.h formats.h params.h omp_autotune.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h johnswap.h stdbool.h aes.h aes/aes_func.h hmac_sha.h memdbg.h os.h os-autoconf.h

iwork_fmt_plug.o:	iwork_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h johnswap.h iwork_common.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h stdbool.h aes.h aes/aes_func.h pbkdf2_hmac_sha1.h sha.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h

keepass_common_plug.o:	keepass_common_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h keepass_common.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h johnswap.h stdbool.h aes.h aes/aes_func.h twofish.h

keepass_fmt_plug.o:	keepass_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h keepass_common.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h johnswap.h stdbool.h aes.h aes/aes_func.h twofish.h chacha.h memdbg.h os.h os-autoconf.h

keychain_fmt_plug.o:	keychain_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h johnswap.h pbkdf2_hmac_sha1.h sha.h aligned.h md4.h md5.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h

keyring_fmt_plug.o:	keyring_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h md5.h sha2.h aligned.h openssl_local_overrides.h md4.h jtr_sha2.h johnswap.h stdbool.h aes.h aes/aes_func.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h

keystore_common_plug.o:	keystore_common_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h keystore_common.h loader.h list.h memdbg.h os.h os-autoconf.h

keystore_fmt_plug.o:	keystore_fmt_plug.c arch.h simd-intrinsics.h common.h memory.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h sha.h md4.h md5.h misc.h jumbo.h autoconfig.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h dyna_salt.h johnswap.h keystore_common.h memdbg.h os.h os-autoconf.h

known_hosts_fmt_plug.o:	known_hosts_fmt_plug.c arch.h sha.h aligned.h md4.h md5.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h base64_convert.h options.h list.h loader.h getopt.h memdbg.h os.h os-autoconf.h common-get-hash.h

krb5_asrep_common_plug.o:	krb5_asrep_common_plug.c formats.h params.h arch.h misc.h jumbo.h autoconfig.h omp_autotune.h common.h memory.h krb5_asrep_common.h dyna_salt.h memdbg.h os.h os-autoconf.h

krb5_asrep_fmt_plug.o:	krb5_asrep_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h formats.h params.h omp_autotune.h common.h memory.h md4.h hmacmd5.h aligned.h md5.h rc4.h hmac_sha.h pbkdf2_hmac_sha1.h sha.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h unicode.h options.h list.h loader.h getopt.h krb5_common.h aes.h aes/aes_func.h krb5_asrep_common.h dyna_salt.h memdbg.h os.h os-autoconf.h

krb5_common_plug.o:	krb5_common_plug.c krb5_common.h arch.h misc.h jumbo.h autoconfig.h aes.h aes/aes_func.h memdbg.h os.h os-autoconf.h memory.h

krb5_db_fmt_plug.o:	krb5_db_fmt_plug.c autoconfig.h arch.h misc.h jumbo.h common.h memory.h formats.h params.h omp_autotune.h johnswap.h options.h list.h loader.h getopt.h simd-intrinsics.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h pbkdf2_hmac_sha1.h sha.h md4.h md5.h aes.h aes/aes_func.h krb5_common.h memdbg.h os.h os-autoconf.h

krb5_tgs_fmt_plug.o:	krb5_tgs_fmt_plug.c misc.h jumbo.h arch.h autoconfig.h formats.h params.h omp_autotune.h common.h memory.h dyna_salt.h md4.h hmacmd5.h aligned.h md5.h rc4.h unicode.h options.h list.h loader.h getopt.h memdbg.h os.h os-autoconf.h

krb5pa-md5_fmt_plug.o:	krb5pa-md5_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h common.h memory.h unicode.h md5.h hmacmd5.h aligned.h md4.h rc4.h memdbg.h os.h os-autoconf.h common-get-hash.h

krb5pa-sha1_fmt_plug.o:	krb5pa-sha1_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h common.h memory.h unicode.h johnswap.h aes.h aes/aes_func.h hmac_sha.h pbkdf2_hmac_sha1.h sha.h aligned.h md4.h md5.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h krb5_common.h memdbg.h os.h os-autoconf.h common-get-hash.h

kwallet_fmt_plug.o:	kwallet_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h memory.h common.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h sha.h aligned.h md4.h md5.h pbkdf2_hmac_sha512.h sha2.h openssl_local_overrides.h jtr_sha2.h johnswap.h stdbool.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h

lastpass_cli_common_plug.o:	lastpass_cli_common_plug.c arch.h formats.h params.h misc.h jumbo.h autoconfig.h omp_autotune.h johnswap.h common.h memory.h options.h list.h loader.h getopt.h aes.h aes/aes_func.h lastpass_cli_common.h

lastpass_cli_fmt_plug.o:	lastpass_cli_fmt_plug.c arch.h johnswap.h common.h memory.h misc.h jumbo.h autoconfig.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h aes.h aes/aes_func.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h stdbool.h pbkdf2_hmac_sha256.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h lastpass_cli_common.h memdbg.h os.h os-autoconf.h

lastpass_common_plug.o:	lastpass_common_plug.c arch.h johnswap.h common.h memory.h params.h options.h autoconfig.h list.h loader.h formats.h misc.h jumbo.h omp_autotune.h getopt.h aes.h aes/aes_func.h lastpass_common.h

lastpass_fmt_plug.o:	lastpass_fmt_plug.c arch.h johnswap.h common.h memory.h misc.h jumbo.h autoconfig.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h aes.h aes/aes_func.h lastpass_common.h pbkdf2_hmac_sha256.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h stdbool.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h

lastpass_sniffed_fmt_plug.o:	lastpass_sniffed_fmt_plug.c arch.h johnswap.h common.h memory.h misc.h jumbo.h autoconfig.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h aes.h aes/aes_func.h base64_convert.h pbkdf2_hmac_sha256.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h stdbool.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h common-get-hash.h

leet_cc_fmt_plug.o:	leet_cc_fmt_plug.c arch.h openssl_local_overrides.h sph_whirlpool.h sph_types.h autoconfig.h sha2.h aligned.h md4.h md5.h jtr_sha2.h johnswap.h common.h memory.h stdbool.h misc.h jumbo.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h common-get-hash.h

libreoffice_common_plug.o:	libreoffice_common_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h libreoffice_common.h formats.h params.h omp_autotune.h johnswap.h sha.h aligned.h md4.h md5.h aes.h aes/aes_func.h pbkdf2_hmac_sha1.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h

libreoffice_fmt_plug.o:	libreoffice_fmt_plug.c arch.h johnswap.h common.h memory.h misc.h jumbo.h autoconfig.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h sha.h aligned.h md4.h md5.h sha2.h openssl_local_overrides.h jtr_sha2.h stdbool.h aes.h aes/aes_func.h libreoffice_common.h libreoffice_variable_code.h pbkdf2_hmac_sha1.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h

lotus5_fmt_plug.o:	lotus5_fmt_plug.c misc.h jumbo.h arch.h autoconfig.h formats.h params.h omp_autotune.h common.h memory.h memdbg.h os.h os-autoconf.h common-get-hash.h

lotus85_fmt_plug.o:	lotus85_fmt_plug.c sha.h aligned.h arch.h md4.h md5.h formats.h params.h misc.h jumbo.h autoconfig.h omp_autotune.h common.h memory.h memdbg.h os.h os-autoconf.h

luks_fmt_plug.o:	luks_fmt_plug.c autoconfig.h arch.h johnswap.h common.h memory.h misc.h jumbo.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h os.h os-autoconf.h aes.h aes/aes_func.h sha.h aligned.h md4.h md5.h sha2.h openssl_local_overrides.h jtr_sha2.h stdbool.h base64_convert.h pbkdf2_hmac_sha1.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h dyna_salt.h memdbg.h luks_insane_tests.h

md2_fmt_plug.o:	md2_fmt_plug.c arch.h sph_md2.h sph_types.h autoconfig.h misc.h jumbo.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h memdbg.h os.h os-autoconf.h common-get-hash.h

mdc2_fmt_plug.o:	mdc2_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h johnswap.h options.h list.h loader.h getopt.h mdc2-JtR.h memdbg.h os.h os-autoconf.h common-get-hash.h

mdc2dgst_plug.o:	mdc2dgst_plug.c mdc2-JtR.h memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h arch.h memory.h

mediawiki_fmt_plug.o:	mediawiki_fmt_plug.c autoconfig.h common.h arch.h memory.h formats.h params.h misc.h jumbo.h omp_autotune.h dynamic.h simd-intrinsics.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h options.h list.h loader.h getopt.h memdbg.h os.h os-autoconf.h

money_fmt_plug.o:	money_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h sha.h aligned.h md4.h md5.h rc4.h unicode.h memdbg.h os.h os-autoconf.h

mongodb_fmt_plug.o:	mongodb_fmt_plug.c md5.h arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h memdbg.h os.h os-autoconf.h common-get-hash.h

mongodb_scram_fmt_plug.o:	mongodb_scram_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h memory.h common.h formats.h params.h omp_autotune.h johnswap.h sha.h aligned.h md4.h md5.h base64_convert.h hmac_sha.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h pbkdf2_hmac_sha1.h memdbg.h os.h os-autoconf.h common-get-hash.h

mozilla_ng_fmt_plug.o:	mozilla_ng_fmt_plug.c arch.h md5.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h johnswap.h options.h list.h loader.h getopt.h sha.h aligned.h md4.h memdbg.h os.h os-autoconf.h common-get-hash.h

mscash1_fmt_plug.o:	mscash1_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h memory.h common.h formats.h params.h omp_autotune.h unicode.h options.h list.h loader.h getopt.h johnswap.h mscash_common.h memdbg.h os.h os-autoconf.h

mscash2_fmt_plug.o:	mscash2_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h memory.h common.h formats.h params.h omp_autotune.h unicode.h options.h list.h loader.h getopt.h sha.h aligned.h md4.h md5.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h mscash_common.h memdbg.h os.h os-autoconf.h

mscash_common_plug.o:	mscash_common_plug.c formats.h params.h arch.h misc.h jumbo.h autoconfig.h omp_autotune.h memory.h common.h base64_convert.h unicode.h options.h list.h loader.h getopt.h johnswap.h mscash_common.h memdbg.h os.h os-autoconf.h

mssql-old_fmt_plug.o:	mssql-old_fmt_plug.c arch.h simd-intrinsics.h common.h memory.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h misc.h jumbo.h autoconfig.h params.h formats.h omp_autotune.h options.h list.h loader.h getopt.h unicode.h sha.h md4.h md5.h johnswap.h memdbg.h os.h os-autoconf.h

mssql05_fmt_plug.o:	mssql05_fmt_plug.c arch.h simd-intrinsics.h common.h memory.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h misc.h jumbo.h autoconfig.h params.h formats.h omp_autotune.h options.h list.h loader.h getopt.h unicode.h sha.h md4.h md5.h johnswap.h memdbg.h os.h os-autoconf.h

mssql12_fmt_plug.o:	mssql12_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h params.h common.h memory.h formats.h omp_autotune.h options.h list.h loader.h getopt.h unicode.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h johnswap.h stdbool.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h common-get-hash.h

multibit_fmt_plug.o:	multibit_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h aes.h aes/aes_func.h md5.h escrypt/crypto_scrypt.h unicode.h memdbg.h os.h os-autoconf.h

mysqlSHA1_fmt_plug.o:	mysqlSHA1_fmt_plug.c arch.h simd-intrinsics.h common.h memory.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h misc.h jumbo.h autoconfig.h formats.h params.h omp_autotune.h sha.h md4.h md5.h johnswap.h memdbg.h os.h os-autoconf.h common-simd-getpos.h common-simd-setkey32.h common-get-hash.h

mysql_fmt_plug.o:	mysql_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h memdbg.h os.h os-autoconf.h common-get-hash.h

mysql_netauth_fmt_plug.o:	mysql_netauth_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h sha.h aligned.h md4.h md5.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h memdbg.h os.h os-autoconf.h common-get-hash.h

net_ah_fmt_plug.o:	net_ah_fmt_plug.c formats.h params.h arch.h misc.h jumbo.h autoconfig.h omp_autotune.h hmacmd5.h aligned.h md5.h common.h memory.h options.h list.h loader.h getopt.h memdbg.h os.h os-autoconf.h

net_md5_fmt_plug.o:	net_md5_fmt_plug.c autoconfig.h formats.h params.h arch.h misc.h jumbo.h omp_autotune.h dynamic.h simd-intrinsics.h common.h memory.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h md5.h options.h list.h loader.h getopt.h memdbg.h os.h os-autoconf.h

net_sha1_fmt_plug.o:	net_sha1_fmt_plug.c autoconfig.h formats.h params.h arch.h misc.h jumbo.h omp_autotune.h dynamic.h simd-intrinsics.h common.h memory.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h sha.h md4.h md5.h options.h list.h loader.h getopt.h memdbg.h os.h os-autoconf.h

notes_common_plug.o:	notes_common_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h notes_common.h formats.h params.h omp_autotune.h johnswap.h memdbg.h os.h os-autoconf.h

notes_fmt_plug.o:	notes_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h aes.h aes/aes_func.h johnswap.h notes_common.h pbkdf2_hmac_sha256.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h stdbool.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h

nsec3_fmt_plug.o:	nsec3_fmt_plug.c sha.h aligned.h arch.h md4.h md5.h params.h common.h memory.h formats.h misc.h jumbo.h autoconfig.h omp_autotune.h memdbg.h os.h os-autoconf.h

nt2_fmt_plug.o:	nt2_fmt_plug.c arch.h md4.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h unicode.h johnswap.h simd-intrinsics.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h

ntlmv1_mschapv2_fmt_plug.o:	ntlmv1_mschapv2_fmt_plug.c arch.h simd-intrinsics.h common.h memory.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h misc.h jumbo.h autoconfig.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h johnswap.h sha.h md4.h md5.h unicode.h john.h os.h os-autoconf.h memdbg.h

nukedclan_fmt_plug.o:	nukedclan_fmt_plug.c arch.h md5.h sha.h aligned.h md4.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h memdbg.h os.h os-autoconf.h common-get-hash.h

o10glogon_fmt_plug.o:	o10glogon_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h aes.h aes/aes_func.h md5.h unicode.h options.h list.h loader.h getopt.h base64_convert.h memdbg.h os.h os-autoconf.h

o3logon_fmt_plug.o:	o3logon_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h sha.h aligned.h md4.h md5.h unicode.h options.h list.h loader.h getopt.h base64_convert.h memdbg.h os.h os-autoconf.h

o5logon_fmt_plug.o:	o5logon_fmt_plug.c arch.h sha.h aligned.h md4.h md5.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h aes.h aes/aes_func.h memdbg.h os.h os-autoconf.h

office_common_plug.o:	office_common_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h office_common.h formats.h params.h omp_autotune.h memdbg.h os.h os-autoconf.h

office_fmt_plug.o:	office_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h unicode.h aes.h aes/aes_func.h sha.h aligned.h md4.h md5.h sha2.h openssl_local_overrides.h jtr_sha2.h johnswap.h stdbool.h office_common.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h

oldoffice_fmt_plug.o:	oldoffice_fmt_plug.c md5.h arch.h rc4.h sha.h aligned.h md4.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h unicode.h dyna_salt.h memdbg.h os.h os-autoconf.h

openbsdsoftraid_common_plug.o:	openbsdsoftraid_common_plug.c misc.h jumbo.h arch.h autoconfig.h common.h memory.h openbsdsoftraid_common.h formats.h params.h omp_autotune.h memdbg.h os.h os-autoconf.h

openbsdsoftraid_fmt_plug.o:	openbsdsoftraid_fmt_plug.c arch.h common.h memory.h formats.h params.h misc.h jumbo.h autoconfig.h omp_autotune.h loader.h list.h aes.h aes/aes_func.h sha.h aligned.h md4.h md5.h hmac_sha.h bcrypt_pbkdf.h pbkdf2_hmac_sha1.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h openbsdsoftraid_common.h openbsdsoftraid_variable_code.h memdbg.h os.h os-autoconf.h

opencl_7z_fmt_plug.o:	opencl_7z_fmt_plug.c arch.h formats.h params.h misc.h jumbo.h autoconfig.h omp_autotune.h common.h memory.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h options.h list.h loader.h getopt.h aes.h aes/aes_func.h crc32.h unicode.h dyna_salt.h lzma/LzmaDec.h lzma/7zTypes.h lzma/Lzma2Dec.h memdbg.h os.h os-autoconf.h opencl_autotune.h config.h logger.h mask_ext.h mask.h

../run/kernels/opencl_DES_hst_dev_shared.h:	opencl_DES_hst_dev_shared.h

opencl_DES_bs_b_plug.o:	opencl_DES_bs_b_plug.c options.h autoconfig.h list.h loader.h params.h arch.h formats.h misc.h jumbo.h omp_autotune.h getopt.h common.h memory.h opencl_DES_bs.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h ../run/kernels/opencl_DES_hst_dev_shared.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_DES_bs_f_plug.o:	opencl_DES_bs_f_plug.c options.h autoconfig.h list.h loader.h params.h arch.h formats.h misc.h jumbo.h omp_autotune.h getopt.h common.h memory.h opencl_DES_bs.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h ../run/kernels/opencl_DES_hst_dev_shared.h mask_ext.h mask.h john.h os.h os-autoconf.h memdbg.h

opencl_DES_bs_h_plug.o:	opencl_DES_bs_h_plug.c options.h autoconfig.h list.h loader.h params.h arch.h formats.h misc.h jumbo.h omp_autotune.h getopt.h common.h memory.h opencl_DES_bs.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h ../run/kernels/opencl_DES_hst_dev_shared.h mask_ext.h mask.h john.h os.h os-autoconf.h memdbg.h

opencl_DES_bs_plug.o:	opencl_DES_bs_plug.c arch.h common.h memory.h opencl_DES_bs.h common-opencl.h common-gpu.h gpu_sensors.h misc.h jumbo.h autoconfig.h formats.h params.h omp_autotune.h path.h opencl_device_info.h ../run/kernels/opencl_DES_hst_dev_shared.h loader.h list.h unicode.h options.h getopt.h bt_interface.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_DES_fmt_plug.o:	opencl_DES_fmt_plug.c arch.h common.h memory.h formats.h params.h misc.h jumbo.h autoconfig.h omp_autotune.h config.h opencl_DES_bs.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h ../run/kernels/opencl_DES_hst_dev_shared.h loader.h list.h memdbg.h os.h os-autoconf.h

opencl_agilekeychain_fmt_plug.o:	opencl_agilekeychain_fmt_plug.c arch.h formats.h params.h misc.h jumbo.h autoconfig.h omp_autotune.h common.h memory.h aes.h aes/aes_func.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h options.h list.h loader.h getopt.h opencl_autotune.h config.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_bf_fmt_plug.o:	opencl_bf_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h opencl_bf_std.h common.h memory.h common-opencl.h common-gpu.h gpu_sensors.h formats.h params.h omp_autotune.h path.h opencl_device_info.h BF_common.h config.h memdbg.h os.h os-autoconf.h

opencl_bf_std_plug.o:	opencl_bf_std_plug.c arch.h common.h memory.h options.h autoconfig.h list.h loader.h params.h formats.h misc.h jumbo.h omp_autotune.h getopt.h opencl_bf_std.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h BF_common.h memdbg.h os.h os-autoconf.h

opencl_bitlocker_fmt_plug.o:	opencl_bitlocker_fmt_plug.c misc.h jumbo.h arch.h autoconfig.h base64_convert.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h bitlocker_common.h bitlocker_variable_code.h opencl_autotune.h config.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_bitwarden_fmt_plug.o:	opencl_bitwarden_fmt_plug.c misc.h jumbo.h arch.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h bitwarden_common.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h opencl_pbkdf2_hmac_sha256.h opencl_autotune.h config.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_blockchain_fmt_plug.o:	opencl_blockchain_fmt_plug.c arch.h aes.h autoconfig.h aes/aes_func.h formats.h params.h misc.h jumbo.h omp_autotune.h common.h memory.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h options.h list.h loader.h getopt.h blockchain_common.h opencl_autotune.h config.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_dashlane_fmt_plug.o:	opencl_dashlane_fmt_plug.c arch.h formats.h params.h misc.h jumbo.h autoconfig.h omp_autotune.h common.h memory.h dashlane_common.h options.h list.h loader.h getopt.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h opencl_pbkdf2_hmac_sha1.h opencl_autotune.h config.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_dmg_fmt_plug.o:	opencl_dmg_fmt_plug.c os.h os-autoconf.h autoconfig.h jumbo.h arch.h aes.h aes/aes_func.h hmac_sha.h formats.h params.h misc.h omp_autotune.h common.h memory.h options.h list.h loader.h getopt.h dmg_common.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h opencl_pbkdf2_hmac_sha1.h opencl_autotune.h config.h logger.h mask_ext.h mask.h memdbg.h

opencl_electrum_modern_fmt_plug.o:	opencl_electrum_modern_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h johnswap.h secp256k1.h secp256k1/secp256k1.h secp256k1/secp256k1_ecdh.h aes.h aes/aes_func.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h stdbool.h hmac_sha.h pbkdf2_hmac_common.h opencl_autotune.h config.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_encfs_fmt_plug.o:	opencl_encfs_fmt_plug.c common-opencl.h common-gpu.h gpu_sensors.h arch.h misc.h jumbo.h autoconfig.h memory.h common.h formats.h params.h omp_autotune.h path.h opencl_device_info.h encfs_common.h aes.h aes/aes_func.h options.h list.h loader.h getopt.h opencl_pbkdf2_hmac_sha1.h opencl_autotune.h config.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_enpass_fmt_plug.o:	opencl_enpass_fmt_plug.c aes.h autoconfig.h aes/aes_func.h arch.h formats.h params.h misc.h jumbo.h omp_autotune.h common.h memory.h enpass_common.h options.h list.h loader.h getopt.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h opencl_pbkdf2_hmac_sha1.h opencl_autotune.h config.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_ethereum_fmt_plug.o:	opencl_ethereum_fmt_plug.c misc.h jumbo.h arch.h autoconfig.h ethereum_common.h formats.h params.h omp_autotune.h common.h memory.h options.h list.h loader.h getopt.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h KeccakHash.h KeccakSponge.h KeccakF-1600-interface.h opencl_pbkdf2_hmac_sha256.h opencl_autotune.h config.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_ethereum_presale_fmt_plug.o:	opencl_ethereum_presale_fmt_plug.c misc.h jumbo.h arch.h autoconfig.h ethereum_common.h formats.h params.h omp_autotune.h common.h memory.h options.h list.h loader.h getopt.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h opencl_autotune.h config.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_fvde_fmt_plug.o:	opencl_fvde_fmt_plug.c misc.h jumbo.h arch.h autoconfig.h fvde_common.h formats.h params.h omp_autotune.h common.h memory.h options.h list.h loader.h getopt.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h opencl_pbkdf2_hmac_sha256.h opencl_autotune.h config.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_geli_fmt_plug.o:	opencl_geli_fmt_plug.c misc.h jumbo.h arch.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h johnswap.h stdbool.h geli_common.h aes.h aes/aes_func.h hmac_sha.h pbkdf2_hmac_common.h opencl_autotune.h config.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_gpg_fmt_plug.o:	opencl_gpg_fmt_plug.c arch.h params.h common.h memory.h formats.h misc.h jumbo.h autoconfig.h omp_autotune.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h options.h list.h loader.h getopt.h gpg_common.h dyna_salt.h twofish.h opencl_autotune.h config.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_hash_check_128_plug.o:	opencl_hash_check_128_plug.c options.h autoconfig.h list.h loader.h params.h arch.h formats.h misc.h jumbo.h omp_autotune.h getopt.h common.h memory.h opencl_hash_check_128.h bt_interface.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_iwork_fmt_plug.o:	opencl_iwork_fmt_plug.c arch.h formats.h params.h misc.h jumbo.h autoconfig.h omp_autotune.h common.h memory.h iwork_common.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h johnswap.h stdbool.h aes.h aes/aes_func.h options.h list.h loader.h getopt.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h opencl_pbkdf2_hmac_sha1.h opencl_autotune.h config.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_keychain_fmt_plug.o:	opencl_keychain_fmt_plug.c arch.h formats.h params.h misc.h jumbo.h autoconfig.h omp_autotune.h common.h memory.h options.h list.h loader.h getopt.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h opencl_autotune.h config.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_keyring_fmt_plug.o:	opencl_keyring_fmt_plug.c arch.h formats.h params.h misc.h jumbo.h autoconfig.h omp_autotune.h common.h memory.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h options.h list.h loader.h getopt.h aes.h aes/aes_func.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h johnswap.h stdbool.h opencl_autotune.h config.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_keystore_fmt_plug.o:	opencl_keystore_fmt_plug.c arch.h sha.h aligned.h md4.h md5.h misc.h jumbo.h autoconfig.h common-opencl.h common-gpu.h gpu_sensors.h memory.h common.h formats.h params.h omp_autotune.h path.h opencl_device_info.h options.h list.h loader.h getopt.h keystore_common.h memdbg.h os.h os-autoconf.h opencl_autotune.h config.h logger.h mask_ext.h mask.h

opencl_krb5_asrep_aes_fmt_plug.o:	opencl_krb5_asrep_aes_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h common.h memory.h unicode.h config.h aes.h aes/aes_func.h krb5_common.h krb5_asrep_common.h dyna_salt.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h opencl_pbkdf2_hmac_sha1.h hmac_sha.h memdbg.h os.h os-autoconf.h opencl_autotune.h logger.h mask_ext.h mask.h

opencl_krb5pa-md5_fmt_plug.o:	opencl_krb5pa-md5_fmt_plug.c misc.h jumbo.h arch.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h config.h unicode.h md5.h hmacmd5.h aligned.h md4.h rc4.h mask_ext.h mask.h bt_interface.h opencl_autotune.h logger.h memdbg.h os.h os-autoconf.h

opencl_krb5pa-sha1_fmt_plug.o:	opencl_krb5pa-sha1_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h common.h memory.h unicode.h config.h aes.h aes/aes_func.h krb5_common.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h opencl_pbkdf2_hmac_sha1.h hmac_sha.h opencl_autotune.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_lastpass_cli_fmt_plug.o:	opencl_lastpass_cli_fmt_plug.c misc.h jumbo.h arch.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h aes.h aes/aes_func.h lastpass_cli_common.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h opencl_pbkdf2_hmac_sha256.h opencl_autotune.h config.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_lastpass_fmt_plug.o:	opencl_lastpass_fmt_plug.c misc.h jumbo.h arch.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h aes.h aes/aes_func.h lastpass_common.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h opencl_pbkdf2_hmac_sha256.h opencl_autotune.h config.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_libreoffice_aes_fmt_plug.o:	opencl_libreoffice_aes_fmt_plug.c arch.h formats.h params.h misc.h jumbo.h autoconfig.h omp_autotune.h common.h memory.h options.h list.h loader.h getopt.h aes.h aes/aes_func.h libreoffice_common.h libreoffice_variable_code.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h opencl_autotune.h config.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_libreoffice_fmt_plug.o:	opencl_libreoffice_fmt_plug.c arch.h sha.h aligned.h md4.h md5.h aes.h autoconfig.h aes/aes_func.h formats.h params.h misc.h jumbo.h omp_autotune.h common.h memory.h options.h list.h loader.h getopt.h libreoffice_common.h libreoffice_variable_code.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h opencl_autotune.h config.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

../run/kernels/opencl_lm_hst_dev_shared.h:	opencl_lm_hst_dev_shared.h

opencl_lm_b_plug.o:	opencl_lm_b_plug.c opencl_lm.h arch.h common-opencl.h common-gpu.h gpu_sensors.h misc.h jumbo.h autoconfig.h memory.h common.h formats.h params.h omp_autotune.h path.h opencl_device_info.h ../run/kernels/opencl_lm_hst_dev_shared.h loader.h list.h options.h getopt.h bt_interface.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_lm_fmt_plug.o:	opencl_lm_fmt_plug.c opencl_lm.h arch.h common-opencl.h common-gpu.h gpu_sensors.h misc.h jumbo.h autoconfig.h memory.h common.h formats.h params.h omp_autotune.h path.h opencl_device_info.h ../run/kernels/opencl_lm_hst_dev_shared.h loader.h list.h config.h memdbg.h os.h os-autoconf.h

opencl_lm_plug.o:	opencl_lm_plug.c opencl_lm.h arch.h common-opencl.h common-gpu.h gpu_sensors.h misc.h jumbo.h autoconfig.h memory.h common.h formats.h params.h omp_autotune.h path.h opencl_device_info.h ../run/kernels/opencl_lm_hst_dev_shared.h loader.h list.h unicode.h options.h getopt.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_lotus5_fmt_plug.o:	opencl_lotus5_fmt_plug.c misc.h jumbo.h arch.h autoconfig.h formats.h params.h omp_autotune.h common.h memory.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h opencl_lotus5_fmt.h options.h list.h loader.h getopt.h opencl_autotune.h config.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_md5crypt_fmt_plug.o:	opencl_md5crypt_fmt_plug.c arch.h formats.h params.h misc.h jumbo.h autoconfig.h omp_autotune.h common.h memory.h path.h config.h common-opencl.h common-gpu.h gpu_sensors.h opencl_device_info.h options.h list.h loader.h getopt.h md5crypt_common.h opencl_autotune.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_mscash2_fmt_plug.o:	opencl_mscash2_fmt_plug.c formats.h params.h arch.h misc.h jumbo.h autoconfig.h omp_autotune.h common.h memory.h md4.h sha.h aligned.h md5.h unicode.h options.h list.h loader.h getopt.h opencl_mscash2_helper_plug.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h config.h mscash_common.h memdbg.h os.h os-autoconf.h

opencl_mscash2_helper_plug.o:	opencl_mscash2_helper_plug.c opencl_mscash2_helper_plug.h common-opencl.h common-gpu.h gpu_sensors.h arch.h misc.h jumbo.h autoconfig.h memory.h common.h formats.h params.h omp_autotune.h path.h opencl_device_info.h options.h list.h loader.h getopt.h memdbg.h os.h os-autoconf.h

opencl_mscash_fmt_plug.o:	opencl_mscash_fmt_plug.c arch.h params.h path.h common.h memory.h formats.h misc.h jumbo.h autoconfig.h omp_autotune.h common-opencl.h common-gpu.h gpu_sensors.h opencl_device_info.h config.h options.h list.h loader.h getopt.h unicode.h mask_ext.h mask.h bt_interface.h mscash_common.h opencl_autotune.h logger.h memdbg.h os.h os-autoconf.h

opencl_mysqlsha1_fmt_plug.o:	opencl_mysqlsha1_fmt_plug.c arch.h params.h path.h common.h memory.h formats.h misc.h jumbo.h autoconfig.h omp_autotune.h common-opencl.h common-gpu.h gpu_sensors.h opencl_device_info.h config.h options.h list.h loader.h getopt.h base64_convert.h mask_ext.h mask.h bt_interface.h memdbg.h os.h os-autoconf.h

opencl_notes_fmt_plug.o:	opencl_notes_fmt_plug.c misc.h jumbo.h arch.h autoconfig.h notes_common.h formats.h params.h omp_autotune.h common.h memory.h options.h list.h loader.h getopt.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h opencl_pbkdf2_hmac_sha256.h opencl_autotune.h config.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_nt_fmt_plug.o:	opencl_nt_fmt_plug.c arch.h params.h path.h common.h memory.h formats.h misc.h jumbo.h autoconfig.h omp_autotune.h config.h options.h list.h loader.h getopt.h unicode.h mask_ext.h mask.h opencl_hash_check_128.h bt_interface.h common-opencl.h common-gpu.h gpu_sensors.h opencl_device_info.h opencl_autotune.h logger.h memdbg.h os.h os-autoconf.h

opencl_ntlmv2_fmt_plug.o:	opencl_ntlmv2_fmt_plug.c arch.h params.h path.h common.h memory.h formats.h misc.h jumbo.h autoconfig.h omp_autotune.h common-opencl.h common-gpu.h gpu_sensors.h opencl_device_info.h config.h options.h list.h loader.h getopt.h unicode.h mask_ext.h mask.h bt_interface.h opencl_autotune.h logger.h memdbg.h os.h os-autoconf.h

opencl_o5logon_fmt_plug.o:	opencl_o5logon_fmt_plug.c arch.h sha.h aligned.h md4.h md5.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h opencl_autotune.h config.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_office_fmt_plug.o:	opencl_office_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h unicode.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h office_common.h config.h opencl_autotune.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_oldoffice_fmt_plug.o:	opencl_oldoffice_fmt_plug.c common-opencl.h common-gpu.h gpu_sensors.h arch.h misc.h jumbo.h autoconfig.h memory.h common.h formats.h params.h omp_autotune.h path.h opencl_device_info.h options.h list.h loader.h getopt.h unicode.h dyna_salt.h mask_ext.h mask.h opencl_autotune.h config.h logger.h memdbg.h os.h os-autoconf.h

opencl_openbsdsoftraid_fmt_plug.o:	opencl_openbsdsoftraid_fmt_plug.c arch.h formats.h params.h misc.h jumbo.h autoconfig.h omp_autotune.h common.h memory.h options.h list.h loader.h getopt.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h aes.h aes/aes_func.h sha.h aligned.h md4.h md5.h hmac_sha.h opencl_pbkdf2_hmac_sha1.h openbsdsoftraid_common.h openbsdsoftraid_variable_code.h opencl_autotune.h config.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_pbkdf2_hmac_md4_fmt_plug.o:	opencl_pbkdf2_hmac_md4_fmt_plug.c common-opencl.h common-gpu.h gpu_sensors.h arch.h misc.h jumbo.h autoconfig.h memory.h common.h formats.h params.h omp_autotune.h path.h opencl_device_info.h base64_convert.h options.h list.h loader.h getopt.h opencl_pbkdf2_hmac_md4.h pbkdf2_hmac_common.h opencl_autotune.h config.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_pbkdf2_hmac_md5_fmt_plug.o:	opencl_pbkdf2_hmac_md5_fmt_plug.c common-opencl.h common-gpu.h gpu_sensors.h arch.h misc.h jumbo.h autoconfig.h memory.h common.h formats.h params.h omp_autotune.h path.h opencl_device_info.h base64_convert.h options.h list.h loader.h getopt.h opencl_pbkdf2_hmac_md5.h pbkdf2_hmac_common.h opencl_autotune.h config.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_pbkdf2_hmac_sha1_fmt_plug.o:	opencl_pbkdf2_hmac_sha1_fmt_plug.c common-opencl.h common-gpu.h gpu_sensors.h arch.h misc.h jumbo.h autoconfig.h memory.h common.h formats.h params.h omp_autotune.h path.h opencl_device_info.h johnswap.h base64_convert.h options.h list.h loader.h getopt.h opencl_pbkdf2_hmac_sha1.h pbkdf2_hmac_common.h opencl_autotune.h config.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_pbkdf2_hmac_sha256_fmt_plug.o:	opencl_pbkdf2_hmac_sha256_fmt_plug.c misc.h jumbo.h arch.h autoconfig.h base64_convert.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h pbkdf2_hmac_common.h opencl_pbkdf2_hmac_sha256.h opencl_autotune.h config.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_pbkdf2_hmac_sha512_fmt_plug.o:	opencl_pbkdf2_hmac_sha512_fmt_plug.c misc.h jumbo.h arch.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h johnswap.h pbkdf2_hmac_common.h opencl_autotune.h config.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_pem_fmt_plug.o:	opencl_pem_fmt_plug.c arch.h formats.h params.h misc.h jumbo.h autoconfig.h omp_autotune.h common.h memory.h pem_common.h asn1.h memdbg.h os.h os-autoconf.h options.h list.h loader.h getopt.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h opencl_pbkdf2_hmac_sha1.h opencl_autotune.h config.h logger.h mask_ext.h mask.h

opencl_pfx_fmt_plug.o:	opencl_pfx_fmt_plug.c misc.h jumbo.h arch.h autoconfig.h params.h common.h memory.h formats.h omp_autotune.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h options.h list.h loader.h getopt.h hmac_sha.h pfx_common.h opencl_autotune.h config.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_pgpdisk_fmt_plug.o:	opencl_pgpdisk_fmt_plug.c arch.h params.h common.h memory.h formats.h misc.h jumbo.h autoconfig.h omp_autotune.h aes.h aes/aes_func.h twofish.h sha.h aligned.h md4.h md5.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h options.h list.h loader.h getopt.h pgpdisk_common.h opencl_autotune.h config.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_pgpsda_fmt_plug.o:	opencl_pgpsda_fmt_plug.c arch.h params.h common.h memory.h formats.h misc.h jumbo.h autoconfig.h omp_autotune.h sha.h aligned.h md4.h md5.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h options.h list.h loader.h getopt.h pgpsda_common.h opencl_autotune.h config.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_pgpwde_fmt_plug.o:	opencl_pgpwde_fmt_plug.c arch.h params.h common.h memory.h formats.h misc.h jumbo.h autoconfig.h omp_autotune.h aes.h aes/aes_func.h sha.h aligned.h md4.h md5.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h options.h list.h loader.h getopt.h pgpwde_common.h opencl_autotune.h config.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_phpass_fmt_plug.o:	opencl_phpass_fmt_plug.c arch.h formats.h params.h misc.h jumbo.h autoconfig.h omp_autotune.h common.h memory.h options.h list.h loader.h getopt.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h phpass_common.h opencl_autotune.h config.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_pwsafe_fmt_plug.o:	opencl_pwsafe_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h opencl_autotune.h config.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_rakp_fmt_plug.o:	opencl_rakp_fmt_plug.c path.h arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h sha.h aligned.h md4.h md5.h johnswap.h common-opencl.h common-gpu.h gpu_sensors.h opencl_device_info.h options.h list.h loader.h getopt.h opencl_autotune.h config.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_rar5_fmt_plug.o:	opencl_rar5_fmt_plug.c misc.h jumbo.h arch.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h rar5_common.h memdbg.h os.h os-autoconf.h opencl_pbkdf2_hmac_sha256.h opencl_autotune.h config.h logger.h mask_ext.h mask.h

opencl_rar_fmt_plug.o:	opencl_rar_fmt_plug.c autoconfig.h win32_memmap.h os.h os-autoconf.h jumbo.h arch.h mmap-windows.c memdbg.h memory.h sha.h aligned.h md4.h md5.h crc32.h misc.h common.h formats.h params.h omp_autotune.h dyna_salt.h options.h list.h loader.h getopt.h unicode.h johnswap.h unrar.h aes.h aes/aes_func.h unrarhlp.h unrarppm.h unrarvm.h unrarcmd.h unrarfilter.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h config.h opencl_autotune.h logger.h mask_ext.h mask.h rar_common.c

opencl_rawmd4_fmt_plug.o:	opencl_rawmd4_fmt_plug.c arch.h params.h path.h common.h memory.h formats.h misc.h jumbo.h autoconfig.h omp_autotune.h config.h options.h list.h loader.h getopt.h mask_ext.h mask.h opencl_hash_check_128.h bt_interface.h common-opencl.h common-gpu.h gpu_sensors.h opencl_device_info.h memdbg.h os.h os-autoconf.h

opencl_rawmd5_fmt_plug.o:	opencl_rawmd5_fmt_plug.c arch.h params.h path.h common.h memory.h formats.h misc.h jumbo.h autoconfig.h omp_autotune.h base64_convert.h config.h options.h list.h loader.h getopt.h mask_ext.h mask.h opencl_hash_check_128.h bt_interface.h common-opencl.h common-gpu.h gpu_sensors.h opencl_device_info.h memdbg.h os.h os-autoconf.h

opencl_rawsha1_fmt_plug.o:	opencl_rawsha1_fmt_plug.c arch.h params.h path.h common.h memory.h formats.h misc.h jumbo.h autoconfig.h omp_autotune.h common-opencl.h common-gpu.h gpu_sensors.h opencl_device_info.h config.h options.h list.h loader.h getopt.h base64_convert.h rawSHA1_common.h mask_ext.h mask.h bt_interface.h memdbg.h os.h os-autoconf.h

../run/kernels/opencl_device_info.h:	opencl_device_info.h

../run/kernels/opencl_misc.h:	opencl_misc.h ../run/kernels/opencl_device_info.h

../run/kernels/opencl_sha2_common.h:	opencl_sha2_common.h ../run/kernels/opencl_misc.h

../run/kernels/opencl_sha256.h:	opencl_sha256.h ../run/kernels/opencl_sha2_common.h

opencl_rawsha256_fmt_plug.o:	opencl_rawsha256_fmt_plug.c sha.h aligned.h arch.h md4.h md5.h sha2.h openssl_local_overrides.h jtr_sha2.h johnswap.h common.h memory.h stdbool.h common-opencl.h common-gpu.h gpu_sensors.h misc.h jumbo.h autoconfig.h formats.h params.h omp_autotune.h path.h opencl_device_info.h config.h options.h list.h loader.h getopt.h opencl_rawsha256.h ../run/kernels/opencl_sha256.h rawSHA256_common.h mask_ext.h mask.h opencl_mask_extras.h opencl_autotune.h logger.h memdbg.h os.h os-autoconf.h

opencl_rawsha512_fmt_plug.o:	opencl_rawsha512_fmt_plug.c arch.h common-opencl.h common-gpu.h gpu_sensors.h misc.h jumbo.h autoconfig.h memory.h common.h formats.h params.h omp_autotune.h path.h opencl_device_info.h options.h list.h loader.h getopt.h johnswap.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h stdbool.h rawSHA512_common.h opencl_autotune.h config.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

../run/kernels/opencl_sha512.h:	opencl_sha512.h ../run/kernels/opencl_sha2_common.h

opencl_rawsha512_gpl_fmt_plug.o:	opencl_rawsha512_gpl_fmt_plug.c sha.h aligned.h arch.h md4.h md5.h sha2.h openssl_local_overrides.h jtr_sha2.h johnswap.h common.h memory.h stdbool.h common-opencl.h common-gpu.h gpu_sensors.h misc.h jumbo.h autoconfig.h formats.h params.h omp_autotune.h path.h opencl_device_info.h config.h options.h list.h loader.h getopt.h opencl_rawsha512.h ../run/kernels/opencl_sha512.h rawSHA512_common.h mask_ext.h mask.h opencl_mask_extras.h opencl_autotune.h logger.h memdbg.h os.h os-autoconf.h

opencl_salted_sha_fmt_plug.o:	opencl_salted_sha_fmt_plug.c arch.h params.h path.h common.h memory.h formats.h misc.h jumbo.h autoconfig.h omp_autotune.h common-opencl.h common-gpu.h gpu_sensors.h opencl_device_info.h config.h options.h list.h loader.h getopt.h salted_sha1_common.h mask_ext.h mask.h base64_convert.h bt_interface.h memdbg.h os.h os-autoconf.h

opencl_sha1crypt_fmt_plug.o:	opencl_sha1crypt_fmt_plug.c arch.h sha.h aligned.h md4.h md5.h params.h common.h memory.h formats.h misc.h jumbo.h autoconfig.h omp_autotune.h options.h list.h loader.h getopt.h base64_convert.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h sha1crypt_common.h opencl_pbkdf1_hmac_sha1.h opencl_autotune.h config.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_sha256crypt_fmt_plug.o:	opencl_sha256crypt_fmt_plug.c common-opencl.h common-gpu.h gpu_sensors.h arch.h misc.h jumbo.h autoconfig.h memory.h common.h formats.h params.h omp_autotune.h path.h opencl_device_info.h config.h options.h list.h loader.h getopt.h opencl_sha256crypt.h ../run/kernels/opencl_sha256.h sha256crypt_common.h opencl_autotune.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_sha2_common_plug.o:	opencl_sha2_common_plug.c memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h arch.h memory.h

opencl_sha512crypt_fmt_plug.o:	opencl_sha512crypt_fmt_plug.c common-opencl.h common-gpu.h gpu_sensors.h arch.h misc.h jumbo.h autoconfig.h memory.h common.h formats.h params.h omp_autotune.h path.h opencl_device_info.h config.h options.h list.h loader.h getopt.h opencl_sha512crypt.h ../run/kernels/opencl_sha512.h sha512crypt_common.h opencl_autotune.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_sl3_fmt_plug.o:	opencl_sl3_fmt_plug.c arch.h params.h path.h common.h memory.h formats.h misc.h jumbo.h autoconfig.h omp_autotune.h common-opencl.h common-gpu.h gpu_sensors.h opencl_device_info.h config.h options.h list.h loader.h getopt.h mask_ext.h mask.h base64_convert.h sl3_common.h bt_interface.h memdbg.h os.h os-autoconf.h

opencl_sspr_fmt_plug.o:	opencl_sspr_fmt_plug.c arch.h params.h common.h memory.h formats.h misc.h jumbo.h autoconfig.h omp_autotune.h options.h list.h loader.h getopt.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h sspr_common.h sspr_variable_code.h opencl_autotune.h config.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_strip_fmt_plug.o:	opencl_strip_fmt_plug.c arch.h aes.h autoconfig.h aes/aes_func.h formats.h params.h misc.h jumbo.h omp_autotune.h options.h list.h loader.h getopt.h common.h memory.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h opencl_autotune.h config.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_tc_fmt_plug.o:	opencl_tc_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h memory.h common.h options.h list.h loader.h params.h formats.h omp_autotune.h getopt.h crc32.h johnswap.h aes.h aes/aes_func.h pbkdf2_hmac_ripemd160.h sph_ripemd.h sph_types.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h opencl_autotune.h config.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_wpapmk_fmt_plug.o:	opencl_wpapmk_fmt_plug.c arch.h formats.h params.h misc.h jumbo.h autoconfig.h omp_autotune.h common.h memory.h config.h options.h list.h loader.h getopt.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h wpapmk.h johnswap.h hmacmd5.h aligned.h md5.h hmac_sha.h sha2.h openssl_local_overrides.h md4.h jtr_sha2.h stdbool.h base64_convert.h hccap.h opencl_autotune.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_wpapsk_fmt_plug.o:	opencl_wpapsk_fmt_plug.c arch.h formats.h params.h misc.h jumbo.h autoconfig.h omp_autotune.h common.h memory.h config.h options.h list.h loader.h getopt.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h wpapsk.h johnswap.h hmacmd5.h aligned.h md5.h hmac_sha.h sha2.h openssl_local_overrides.h md4.h jtr_sha2.h stdbool.h hccap.h opencl_autotune.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_xsha512_fmt_plug.o:	opencl_xsha512_fmt_plug.c arch.h common-opencl.h common-gpu.h gpu_sensors.h misc.h jumbo.h autoconfig.h memory.h common.h formats.h params.h omp_autotune.h path.h opencl_device_info.h options.h list.h loader.h getopt.h johnswap.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h stdbool.h rawSHA512_common.h opencl_autotune.h config.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

opencl_zip_fmt_plug.o:	opencl_zip_fmt_plug.c arch.h formats.h params.h misc.h jumbo.h autoconfig.h omp_autotune.h common.h memory.h common-opencl.h common-gpu.h gpu_sensors.h path.h opencl_device_info.h pkzip.h dyna_salt.h crc32.h hmac_sha.h options.h list.h loader.h getopt.h pbkdf2_hmac_sha1.h sha.h aligned.h md4.h md5.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h opencl_autotune.h config.h logger.h mask_ext.h mask.h memdbg.h os.h os-autoconf.h

openssl_code_plug.o:	openssl_code_plug.c md5.h arch.h sha.h aligned.h md4.h openssl_code.h

openssl_enc_fmt_plug.o:	openssl_enc_fmt_plug.c autoconfig.h aes.h aes/aes_func.h md5.h arch.h sha.h aligned.h md4.h openssl_code.h misc.h jumbo.h params.h common.h memory.h formats.h omp_autotune.h memdbg.h os.h os-autoconf.h

oracle11_fmt_plug.o:	oracle11_fmt_plug.c arch.h simd-intrinsics.h common.h memory.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h misc.h jumbo.h autoconfig.h formats.h params.h omp_autotune.h sha.h md4.h md5.h johnswap.h memdbg.h os.h os-autoconf.h common-simd-getpos.h common-simd-setkey32.h common-get-hash.h

oracle12c_fmt_plug.o:	oracle12c_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h memory.h common.h formats.h params.h omp_autotune.h johnswap.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h stdbool.h pbkdf2_hmac_sha512.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h common-get-hash.h

oracle_fmt_plug.o:	oracle_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h unicode.h options.h list.h loader.h getopt.h memdbg.h os.h os-autoconf.h common-get-hash.h

osc_fmt_plug.o:	osc_fmt_plug.c autoconfig.h common.h arch.h memory.h formats.h params.h misc.h jumbo.h omp_autotune.h dynamic.h simd-intrinsics.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h options.h list.h loader.h getopt.h memdbg.h os.h os-autoconf.h

ospf_fmt_plug.o:	ospf_fmt_plug.c formats.h params.h arch.h misc.h jumbo.h autoconfig.h omp_autotune.h sha.h aligned.h md4.h md5.h sha2.h openssl_local_overrides.h jtr_sha2.h johnswap.h common.h memory.h stdbool.h hmac_sha.h options.h list.h loader.h getopt.h memdbg.h os.h os-autoconf.h

padlock_fmt_plug.o:	padlock_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h memory.h common.h formats.h params.h omp_autotune.h johnswap.h sha.h aligned.h md4.h md5.h loader.h list.h aes.h aes/aes_func.h aes_ccm.h pbkdf2_hmac_sha256.h sha2.h openssl_local_overrides.h jtr_sha2.h stdbool.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h

palshop_fmt_plug.o:	palshop_fmt_plug.c arch.h sha.h aligned.h md4.h md5.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h base64_convert.h memdbg.h os.h os-autoconf.h common-get-hash.h

panama_fmt_plug.o:	panama_fmt_plug.c arch.h sph_panama.h sph_types.h autoconfig.h misc.h jumbo.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h memdbg.h os.h os-autoconf.h common-get-hash.h

pbkdf2-hmac-md4_fmt_plug.o:	pbkdf2-hmac-md4_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h pbkdf2_hmac_md4.h md4.h simd-intrinsics.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h pbkdf2_hmac_common.h memdbg.h os.h os-autoconf.h common-get-hash.h

pbkdf2-hmac-md5_fmt_plug.o:	pbkdf2-hmac-md5_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h pbkdf2_hmac_md5.h md5.h simd-intrinsics.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h pbkdf2_hmac_common.h memdbg.h os.h os-autoconf.h common-get-hash.h

pbkdf2-hmac-sha1_fmt_plug.o:	pbkdf2-hmac-sha1_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h johnswap.h base64_convert.h pbkdf2_hmac_sha1.h sha.h aligned.h md4.h md5.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h pbkdf2_hmac_common.h memdbg.h os.h os-autoconf.h common-get-hash.h

pbkdf2-hmac-sha512_fmt_plug.o:	pbkdf2-hmac-sha512_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h johnswap.h stdbool.h pbkdf2_hmac_common.h pbkdf2_hmac_sha512.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h common-get-hash.h

pbkdf2_hmac_common_plug.o:	pbkdf2_hmac_common_plug.c formats.h params.h arch.h misc.h jumbo.h autoconfig.h omp_autotune.h memory.h common.h base64_convert.h pbkdf2_hmac_common.h pbkdf2_hmac_md4.h md4.h simd-intrinsics.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h pbkdf2_hmac_md5.h md5.h pbkdf2_hmac_sha1.h sha.h pbkdf2_hmac_sha512.h sha2.h openssl_local_overrides.h jtr_sha2.h johnswap.h stdbool.h memdbg.h os.h os-autoconf.h

pbkdf2_hmac_sha256_fmt_plug.o:	pbkdf2_hmac_sha256_fmt_plug.c misc.h jumbo.h arch.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h base64_convert.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h johnswap.h stdbool.h pbkdf2_hmac_sha256.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h pbkdf2_hmac_common.h memdbg.h os.h os-autoconf.h common-get-hash.h

pdf_fmt_plug.o:	pdf_fmt_plug.c arch.h params.h common.h memory.h formats.h misc.h jumbo.h autoconfig.h omp_autotune.h md5.h aes.h aes/aes_func.h sha2.h aligned.h openssl_local_overrides.h md4.h jtr_sha2.h johnswap.h stdbool.h rc4.h pdfcrack_md5.h loader.h list.h memdbg.h os.h os-autoconf.h

pdfcrack_md5_plug.o:	pdfcrack_md5_plug.c pdfcrack_md5.h memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h arch.h memory.h

pem_common_plug.o:	pem_common_plug.c arch.h pem_common.h common.h memory.h formats.h params.h misc.h jumbo.h autoconfig.h omp_autotune.h asn1.h memdbg.h os.h os-autoconf.h

pem_fmt_plug.o:	pem_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h pem_common.h asn1.h memdbg.h os.h os-autoconf.h pbkdf2_hmac_sha1.h sha.h aligned.h md4.h md5.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h

pfx_common_plug.o:	pfx_common_plug.c pfx_common.h formats.h params.h arch.h misc.h jumbo.h autoconfig.h omp_autotune.h memory.h common.h loader.h list.h

pfx_fmt_plug.o:	pfx_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h memory.h common.h formats.h params.h omp_autotune.h johnswap.h hmac_sha.h twofish.h sha.h aligned.h md4.h md5.h loader.h list.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h pkcs12.h pfx_common.h memdbg.h os.h os-autoconf.h

pgpdisk_common_plug.o:	pgpdisk_common_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h pgpdisk_common.h formats.h params.h omp_autotune.h sha.h aligned.h md4.h md5.h aes.h aes/aes_func.h twofish.h memdbg.h os.h os-autoconf.h

pgpdisk_fmt_plug.o:	pgpdisk_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h memory.h common.h formats.h params.h omp_autotune.h johnswap.h sha.h aligned.h md4.h md5.h loader.h list.h aes.h aes/aes_func.h twofish.h pgpdisk_common.h memdbg.h os.h os-autoconf.h

pgpsda_common_plug.o:	pgpsda_common_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h pgpsda_common.h formats.h params.h omp_autotune.h sha.h aligned.h md4.h md5.h memdbg.h os.h os-autoconf.h

pgpsda_fmt_plug.o:	pgpsda_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h memory.h common.h formats.h params.h omp_autotune.h johnswap.h sha.h aligned.h md4.h md5.h loader.h list.h pgpsda_common.h memdbg.h os.h os-autoconf.h

pgpwde_common_plug.o:	pgpwde_common_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h pgpwde_common.h formats.h params.h omp_autotune.h sha.h aligned.h md4.h md5.h aes.h aes/aes_func.h memdbg.h os.h os-autoconf.h

pgpwde_fmt_plug.o:	pgpwde_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h memory.h common.h formats.h params.h omp_autotune.h johnswap.h loader.h list.h pgpwde_common.h sha.h aligned.h md4.h md5.h aes.h aes/aes_func.h memdbg.h os.h os-autoconf.h

phpassMD5_fmt_plug.o:	phpassMD5_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h johnswap.h formats.h params.h omp_autotune.h md5.h phpass_common.h simd-intrinsics.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h common-get-hash.h

phpass_common_plug.o:	phpass_common_plug.c formats.h params.h arch.h misc.h jumbo.h autoconfig.h omp_autotune.h memory.h common.h phpass_common.h memdbg.h os.h os-autoconf.h

pixMD5_fmt_plug.o:	pixMD5_fmt_plug.c autoconfig.h common.h arch.h memory.h formats.h params.h misc.h jumbo.h omp_autotune.h dynamic.h simd-intrinsics.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h

pkcs12_plug.o:	pkcs12_plug.c sha2.h arch.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h johnswap.h common.h memory.h stdbool.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h pkcs12.h sha.h sph_whirlpool.h sph_types.h autoconfig.h

pkzip_fmt_plug.o:	pkzip_fmt_plug.c arch.h common.h memory.h misc.h jumbo.h autoconfig.h formats.h params.h omp_autotune.h pkzip.h dyna_salt.h crc32.h pkzip_inffixed.h loader.h list.h memdbg.h os.h os-autoconf.h

plaintext_fmt_plug.o:	plaintext_fmt_plug.c common.h arch.h memory.h formats.h params.h misc.h jumbo.h autoconfig.h omp_autotune.h options.h list.h loader.h getopt.h memdbg.h os.h os-autoconf.h

pomelo_fmt_plug.o:	pomelo_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h memdbg.h os.h os-autoconf.h common-get-hash.h

pomelo_plug.o:	pomelo_plug.c arch.h memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h memory.h

postgres_fmt_plug.o:	postgres_fmt_plug.c arch.h md5.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h memdbg.h os.h os-autoconf.h common-get-hash.h

pst_fmt_plug.o:	pst_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h crc32.h memdbg.h os.h os-autoconf.h common-get-hash.h

putty_fmt_plug.o:	putty_fmt_plug.c arch.h params.h common.h memory.h formats.h misc.h jumbo.h autoconfig.h omp_autotune.h aes.h aes/aes_func.h sha.h aligned.h md4.h md5.h hmac_sha.h loader.h list.h memdbg.h os.h os-autoconf.h

pwsafe_fmt_plug.o:	pwsafe_fmt_plug.c arch.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h johnswap.h common.h memory.h stdbool.h misc.h jumbo.h autoconfig.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h common-get-hash.h

qnx_fmt_plug.o:	qnx_fmt_plug.c arch.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h johnswap.h common.h memory.h stdbool.h params.h formats.h misc.h jumbo.h autoconfig.h omp_autotune.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h qnx_common.h base64_convert.h common-get-hash.h

racf_fmt_plug.o:	racf_fmt_plug.c arch.h crc32.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h memdbg.h os.h os-autoconf.h common-get-hash.h

radmin_fmt_plug.o:	radmin_fmt_plug.c md5.h arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h memdbg.h os.h os-autoconf.h common-get-hash.h

rakp_fmt_plug.o:	rakp_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h sha.h aligned.h md4.h md5.h johnswap.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h

rar5_fmt_plug.o:	rar5_fmt_plug.c arch.h johnswap.h common.h memory.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h stdbool.h misc.h jumbo.h autoconfig.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h rar5_common.h memdbg.h os.h os-autoconf.h pbkdf2_hmac_sha256.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h

rar_fmt_plug.o:	rar_fmt_plug.c arch.h autoconfig.h win32_memmap.h os.h os-autoconf.h jumbo.h mmap-windows.c memdbg.h memory.h sha.h aligned.h md4.h md5.h crc32.h misc.h common.h formats.h params.h omp_autotune.h dyna_salt.h options.h list.h loader.h getopt.h unicode.h johnswap.h unrar.h aes.h aes/aes_func.h unrarhlp.h unrarppm.h unrarvm.h unrarcmd.h unrarfilter.h config.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h rar_common.c

rawBLAKE2_512_fmt_plug.o:	rawBLAKE2_512_fmt_plug.c arch.h blake2.h aligned.h jumbo.h params.h common.h memory.h formats.h misc.h autoconfig.h omp_autotune.h memdbg.h os.h os-autoconf.h common-get-hash.h

rawKeccak_256_fmt_plug.o:	rawKeccak_256_fmt_plug.c arch.h params.h common.h memory.h formats.h misc.h jumbo.h autoconfig.h omp_autotune.h options.h list.h loader.h getopt.h KeccakHash.h KeccakSponge.h KeccakF-1600-interface.h memdbg.h os.h os-autoconf.h common-get-hash.h

rawKeccak_512_fmt_plug.o:	rawKeccak_512_fmt_plug.c arch.h params.h common.h memory.h formats.h misc.h jumbo.h autoconfig.h omp_autotune.h options.h list.h loader.h getopt.h KeccakHash.h KeccakSponge.h KeccakF-1600-interface.h memdbg.h os.h os-autoconf.h common-get-hash.h

rawMD4_fmt_plug.o:	rawMD4_fmt_plug.c arch.h md4.h common.h memory.h johnswap.h formats.h params.h misc.h jumbo.h autoconfig.h omp_autotune.h simd-intrinsics.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h common-simd-getpos.h common-simd-setkey32.h

rawMD5_fmt_plug.o:	rawMD5_fmt_plug.c arch.h md5.h misc.h jumbo.h autoconfig.h common.h memory.h johnswap.h formats.h params.h omp_autotune.h base64_convert.h simd-intrinsics.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h common-simd-getpos.h common-simd-setkey32.h common-get-hash.h

rawMD5flat_fmt_plug.o:	rawMD5flat_fmt_plug.c arch.h md5.h common.h memory.h formats.h params.h misc.h jumbo.h autoconfig.h omp_autotune.h simd-intrinsics.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h

rawSHA1_common_plug.o:	rawSHA1_common_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h base64_convert.h johnswap.h rawSHA1_common.h memdbg.h os.h os-autoconf.h

rawSHA1_fmt_plug.o:	rawSHA1_fmt_plug.c arch.h sha.h aligned.h md4.h md5.h common.h memory.h formats.h params.h misc.h jumbo.h autoconfig.h omp_autotune.h base64_convert.h rawSHA1_common.h johnswap.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h common-simd-getpos.h common-simd-setkey32.h

rawSHA1_linkedIn_fmt_plug.o:	rawSHA1_linkedIn_fmt_plug.c arch.h simd-intrinsics.h common.h memory.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h misc.h jumbo.h autoconfig.h formats.h params.h omp_autotune.h sha.h md4.h md5.h johnswap.h loader.h list.h rawSHA1_common.h base64_convert.h memdbg.h os.h os-autoconf.h common-simd-getpos.h common-simd-setkey32.h

rawSHA1_ng_fmt_plug.o:	rawSHA1_ng_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h stdbool.h int128.h pseudo_intrinsics.h aligned.h common.h memory.h params.h formats.h omp_autotune.h sha.h md4.h md5.h johnswap.h rawSHA1_common.h memdbg.h os.h os-autoconf.h

rawSHA224_fmt_plug.o:	rawSHA224_fmt_plug.c arch.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h johnswap.h common.h memory.h stdbool.h params.h formats.h misc.h jumbo.h autoconfig.h omp_autotune.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h common-simd-getpos.h common-simd-setkey32.h

rawSHA256_common_plug.o:	rawSHA256_common_plug.c formats.h params.h arch.h misc.h jumbo.h autoconfig.h omp_autotune.h johnswap.h common.h memory.h rawSHA256_common.h memdbg.h os.h os-autoconf.h

rawSHA256_fmt_plug.o:	rawSHA256_fmt_plug.c arch.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h johnswap.h common.h memory.h stdbool.h params.h formats.h misc.h jumbo.h autoconfig.h omp_autotune.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h rawSHA256_common.h common-simd-getpos.h common-get-hash.h common-simd-setkey32.h

rawSHA256_ng_fmt_plug.o:	rawSHA256_ng_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h pseudo_intrinsics.h aligned.h common.h memory.h formats.h params.h omp_autotune.h memdbg.h os.h os-autoconf.h rawSHA256_common.h

rawSHA384_fmt_plug.o:	rawSHA384_fmt_plug.c arch.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h johnswap.h common.h memory.h stdbool.h params.h formats.h misc.h jumbo.h autoconfig.h omp_autotune.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h common-simd-getpos.h common-simd-setkey64.h

rawSHA512_common_plug.o:	rawSHA512_common_plug.c formats.h params.h arch.h misc.h jumbo.h autoconfig.h omp_autotune.h johnswap.h common.h memory.h base64_convert.h rawSHA512_common.h memdbg.h os.h os-autoconf.h

rawSHA512_fmt_plug.o:	rawSHA512_fmt_plug.c arch.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h johnswap.h common.h memory.h stdbool.h params.h formats.h misc.h jumbo.h autoconfig.h omp_autotune.h rawSHA512_common.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h common-simd-getpos.h common-simd-setkey64.h

rawSHA512_ng_fmt_plug.o:	rawSHA512_ng_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h pseudo_intrinsics.h aligned.h common.h memory.h formats.h params.h omp_autotune.h johnswap.h rawSHA512_common.h memdbg.h os.h os-autoconf.h

rawmd5u_fmt_plug.o:	rawmd5u_fmt_plug.c arch.h simd-intrinsics.h common.h memory.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h md5.h misc.h jumbo.h autoconfig.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h unicode.h johnswap.h memdbg.h os.h os-autoconf.h common-get-hash.h

ripemd_fmt_plug.o:	ripemd_fmt_plug.c arch.h sph_ripemd.h sph_types.h autoconfig.h misc.h jumbo.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h memdbg.h os.h os-autoconf.h common-get-hash.h

rsvp_fmt_plug.o:	rsvp_fmt_plug.c arch.h md5.h sha.h aligned.h md4.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h johnswap.h options.h list.h loader.h getopt.h memdbg.h os.h os-autoconf.h

salted_sha1_common_plug.o:	salted_sha1_common_plug.c arch.h formats.h params.h misc.h jumbo.h autoconfig.h omp_autotune.h base64_convert.h salted_sha1_common.h memdbg.h os.h os-autoconf.h memory.h

salted_sha1_fmt_plug.o:	salted_sha1_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h common.h memory.h johnswap.h salted_sha1_common.h simd-intrinsics.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h sha.h md4.h md5.h base64_convert.h memdbg.h os.h os-autoconf.h common-simd-getpos.h common-simd-setkey32.h common-get-hash.h

sapB_fmt_plug.o:	sapB_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h johnswap.h options.h list.h loader.h getopt.h unicode.h md5.h simd-intrinsics.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h common-get-hash.h

sapG_fmt_plug.o:	sapG_fmt_plug.c arch.h simd-intrinsics.h common.h memory.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h misc.h jumbo.h autoconfig.h formats.h params.h omp_autotune.h sha.h md4.h md5.h options.h list.h loader.h getopt.h unicode.h johnswap.h memdbg.h os.h os-autoconf.h common-get-hash.h

sapH_fmt_plug.o:	sapH_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h base64_convert.h sha.h aligned.h md4.h md5.h sha2.h openssl_local_overrides.h jtr_sha2.h johnswap.h stdbool.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h common-get-hash.h

securezip_common_plug.o:	securezip_common_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h securezip_common.h formats.h params.h omp_autotune.h sha.h aligned.h md4.h md5.h memdbg.h os.h os-autoconf.h

securezip_fmt_plug.o:	securezip_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h sha.h aligned.h md4.h md5.h aes.h aes/aes_func.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h securezip_common.h memdbg.h os.h os-autoconf.h

serpent_plug.o:	serpent_plug.c serpent.h arch.h

sha1crypt_common_plug.o:	sha1crypt_common_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h base64_convert.h johnswap.h sha1crypt_common.h memdbg.h os.h os-autoconf.h

sha1crypt_fmt_plug.o:	sha1crypt_fmt_plug.c arch.h sha.h aligned.h md4.h md5.h params.h common.h memory.h formats.h misc.h jumbo.h autoconfig.h omp_autotune.h johnswap.h pbkdf2_hmac_sha1.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h base64_convert.h sha1crypt_common.h memdbg.h os.h os-autoconf.h common-get-hash.h

sha256crypt_fmt_plug.o:	sha256crypt_fmt_plug.c arch.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h johnswap.h common.h memory.h stdbool.h params.h formats.h misc.h jumbo.h autoconfig.h omp_autotune.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h sha256crypt_common.h common-get-hash.h

sha3_512_fmt_plug.o:	sha3_512_fmt_plug.c arch.h params.h common.h memory.h formats.h misc.h jumbo.h autoconfig.h omp_autotune.h options.h list.h loader.h getopt.h KeccakHash.h KeccakSponge.h KeccakF-1600-interface.h memdbg.h os.h os-autoconf.h common-get-hash.h

sha512crypt_fmt_plug.o:	sha512crypt_fmt_plug.c arch.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h johnswap.h common.h memory.h stdbool.h params.h formats.h misc.h jumbo.h autoconfig.h omp_autotune.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h sha512crypt_common.h common-get-hash.h

siemens-s7_fmt_plug.o:	siemens-s7_fmt_plug.c sha.h aligned.h arch.h md4.h md5.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h memdbg.h os.h os-autoconf.h common-get-hash.h

sip_fmt_plug.o:	sip_fmt_plug.c arch.h md5.h crc32.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h sip_fmt_plug.h memdbg.h os.h os-autoconf.h

skein_fmt_plug.o:	skein_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h sph_skein.h sph_types.h memdbg.h os.h os-autoconf.h common-get-hash.h

sl3_common_plug.o:	sl3_common_plug.c formats.h params.h arch.h misc.h jumbo.h autoconfig.h omp_autotune.h memory.h base64_convert.h sl3_common.h memdbg.h os.h os-autoconf.h

sl3_fmt_plug.o:	sl3_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h common.h memory.h johnswap.h simd-intrinsics.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h sha.h md4.h md5.h sl3_common.h base64_convert.h memdbg.h os.h os-autoconf.h common-get-hash.h

snefru_fmt_plug.o:	snefru_fmt_plug.c arch.h snefru.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h memdbg.h os.h os-autoconf.h common-get-hash.h

snefru_plug.o:	snefru_plug.c gost.h arch.h johnswap.h common.h memory.h snefru.h memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h

snmp_fmt_plug.o:	snmp_fmt_plug.c formats.h params.h arch.h misc.h jumbo.h autoconfig.h omp_autotune.h md5.h hmacmd5.h aligned.h sha.h md4.h hmac_sha.h common.h memory.h options.h list.h loader.h getopt.h memdbg.h os.h os-autoconf.h

ssh_ng_fmt_plug.o:	ssh_ng_fmt_plug.c arch.h aes.h autoconfig.h aes/aes_func.h jumbo.h common.h memory.h formats.h params.h misc.h omp_autotune.h options.h list.h loader.h getopt.h md5.h bcrypt_pbkdf.h asn1.h memdbg.h os.h os-autoconf.h

ssha512_fmt_plug.o:	ssha512_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h common.h memory.h johnswap.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h stdbool.h base64_convert.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h rawSHA512_common.h memdbg.h os.h os-autoconf.h common-simd-getpos.h common-simd-setkey64.h

sspr_common_plug.o:	sspr_common_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h sspr_common.h formats.h params.h omp_autotune.h memdbg.h os.h os-autoconf.h

sspr_fmt_plug.o:	sspr_fmt_plug.c formats.h params.h arch.h misc.h jumbo.h autoconfig.h omp_autotune.h md5.h sha.h aligned.h md4.h sha2.h openssl_local_overrides.h jtr_sha2.h johnswap.h common.h memory.h stdbool.h options.h list.h loader.h getopt.h sspr_common.h sspr_variable_code.h memdbg.h os.h os-autoconf.h

stribog_fmt_plug.o:	stribog_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h gost3411-2012-sse41.h memdbg.h os.h os-autoconf.h

strip_fmt_plug.o:	strip_fmt_plug.c arch.h aes.h autoconfig.h aes/aes_func.h misc.h jumbo.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h johnswap.h pbkdf2_hmac_sha1.h sha.h aligned.h md4.h md5.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h

sunmd5_fmt_plug.o:	sunmd5_fmt_plug.c os.h os-autoconf.h autoconfig.h jumbo.h arch.h misc.h options.h list.h loader.h params.h formats.h omp_autotune.h getopt.h common.h memory.h md5.h simd-intrinsics.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h memdbg.h common-get-hash.h

syb-prop_repro_plug.o:	syb-prop_repro_plug.c syb-prop_repro.h common.h arch.h memory.h feal8.h memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h

tacacs_plus_fmt_plug.o:	tacacs_plus_fmt_plug.c formats.h params.h arch.h misc.h jumbo.h autoconfig.h omp_autotune.h common.h memory.h options.h list.h loader.h getopt.h md5.h memdbg.h os.h os-autoconf.h

tcp_md5_fmt_plug.o:	tcp_md5_fmt_plug.c arch.h md5.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h memdbg.h os.h os-autoconf.h

tiger_fmt_plug.o:	tiger_fmt_plug.c arch.h sph_tiger.h sph_types.h autoconfig.h misc.h jumbo.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h memdbg.h os.h os-autoconf.h common-get-hash.h

truecrypt_fmt_plug.o:	truecrypt_fmt_plug.c arch.h xts.h aes.h autoconfig.h aes/aes_func.h twofish.h serpent.h misc.h jumbo.h memory.h common.h formats.h params.h omp_autotune.h crc32.h johnswap.h loader.h list.h pbkdf2_hmac_sha512.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h stdbool.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h pbkdf2_hmac_ripemd160.h sph_ripemd.h sph_types.h pbkdf2_hmac_whirlpool.h sph_whirlpool.h memdbg.h os.h os-autoconf.h

twofish_plug.o:	twofish_plug.c twofish.h memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h arch.h memory.h

vdi_fmt_plug.o:	vdi_fmt_plug.c arch.h xts.h aes.h autoconfig.h aes/aes_func.h twofish.h serpent.h misc.h jumbo.h memory.h common.h formats.h params.h omp_autotune.h crc32.h johnswap.h base64_convert.h pbkdf2_hmac_sha256.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h stdbool.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h

vms_fmt_plug.o:	vms_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h vms_std.h common.h memory.h uaf_encode.h formats.h params.h omp_autotune.h memdbg.h os.h os-autoconf.h common-get-hash.h

vnc_fmt_plug.o:	vnc_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h memdbg.h os.h os-autoconf.h common-get-hash.h

vtp_fmt_plug.o:	vtp_fmt_plug.c arch.h md5.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h johnswap.h options.h list.h loader.h getopt.h memdbg.h os.h os-autoconf.h

wbb3_fmt_plug.o:	wbb3_fmt_plug.c arch.h sha.h aligned.h md4.h md5.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h memdbg.h os.h os-autoconf.h common-get-hash.h

whirlpool_fmt_plug.o:	whirlpool_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h sph_whirlpool.h sph_types.h openssl_local_overrides.h memdbg.h os.h os-autoconf.h common-get-hash.h

wow_srp_fmt_plug.o:	wow_srp_fmt_plug.c autoconfig.h sha.h aligned.h arch.h md4.h md5.h sha2.h openssl_local_overrides.h jtr_sha2.h johnswap.h common.h memory.h stdbool.h params.h formats.h misc.h jumbo.h omp_autotune.h unicode.h options.h list.h loader.h getopt.h memdbg.h os.h os-autoconf.h common-get-hash.h

wpapmk_fmt_plug.o:	wpapmk_fmt_plug.c arch.h formats.h params.h misc.h jumbo.h autoconfig.h omp_autotune.h common.h memory.h wpapmk.h johnswap.h hmacmd5.h aligned.h md5.h hmac_sha.h sha2.h openssl_local_overrides.h md4.h jtr_sha2.h stdbool.h base64_convert.h hccap.h sha.h memdbg.h os.h os-autoconf.h

wpapsk_fmt_plug.o:	wpapsk_fmt_plug.c arch.h simd-intrinsics.h common.h memory.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h formats.h params.h misc.h jumbo.h autoconfig.h omp_autotune.h pbkdf2_hmac_sha1.h sha.h md4.h md5.h wpapsk.h johnswap.h hmacmd5.h hmac_sha.h sha2.h openssl_local_overrides.h jtr_sha2.h stdbool.h hccap.h memdbg.h os.h os-autoconf.h

xmpp_scram_fmt_plug.o:	xmpp_scram_fmt_plug.c arch.h misc.h jumbo.h autoconfig.h memory.h common.h formats.h params.h omp_autotune.h johnswap.h sha.h aligned.h md4.h md5.h hmac_sha.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h pbkdf2_hmac_sha1.h memdbg.h os.h os-autoconf.h common-get-hash.h

xts_plug.o:	xts_plug.c arch.h xts.h aes.h autoconfig.h aes/aes_func.h twofish.h serpent.h

zip_fmt_plug.o:	zip_fmt_plug.c arch.h crc32.h misc.h jumbo.h autoconfig.h params.h common.h memory.h formats.h omp_autotune.h johnswap.h pkzip.h dyna_salt.h pbkdf2_hmac_sha1.h sha.h aligned.h md4.h md5.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h hmac_sha.h memdbg.h os.h os-autoconf.h

zipmonster_fmt_plug.o:	zipmonster_fmt_plug.c arch.h sha.h aligned.h md4.h md5.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h omp_autotune.h options.h list.h loader.h getopt.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h memdbg.h os.h os-autoconf.h common-get-hash.h

opencl_%.h:	| ../run/kernels
	$(CP) $< ../run/kernels

%.cl:	| ../run/kernels
	$(CP) $< ../run/kernels

../run/kernels:
	$(MKDIR) ../run/kernels



######## auto-generated, best-effort

AFS_fmt.o:	AFS_fmt.c arch.h misc.h jumbo.h autoconfig.h params.h DES_std.h common.h memory.h formats.h memdbg.h os.h os-autoconf.h

lzma/Lzma2Dec.o:	lzma/Lzma2Dec.c lzma/Precomp.h lzma/Compiler.h lzma/Lzma2Dec.h lzma/LzmaDec.h lzma/7zTypes.h

lzma/LzmaDec.o:	lzma/LzmaDec.c lzma/Precomp.h lzma/Compiler.h lzma/LzmaDec.h lzma/7zTypes.h

base64_convert.o:	base64_convert.c missing_getopt.h memory.h arch.h misc.h jumbo.h autoconfig.h common.h base64_convert.h memdbg.h os.h os-autoconf.h

batch.o:	batch.c params.h arch.h os.h os-autoconf.h autoconfig.h jumbo.h signals.h loader.h list.h formats.h misc.h status.h config.h single.h wordlist.h inc.h memdbg.h memory.h

bench.o:	bench.c os.h os-autoconf.h autoconfig.h jumbo.h arch.h times.h misc.h params.h memory.h signals.h formats.h dyna_salt.h bench.h john.h unicode.h options.h list.h loader.h getopt.h common.h config.h common-gpu.h gpu_sensors.h john-mpi.h memdbg.h

best.o:	best.c os.h os-autoconf.h autoconfig.h jumbo.h arch.h params.h common.h memory.h formats.h misc.h bench.h memdbg.h

BF_common.o:	BF_common.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h BF_common.h memdbg.h os.h os-autoconf.h

BF_fmt.o:	BF_fmt.c arch.h misc.h jumbo.h autoconfig.h BF_std.h common.h memory.h formats.h params.h BF_common.h memdbg.h os.h os-autoconf.h

BF_std.o:	BF_std.c arch.h common.h memory.h BF_std.h formats.h params.h misc.h jumbo.h autoconfig.h BF_common.h memdbg.h os.h os-autoconf.h

blowfish.o:	blowfish.c blowfish.h arch.h bf_tab.h memory.h johnswap.h common.h memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h

BSDI_fmt.o:	BSDI_fmt.c arch.h misc.h jumbo.h autoconfig.h DES_std.h common.h memory.h formats.h params.h DES_bs.h loader.h list.h memdbg.h os.h os-autoconf.h

bt.o:	bt.c bt_twister.h bt_hash_types.h bt_interface.h memory.h arch.h memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h misc.h

bt_hash_type_128.o:	bt_hash_type_128.c bt_hash_types.h bt_interface.h memory.h arch.h memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h misc.h

bt_hash_type_192.o:	bt_hash_type_192.c bt_hash_types.h bt_interface.h memory.h arch.h memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h misc.h

bt_hash_type_64.o:	bt_hash_type_64.c bt_hash_types.h bt_interface.h memory.h arch.h memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h misc.h

bt_twister.o:	bt_twister.c bt_twister.h

c3_fmt.o:	c3_fmt.c autoconfig.h options.h list.h loader.h params.h arch.h formats.h misc.h jumbo.h getopt.h common.h memory.h john.h os.h os-autoconf.h john-mpi.h memdbg.h

calc_stat.o:	calc_stat.c autoconfig.h memory.h arch.h memdbg.h os.h os-autoconf.h jumbo.h

charset.o:	charset.c os.h os-autoconf.h autoconfig.h jumbo.h arch.h misc.h params.h path.h memory.h list.h crc32.h signals.h loader.h formats.h external.h compiler.h charset.h memdbg.h

common.o:	common.c arch.h common.h memory.h memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h misc.h base64_convert.h

ifdef WITH_OPENCL
opencl_autotune.o:	opencl_autotune.c $(CL_COMMON_HEADER) arch.h misc.h jumbo.h autoconfig.h memory.h common.h formats.h params.h path.h $(CL_DEVICE_HEADER) memdbg.h os.h os-autoconf.h

common-gpu.o:	common-gpu.c autoconfig.h Win32-dlfcn-port.h common-gpu.h gpu_sensors.h john.h os.h os-autoconf.h jumbo.h arch.h memory.h params.h logger.h config.h signals.h memdbg.h

common-opencl.o:	common-opencl.c os.h os-autoconf.h autoconfig.h jumbo.h arch.h options.h list.h loader.h params.h formats.h misc.h getopt.h common.h memory.h config.h logger.h $(CL_COMMON_HEADER) path.h $(CL_DEVICE_HEADER) mask_ext.h mask.h dyna_salt.h signals.h recovery.h status.h john.h md5.h john-mpi.h memdbg.h
endif

compiler.o:	compiler.c arch.h params.h memory.h compiler.h memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h

config.o:	config.c misc.h jumbo.h arch.h autoconfig.h params.h path.h memory.h config.h john.h os.h os-autoconf.h logger.h external.h compiler.h loader.h list.h formats.h memdbg.h

cprepair.o:	cprepair.c autoconfig.h unicode.h options.h list.h loader.h params.h arch.h formats.h misc.h jumbo.h getopt.h common.h memory.h memdbg.h os.h os-autoconf.h

cracker.o:	cracker.c os.h os-autoconf.h autoconfig.h jumbo.h arch.h misc.h params.h memory.h signals.h idle.h formats.h dyna_salt.h loader.h list.h logger.h status.h recovery.h external.h compiler.h options.h getopt.h common.h mask_ext.h mask.h unicode.h john.h fake_salts.h john-mpi.h path.h common-gpu.h gpu_sensors.h memdbg.h

crc32.o:	crc32.c memory.h arch.h crc32.h memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h

md5crypt_common.o:	md5crypt_common.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h md5crypt_common.h memdbg.h os.h os-autoconf.h

DES_bs.o:	DES_bs.c arch.h common.h memory.h DES_std.h DES_bs.h loader.h params.h list.h formats.h misc.h jumbo.h autoconfig.h unicode.h options.h getopt.h memdbg.h os.h os-autoconf.h

DES_fmt.o:	DES_fmt.c arch.h DES_std.h common.h memory.h formats.h params.h misc.h jumbo.h autoconfig.h DES_bs.h loader.h list.h memdbg.h os.h os-autoconf.h

DES_std.o:	DES_std.c arch.h common.h memory.h DES_std.h memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h misc.h

detect.o:	detect.c

dmg2john.o:	dmg2john.c autoconfig.h arch.h filevault.h misc.h jumbo.h memory.h memdbg.h os.h os-autoconf.h

dummy.o:	dummy.c common.h arch.h memory.h formats.h params.h misc.h jumbo.h autoconfig.h options.h list.h loader.h getopt.h memdbg.h os.h os-autoconf.h

dynamic_big_crypt.o:	dynamic_big_crypt.c autoconfig.h openssl_local_overrides.h arch.h misc.h jumbo.h common.h memory.h formats.h params.h sha.h aligned.h md4.h md5.h sha2.h jtr_sha2.h johnswap.h stdbool.h dynamic.h simd-intrinsics.h pseudo_intrinsics.h simd-intrinsics-load-flags.h dynamic_types.h gost.h sph_ripemd.h sph_types.h sph_tiger.h sph_haval.h sph_md2.h sph_panama.h sph_skein.h sph_whirlpool.h KeccakHash.h KeccakSponge.h KeccakF-1600-interface.h memdbg.h os.h os-autoconf.h

dynamic_compiler.o:	dynamic_compiler.c arch.h common.h memory.h formats.h params.h misc.h jumbo.h autoconfig.h list.h crc32.h johnswap.h dynamic.h simd-intrinsics.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h dynamic_compiler.h base64_convert.h md5.h md4.h sha.h sha2.h openssl_local_overrides.h jtr_sha2.h stdbool.h gost.h unicode.h options.h loader.h getopt.h sph_ripemd.h sph_types.h sph_tiger.h sph_whirlpool.h sph_haval.h sph_md2.h sph_panama.h sph_skein.h KeccakHash.h KeccakSponge.h KeccakF-1600-interface.h memdbg.h os.h os-autoconf.h

dynamic_compiler_lib.o:	dynamic_compiler_lib.c arch.h formats.h params.h misc.h jumbo.h autoconfig.h dynamic.h simd-intrinsics.h common.h memory.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h dynamic_compiler.h memdbg.h os.h os-autoconf.h

dynamic_fmt.o:	dynamic_fmt.c autoconfig.h arch.h simd-intrinsics.h common.h memory.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h misc.h jumbo.h formats.h params.h md5.h md4.h dynamic.h options.h list.h loader.h getopt.h config.h sha.h sha2.h openssl_local_overrides.h jtr_sha2.h johnswap.h stdbool.h gost.h sph_haval.h sph_types.h sph_ripemd.h sph_tiger.h sph_md2.h sph_panama.h sph_skein.h sph_whirlpool.h unicode.h crc32.h fake_salts.h base64_convert.h KeccakHash.h KeccakSponge.h KeccakF-1600-interface.h dynamic_types.h memdbg.h os.h os-autoconf.h

dynamic_parser.o:	dynamic_parser.c autoconfig.h arch.h misc.h jumbo.h common.h memory.h formats.h params.h config.h md5.h options.h list.h loader.h getopt.h john.h os.h os-autoconf.h unicode.h dynamic.h simd-intrinsics.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h memdbg.h

dynamic_preloads.o:	dynamic_preloads.c autoconfig.h arch.h misc.h jumbo.h common.h memory.h formats.h params.h md5.h dynamic.h simd-intrinsics.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h options.h list.h loader.h getopt.h config.h memdbg.h os.h os-autoconf.h

dynamic_utils.o:	dynamic_utils.c autoconfig.h arch.h misc.h jumbo.h common.h memory.h formats.h params.h config.h md5.h dynamic.h simd-intrinsics.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h options.h list.h loader.h getopt.h memdbg.h os.h os-autoconf.h

dyna_salt.o:	dyna_salt.c formats.h params.h arch.h misc.h jumbo.h autoconfig.h memory.h dyna_salt.h memdbg.h os.h os-autoconf.h

external.o:	external.c misc.h jumbo.h arch.h autoconfig.h params.h os.h os-autoconf.h signals.h compiler.h loader.h list.h formats.h logger.h status.h recovery.h options.h getopt.h common.h memory.h config.h cracker.h john.h external.h mask.h memdbg.h

fake_salts.o:	fake_salts.c config.h john.h os.h os-autoconf.h autoconfig.h jumbo.h arch.h memory.h options.h list.h loader.h params.h formats.h misc.h getopt.h common.h fake_salts.h memdbg.h

formats.o:	formats.c params.h arch.h memory.h formats.h misc.h jumbo.h autoconfig.h dyna_salt.h unicode.h options.h list.h loader.h getopt.h common.h base64_convert.h $(CL_COMMON_HEADER) path.h $(CL_DEVICE_HEADER) bench.h memdbg.h os.h os-autoconf.h

fuzz.o:	fuzz.c os.h os-autoconf.h autoconfig.h jumbo.h arch.h win32_memmap.h mmap-windows.c memdbg.h memory.h config.h john.h params.h signals.h unicode.h options.h list.h loader.h formats.h misc.h getopt.h common.h

genmkvpwd.o:	genmkvpwd.c autoconfig.h jumbo.h arch.h params.h memory.h mkvlib.h memdbg.h os.h os-autoconf.h

getopt.o:	getopt.c misc.h jumbo.h arch.h autoconfig.h memory.h list.h getopt.h common.h john.h os.h os-autoconf.h memdbg.h

gost.o:	gost.c gost.h arch.h memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h memory.h

gpg2john.o:	gpg2john.c autoconfig.h arch.h jumbo.h misc.h memdbg.h os.h os-autoconf.h memory.h

haval.o:	haval.c arch.h sph_haval.h sph_types.h autoconfig.h memdbg.h os.h os-autoconf.h jumbo.h memory.h haval_helper.c

haval_helper.o:	haval_helper.c

hccap2john.o:	hccap2john.c autoconfig.h jumbo.h arch.h os.h os-autoconf.h common.h memory.h memdbg.h

hmacmd5.o:	hmacmd5.c arch.h common.h memory.h md5.h hmacmd5.h aligned.h memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h

idle.o:	idle.c os.h os-autoconf.h autoconfig.h jumbo.h arch.h params.h config.h options.h list.h loader.h formats.h misc.h getopt.h common.h memory.h signals.h bench.h memdbg.h

inc.o:	inc.c arch.h misc.h jumbo.h autoconfig.h params.h path.h memory.h os.h os-autoconf.h signals.h formats.h loader.h list.h logger.h status.h recovery.h options.h getopt.h common.h config.h charset.h external.h compiler.h cracker.h john.h unicode.h mask.h memdbg.h

john-mpi.o:	john-mpi.c autoconfig.h john-mpi.h john.h os.h os-autoconf.h jumbo.h arch.h memory.h memdbg.h

jumbo.o:	jumbo.c jumbo.h arch.h params.h memory.h memdbg.h os.h os-autoconf.h autoconfig.h

KeccakDuplex.o:	KeccakDuplex.c KeccakDuplex.h KeccakF-1600-interface.h memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h arch.h memory.h

KeccakF-1600-opt64.o:	KeccakF-1600-opt64.c brg_endian.h KeccakF-1600-opt64-settings.h KeccakF-1600-interface.h memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h arch.h memory.h KeccakF-1600-64.macros KeccakF-1600-unrolling.macros

KeccakF-1600-reference32BI.o:	KeccakF-1600-reference32BI.c brg_endian.h KeccakF-1600-interface.h

KeccakHash.o:	KeccakHash.c KeccakHash.h KeccakSponge.h KeccakF-1600-interface.h memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h arch.h memory.h

KeccakSponge.o:	KeccakSponge.c KeccakSponge.h KeccakF-1600-interface.h memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h arch.h memory.h

keepass2john.o:	keepass2john.c autoconfig.h arch.h missing_getopt.h jumbo.h params.h memory.h memdbg.h os.h os-autoconf.h base64.h

bitlocker2john.o:	bitlocker2john.c autoconfig.h arch.h missing_getopt.h jumbo.h params.h memory.h memdbg.h os.h os-autoconf.h

list.o:	list.c memory.h arch.h list.h memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h

listconf.o:	listconf.c autoconfig.h os.h os-autoconf.h jumbo.h arch.h simd-intrinsics.h common.h memory.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h params.h path.h formats.h misc.h options.h list.h loader.h getopt.h unicode.h dynamic.h dynamic_types.h config.h regex.h john_build_rule.h $(CL_COMMON_HEADER) $(CL_DEVICE_HEADER) version.h listconf.h memdbg.h

LM_fmt.o:	LM_fmt.c arch.h misc.h jumbo.h autoconfig.h memory.h DES_bs.h common.h loader.h params.h list.h formats.h memdbg.h os.h os-autoconf.h

loader.o:	loader.c autoconfig.h jumbo.h arch.h os.h os-autoconf.h misc.h params.h path.h memory.h list.h signals.h formats.h dyna_salt.h loader.h options.h getopt.h common.h config.h unicode.h dynamic.h simd-intrinsics.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h fake_salts.h john.h cracker.h logger.h base64_convert.h memdbg.h

logger.o:	logger.c os.h os-autoconf.h autoconfig.h jumbo.h arch.h misc.h params.h path.h memory.h status.h options.h list.h loader.h formats.h getopt.h common.h config.h recovery.h unicode.h dynamic.h simd-intrinsics.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h john-mpi.h cracker.h signals.h memdbg.h

mask.o:	mask.c misc.h jumbo.h arch.h autoconfig.h logger.h recovery.h loader.h params.h list.h formats.h os.h os-autoconf.h signals.h status.h options.h getopt.h common.h memory.h config.h external.h compiler.h cracker.h john.h mask.h unicode.h encoding_data.h memdbg.h mask_ext.h

mask_ext.o:	mask_ext.c mask_ext.h mask.h loader.h params.h arch.h list.h formats.h misc.h jumbo.h autoconfig.h options.h getopt.h common.h memory.h memdbg.h os.h os-autoconf.h

md2.o:	md2.c sph_md2.h sph_types.h autoconfig.h arch.h memdbg.h os.h os-autoconf.h jumbo.h memory.h

md4.o:	md4.c md4.h arch.h memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h memory.h

md5.o:	md5.c md5.h arch.h memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h memory.h

MD5_fmt.o:	MD5_fmt.c arch.h misc.h jumbo.h autoconfig.h simd-intrinsics.h common.h memory.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h MD5_std.h formats.h params.h md5crypt_common.h memdbg.h os.h os-autoconf.h

MD5_std.o:	MD5_std.c arch.h common.h memory.h MD5_std.h memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h

md_helper.o:	md_helper.c

memdbg.o:	memdbg.c common.h arch.h memory.h memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h pseudo_intrinsics.h aligned.h

memory.o:	memory.c arch.h misc.h jumbo.h autoconfig.h memory.h common.h johnswap.h memdbg.h os.h os-autoconf.h

misc.o:	misc.c os.h os-autoconf.h autoconfig.h jumbo.h arch.h logger.h params.h misc.h options.h list.h loader.h formats.h getopt.h common.h memory.h john-mpi.h memdbg.h

missing_getopt.o:	missing_getopt.c missing_getopt.h memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h arch.h memory.h

mkv.o:	mkv.c arch.h misc.h jumbo.h autoconfig.h params.h path.h memory.h os.h os-autoconf.h signals.h formats.h loader.h list.h logger.h status.h recovery.h config.h charset.h external.h compiler.h cracker.h options.h getopt.h common.h john.h mkv.h mkvlib.h mask.h memdbg.h

mkvcalcproba.o:	mkvcalcproba.c autoconfig.h params.h arch.h mkvlib.h memory.h jumbo.h memdbg.h os.h os-autoconf.h

mkvlib.o:	mkvlib.c arch.h misc.h jumbo.h autoconfig.h params.h memory.h mkvlib.h path.h memdbg.h os.h os-autoconf.h

mmap-windows.o:	mmap-windows.c memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h arch.h memory.h

nonstd.o:	nonstd.c

NT_fmt.o:	NT_fmt.c arch.h misc.h jumbo.h autoconfig.h memory.h common.h formats.h params.h options.h list.h loader.h getopt.h unicode.h aligned.h johnswap.h memdbg.h os.h os-autoconf.h

omp_autotune.o:	timer.h memdbg.h

options.o:	options.c os.h os-autoconf.h autoconfig.h jumbo.h arch.h misc.h params.h memory.h list.h loader.h formats.h logger.h status.h recovery.h options.h getopt.h common.h bench.h external.h compiler.h john.h dynamic.h simd-intrinsics.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h unicode.h fake_salts.h path.h regex.h john-mpi.h $(CL_COMMON_HEADER) $(CL_DEVICE_HEADER) prince.h version.h listconf.h memdbg.h john_build_rule.h

panama.o:	panama.c sph_panama.h sph_types.h autoconfig.h arch.h memdbg.h os.h os-autoconf.h jumbo.h memory.h

params.o:	params.c params.h arch.h memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h memory.h

path.o:	path.c autoconfig.h misc.h jumbo.h arch.h params.h memory.h path.h memdbg.h os.h os-autoconf.h

pkzip.o:	pkzip.c arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h pkzip.h dyna_salt.h crc32.h memdbg.h os.h os-autoconf.h

putty2john.o:	putty2john.c autoconfig.h memory.h arch.h jumbo.h memdbg.h os.h os-autoconf.h

racf2john.o:	racf2john.c autoconfig.h jumbo.h arch.h memory.h memdbg.h os.h os-autoconf.h

rar2john.o:	rar2john.c jumbo.h arch.h common.h memory.h params.h crc32.h unicode.h options.h autoconfig.h list.h loader.h formats.h misc.h getopt.h base64_convert.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h johnswap.h stdbool.h rar2john.h missing_getopt.h memdbg.h os.h os-autoconf.h

rar_common.o:	rar_common.c

raw2dyna.o:	raw2dyna.c autoconfig.h memdbg.h os.h os-autoconf.h jumbo.h arch.h memory.h

rc4.o:	rc4.c rc4.h arch.h memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h memory.h

recovery.o:	recovery.c os.h os-autoconf.h autoconfig.h jumbo.h arch.h misc.h params.h path.h memory.h config.h options.h list.h loader.h formats.h getopt.h common.h logger.h status.h recovery.h john.h mask.h unicode.h john-mpi.h signals.h memdbg.h

regex.o:	regex.c regex.h autoconfig.h loader.h params.h arch.h list.h formats.h misc.h jumbo.h logger.h status.h os.h os-autoconf.h signals.h recovery.h options.h getopt.h common.h memory.h config.h cracker.h john.h external.h compiler.h memdbg.h

ripemd.o:	ripemd.c sph_ripemd.h sph_types.h autoconfig.h arch.h memdbg.h os.h os-autoconf.h jumbo.h memory.h md_helper.c

rpp.o:	rpp.c arch.h params.h config.h rpp.h common.h memory.h memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h

rules.o:	rules.c arch.h misc.h jumbo.h autoconfig.h params.h common.h memory.h formats.h loader.h list.h logger.h rpp.h config.h rules.h options.h getopt.h john.h os.h os-autoconf.h unicode.h encoding_data.h memdbg.h

sboxes.o:	sboxes.c nonstd.c

sboxes-s.o:	sboxes-s.c

scrypt_fmt.o:	scrypt_fmt.c escrypt/crypto_scrypt.h arch.h misc.h jumbo.h autoconfig.h common.h memory.h formats.h params.h base64_convert.h memdbg.h os.h os-autoconf.h

sha2.o:	sha2.c arch.h sha2.h aligned.h openssl_local_overrides.h md4.h md5.h jtr_sha2.h johnswap.h common.h memory.h stdbool.h params.h memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h

signals.o:	signals.c os.h os-autoconf.h autoconfig.h jumbo.h arch.h misc.h params.h tty.h options.h list.h loader.h formats.h getopt.h common.h memory.h config.h bench.h john.h status.h signals.h john-mpi.h memdbg.h

simd-intrinsics.o:	simd-intrinsics.c arch.h pseudo_intrinsics.h aligned.h common.h memory.h md5.h MD5_std.h johnswap.h simd-intrinsics-load-flags.h misc.h jumbo.h autoconfig.h memdbg.h os.h os-autoconf.h

single.o:	single.c misc.h jumbo.h arch.h autoconfig.h params.h common.h memory.h os.h os-autoconf.h signals.h loader.h list.h formats.h logger.h status.h recovery.h options.h getopt.h rpp.h config.h rules.h external.h compiler.h cracker.h john.h unicode.h memdbg.h

SIPdump.o:	SIPdump.c autoconfig.h tcphdr.h arch.h SIPdump.h memdbg.h os.h os-autoconf.h jumbo.h memory.h

skein.o:	skein.c sph_skein.h sph_types.h autoconfig.h arch.h memdbg.h os.h os-autoconf.h jumbo.h memory.h

status.o:	status.c os.h os-autoconf.h autoconfig.h jumbo.h arch.h times.h misc.h params.h cracker.h loader.h list.h formats.h options.h getopt.h common.h memory.h status.h bench.h config.h unicode.h signals.h mask.h john-mpi.h common-gpu.h gpu_sensors.h memdbg.h

symlink.o:	symlink.c

tgtsnarf.o:	tgtsnarf.c autoconfig.h memory.h arch.h memdbg.h os.h os-autoconf.h jumbo.h common.h

tiger.o:	tiger.c sph_tiger.h sph_types.h autoconfig.h arch.h memdbg.h os.h os-autoconf.h jumbo.h memory.h md_helper.c

timer.o:	timer.c timer.h memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h arch.h memory.h

trip_fmt.o:	trip_fmt.c arch.h DES_std.h common.h memory.h formats.h params.h misc.h jumbo.h autoconfig.h DES_bs.h loader.h list.h memdbg.h os.h os-autoconf.h

tty.o:	tty.c arch.h tty.h memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h memory.h

uaf2john.o:	uaf2john.c uaf_encode.h uaf_raw.h memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h arch.h memory.h

uaf_encode.o:	uaf_encode.c arch.h uaf_raw.h uaf_encode.h memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h memory.h uaf_hash.c uaf_encode.c

uaf_hash.o:	uaf_hash.c uaf_encode.c arch.h uaf_raw.h uaf_encode.h memdbg.h os.h os-autoconf.h autoconfig.h jumbo.h memory.h uaf_hash.c

unafs.o:	unafs.c misc.h jumbo.h arch.h autoconfig.h memdbg.h os.h os-autoconf.h memory.h

undrop.o:	undrop.c os.h os-autoconf.h autoconfig.h jumbo.h arch.h memdbg.h memory.h

unicode.o:	unicode.c common.h arch.h memory.h byteorder.h unicode.h options.h autoconfig.h list.h loader.h params.h formats.h misc.h jumbo.h getopt.h UnicodeData.h encoding_data.h config.h md4.h john.h os.h os-autoconf.h memdbg.h

unique.o:	unique.c autoconfig.h arch.h misc.h jumbo.h params.h memory.h memdbg.h os.h os-autoconf.h

unrar.o:	unrar.c arch.h unrar.h aes.h autoconfig.h aes/aes_func.h unrarhlp.h memory.h jumbo.h unrarppm.h unrarvm.h unrarcmd.h unrarfilter.h memdbg.h os.h os-autoconf.h

unrarcmd.o:	unrarcmd.c aes.h autoconfig.h aes/aes_func.h unrar.h arch.h unrarhlp.h memory.h jumbo.h unrarppm.h unrarvm.h unrarcmd.h unrarfilter.h memdbg.h os.h os-autoconf.h

unrarfilter.o:	unrarfilter.c arch.h aes.h autoconfig.h aes/aes_func.h unrar.h unrarhlp.h memory.h jumbo.h unrarppm.h unrarvm.h unrarcmd.h unrarfilter.h memdbg.h os.h os-autoconf.h

unrarhlp.o:	unrarhlp.c jumbo.h arch.h unrarhlp.h memory.h memdbg.h os.h os-autoconf.h autoconfig.h

unrarvm.o:	unrarvm.c arch.h aes.h autoconfig.h aes/aes_func.h unrar.h unrarhlp.h memory.h jumbo.h unrarppm.h unrarvm.h unrarcmd.h unrarfilter.h common.h memdbg.h os.h os-autoconf.h

unshadow.o:	unshadow.c misc.h jumbo.h arch.h autoconfig.h params.h memory.h memdbg.h os.h os-autoconf.h

vncpcap2john.o:	vncpcap2john.c autoconfig.h cygwin_ethernet.h arch.h tcphdr.h memdbg.h os.h os-autoconf.h jumbo.h memory.h

eapmd5tojohn.o:	eapmd5tojohn.c arch.h memdbg.h os.h os-autoconf.h jumbo.h memory.h

whirlpool.o:	whirlpool.c sph_whirlpool.h sph_types.h autoconfig.h arch.h memdbg.h os.h os-autoconf.h jumbo.h memory.h md_helper.c

win32_memmap.o:	win32_memmap.c os.h os-autoconf.h autoconfig.h jumbo.h arch.h win32_memmap.h misc.h memdbg.h memory.h

wordlist.o:	wordlist.c autoconfig.h os.h os-autoconf.h jumbo.h arch.h win32_memmap.h mmap-windows.c memdbg.h memory.h misc.h params.h common.h path.h signals.h loader.h list.h formats.h logger.h status.h recovery.h options.h getopt.h rpp.h config.h rules.h external.h compiler.h cracker.h john.h unicode.h regex.h mask.h pseudo_intrinsics.h aligned.h

wpapcap2john.o:	wpapcap2john.c wpapcap2john.h arch.h johnswap.h common.h memory.h jumbo.h memdbg.h os.h os-autoconf.h autoconfig.h

x86-64.o:	x86-64.S arch.h

x86-mmx.o:	x86-mmx.S arch.h

x86-sse.o:	x86-sse.S arch.h

x86.o:	x86.S arch.h

zip2john.o:	zip2john.c arch.h common.h memory.h jumbo.h formats.h params.h misc.h autoconfig.h pkzip.h dyna_salt.h crc32.h missing_getopt.h memdbg.h os.h os-autoconf.h


######## End auto-generated

pp.o:	pp.c autoconfig.h arch.h win32_memmap.h os.h os-autoconf.h jumbo.h mmap-windows.c memdbg.h memory.h mpz_int128.h int128.h misc.h config.h params.h common.h path.h signals.h loader.h list.h formats.h logger.h status.h recovery.h options.h getopt.h external.h compiler.h cracker.h john.h unicode.h prince.h rpp.h rules.h mask.h
	$(CC) $(CFLAGS) $(OPT_NORMAL) -DJTR_MODE -Wno-declaration-after-statement -std=c99 -c pp.c

version.h: find_version

find_version: kernels
	echo "#define JTR_GIT_VERSION $(JTR_GIT_VERSION)" > version.h.new
	diff >/dev/null 2>/dev/null version.h.new version.h && $(RM) version.h.new || $(MV) version.h.new version.h

SUBDIRS = aes secp256k1 

.PHONY: subdirs $(SUBDIRS) find_version kernels

subdirs: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@ all

# Inlining the S-boxes produces faster code as long as they fit in the cache.
DES_bs_b.o:	DES_bs_b.c arch.h common.h memory.h DES_bs.h loader.h params.h list.h formats.h misc.h jumbo.h autoconfig.h memdbg.h os.h os-autoconf.h sboxes-s.c sboxes.c nonstd.c
	$(CC) $(CFLAGS) $(OPT_INLINE) DES_bs_b.c

miscnl.o: misc.c
	$(CC) $(CFLAGS) $(OPT_NORMAL) -D_JOHN_MISC_NO_LOG misc.c -o miscnl.o

aes/aes.a:
	$(MAKE) -C aes all

secp256k1/secp256k1.a:
	$(MAKE) -C secp256k1 all

kernels: 

###############################################################################
#  Process targets.  Note, these are *nix targets, but also work fine under
#  cygwin.  The only problem with cygwin, is that the ln -s will NOT generate
#  a valid exe which can be run under native Win32 cmd shell
#  If a use wants that behavior, then run configure, with --enable-ln-s
#  By default, it is set to cygwin will use the .EXE symlink.c building,
#  where the macro EXE_EXT is .exe.  Mingw builds always set EXE_EXT to .exe
###############################################################################

# PTHREAD_CFLAGS and OPENMP_CFLAGS may actually contain linker options,
# like -fopenmp
../run/john: $(JOHN_OBJS) aes/aes.a secp256k1/secp256k1.a 
	$(LD) $(JOHN_OBJS) $(LDFLAGS) -lssl -lcrypto  -fopenmp -lgmp    -pthread  -lm -lz -ldl -lcrypt  -lbz2  aes/aes.a secp256k1/secp256k1.a -o ../run/john

../run/unshadow: ../run/john
	$(RM) ../run/unshadow
	$(LN) john ../run/unshadow

../run/unafs: ../run/john
	$(RM) ../run/unafs
	$(LN) john ../run/unafs

../run/undrop: ../run/john
	$(RM) ../run/undrop
	$(LN) john ../run/undrop

../run/zip2john: ../run/john
	$(RM) ../run/zip2john
	$(LN) john ../run/zip2john

../run/gpg2john: ../run/john
	$(RM) ../run/gpg2john
	$(LN) john ../run/gpg2john

../run/rar2john: ../run/john
	$(RM) ../run/rar2john
	$(LN) john ../run/rar2john

../run/base64conv: ../run/john
	$(RM) ../run/base64conv
	$(LN) john ../run/base64conv

../run/unique: ../run/john
	$(RM) ../run/unique
	$(LN) john ../run/unique

#####################################################################
# These targets MUST match ALL of the john targets that use ln -s
# These are built for Win32, so that we have a 'native' symlink back
# to the john exe.  The john exe is still built fat, but there is no
# workable ln -s, so we have built a 'symlink.c' file. It works in
# a limited way, like symlink. Mingw and default cygwin use these.
# cygwin can override this within ./configure using --enable-ln-s
#####################################################################
../run/unshadow.exe: symlink.c
	$(CC) symlink.c -o ../run/unshadow.exe
	$(STRIP) ../run/unshadow.exe

../run/unafs.exe: symlink.c
	$(CC) symlink.c -o ../run/unafs.exe
	$(STRIP) ../run/unafs.exe

../run/undrop.exe: symlink.c
	$(CC) symlink.c -o ../run/undrop.exe
	$(STRIP) ../run/undrop.exe

../run/zip2john.exe: symlink.c
	$(CC) symlink.c -o ../run/zip2john.exe
	$(STRIP) ../run/zip2john.exe

../run/gpg2john.exe: symlink.c
	$(CC) symlink.c -o ../run/gpg2john.exe
	$(STRIP) ../run/gpg2john.exe

../run/rar2john.exe: symlink.c
	$(CC) symlink.c -o ../run/rar2john.exe
	$(STRIP) ../run/rar2john.exe

../run/base64conv.exe: symlink.c
	$(CC) symlink.c -o ../run/base64conv.exe
	$(STRIP) ../run/base64conv.exe

../run/unique.exe: symlink.c
	$(CC) symlink.c -o ../run/unique.exe
	$(STRIP) ../run/unique.exe

########################################################
# Not linked to symlink for a .exe file, so simply make
# single targets, using the EXE_EXT macro
########################################################
../run/genmkvpwd: $(GENMKVPWD_OBJS)
	$(LD) $(GENMKVPWD_OBJS) $(LDFLAGS) -lm -fopenmp -o ../run/genmkvpwd

../run/mkvcalcproba: mkvcalcproba.o memdbg.o
	$(LD) mkvcalcproba.o  memdbg.o $(LDFLAGS) -lm -fopenmp -o ../run/mkvcalcproba

../run/calc_stat: calc_stat.o memdbg.o
	$(LD) calc_stat.o  memdbg.o $(LDFLAGS) -lm -fopenmp -o ../run/calc_stat

../run/raw2dyna: raw2dyna.o memdbg.o
	$(LD) raw2dyna.o  memdbg.o $(LDFLAGS) -fopenmp -o ../run/raw2dyna

../run/SIPdump: SIPdump.o memdbg.o
	$(LD) SIPdump.o  memdbg.o $(LDFLAGS) -lpcap -fopenmp -o ../run/SIPdump

../run/vncpcap2john: vncpcap2john.o memdbg.o
	$(CC) -DAC_BUILT -Wall vncpcap2john.o  memdbg.o $(LDFLAGS) -lpcap -fopenmp -o ../run/vncpcap2john

../run/eapmd5tojohn: eapmd5tojohn.o memdbg.o
	$(CC) -DAC_BUILT -Wall eapmd5tojohn.o  memdbg.o $(LDFLAGS) -lpcap -fopenmp -o ../run/eapmd5tojohn

../run/uaf2john: uaf2john.o uaf_encode.o memdbg.o
	$(LD) $(LDFLAGS) -pthread  uaf2john.o uaf_encode.o  memdbg.o -fopenmp -o ../run/uaf2john

../run/keepass2john: keepass2john.c jumbo.c memdbg.c base64_convert.c misc.c common.c memory.c
	$(CC) -DAC_BUILT -Wall -O2  -I/usr/local/include -m64 -g -O2 -I/usr/local/include -DARCH_LITTLE_ENDIAN=1  -Wall -Wdeclaration-after-statement -fno-omit-frame-pointer --param allow-store-data-races=0 -Wno-deprecated-declarations -Wunused-but-set-variable -std=gnu89 -Wdate-time -D_POSIX_SOURCE -D_GNU_SOURCE -D_XOPEN_SOURCE=600 -pthread  keepass2john.c jumbo.c  memdbg.c base64_convert.c -D_JOHN_MISC_NO_LOG misc.c common.c memory.c  $(LDFLAGS) -fopenmp -lcrypto -o ../run/keepass2john

../run/dmg2john: dmg2john.o jumbo.o memdbg.o
	$(LD) $(LDFLAGS) -pthread  dmg2john.o jumbo.o  memdbg.o -fopenmp -o ../run/dmg2john

../run/bitlocker2john: bitlocker2john.c jumbo.c memdbg.c base64_convert.c misc.c common.o memory.c
	$(CC) -DAC_BUILT -Wall -O2  -I/usr/local/include -m64 -g -O2 -I/usr/local/include -DARCH_LITTLE_ENDIAN=1  -Wall -Wdeclaration-after-statement -fno-omit-frame-pointer --param allow-store-data-races=0 -Wno-deprecated-declarations -Wunused-but-set-variable -std=gnu89 -Wdate-time -D_POSIX_SOURCE -D_GNU_SOURCE -D_XOPEN_SOURCE=600 -pthread  bitlocker2john.c jumbo.c  memdbg.c base64_convert.c -D_JOHN_MISC_NO_LOG misc.c common.c memory.c  $(LDFLAGS) -fopenmp -lcrypto -o ../run/bitlocker2john

../run/racf2john: racf2john.o jumbo.o memdbg.o
	$(LD) $(LDFLAGS) -pthread  racf2john.o jumbo.o  memdbg.o -fopenmp -o ../run/racf2john

../run/hccap2john: hccap2john.o common.o jumbo.o memdbg.o
	$(LD) $(LDFLAGS) -pthread  common.o hccap2john.o jumbo.o  memdbg.o -fopenmp -o ../run/hccap2john

../run/putty2john: putty2john.o jumbo.o memdbg.o
	$(LD) $(LDFLAGS) -pthread  putty2john.o jumbo.o  memdbg.o -fopenmp -o ../run/putty2john

# Note that this is NOT depending on PCAP lib. It is self-contained.
../run/wpapcap2john: wpapcap2john.o jumbo.o memdbg.o
	$(LD) $(LDFLAGS) wpapcap2john.o jumbo.o  memdbg.o -fopenmp -o ../run/wpapcap2john

# Note, this one is NOT build by default. To get it, do a make ../run/dynacomptest (or ../run/dynacomptest.exe for cygwin builds)
../run/dynacomptest: dynamic_compiler.c dynamic_compiler_lib.c dynamic_utils.c misc.c unicode.c base64_convert.o base64.o common.o crc32.o KeccakDuplex.o KeccakF-1600-opt64.o KeccakHash.o KeccakSponge.o gost.o jumbo.o memdbg.o memory.o ripemd.o tiger.o haval.o skein.o md2.o panama.o whirlpool.o sha2.o
	$(CC) -DAC_BUILT -Wall -O2  -I/usr/local/include -m64 -g -O2 -I/usr/local/include -DARCH_LITTLE_ENDIAN=1  -Wall -Wdeclaration-after-statement -fno-omit-frame-pointer --param allow-store-data-races=0 -Wno-deprecated-declarations -Wunused-but-set-variable -std=gnu89 -Wdate-time -D_POSIX_SOURCE -D_GNU_SOURCE -D_XOPEN_SOURCE=600  -fopenmp -DWITH_MAIN -D_JOHN_MISC_NO_LOG -DUNICODE_NO_OPTIONS  dynamic_compiler.c dynamic_compiler_lib.c dynamic_utils.c misc.c unicode.c base64_convert.o base64.o common.o crc32.o KeccakDuplex.o KeccakF-1600-opt64.o KeccakHash.o KeccakSponge.o gost.o jumbo.o memdbg.o memory.o ripemd.o tiger.o haval.o skein.o md2.o panama.o whirlpool.o sha2.o $(LDFLAGS)  -lssl -lcrypto   -o ../run/dynacomptest

../run/cprepair: cprepair.c autoconfig.h unicode.c unicode.h options.h misc.h misc.c memdbg.h memdbg.c
	$(CC) -DAC_BUILT -Wall -O3 -Wall -Wdeclaration-after-statement -fno-omit-frame-pointer --param allow-store-data-races=0 -Wno-deprecated-declarations -Wunused-but-set-variable -std=gnu89 -Wdate-time -D_POSIX_SOURCE -D_GNU_SOURCE -D_XOPEN_SOURCE=600  -DNOT_JOHN -D_JOHN_MISC_NO_LOG $(CPPFLAGS) cprepair.c unicode.c misc.c memdbg.c -o ../run/cprepair

../run/tgtsnarf: tgtsnarf.o memdbg.o
	$(LD) tgtsnarf.o  memdbg.o $(LDFLAGS) -fopenmp -o ../run/tgtsnarf

john.o:	john.c autoconfig.h os.h os-autoconf.h jumbo.h arch.h params.h openssl_local_overrides.h misc.h path.h memory.h list.h tty.h signals.h common.h idle.h formats.h dyna_salt.h loader.h logger.h status.h recovery.h options.h getopt.h config.h bench.h fuzz.h charset.h single.h wordlist.h prince.h inc.h mask.h mkv.h mkvlib.h external.h compiler.h batch.h dynamic.h simd-intrinsics.h pseudo_intrinsics.h aligned.h simd-intrinsics-load-flags.h dynamic_compiler.h fake_salts.h listconf.h crc32.h john-mpi.h regex.h unicode.h $(CL_COMMON_HEADER) $(CL_DEVICE_HEADER) john_build_rule.h memdbg.h fmt_externs.h fmt_registers.h
	$(CC) $(CFLAGS_MAIN) $(OPT_NORMAL) -O0 $*.c

# Workaround for gcc 3.4.6 (seen on Sparc32) (do not use -funroll-loops)
unrarppm.o:	unrarppm.c arch.h aes.h autoconfig.h aes/aes_func.h unrar.h unrarhlp.h memory.h jumbo.h unrarppm.h unrarvm.h unrarcmd.h unrarfilter.h common.h memdbg.h os.h os-autoconf.h
	$(CC) -DAC_BUILT $(CFLAGS) $< -o $@

.c.o:
	$(CC) $(CFLAGS) $(OPT_NORMAL) $< -o $@

.S.o:
	$(AS) $(ASFLAGS) $*.S

# For jumbo, --make_check fails for the first thin format that is linked
# to a dynamic format in a config file, so we deviate from core here.
check: default
	../run/john --list=build-info
	../run/john --test=0 --verbosity=2
	../run/john --test=0 --verbosity=2 --format=dynamic-all

depend:
	makedepend -fMakefile.dep -Y *.c 2>> /dev/null

test: default
	cd ../test && perl jtrts.pl -q

test_full: default
	cd ../test && perl jtrts.pl -q -type full

test_utf8: default
	cd ../test && perl jtrts.pl -q -type utf-8

test_verbose: default
	cd ../test && perl jtrts.pl

test_full_verbose: default
	cd ../test && perl jtrts.pl -type full

test_utf8_verbose: default
	cd ../test && perl jtrts.pl -type utf-8

testfiles:
	../run/john --list=format-tests -format=cpu | LC_ALL=C cut -f3 > all_tests.in
	../run/john --list=format-tests -format=cpu | LC_ALL=C cut -f4 > all_tests.lst

bash-completion:
	[ -d $(DESTDIR)/etc/bash_completion.d ] && $(CP) ../run/john.bash_completion $(DESTDIR)/etc/bash_completion.d/ || true
	[ -d $(DESTDIR)/usr/local/etc/bash_completion.d ] && $(CP) ../run/john.bash_completion $(DESTDIR)/usr/local/etc/bash_completion.d/ || true
	[ -d $(DESTDIR)/opt/local/etc/bash_completion.d ] && $(CP) ../run/john.bash_completion $(DESTDIR)/opt/local/etc/bash_completion.d/ || true
	@echo Bash-completion for JtR opportunistically installed.
	@echo Source \". ../run/john.bash_completion\" or logout/login to activate the changes

zsh-completion:
	[ -d $(DESTDIR)/usr/share/zsh/functions/Completion/Unix ] && $(CP) ../run/john.zsh_completion $(DESTDIR)/usr/share/zsh/functions/Completion/Unix/_john || true
	[ -d $(DESTDIR)/usr/share/zsh/site-functions ] && $(CP) ../run/john.zsh_completion $(DESTDIR)/usr/share/zsh/site-functions/_john || true
	[ -d $(DESTDIR)/usr/local/share/zsh/site-functions ] && $(CP) ../run/john.zsh_completion $(DESTDIR)/usr/local/share/zsh/site-functions/_john || true
	@echo zsh-completion for JtR opportunistically installed.
	@echo Source \". ../run/john.zsh_completion\" or logout/login to activate the changes

shell-completion: bash-completion zsh-completion

kernel-cache-clean:
	$(RM) -fr ~/.nv/ComputeCache ../run/kernels/*.bin

clean:
	$(RM) $(PROJ)
	@for exe in ${PROJ}; do \
	  ($(RM) $$exe.exe) \
	done
	$(RM) john-macosx-* *.o escrypt/*.o *.bak core
	$(RM) ../run/kernels/*
	$(RM) lzma/*.o
	$(RM) detect bench generic.h tmp.s
	$(RM) *~
	$(CP) $(NULL) Makefile.dep
	@for dir in ${subdirs}; do \
	  (cd $$dir && $(MAKE) clean) \
	  || case "$(MFLAGS)" in *k*) fail=yes;; *) exit 1;; esac; \
	done && test -z "$$fail"

# These are mostly for internal use.
charsets: ../run/ascii.chr ../run/alpha.chr ../run/lowernum.chr ../run/uppernum.chr ../run/lowerspace.chr ../run/lower.chr ../run/upper.chr ../run/digits.chr ../run/alnum.chr ../run/lanman.chr ../run/lm_ascii.chr ../run/alnumspace.chr ../run/latin1.chr ../run/utf8.chr

../run/ascii.chr: charset.c params.h
	../run/john -make-charset=../run/ascii.chr -pot:rockyou.ansi.pot -ext:filter_ascii

../run/alpha.chr: charset.c params.h
	../run/john -make-charset=../run/alpha.chr -pot:rockyou.ansi.pot -ext:filter_alpha

../run/lowernum.chr: charset.c params.h
	../run/john -make-charset=../run/lowernum.chr -pot:rockyou.ansi.pot -ext:filter_lowernum

../run/uppernum.chr: charset.c params.h
	../run/john -make-charset=../run/uppernum.chr -pot:rockyou.ansi.pot -ext:filter_uppernum

../run/lowerspace.chr: charset.c params.h
	../run/john -make-charset=../run/lowerspace.chr -pot:rockyou.ansi.pot -ext:filter_lowerspace

../run/lower.chr: charset.c params.h
	../run/john -make-charset=../run/lower.chr -pot:rockyou.ansi.pot -ext:filter_lower

../run/upper.chr: charset.c params.h
	../run/john -make-charset=../run/upper.chr -pot:rockyou.ansi.pot -ext:filter_upper

../run/digits.chr: charset.c params.h
	../run/john -make-charset=../run/digits.chr -pot:rockyou.ansi.pot -ext:filter_digits

../run/alnum.chr: charset.c params.h
	../run/john -make-charset=../run/alnum.chr -pot:rockyou.ansi.pot -ext:filter_alnum

../run/lanman.chr: charset.c params.h
	../run/john -make-charset=../run/lanman.chr -pot:rockyou.lm850.pot -ext:filter_lanman

../run/lm_ascii.chr: charset.c params.h
	../run/john -make-charset=../run/lm_ascii.chr -pot:rockyou.lm850.pot -ext:filter_lm_ascii

../run/alnumspace.chr: charset.c params.h
	../run/john -make-charset=../run/alnumspace.chr -pot:rockyou.ansi.pot -ext:filter_alnumspace

../run/latin1.chr: charset.c params.h
	../run/john -make-charset=../run/latin1.chr -pot:rockyou.ansi.16.pot

../run/utf8.chr: charset.c params.h
	../run/john -make-charset=../run/utf8.chr -pot:rockyou.utf8.24.pot


#######################################################################
## NOTE, auto re-building configure will ONLY happen IF the user has ##
## CONFIG_MAINT=1 environment variable.  Beware.                     ##
#######################################################################

M4_INCLUDES=m4/ax_check_gnu_make.m4 m4/ax_lang_compiler_ms.m4 m4/ax_opencl.m4 m4/ax_prog_cc_mpi.m4 m4/ax_pthread.m4 m4/ax_ztex.m4 m4/jtr_arm_logic.m4 m4/jtr_asm_magic.m4 m4/jtr_generic_logic.m4 m4/jtr_mic_logic.m4 m4/jtr_ppc_logic.m4 m4/jtr_specific_configure_help_message.m4 m4/jtr_systems_specific_logic.m4 m4/jtr_utility_macros.m4 m4/jtr_x86_logic.m4 m4/pkg.m4

## automatic re-running of configure if the configure.ac file has changed
ifeq ($(CONFIG_MAINT), 1)
configure: configure.ac
	autoconf
else
configure: configure.ac
	@touch configure
endif

# autoheader might not change autoconfig.h.in, so touch a stamp file
ifeq ($(CONFIG_MAINT), 1)
autoconfig.h.in: autoconfig-stamp-h-in
autoconfig-stamp-h-in: configure.ac $(M4_INCLUDES)
	autoheader
	echo "timestamp from Makefile" > autoconfig-stamp-h-in
else
autoconfig.h.in: autoconfig-stamp-h-in
autoconfig-stamp-h-in: configure.ac $(M4_INCLUDES)
	echo "timestamp from Makefile" > autoconfig-stamp-h-in
endif

ifeq ($(CONFIG_MAINT), 1)
autoconfig.h: autoconfig-stamp-h
autoconfig-stamp-h: autoconfig.h.in config.status
	./config.status
else
autoconfig.h: autoconfig-stamp-h
autoconfig-stamp-h: autoconfig.h.in config.status
	@touch config.status
	@touch autoconfig.h.in
	@touch autoconfig-stamp-h
	@touch autoconfig.h
endif

ifeq ($(CONFIG_MAINT), 1)
Makefile: Makefile.in config.status
	./config.status
endif

ifeq ($(CONFIG_MAINT), 1)
config.status: configure
	./config.status --recheck
endif

all:
	@for dir in ${subdirs}; do \
	  (cd $$dir && $(MAKE) all) \
	  || case "$(MFLAGS)" in *k*) fail=yes;; *) exit 1;; esac; \
	done && test -z "$$fail"

distclean: clean
	$(RM) -r autom4te.cache
	@for dir in ${subdirs}; do \
	  (cd $$dir && $(MAKE) distclean) \
	  || case "$(MFLAGS)" in *k*) fail=yes;; *) exit 1;; esac; \
	done && test -z "$$fail"
	$(RM) Makefile autoconfig.h config.status config.cache \
		config.log autoconfig-stamp-h autoconfig-stamp-h-in stamp-h1
	$(LN) Makefile.stub Makefile
	$(RM) arch.h
	$(RM) fmt_registers.h fmt_externs.h dynamic_big_crypt.c john_build_rule.h version.h version.h.new

strip: default
	@echo Stripping executables.
	$(STRIP) $(PROJ)

### cppcheck static coverage analysis
#
.PHONY: cppcheck

cppcheck:
	$(CPPCHECK) --enable=all --force -q .

### Copy OpenCL stuff to run/kernels
#
.PHONY: kernel-copy

kernel-copy:
	$(MKDIR) ../run/kernels
	$(CP) opencl/*.cl ../run/kernels
	$(CP) opencl_*.h ../run/kernels

install: strip shell-completion
#ifneq ($(prefix), ../run)
#	@echo Copying binaries to $(prefix)
#	$(MKDIR) $(prefix)
#	$(CP) -p -P -R ../run/*.{py,pl,rb} $(PROJ) $(prefix)
#	@echo Copying data and config files to $(prefix)
#	$(MKDIR) $(prefix)
#	$(CP) -p -P -R ../run/*.{chr,conf,lst} $(prefix)
#ifdef WITH_OPENCL
#	$(CP) -p -P -R ../run/kernels $(prefix)
#endif
#endif

include Makefile.dep
