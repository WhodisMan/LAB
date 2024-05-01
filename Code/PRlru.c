#include<stdio.h>
int main(){
    int nf,np,pages[100],frames[10],count[10],flag,min,next=0,i,j,k,fault=0;

    printf("Number Of Frames = ");
    scanf("%d",&nf);
    printf("Number Of Pages = ");
    scanf("%d",&np);
    printf("Pages >> ");

    for(i=0;i<np;i++)
        scanf("%d",&pages[i]);

    for(i=0;i<nf;i++){
        count[i]=0;
        frames[i]=-1;
    }
    for(i=0;i<np;i++){
        flag=0;
        for(j=0;j<nf;j++){
            if(frames[j]==pages[i]){
                flag=1;
                count[j]=next;
                next++;
            }
        }
        if(flag==0){
            if(i<nf){
                frames[i]=pages[i];
                count[i]=next;
                next++;
            }
            else{
                min=0;
                for(j=1;j<nf;j++)
                    if(count[min]>count[j])
                        min=j;
                    frames[min]=pages[i];
                    count[min]=next;
                    next++;
            }
            fault++;
        }
        for(j=0;j<nf;j++)
            printf("%d\t",frames[j]);
        if(flag==0)
            printf("PF no = %d",fault);
            printf("\n");
    }
    printf("Page Fault = %d\n",fault);
    return 0;
}
