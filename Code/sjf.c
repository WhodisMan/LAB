#include <stdio.h>
#define MAX 20

int n;
struct process{
    int p,at,bt,ct,tat,wt,st;
}p[MAX];

void display(){
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

void def(){
    for(int i=0;i<n;i++){
        p[i].p = i+1;
        printf("Enter the ARRIVAL TIME for [PROCESS %d] : ",p[i].p);
        scanf("%d",&p[i].at);
        printf("Enter the BURST TIME for [PROCESS %d] : ",p[i].p);
        scanf("%d",&p[i].bt);
    }
}

void swap(struct process *p1, struct process *p2){
    struct process temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void sort(int code){
    if(code == 0){
        for(int i=0;i<n;i++)
            for(int j=i;j>0 && p[j-1].at > p[j].at;j--)
                swap(&p[j-1],&p[j]);
    }
    if(code == 1){
        for(int i=0;i<n;i++)
            for(int j=i;j>0 && p[j-1].bt > p[j].bt;j--)
                swap(&p[j-1],&p[j]);
    }
    if(code == 2){
        for(int i=0;i<n;i++)
            for(int j=i;j>0 && p[j-1].p > p[j].p;j--)
                swap(&p[j-1],&p[j]);
    }
}

void print_gantt_chart()
{
    int i, j;
    printf("\nGANTT CHART\n"); 
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
        if(p[i].ct > 9) printf("\b"); // backspace : remove 1 space
        printf("%d", p[i].ct);
 
    }
    printf("\n");
}

void sjf(){

    int temp,t=0;
    for(int i=0; i<n;i++){
        if (p[i].at > t){
            temp = p[i].at - t;
            t += temp;
        }
        p[i].ct = p[i].bt + t;
        t = p[i].ct;

        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;

        // sorts the list according to Burst Time for arival time less than completion time of the previous process.
        for(int x=1;x<n;x++){
            for(int y=1;y<n-x && p[y].at <= p[i].ct;y++){
                if(p[y].bt > p[y+1].bt ){
                    swap(&p[y],&p[y+1]);
                }
            }
        }

    }
}

void print_avg(){
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


int main() {

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    def();
    sort(1);
    sort(0);
    sjf();
    print_gantt_chart();
    sort(2);
    display();
    print_avg();
    return 0;
}
