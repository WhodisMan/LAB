#include <stdio.h>
#include <string.h>


void slice(const char* str, char* result, size_t start, size_t end) {
    strncpy(result, str + start, end - start);
}


void main(){

    char str1[100],str2[100];
    int i = 0;

    strcpy(str1,"Frame 1\n");

    printf("%s",str1);

    slice(str1,str2,6,100);

    printf("%s",str2);

    sscanf(str2,"%d",&i);
    i++;
    printf("%d",i);
}
