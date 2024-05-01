#include<stdio.h>

int main(){
    int a[10],len,rr,n;
    printf("Enter Size of the array : ");
    scanf("%d",&len);
    printf("Enter the Array \n");
    for (int i=0;i<len;i++)
        scanf("%d",&a[i]);
    printf("Enter right shift value : ");
    scanf("%d",&rr);

    n = rr;

    for(int j=0;j<n;j++){
        int temp =  a[(len-1)];
        for(int i=len-2;i>=0;i--){
            a[i+1] = a[(i)];
        }
        a[0] = temp;
    }

    for(int i=0;i<len;i++)
        printf("%d ",a[i]);
}