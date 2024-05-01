#include<stdio.h>


struct Queue
{
    int front; 
    int rear;
    int size;
    int array[100];
};


void enqueue(int queue[],int item,int *rear,int *size)
{
    if (*rear == *size-1)
    {
        printf("Overflow\n");
    }
    else
    {
        *rear = *rear + 1;
        queue[*rear] = item;
    } 
}

int dequeue(int queue[],int *rear,int *front)
{
    if (*front > *rear)
    {
        printf("Underflow");
    }
    else
    {
        int item = queue[*front];
        *front = *front + 1;
        return item;
    }

}

void display(int queue[],int *rear,int *front)
{
    printf("QUEUE = [");
    for (int i = *front ; i<*rear ; i++)
    {
        printf("%d,",queue[i]);
    }
    if (*front != *rear)
        printf("\b");
    printf("]\n");
}

void main()
{
    struct Queue Q = {0,-1,30,{}};
    int item;
    
/*
    enqueue(Q.array,1,&Q.rear,&Q.size);
    display(Q.array,&Q.rear,&Q.front);
    enqueue(Q.array,2,&Q.rear,&Q.size);
    display(Q.array,&Q.rear,&Q.front);
    enqueue(Q.array,3,&Q.rear,&Q.size);
    display(Q.array,&Q.rear,&Q.front);
    enqueue(Q.array,5,&Q.rear,&Q.size);
    display(Q.array,&Q.rear,&Q.front);
    item = dequeue(Q.array,&Q.rear,&Q.front);
    printf("%d\n",item);
    display(Q.array,&Q.rear,&Q.front);
    item = dequeue(Q.array,&Q.rear,&Q.front);
    printf("%d\n",item);
    display(Q.array,&Q.rear,&Q.front);
*/

    printf("Enter the ");
    

}