#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *head,*ptr,*temp,*prev;

void display(){
    printf("[");
    ptr = head;
    if (head == NULL){
        printf("Empty List ");
    }
    else{
        while(ptr != NULL){
            printf("%d,",ptr -> data);
            ptr = ptr -> link;
        }
    }
    printf("\b]\n");
}

void insertF(int val){
    temp = (struct node *)malloc(sizeof(struct node));
    
    temp -> data = val;
    temp -> link = head;
    head = temp;
}


void insertE(int val){
    temp = (struct node *)malloc(sizeof(struct node));

    temp -> data = val;
    temp -> link = NULL;
    ptr = head;
    if (head == NULL){
        head = temp;
    }
    else{
        while( ptr -> link != NULL){
            ptr = ptr -> link;
        }
        ptr -> link = temp;
    }
}

void insertA(int val,int pos){
    temp = (struct node *)malloc(sizeof(struct node));

    temp -> data =val;
    ptr = head;
    
    while(ptr != NULL && ptr -> data != pos){
         prev = ptr;
         ptr = ptr -> link;
    }

    if (ptr == NULL){
        printf("Element not found\n");
    }
    else{
        prev -> link = temp;
        temp -> link = ptr;
    }
}

void deleteF(){
    if (head == NULL){
        printf("Empty List\n");
    }
    else{
        ptr = head;
        head = ptr -> link;
        free(ptr);
    }
}

void deleteE(){
    if (head == NULL){
        printf("Empty List\n");
    }
    else if(head -> link == NULL){
        free(head);
        head = NULL;
    }
    else{
        ptr = head;
        while( ptr -> link != NULL){
            prev = ptr;
            ptr = ptr -> link;
        }
        prev -> link = NULL;
        free(ptr);
    }
}

void deleteA(int pos){
    if (head == NULL){
        printf("Empty List\n");
    }
    else{
        ptr = head;
        
        while(ptr != NULL && ptr -> data != pos){
            prev = ptr;
            ptr = ptr -> link;
        }
        if (ptr == NULL){
            printf("Element Not Found\n");
        }
        else{
            if (head -> data == pos){
                deleteF();
            }
            else{
                prev -> link = ptr -> link;
                free(ptr);
            }
        }
    }
}

int get(){
    int num;
    printf("Enter Element : ");
    scanf("%d",&num);
    return num;
}

void main(){
    head = NULL;
    
    int ans,run = 1,num,pos;
    while(run){
        printf("### MENU ###\n1.Display\n2.Insert at Front\n3.Insert at End\n4.Insert at Data\n5.Delete form Front\n6.Delete from End\n7.Delete given Data\n0.Exit\n>>> ");
        scanf("%d",&ans);

        switch(ans){
            case 1:
                display();
                break;
            case 2:
                num = get();
                insertF(num);
                display();
                break;
            case 3:
                num = get();
                insertE(num);
                display();
                break;
            case 4:
                num = get();
                printf("Enter value to insert at  :");
                scanf("%d",&pos);
                insertA(num,pos);
                display();
                break;
            case 5:
                deleteF();
                display();
                break;
            case 6:
                deleteE();
                display();
                break;
            case 7:
                num = get();
                deleteA(num);
                display();
                break;
            case 0:
                run = 0;
                display();
                break;
            default :
                printf("INVALID\n");
                break;
        }
    }
}
