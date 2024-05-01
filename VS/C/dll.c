#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

void insertF(struct node **head, int data){
    struct node *temp = (struct node*) malloc(sizeof(struct node));

    temp -> data = data;

    temp -> next = *head;
    temp -> prev = NULL;

    if ((*head) != NULL){
        (*head) -> prev = temp;
    }

    (*head) = temp;
}

void insertE(struct node **head, int data){
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    struct node *ptr = (*head);

    temp -> data = data;
    temp -> next = NULL;

    if (ptr == NULL){
        temp -> prev = NULL;
        (*head) = temp;
        return;
    }

    while (ptr -> next!= NULL){
        ptr = ptr -> next;
    }
    ptr -> next = temp;
    temp -> prev = ptr;
    return;
}

void insertA(struct node **head, int data, int val){

    struct node *ptr = (*head);

    if (ptr == NULL){
        printf("Empty List\n");
    }
    else{
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        temp -> data = data;

        while(ptr != NULL){
            if (ptr -> data == val){
                if (ptr -> next == NULL){
                    insertE(&(*head),data);
                    break;
                }
                else if(ptr -> prev == NULL){
                    insertF(&(*head),data);
                    break;
                }
                temp -> prev = ptr;
                temp -> next = ptr -> next;
                (ptr -> next) -> prev = temp;
                ptr -> next = temp;
                break;
            }
            ptr = ptr -> next;
        }
        if (ptr == NULL){
            printf("Element not found\n");
        }

    }
}

void deleteF(struct node **head){
    struct node *ptr = (*head);

    if (ptr == NULL){
        printf("Empty list\n");
    }
    ptr = ptr -> next;
    ptr -> prev = NULL;
    (*head) = ptr;
    
}

void deleteE(struct node **head){
    struct node *ptr = (*head);

    if (ptr == NULL){
        printf("Empty List\n");
    }

    else if (ptr -> next == NULL){
        (*head) = NULL;
    }
    else{
        while(ptr -> next != NULL){
            ptr = ptr -> next;
        }
        ptr = ptr -> prev;
        ptr -> next = NULL;
    }
}

void deleteA(struct node **head,int val){

    struct node *ptr = (*head);

    if (ptr == NULL){
        printf("Empty List\n");
    }
    else{
        while(ptr != NULL){
            if (ptr -> data == val){
                if (ptr -> next == NULL){
                    deleteE(&(*head));
                    break;
                }
                else if(ptr -> prev == NULL){
                    deleteF(&(*head));
                    break;
                }
                (ptr -> prev) -> next = ptr -> next;
                (ptr -> next) -> prev = ptr -> prev;
                free(ptr);
                break;
            }
            ptr = ptr -> next;
        }
        if (ptr == NULL){
            printf("Element not found\n");
        }

    }
}

void display(struct node **head){
    struct node *ptr = (*head);
    if ((*head) == NULL){
        printf("Empty List\n");
        return;
    }
    printf("[");
    while (ptr != NULL){
        //printf("%d <- %d -> %d,",ptr->prev,ptr->data,ptr->next);
        printf("%d,",ptr -> data);
        ptr = ptr->next;
    }
    printf("\b]\n");
}

int get(){
    int num;
    printf("Enter Element : ");
    scanf("%d",&num);
    return num;
}

void main(){
    struct node *list1 = NULL;

    int ans,run = 1,num,pos;
    while(run){
        printf("### MENU ###\n1.Display\n2.Insert at Front\n3.Insert at End\n4.Insert at Data\n5.Delete form Front\n6.Delete from End\n7.Delete given Data\n0.Exit\n>>> ");
        scanf("%d",&ans);

        switch(ans){
            case 1:
                display(&list1);
                break;
            case 2:
                num = get();
                insertF(&list1,num);
                display(&list1);
                break;
            case 3:
                num = get();
                insertE(&list1,num);
                display(&list1);
                break;
            case 4:
                num = get();
                printf("Enter value to insert at  :");
                scanf("%d",&pos);
                insertA(&list1,num,pos);
                display(&list1);
                break;
            case 5:
                deleteF(&list1);
                display(&list1);
                break;
            case 6:
                deleteE(&list1);
                display(&list1);
                break;
            case 7:
                num = get();
                deleteA(&list1,num);
                display(&list1);
                break;
            case 0:
                run = 0;
                display(&list1);
                break;
            default :
                printf("INVALID\n");
                break;
        }
    }
}