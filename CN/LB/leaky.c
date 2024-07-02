#include <stdio.h>

void main(){

    int bucket_size,num_packets,out_rate,in_packets,drop=0,status=0;


    printf("Enter the Bucket Size : ");
    scanf("%d",&bucket_size);
    printf("Enter the number of iterations : ");
    scanf("%d",&num_packets);
    printf("Enter the outgoing packet rate : ");
    scanf("%d",&out_rate);

    for (int i=0;i<num_packets;i++){
        printf("\n");
        printf("Enter the incoming packet size : ");
        scanf("%d",&in_packets);
        
        status = status + in_packets;
        if (status > bucket_size){
            drop = status - bucket_size;
            status = bucket_size;
            printf("Dropped packets : %d\n",drop);
        }

        printf("Before outgoing Bucket status : %d out of %d\n",status,bucket_size);
        
        if (status > out_rate)
            status = status - out_rate;
        else
            status = 0;

        printf("After outgoing Bucket status : %d out of %d\n",status,bucket_size);
        
    }

}