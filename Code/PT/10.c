#include<stdio.h>

void main(){
    int size;
    printf("Enter Size : ");
    scanf("%d",&size);
    int a[size];
    printf("Enter the values \n");
    for(int i=0;i<size;i++)
        scanf("%d",&a[i]);

    int unique[size],idx=0,flag=0;

    for(int i=0;i<size;i++){
        for(int j=0;j<idx;j++){
            if (a[i] == unique[j])
                flag = 1;
        }
        if (flag == 0){
            unique[idx] = a[i];
            idx++;
        }
        flag = 0;
    }

    int counts[size];
    for(int i=0;i<idx;i++){
        int count=0;
        for(int j=0;j<size;j++){
            if (a[j] == unique[i])
                count++;

        }
        counts[i] = count;
    }

    for(int i=0;i<idx;i++)
        if(counts[i] == 1)
            printf("%d ",unique[i]);
    
}