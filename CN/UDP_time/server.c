#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>

void get_time(char *str)
{
  time_t t = time(&t);

  sprintf(str,"%s",ctime(&t));
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

        if (strcmp(rmsg,"Time")==0 || strcmp(rmsg,"time")== 0 || strcmp(rmsg,"TIME")== 0){
            get_time(smsg);
        }
        else{
            printf("Message to client: ");
            gets(smsg);
        }

        sendto(s,smsg,100,0,(struct sockaddr*)&client,len);
        if (strcmp(smsg,"quit")==0 || strcmp(rmsg,"quit")== 0)
        	exit(0);
    }
}


    