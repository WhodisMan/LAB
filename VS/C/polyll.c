#include<stdio.h>
#include<stdlib.h>

struct node
{
    int exp;
    int coef;
    struct node *link;
};

void display(struct node **head){
    struct node *ptr;

    printf("Polynomial = ");
    ptr = *head;
    if (*head == NULL){
        printf("Empty List ");
    }
    else{
        while(ptr != NULL){
            printf("%dx^%d+",ptr -> coef, ptr -> exp);
            ptr = ptr -> link;
        }
    }
    printf("\b \n");
}

void insertE(struct node **head, int coef, int exp){

    struct node *ptr,*temp = (struct node *)malloc(sizeof(struct node));
    temp -> exp = exp;
    temp -> coef = coef;
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

void multi(struct node **head, int num){
    struct node *ptr = *head;

    if (*head != NULL){
        while( ptr != NULL){
            ptr -> coef = ptr -> coef * num;
            ptr = ptr -> link;
        }
    }
}

void main(){

    struct node *list = NULL;
    int len,coef,exp,i,num;

    printf("Enter the length of the list : ");
    scanf("%d",&len);

    for (i = 1; i <= len; i++){
        printf("Enter Coefficitent for element %d : ",i);
        scanf("%d",&coef);
        printf("Enter Exponent for element %d : ",i);
        scanf("%d",&exp);

        insertE(&list,coef,exp);
    }

    display(&list);

    printf("Enter the constant : ");
    scanf("%d",&num);
    multi(&list,num);

    display(&list);

}