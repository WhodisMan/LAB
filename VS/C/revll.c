#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *ptr,*temp;

void display(struct node **head){
    printf("[");
    ptr = *head;
    if (*head == NULL){
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


void insertF(struct node **head,int val){
    temp = (struct node *)malloc(sizeof(struct node));
    
    temp -> data = val;
    temp -> link = *head;
    *head = temp;
}

void insertE(struct node **head,int val){
    temp = (struct node *)malloc(sizeof(struct node));

    temp -> data = val;
    temp -> link = NULL;
    ptr = *head;
    if (*head == NULL){
        *head = temp;
    }
    else{
        while( ptr -> link != NULL){
            ptr = ptr -> link;
        }
        ptr -> link = temp;
    }
}

int deleteF(struct node **head){
    if (*head == NULL){
        printf("Empty List\n");
    }
    else{
        ptr = *head;
        *head = ptr -> link;
        return ptr -> data;

    }
}

void main(){
    struct node *list1 = NULL,*list2 = NULL;
    int temp,len,ele,i;


    printf("Enter the length of the list : ");
    scanf("%d",&len);

    for (i = 1; i <= len; i++){
        printf("Enter Element %d : ",i);
        scanf("%d",&ele);

        insertE(&list1,ele);
    }
    display(&list1);
    //rev

    for (i = 0; i < len; i++){
        temp = deleteF(&list1);
        insertF(&list2,temp);
    }
    display(&list1);
    display(&list2);

    
}