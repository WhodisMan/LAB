#include<stdio.h>
#define MAX 20

struct process{
    int p,at,bt,ct,tat,wt;
}p[MAX];

void display(int n,struct process p[]){
	printf(" ");
	for(int i=0;i<6*16;i++) printf("-");
    printf("\n");
    printf("|   PROCESS\t|\tAT\t|\tBT\t|\tCT\t|\tTAT\t|\tWT\t|\n");
    printf(" ");
	for(int i=0;i<6*16;i++) printf("-");
    printf("\n");
    for(int i=0;i<n;i++){
        printf("|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\n",p[i].p,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    }
    printf(" ");
	for(int i=0;i<6*16;i++) printf("-");
    printf("\n");
}

void print_gantt_chart(struct process p[], int n)
{
    int i, j;
    // print top bar
    printf(" ");
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].bt; j++) printf("--");
        printf(" ");
    }
    printf("\n|");
 
    // printing process id in the middle
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].bt - 1; j++) printf(" ");
        printf("P%d", p[i].p);
        for(j=0; j<p[i].bt - 1; j++) printf(" ");
        printf("|");
    }
    printf("\n ");
    // printing bottom bar
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].bt; j++) printf("--");
        printf(" ");
    }
    printf("\n");
 
    // printing the time line
    printf("0");
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].bt; j++) printf("  ");
        if(p[i].tat > 9) printf("\b"); // backspace : remove 1 space
        printf("%d", p[i].tat);
 
    }
    printf("\n");
}

void def(int n,struct process p[]){
    for(int i=0;i<n;i++){
        p[i].p = i+1;
        printf("Enter the ARRIVAL TIME for [PROCESS %d] : ",p[i].p);
        scanf("%d",&p[i].at);
        printf("Enter the BURST TIME for [PROCESS %d] : ",p[i].p);
        scanf("%d",&p[i].bt);
    }
}

void print_avg(int n, struct process p[]){
	float avg_tat = 0,avg_wt = 0;
	
	for(int i=0;i<n;i++){
		avg_tat += p[i].tat;
		avg_wt += p[i].wt;
	}
	avg_tat = avg_tat/n;
	avg_wt = avg_wt/n;
	printf("\nAverage Turnaround Time = %f\n",avg_tat);
	printf("Average Waiting Time = %f\n",avg_wt);
}

void swap(struct process *p1, struct process *p2){
    struct process temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void fcfs(int n, struct process p[]){

    int temp,t=0;
    for(int i=0; i<n;i++){
        if (p[i].at > t){
            temp = p[i].at - t;
            t += temp;
        }
        p[i].ct = p[i].bt + t;
        t = p[i].ct;
    }
    
    for(int i=0;i<n;i++){
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
    }
}

// code = 0 -> at
// code = 1 -> p 
// code = 2 -> st
void bubble(int n,struct process p[],int code){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
        	if (code == 0){
        		if(p[j].at > p[j+1].at){ 
                	swap(&p[j],&p[j+1]);
                }
            }
            else if (code == 1 ){
            	if(p[j].p > p[j+1].p){
            		swap(&p[j],&p[j+1]);
            	}	
            }
        }
    }
}

void main(){
    int n;
    printf("-----------FCFS---------\n\n");

    printf("Enter the number of Processes (Maximum %d) : ",MAX);
    scanf("%d",&n);

    def(n,p);
    //display(n,p);
    
    bubble(n,p,0);
    fcfs(n,p);
    //bubble(n,p,1);
    
  
    display(n,p);
    print_gantt_chart(p,n);
    
    //bubble(n,p,2);
    
    print_avg(n,p);    
}

