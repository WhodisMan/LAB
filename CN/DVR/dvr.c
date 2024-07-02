# include <stdio.h>

struct routing_table {
    int distance[10];
    int next_node[10];
}rt[10];

int costmat [10][10],n,n,i,j,k;

void print_costmat(){
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            printf("%d ",costmat[i][j]);
        }
        printf("\n");
    }
}

void read_costmat(){
    printf("Enter the number of nodes : ");
    scanf("%d",&n);


    printf("Enter Cost Matrix : ");

    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            scanf("%d",&costmat[i][j]);
            costmat[i][i] = 0;
            rt[i].distance[j] = costmat[i][j];
            rt[i].next_node[j] = j;
        }
    }
}

void print_rt(){
    for (int x=0;x<n;x++){
        printf("-------------- %c --------------\nNode\tDistance    Next Node\n",65+x);
        for (int y=0;y<n;y++){
            printf("  %c\t   %d\t      %c\n",(65+y),rt[x].distance[y],rt[x].next_node[y]+65);
        }
    }
}

void dvr(){
    for (i=0;i<n;i++){
        printf("\n----------- PASS %d ------------\n",i);
        for (j=0;j<n;j++){
            for (k=0;k<n;k++){
                if (rt[i].distance[j] > costmat[i][k] + costmat[k][j]){
                    rt[i].distance[j] = costmat[i][k] + costmat[k][j];
                    rt[i].next_node[j] = k;
                }
            }
        }
        print_rt();
    }
}


void main(){
    read_costmat();
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    //print_costmat();
    print_costmat();
    dvr();
}

