#include <stdio.h>

int a[10] = {0};
void main(){
    for (int i =0; i<10;i++)
        scanf("%d",(a+i));
    for (int i =0; i<10;i++)
        printf("%d",*(a+i));
}
