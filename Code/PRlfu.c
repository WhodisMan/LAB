#include<stdio.h>
void print(int frameno,int frame[]){
    int j;
    for(j=0;j<frameno;j++)
        printf("%d\t",frame[j]);
    printf("\n");
}

int main(){
    int i,j,k,n,page[50],frameno,frame[10],move=0,flag,count=0,count1[10]={0},repindex,leastcount;
    float rate;
    printf("Number Of Pages = ");
    scanf("%d",&n);
    printf("Page Reference Numbers >> ");
    for(i=0;i<n;i++)
        scanf("%d",&page[i]);
    printf("Number Of Frames = ");
    scanf("%d",&frameno);
    for(i=0;i<frameno;i++)
        frame[i]=-1;
    printf("Page Reference String\tFrames\n");
    for(i=0;i<n;i++){
        printf("%d\t\t\t",page[i]);
        flag=0;
        for(j=0;j<frameno;j++){
            if(page[i]==frame[j]){
                flag=1;
                count1[j]++;
                printf("No Replacement\n");
                break;
            }
        }
        if(flag==0&&count<frameno){
            frame[move]=page[i];
            count1[move]=1;
            move=(move+1)%frameno;
            count++;
            print(frameno,frame);
            }
        else if(flag==0){
            repindex=0;
            leastcount=count1[0];
            for(j=1;j<frameno;j++){
                if(count1[j]<leastcount){
                    repindex=j;
                    leastcount=count1[j];
                }
            }
            frame[repindex]=page[i];
            count1[repindex]=1;
            count++;
            print(frameno,frame);
        }
    }
    rate=(float)count/(float)n;
    printf("Number Of Page Faults = %d\n",count);
    printf("Fault Rate = %f\n",rate);
    return 0;
}
