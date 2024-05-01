#include<stdio.h>
#include<string.h>



void space(int n){
    for(int x=0;x<n;x++)
        printf(" ");
}

void main(){
    char str[] = "hello";

    int len = strlen(str);
    int mid = len/2;
    

    int width = len;
    int linecount = 1;
    for(int i=0;i<len;i++){
        space(width);
        for(int j=0;j<linecount;j++)
            printf("%c ",str[(mid+j)%len]);
        printf("\n");
        linecount++;
        width--;
    }


}