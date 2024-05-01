#include<stdio.h>
#include<string.h>

char input[20],stack[20],output[20];
int top=-1,max=20;

void push(char *str ,char a)
{
    if (top == max-1)
        printf("Stack Overflow\n");
    else
        top++;
        strncat(str,&a,1);
}

void display(char* str)
{
    int j;
    printf("Stack = [");
    for (j=0;str[j]!='\0';j++)
    {
        printf("%c,",str[j]);
    }
    printf("\b]\n");
}

char pop(char *str)
{
    char a;
    if (top == -1)
        printf("Stack Underflow\n");
    else
    a = str[top];
    top--;
    return a;
}

int length(char *str)
{
    int len;
    for (len=0;str[len]!='\0';len++)
    {
        continue;
    }
    return len;
}

void main()
{  
    int i;

    // input string   
    printf("Enter String : ");
    scanf("%s",input);
 
    int len = length(input);

    for (i=0;i<len;i++)
    {
        char lol = input[i];
        printf("%c\n",lol);
        push(stack,lol);
        display(stack);
    }
    display(stack);
}
