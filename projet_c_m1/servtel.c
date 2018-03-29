#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include<unistd.h> 

main(int argc, char *argv[])
{
  int listenfd,connfd,port;
  socklen_t len;
  struct sockaddr_in servaddr,cliaddr;
  char adresseIP[16],buff[50];
  time_t tempo;

  // s'il n'y a pas 2 arguments sur la ligne de commande, on sort
  if (argc!=3){
    printf("Usage : <serveur> <port>");
    exit(-1);
  }

  // creation de la socket TCP(SOCK_STREAM) sur IPv4(AF_INET)
  // recuperation du descripteur de socket listenfd 
  listenfd=socket(AF_INET,SOCK_STREAM,0);

  // mise a zero de la structure servaddr
  bzero(&servaddr,sizeof(servaddr));

  // famille d'adresses : IPv4
  servaddr.sin_family=AF_INET;
  // adresse IP d'ecoute du serveur : INADDR_ANY (adresse wildcard)
  // c'est-a-dire que le serveur ecoutera sur toutes ses interfaces
  // on la range en ordre réseau avec htonl
  servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
  // port d'ecoute du serveur : l'argument n°1
  // on le convertit en entier avec atoi
  // puis on le range en ordre reseau avec htons
  servaddr.sin_port=htons(atoi(argv[2]));

  // on lie la structure servaddr a la socket listenfd
  // pour definir le port et l'adresse d'ecoute du serveur
  if (bind(listenfd,(struct sockaddr *)& servaddr,sizeof(servaddr))<0)
	  {
	    perror("Erreur de bind");
	    exit(-1);
	  }  

  // on passe la socket en mode passif : elle devient capable d'attendre une connexion
  listen(listenfd,10);
  // boucle infinie du serveur
  for(;;)
 	  {
	    len=sizeof(cliaddr);
	    // mise en attente de connexion
	    // on recuperera dans cliaddr les coordonnees (adresse et port du client)
	    // accept retourne un descripteur de socket connectée avec lequel on lire et ecrira dans la socket
	    connfd=accept(listenfd,(struct sockaddr*)&cliaddr,&len);
	    // On recupere dans port le port de connexion du client
	    // on le passe en ordre machine avec ntohs
	    port=ntohs(cliaddr.sin_port);
	    // on convertit l'adresse IP stockee en numerique dans cliaddr
	    // en decimale pointee
	    inet_ntop(AF_INET,&cliaddr.sin_addr,adresseIP,sizeof(adresseIP));
	    // on affiche les coordonnees du client
	    printf("connexion de %s, port %d\n",adresseIP,port);

	    // on met dans tempo le nombre de secondes ecoulees depuis le 01/01/1970
	    tempo=time(NULL);
	    // on tranforme tempo en chaine de caracteres buff contenant la date et l'heure
	    snprintf(buff,sizeof(buff),"%.24s\n",ctime(&tempo));
	    // on ecrit dans la socket la chaine buff
	    write(connfd,buff,strlen(buff));
	    // on ferme la connexion
	    close(connfd);
	  }
}

