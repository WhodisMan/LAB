%{
#include<stdio.h>
#include<string.h>
char key[100][100],head[100][100],dig[100][100],op[100][100],id[100][100],lit[100][100];
int i=0,j=0,k=0,l=0,a=0,b=0,c=0,d=0,m=0,n=0,sz=0,count=0;
%}
KW "int"|"while"|"if"|"else"|"for"|"char"|"float"|"case"|"switch"|"printf"|"scanf"|"void"
HF "#include<".*">"
OP "+"|"-"|"*"|"/"|"="
DIG [0-9]*|[0-9]*"."[0-9]+
ID [a-zA-Z][a-zA-Z0-9]*
LI "\"".*"\""
%%
{KW} {strcpy(key[i],yytext);i++;}
{HF} {strcpy(head[j],yytext);j++;}
{DIG} {strcpy(dig[k],yytext);k++;}
{OP} {strcpy(op[sz],yytext);sz++;}
{ID} {strcpy(id[n],yytext);n++;}
{LI} {strcpy(lit[count],yytext);n++;}
. {}
%%
int main()
{
    yyin=fopen("input.txt","r+");
    yylex();
    printf("\nThe keywords :\n");
    for(b=0;b<i;b++) 
    {  
        for(m=b+1;m<i;m++)  
        {  
            if(strcmp(key[b],key[m])==0)  
            { 
                for(c=m;c<i-1;c++)  
                {  
                    strcpy(key[c],key[c+1]);  
                }  
                i--;  
                m--;
            }  
        }  
    }
    for(a=0;a<i;a++)
    {
        printf("%s\n",key[a]);
    }
    printf("\nThe headerfile :\n");
    for (a=0;a<j;a++)
    {
        printf("%s\n",head[a]);
    }

    printf("\nThe digits :\n");
    for(a=0;a<k;a++)
    {
        printf("%s\n",dig[a]);
    }
    printf("\nOperators :\n");
    for(b=0;b<sz;b++) 
    {  
        for(m=b+1;m<sz;m++)  
        {  
            if(strcmp(op[b],op[m])==0)  
            { 
                for(c=m;c<sz-1;c++)  
                {  
                    strcpy(op[c],op[c+1]);  
                }  
                sz--;  
                m--;
            }  
        }  
    }
    for (a=0;a<sz;a++)
    {
        printf("%s\n",op[a]);
    }
    printf("\nIdentifiers :\n");
    for(b=0;b<n;b++) 
    {  
        for(m=b+1;m<n;m++)  
        {  
            if(strcmp(id[b],id[m])==0)  
            { 
                for(c=m;c<n-1;c++)  
                {  
                    strcpy(id[c],id[c+1]);  
                }  
                n--;  
                m--;
            }  
        }  
    }
    for(a=0;a<n;a++)
    {
        printf("%s\n",id[a]);
    }
}
int yywrap()
{
    return 1;
}
