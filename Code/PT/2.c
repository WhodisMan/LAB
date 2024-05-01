#include<stdio.h>
#include<math.h>


//123456
//321456

void main(){
    int num,n,temp,count,place,ans=0,rem,rdigit=1;
    scanf("%d%n",&num,&count);
    place = 3;
    int digit=pow(10,count-1);
    while(place != 0){
        rem = num/digit;
        ans = ans+rem*rdigit;

        num = num %digit;
        digit /= 10;
        rdigit *= 10;
        place--;
    }
    ans = ans*digit*10+num;

    printf("ans = %d",ans);

   
}