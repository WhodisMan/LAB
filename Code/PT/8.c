#include<stdio.h>

int main(){
    int len,r;
    char ch;
    printf("Enter Size of the array : ");
    scanf("%d",&len);
    int a[len];
    printf("Enter the Array \n");
    for (int i=0;i<len;i++)
        scanf("%d",&a[i]);

    printf("Enter shift value : ");
    scanf(" %c %d",&ch,&r);

    if (ch == 'l'){
        for(int j=0;j<r;j++){
            int temp =  a[0];
            for(int i=0;i<len-1;i++){
                a[i] = a[(i+1)];
            }
            a[(len-1)] = temp;
        }
    }
    else{
        for(int j=0;j<r;j++){
        int temp =  a[(len-1)];
        for(int i=len-2;i>=0;i--){
            a[i+1] = a[(i)];
        }
        a[0] = temp;
    }
    }

    for(int i=0;i<len;i++)
        printf("%d ",a[i]);
}