#include <stdio.h>


int a[] = {6,4,2,1};
int n = sizeof(a)/sizeof(a[0]);



void swap(int *p1,int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int partition(int l, int u)
{
    int pivot = a[u];
    int i = l-1;

    for (int j = l; j <= u ; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(&a[i],&a[j]);
        }
    } 
    swap(&a[i+1],&a[u]);
    return (i+1);  
    
}

void quicksort(int l,int u)
{
    if (l<u)
    {
        int j = partition(l,u);
        quicksort(l,j-1);
        quicksort(j+1,u);
    }
}

void print()
{
    printf("[");
    for (int i = 0; i < n ; i++)
    {
        printf("%d,",a[i]);
    }
    printf("\b]\n");
}


void main()
{
    print();
    quicksort(0,n);
    print();
}