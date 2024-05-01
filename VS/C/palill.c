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

void rev_cpy(struct node **list, struct node **rev){

    struct node *a;
    a = *list;
    while (a != NULL){
        insertF(&(*rev),a->data);
        a = a -> link;
    }
}

void cmp(struct node **list1, struct node **list2){
    struct node *ptr1, *ptr2;

    ptr1 = *list1;
    ptr2 = *list2;

    while(ptr1 != NULL && ptr2 != NULL && ptr1 -> data == ptr2 -> data){
        ptr1 = ptr1 -> link;
        ptr2 = ptr2 -> link;
    }

    if (ptr1 == ptr2){
        printf("PALINDROME\n");
    }
    else{
        printf("NOT PALINDROME\n");
    }

}

void main(){
    struct node *list1 = NULL,*list2 = NULL;
    int temp,len,ele,i;


    printf("Enter the length of the list : ");
    scanf("%d",&len);

    // loop to input elements

    for (i = 1; i <= len; i++){
        printf("Enter Element %d : ",i);
        scanf("%d",&ele);

        insertE(&list1,ele);
    }
    display(&list1);
    rev_cpy(&list1,&list2);
    display(&list2);

    cmp(&list1,&list2);

}