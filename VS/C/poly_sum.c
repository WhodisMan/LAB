#include <stdio.h>
#include <stdlib.h>

struct poly{
    int coef;
    int exp;
    struct poly *link;
    };

void insert(struct poly **head, int coef, int exp){
    
    struct poly *temp = (struct poly*)malloc(sizeof(struct poly));
    struct poly *ptr = (*head);

    temp -> coef = coef;
    temp -> exp = exp;
    temp -> link = NULL;

    if (ptr == NULL){
        (*head) = temp;
    }
    else{
        while( ptr -> link != NULL){
            ptr = ptr -> link;
        }
        ptr -> link = temp;
    }
} 

void new_poly(struct poly **head){
    
    int n,i,coef,exp;

    printf("Enter number of Terms in the polynomial : ");
    scanf("%d",&n);

    for(i=1 ; i<=n ; i++){
        printf("Enter coefficient for term(%d) : ",i);
        scanf("%d",&coef);
        printf("Enter exponent for term(%d) : ",i);
        scanf("%d",&exp);

        insert(&(*head),coef,exp);
    }
}

void display(struct poly **head){

    struct poly *ptr = (*head);


    if (ptr == NULL){
        printf("Empty List ");
    }
    else{
        while(ptr != NULL){
            printf(" %dx",ptr -> coef);
            printf("^%d ",ptr -> exp);
            printf("+");
            ptr = ptr -> link;
        }
        printf("\b \n");
    }
}   

void add(struct poly **h1, struct poly **h2, struct poly **h3){
    struct poly *ptr1 = (*h1), *ptr2 = (*h2), *ptr3 = (*h3);

    while((ptr1 != NULL) && (ptr2 != NULL)){
        if ((ptr1 -> exp) == (ptr2 -> exp)){
            insert(&(*h3), ((ptr1 -> coef) + (ptr2 -> coef)), ptr1 -> exp);
            ptr1 = ptr1 -> link;
            ptr2 = ptr2 -> link;
        }
        else if ((ptr1 -> exp) > (ptr2 -> exp)){
            insert(&(*h3), (ptr1 -> coef), (ptr1 -> exp));
            ptr1 = ptr1 -> link;
        }
        else {
            insert(&(*h3), (ptr2 -> coef), (ptr2 -> exp));
            ptr2 = ptr2 -> link;
        }
    }
    while (ptr1 != NULL){
        insert(&(*h3), (ptr1 -> coef), (ptr1 -> exp));
        ptr1 = ptr1 -> link;
    }
    while (ptr2 != NULL){
        insert(&(*h3), (ptr2 -> coef), (ptr2 -> exp));
        ptr2 = ptr2 -> link;
    }
}

void main(){
    
    struct poly *poly1 = NULL,*poly2 = NULL,*poly3 = NULL;

    int n,m;
    
    printf("First Polynomial \n");
    new_poly(&poly1);
    printf("Polynomial 1 = ");
    display(&poly1);

    printf("Second Polynomial \n");
    new_poly(&poly2);
    printf("Polynomial 2 = ");
    display(&poly2);

    add(&poly1,&poly2,&poly3);
    printf("SUM = ");
    display(&poly3);
}

