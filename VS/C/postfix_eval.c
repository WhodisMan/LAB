#include <stdio.h>
#include<string.h>

int max = 30;


struct str_stacks
{
    char stack[30];
    int top;
    int max;
    char name[30];
};

struct int_stacks
{
    int stack[30];
    int top;
    int max;
    char name[30];
};

//function to return the length of a string.
int length(char *stack)
{
    int len;
    for (len=0;stack[len]!='\0';len++)
    {
        continue;
    }
    return len;
}

void push(int stack[],int element,int *top)
{
    if (*top == max-1) 
        printf("Stack Overflow\n");
    else
    {
        *top = *top + 1;
        stack[*top] = element;
    }
}

void display(int stack[],int*top)
{
    int i;
    printf("STACK = [");
    for (i=0;i<=*top;i++)
    {
        printf("%d,",stack[i]);
    }
    printf("\b]\n");
}

int pop(int stack[],int *top)
{
    if (*top == -1)
        printf("Stack Underflow\n");
    else
    {
        int element = stack[*top];
        *top = *top - 1;
        return element;
    }
}

void main()
{
    int x;

    struct str_stacks input = {"",-1,max,"INPUT"};
    struct int_stacks storage = {{},-1,max,"STACK"};

    printf("Enter the Postfix Expression : ");
    scanf("%s",input.stack);

    input.top = length(input.stack) - 1;

    for (x=0;x <=input.top;x++)
    {
        char ele = input.stack[x];
        if ((ele >= 'a' && ele<= 'z') || ele >= 'A' && ele <='Z')
        {
            int num;

            printf("Enter Value for %c : ",ele);
            scanf("%d",&num);

            push(storage.stack,num,&storage.top);
        }
        else if (ele=='+'||ele=='-'||ele=='*'||ele=='/'||ele=='^')
        {
            int num1,num2;

            num1 = pop(storage.stack,&storage.top);
            num2 = pop(storage.stack,&storage.top);

            int ans;

            switch (ele)
            {
            case '+':
                ans = num2 + num1;
                break;
            case '-':
                ans = num2 - num1;
                break;
            case '*':
                ans = num2 * num1;
                break;
            case '/':
                ans = num2 / num1;
                break;
            case '^':
                ans = num2 ^ num1;
                break;
            }
            push(storage.stack,ans,&storage.top);
        }
    }
    printf("answer = %d",storage.stack[0]);
    
}