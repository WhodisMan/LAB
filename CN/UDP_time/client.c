#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main(){
    int c,len;
    char rmsg[100],smsg[100];
    struct sockaddr_in server,client;
    
    c = socket(AF_INET,SOCK_DGRAM,0);
    
    server.sin_family = AF_INET;
    server.sin_port = htons(3000);
    server.sin_addr.s_addr=htonl(INADDR_ANY);

    bind(c,(struct sockaddr*)&client, sizeof(client));



    len = sizeof(server);

    while(1){

        printf("Message to server : ");
        gets(smsg);
    
        sendto(c,smsg,100,0,(struct sockaddr*)&server,len);
        if (strcmp(smsg,"quit")==0 || strcmp(rmsg,"quit")== 0)
        	exit(0);
        

        recvfrom(c,rmsg,100,0,(struct sockaddr*)&server, &len);
        if (strcmp(smsg,"quit")==0 || strcmp(rmsg,"quit")== 0)
        	exit(0);
        printf("Message from server: %s\n",rmsg);

    }

    close(c);
}