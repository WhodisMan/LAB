#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
char arr1[20];
int a1c=0;
char arr2[20];
int a2c=0;

char inp[20][20];
int ic=0;

void getInp(){
    int n;
    printf("Number of Input Expressions >> ");
    scanf("%d",&n);
    printf("List the Expressions\n");
    for(int i=0;i<n;i++){
        scanf("%s",inp[ic]);
        ic++;
    }
}

int getVal(char x){
    if(isdigit(x)){
        return x-'0';
    }
    else{
        for(int i=0;i<a1c;i++){
            if(x==arr1[i]){
                return arr2[i];
            }
        }
    }
    return 99;
}

int op(char opr,int x,int y){
    if(opr=='+')
        return x+y;
    else if(opr=='-')
        return x-y;
    else if(opr=='*')
        return x*y;
    else if(opr=='/')
        return x/y;
    else
        return 0;
}

void res(){
    printf("\nValues >> \n");
    for(int i=0;i<a2c;i++){
        printf("%c : %d\n",arr1[i],arr2[i]);
    }
}

void optimized(){
    int x=0;
    int f=0;
    for(int i=0;i<ic;i++){
        for(int j=0;inp[i][j]!='\0';j++){
            x=getVal(inp[i][j]);
            if(f==0){
                printf("%c",inp[i][j]);
                f=1;
            }
            else if(x==99){
                printf("%c",inp[i][j]);
            }
            else{
                printf("%d",x);
            }
        }
        printf("\n");
        f=0;
    }
    printf("\n");
}
void calc(){
    int val;
    char c;
    int tmp;
    for(int i=0;i<ic;i++){
        val=0;
        arr1[a1c]=inp[i][0];
        a1c++;//LHS of input expr
        for(int j=2;inp[i][j]!='\0';j++){
            tmp=getVal(inp[i][j]);
            while(isdigit(inp[i][j+1])){
                tmp*=10;
                tmp+=getVal(inp[i][j+1]);
                j+=1;
            }
            val+=tmp;
            //printf("%d\n",val);
            if(inp[i][j]=='+'||inp[i][j]=='-'||inp[i][j]=='*'||inp[i][j]=='/'){
                tmp=getVal(inp[i][j+1]);
                while(isdigit(inp[i][j+1])){
                    tmp*=10;
                    tmp+=getVal(inp[i][j+1]);
                    j+=1;
                }
                val=op(inp[i][j],val,tmp);
            }
            j+=1;
        }
        arr2[a2c]=val;
        a2c++;

    }
}
void main(){
    getInp();
    calc();
    res();
    optimized();

}