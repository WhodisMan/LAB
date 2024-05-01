#include<stdio.h>
#define MAX 15


// Hash function used is k mod h where h = 10

int getKey(int val){
    int key = val % 10;
    return key;
}


void defEmpty(int a[],int n){
    for (int i = 0; i < n; i++)
        a[i] = -1;
    
}

void insert(int a[],int n, int val){
    int key = getKey(val);
    if (a[key] == -1)
        a[key] = val;
    else {
        for (int i = key+1; i < n; i++){
            if (a[i] == -1)
                a[i] = val;
                break;
        }

    }
}

void search(int a[],int n,int val){
    int key = getKey(val);
    int flag = 0;

    if (a[key] == val){
        flag = 1;
        printf("Element found at index : %d\n",key);
    }
    else{
        for (int i = key+1; i < n; i++){
            if (a[i] == val){
                flag = 1;
                printf("Element found at index : %d\n",i);
                break;
            }
        }
    }
    if (flag == 0)
        printf("Element not found\n");
}

void display(int a[],int n){
    if (n == 0)
        printf("Empty Table\n");
    else{
        printf("[");
        for (int i = 0; i < n ; i++)
            printf("%d,",a[i]);
        printf("\b]\n");
    }
}

void main(){
    int a[MAX],val,ans, run=1;
    defEmpty(a,MAX);
    
    printf("### Program to impement a hash table ###\n");
    
    while (run){
        printf("### MENU ###\n1.Display table\n2.Insert Element\n3.Search Element\n0.Exit\n-----> : ");
        scanf("%d",&ans);

        switch (ans)
        {
        case 1:
            display(a,MAX);
            break;
        case 2:
            printf("Enter Element : ");
            scanf("%d",&val);
            insert(a,MAX,val);
            break;
        case 3:
            printf("Enter Element : ");
            scanf("%d",&val);
            search(a,MAX,val);
        case 0:
            run = 0;
            break;
        default:
            printf("Invalid");
            break;
        }
    }

}