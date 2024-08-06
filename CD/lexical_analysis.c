#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdbool.h>


bool isValidDelimiter(char ch) {
   if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
   ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
   ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
   ch == '[' || ch == ']' || ch == '{' || ch == '}')
   return (true);
   return (false);
}

void readfile(char *filename){
    FILE *fptr;

    char a[100];
    
    fptr = fopen(filename,"r+");
    
    char ch = fgetc(fptr);
    while (ch != EOF){
        ch = fgetc(fptr);
        if (isValidDelimiter(ch)){

        }
    }
}


// TOKENS
// - Keyword
// - Identifiers 
// - Operator
// - Literal
// - Special Symbol
// - Constants
// - string
// - character set


void main(){
    char *filename;
    //printf("Enter filename : ");
   // scanf("%s",filename);
    readfile("sum.txt");
}