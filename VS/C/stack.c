#include<stdio.h>

const int max = 20;
int stack[20],top = -1,val;

void push()
{
    if (top == max-1) 
        printf("Stack Overflow\n");
    else
    {
        top++;
        printf("Enter Element : ");
        scanf("%d",&val);
        stack[top] = val;
    }
}

void pop()
{
    if (top == -1)
        printf("Stack Underflow\n");
    else
    {
        val = stack[top];
        top--;
        printf("Poped Element = %d\n",val);
    }
}

void display()
{
    int i;
    printf("STACK = [");
    for (i=0;i<=top;i++)
    {
        printf("%d,",stack[i]);
    }
    printf("\b]\n");
}


void main()
{
    int run = 1,ans;
    printf("#### Program to perform operations on STACKS ####\n\n");
    while (run)
    {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter Code : ");
        scanf("%d",&ans);
        printf("\n");

        switch (ans)
        {
            case 1 : push();
                break;
            case 2 : pop();
                break;
            case 3 : display();
                break;
            case 4 : run = 0;
                printf("BYE");
                break; 
        }
    }
}