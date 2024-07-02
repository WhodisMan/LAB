#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include <stdlib.h>
#include <unistd.h>

void main()
{
    FILE* fptr;

	int socketid,b,newsocket,len;
	char recline[100],sendline[100];
	struct sockaddr_in serveraddr,clientaddr;
	bzero(&serveraddr,sizeof(serveraddr));
	
	//creating socket
	socketid = socket(AF_INET,SOCK_STREAM,0);
	if(socketid<0)
		printf("Socket Cannot be created\n");
	else
		printf("Socket Created\n");

	//setting parameters of socket
	serveraddr.sin_family=AF_INET;
	serveraddr.sin_port=htons(3000);
	serveraddr.sin_addr.s_addr=htonl(INADDR_ANY);
	
	//binding socket
	b = bind(socketid,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
	if(b<0)
		printf("Cannot bind socket\n");
	else
		printf("Socket Binded Successfully\n");	
	
	
	//listen()
	listen(socketid,10);
		
	len=sizeof(clientaddr);
	newsocket=accept(socketid,(struct sockaddr*)&clientaddr,&len);
	printf("Connection Accepted\n");
	
	
	bzero(recline,100);
	bzero(sendline,100);

	char str1[100];

	while(1)
	{
		//message recv from client 	
		read(newsocket,recline,100);
		if (strcmp(recline,"quit")==0 || strcmp(sendline,"quit")== 0)
        	exit(0);
		//display
		printf("Message from Client = ");
		puts(recline);

        //opening file
        fptr = fopen(recline,"r");
        if (fptr == NULL){
            strcpy(sendline,"Error while opening the file");
        }        
        else{
			strcpy(sendline,"");
            while(fgets(str1,100,fptr) != NULL){
				strcat(sendline,str1);
			}
        }

        puts(sendline);
		write(newsocket,sendline,sizeof(sendline));
		if (strcmp(recline,"quit")==0 || strcmp(sendline,"quit")== 0)
            exit(0);
	}
	close(socketid);	
}





