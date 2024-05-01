#include<stdio.h>

void main(){
    int size;
    printf("Enter Size : ");
    scanf("%d",&size);
    int a[size];
    printf("Enter the values \n");
    for(int i=0;i<size;i++)
        scanf("%d",&a[i]);
    
    int count[size/2];
    int value[size/2];

    for(int i=0;i<(size/2);i++){
        value[i]=0;
        count[i]=1;
    }
    int index=0,flag=0;

    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(a[i] == a[j] && a[j] != -1){

                a[j] = -1;
                flag=1;
                value[index] = a[i];
                count[index]++;
            }
        }

            if (flag == 1)
                index++;
            flag=0;
    }

    for(int i=0;i<(size/2);i++)
       if (count[i] > 1)
            printf("%d->%d\n",value[i],count[i]);
}

