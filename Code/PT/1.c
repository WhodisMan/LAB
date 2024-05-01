#include<stdio.h>

void main(){
    int num,n,temp,count=0,odd=0,even=0,ans=0;
    scanf("%d",&num);
    temp = num;

    while(temp!=0){
        n = temp%10;
        count++;
        if (n % 2 == 0)
            even = even*10 + n;
        else
            odd = odd*10 + n;
        temp /= 10;
    }

    while(num!=0){
        if (even != 0){
            ans = ans * 10 + (even%10);
            even/=10;
        }
        if (odd != 0){
            ans = ans * 10 + (odd%10);
            odd/=10;
        }
        num/=10;
    }
    printf("%d",ans);
       
}