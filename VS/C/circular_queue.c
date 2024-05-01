#include <stdio.h>
#define MAX 10


int Q[MAX];
int f = -1,r=-1;

int isFull()
{
    if(f == (r + 1) % MAX)
        return 1;
    return 0;
}

int isEmpty()
{
    if(f == -1 && r == -1)
        return 1;
    return 0;
}

void display()
{
    int i;
    if (isEmpty())
        printf("Empty Q\n");
    else
    {
        printf("Q = [");
        for (i = f; i != r; i = (i+1) % MAX)
        {
            printf("%d,",Q[i]);
        }
        printf("%d]",Q[i]);
        
    }
}

void enQ()
{
    int item;
    if (isFull())
        printf("Overflow\n");
    else
    {
        printf("Enter item : ");
        scanf("%d",&item);
        if (f == -1 )
            f = 0;
        r = (r + 1) % MAX;
        Q[r] = item;
        printf("%d inserted\n",item);
    }
}

int deQ()
{
    int item;
    if (isEmpty())
    {
        printf("Empty Q\n");
        return(-1);
    }
    else
    {
        item = Q[f];
        if (f == r)
        {
            f = -1;
            r = -1;
        }
        else
        {
            f = (f + 1 ) % MAX;
        }
        printf("\nDeleted => %d",item);
        return item;
    }
}

void main() 
{
    int ans,run = 1;
    while (run)
    {
        printf("\n#####MENU#####\n1.Display\n2.Enqueue\n3.Dequeue\n4.Exit\n");
        scanf("%d",&ans);

        switch (ans)
        {
        case 1:
            display();
            break;
        case 2:
            enQ();
            break;
        case 3:
            deQ();
            break;
        case 4:
            run = 0;
            break;
        }
    }
    
}