/*
1. Push the left paranthesis into the stack and add a right paranthesis at the end of the input string Q.
2. Scan the expression from left to right and repeat steps 3 to 6 for each element of Q.
3. If the symbol is an operand then add it to the end of the output string P.
4. If the symbol is a left paranthesis then push it on to the stack.
5. If the symbol is an operator then -
    5.1 Reapeatedly pop the stack and add it to P for each operator which has the same or higher precedence than the incoming operator.
    5.2 Add the operator to the stack.
6. If the symbol is a right paranthesis then repeatedly pop the lements of the stack and add it to P untill a left paranthesis is reached and then pop the parethesis.
7. STOP
*/


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


// function to display the stack till top value.
void display(char* stack,int *top,char* name)
{
    int j;
    printf("%s = [",name);
    for (j=0 ; j <= *top ; j++)
    {
        printf("%c,",stack[j]);
    }
    if (*top != -1)
        printf("\b");
    printf("]\n");
}

// push funtion
void push(char *stack,char element,int *top)
{
    if (*top == max-1)
        printf("Stack Overflow\n");
    else
    {   
        // don't know why but top++; doesn't work
        *top = *top + 1;
        strncat(stack,&element,1);
    }
}

// pop function
char pop(char* stack,int *top)
{
    char element;
    if (*top == -1)
        printf("Stack Underflow\n");
    else
    {
        element = stack[*top];
        // same here top--; doesn't work
        *top = *top - 1;
        char test[30] = "";
        strncpy(test,stack,*top+1);
        strcpy(stack,test);
        return element;
    }

}

int precedence(char element)
{
    if ((element == '+')||(element == '-'))
        return 1;
    else if ((element == '*')||(element == '/'))
        return  2;
    else if (element == '^')
        return 3;
    else    
        return 0;

}

void main()
{
    int x,y;
    
    // structure definitions
    struct str_stacks input = {"",-1,max,"INPUT"};
    struct str_stacks storage = {"",-1,max,"STACK"};
    struct str_stacks output = {"",-1,max,"OUTPUT"};

    printf("Enter Input String : ");
    scanf("%s",input.stack);

    input.top = length(input.stack)-1;

    push(storage.stack,'(',&storage.top);
    push(input.stack,')',&input.top);
  
    for (x=0; x <=input.top ; x++)
    {
        char ele = input.stack[x]; 
        if ((ele >= 'a' && ele<= 'z') || ele >= 'A' && ele <='Z')
        {
            push(output.stack,ele,&output.top);
        }
        else if (ele == '(')
        {
                push(storage.stack,ele,&storage.top);
        }
        else if (ele == ')')
        {
            for (y = storage.top ; y >= 0 ; y--)
            {
                char temp = pop(storage.stack,&storage.top);
                if (temp != '(')
                {
                    push(output.stack,temp,&output.top);
                }
                else
                    break;
            }
        }
        else if (ele=='+'||ele=='-'||ele=='*'||ele=='/'||ele=='^')
        {
            while(precedence(storage.stack[storage.top]) >= precedence(ele))
            {
                char val = pop(storage.stack,&storage.top);
                push(output.stack,val,&output.top);
            }
            push(storage.stack,ele,&storage.top);
        }
        else
            printf("WTF\n");

    }

    printf("Postfix = %s",output.stack);

}
