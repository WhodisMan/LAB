#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
     FILE *fp1;
     fp1 = fopen("length.txt","r");
     char a[20];
     char b[20];
 
     fscanf(fp1,"%s",a);
     fscanf(fp1,"%s",b);

     int temp = atoi(b);
     itoa(temp,b,16);

     printf("%d %s %s ",temp,a,b);
     fclose(fp1);
}