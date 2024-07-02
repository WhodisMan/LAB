#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int pali(char str[100]){

    int l = 0;
    int h = strlen(str) - 1;
 
    while (h > l) {
        if (str[l++] != str[h--]) {
            return 0;
        }
    }
 	return 1;
}

void main(){
    int s,len;
    char smsg[100],rmsg[100];
    struct sockaddr_in server,client;
    
    s = socket(AF_INET,SOCK_DGRAM,0);
    
    server.sin_family = AF_INET;
    server.sin_port = htons(3000);
    server.sin_addr.s_addr=htonl(INADDR_ANY);

    bind(s,(struct sockaddr*)&server, sizeof(server));

    len = sizeof(client);


    while(1){
        recvfrom(s,rmsg,100,0,(struct sockaddr*)&client, &len);
        if (strcmp(smsg,"quit")==0 || strcmp(rmsg,"quit")== 0)
        	exit(0);
        printf("Message from client: %s\n",rmsg);

        if (pali(rmsg))
            strcpy(smsg,"PALINDROME\n");
        else
            strcpy(smsg,"NOT PALINDROME\n");

        sendto(s,smsg,100,0,(struct sockaddr*)&client,len);
        if (strcmp(smsg,"quit")==0 || strcmp(rmsg,"quit")== 0)
        	exit(0);
    }
}

    