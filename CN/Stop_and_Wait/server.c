#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main(){
    int s,len;
    char smsg[100],rmsg[100];
    struct sockaddr_in server,client;


    int frame=0, in_frame=0;
    char info[100],str1[100],str2[100];
    
    s = socket(AF_INET,SOCK_DGRAM,0);
    
    server.sin_family = AF_INET;
    server.sin_port = htons(3000);
    server.sin_addr.s_addr=htonl(INADDR_ANY);

    bind(s,(struct sockaddr*)&server, sizeof(server));

    len = sizeof(client);


    while(1){

        frame++;
        sprintf(str1,"%d",frame);

        recvfrom(s,rmsg,100,0,(struct sockaddr*)&client, &len);
        if (strcmp(smsg,"quit")==0 || strcmp(rmsg,"quit")== 0)
        	exit(0);

        printf("Message from client: %s\n",rmsg);
        sscanf(rmsg,"%d",&in_frame);
        
        
        if (in_frame == frame){
            printf("Frame %d Recieved\n",in_frame);
            strcpy(smsg,rmsg);
            sendto(s,smsg,100,0,(struct sockaddr*)&client,len);
        }
        else{
            frame--;
            printf("Frame number missmatch\n");
            strcpy(smsg,"Resend Frame ");
            strcat(smsg,str1);
            sendto(s,smsg,100,0,(struct sockaddr*)&client,len);
        }

    }
    

    close(s);
}
