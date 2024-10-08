#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdbool.h>
#include <ctype.h>

char digit[20][20];
int digiti = 0;

char string[20][50];
int stringi = 0;

char keyword[20][10];
int keywordi = 0;

char operator[20][1];
int operatori = 0;

char punctuator[20][1];
int punctuatori = 0;

char identifier[20][10];
int identifieri = 0;

bool isValidDelimiter(char ch) {
   if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
   ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
   ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
   ch == '[' || ch == ']' || ch == '{' || ch == '}' || 
   ch == '\n' || ch == '&')
   return (true);
   return (false);
}


bool isKeyword(char* str){
    if (!strcmp(str,"if") || !strcmp(str,"else") || !strcmp(str,"while") ||
        !strcmp(str,"do") || !strcmp(str,"break") || !strcmp(str,"continue") ||
        !strcmp(str,"int") || !strcmp(str,"double") || !strcmp(str,"float") || 
        !strcmp(str,"return") || !strcmp(str,"char") || !strcmp(str,"case") || 
        !strcmp(str,"long") || !strcmp(str,"sizeof") || !strcmp(str,"void") ||
        !strcmp(str,"switch") || !strcmp(str,"struct") || !strcmp(str,"goto") ||
        !strcmp(str,"static") || !strcmp(str,"unsigned") )
            return(true);
        return(false);
}

bool isOperator(char ch){
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
     ch == '>' || ch == '<' || ch == '=' || ch == '&')
        return(true);
    return(false);
}

bool isPunctuator(char ch){
    if (ch == ',' || ch == ';' || ch == '(' || ch == ')' ||
     ch == '[' || ch == ']' || ch == '{' || ch == '}')
        return(true);
    return(false);
}

void readfile(char *filename){
    FILE *fptr;

    char a[50];
    strcpy(a,"");
    
    fptr = fopen(filename,"r+");
    
    char ch = fgetc(fptr);
   
    
    while(ch != EOF){
        strcpy(a,"");
        while(!isValidDelimiter(ch)){
            if (ch == '"'){
                strncat(a,&ch,1);
                ch = fgetc(fptr);
                while(ch != '"'){
                    strncat(a,&ch,1);
                    ch = fgetc(fptr);
                }
                strncat(a,&ch,1);
                strcpy(string[stringi++],a);

                strcpy(a,"");
                break;
            }
            strncat(a,&ch,1);
            ch = fgetc(fptr);
        }
        if (strcmp(a,"")){

            if (isdigit(a[0])){
                strcpy(digit[digiti++],a);
            }
            else if (!isKeyword(a))
                strcpy(identifier[identifieri++],a);
        }
        if (isKeyword(a)){
            strcpy(keyword[keywordi++],a);
        }
        else if (isOperator(ch)){
            strncat(operator[operatori++],&ch,1);
        }
        else if (isPunctuator(ch)){
            strncat(punctuator[punctuatori++],&ch,1);
        }            

        ch = fgetc(fptr);
    }
}

void print_string(){
    printf("LITERALS : ");
    for (int i=0;i<stringi;i++){
        printf("%s, ",string[i]);
    }
    printf("\n");
}

void print_digit(){
    printf("DIGITS : ");
    for (int i=0;i<digiti;i++){
        printf("%s, ",digit[i]);
    }
    printf("\n");
}

void print_operator(){
    printf("OPERATORS : ");
    for (int i=0;i<operatori;i++){
        printf("%c, ",operator[i][0]);
    }
    printf("\n");
}

void print_punctuator(){
    printf("PUNCTUATORS : ");
    for (int i=0;i<punctuatori;i++){
        printf("%c, ",punctuator[i][0]);
    }
    printf("\n");
}

void print_keyword(){
    printf("KEYWORDS : ");
    for (int i=0;i<keywordi;i++){
        printf("%s, ",keyword[i]);
    }
    printf("\n");
}

void print_identifier(){
    printf("IDENTIFIERS : ");
    for (int i=0;i<identifieri;i++){
        printf("%s, ",identifier[i]);
    }
    printf("\n");
}

// TOKENS
// - Keyword
// - Identifiers 
// - Operator
// - Literal
// - puctuators


void main(){
    char *filename;
    //printf("Enter filename : ");
   // scanf("%s",filename);
    readfile("sum.txt");
    print_string();
    print_digit();
    print_operator();
    print_keyword();
    print_punctuator();
    print_identifier();
 
}