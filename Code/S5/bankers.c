
#include<stdio.h>
#define MAX 10

int alloc[MAX][MAX],max[MAX][MAX],need[MAX][MAX],avail[MAX];
int m,n;

void printmat(int mat[MAX][MAX]){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf(" %d  ",mat[i][j]);
        }
        printf("\n");
    }

}

void printarr(int arr[MAX]){
    for(int i=0;i<m;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void def(){
    printf("Enter the number of processes : ");
    scanf("%d",&m);
    printf("Enter the number of resources : ");
    scanf("%d",&n);

    printf("Enter allocation matrix\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("Process[%d] Resource[%c] : ",i,65+j);
            scanf("%d",&alloc[i][j]);
        }
        printf("\n");
    }
    printf("Enter maximum need matrix\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("Process[%d] Resource[%c] : ",i,65+j);
            scanf("%d",&max[i][j]);

            need[i][j] = max[i][j] - alloc[i][j];
        }
        printf("\n");
    }
    printf("Enter available array\n");
    for(int i=0;i<n;i++){
        printf("Resource[%c] : ",i+65);
        scanf("%d",&avail[i]);
    }
}

void bankers(){
    int f[MAX]={0},ans[MAX],flag,idx=0;

    for(int k=0;k<m;k++){
        for(int i=0;i<m;i++){
            if (f[i] == 0){
                flag = 0;
                for(int j=0;j<n;j++){
                    if (need[i][j] > avail[j]){
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0){
                    f[i] = 1;
                    ans[idx++] = i;
                    for(int j=0;j<n;j++)
                        avail[j] = avail[j] + alloc[i][j];
                }
            }
        }
    }

    flag = 0;
    for(int i=0;i<m;i++){
        if (f[i] == 0){
            flag=1;
            break;
        }
    }

    if (flag == 1){
        printf("The given set of Processes are unsafe\n");
    }
    else{
        printf("Safe sequence : ");
        for(int i=0;i<m-1;i++){
            printf(" %d ->",ans[i]);
        }

        printf(" %d\n",ans[m-1]);
    }
}

void main(){
    def();
    printf("Need Matrix \n");
    printmat(need);
    bankers();
}