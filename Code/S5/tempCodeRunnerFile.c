#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#define MAX 20

// status = 0 -> fresh | 1 -> executing | 2 -> finished
// p - process
// at - arrival time
// bt - burst time
// ct - completion time
// tat - turnaround time
// wt - waiting time
// st - start time
// pri - priority
// rbt - remaining burst time

struct process{
    int p,at,bt,ct,tat,wt,pri,st[MAX],status;
}p[MAX],exec[MAX];

int n;

// to define the process list
void def(){
    for(int i=0;i<n;i++){
        p[i].p = i+1;
        printf("Enter the ARRIVAL TIME for [PROCESS %d] : ",p[i].p);
        scanf("%d",&p[i].at);
        printf("Enter the BURST TIME for [PROCESS %d] : ",p[i].p);
        scanf("%d",&p[i].bt);
        printf("Enter the PRIORITY for [PROCESS %d] : ",p[i].p);
        scanf("%d",&p[i].pri);
    }
}

void clear(){   
    for(int i=0;i<n;i++){
        p[i].ct = 0;
        p[i].tat = 0;
        p[i].wt = 0;
        p[i].st[0] = 0;
        p[i].status = 0;
    }
}

// print average
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

void display(){
    int col=7;
	printf(" ");
	for(int i=0;i<col*16;i++) printf("-");
    printf("\n");
    printf("|   PROCESS\t|\tAT\t|\tBT\t|\tPRI\t|\tCT\t|\tTAT\t|\tWT\t|\n");
    printf(" ");
	for(int i=0;i<col*16;i++) printf("-");
    printf("\n");
    for(int i=0;i<n;i++){
        printf("|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\n",p[i].p,p[i].at,p[i].bt,p[i].pri,p[i].ct,p[i].tat,p[i].wt);
    }
    printf(" ");
	for(int i=0;i<col*16;i++) printf("-");
    printf("\n");
}

void swap(struct process *p1, struct process *p2){
    struct process temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// code = 0 -> process number
// code = 1 -> arrival time
// code = 2 -> burst time
// code = 3 -> priority
void bubble(int code){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
        	if (code == 0){
        		if(p[j].p > p[j+1].p)
                	swap(&p[j],&p[j+1]);
            }
            else if (code == 1 ){
            	if(p[j].at > p[j+1].at)
            		swap(&p[j],&p[j+1]);
            }
            else if (code == 2 ){
            	if(p[j].bt > p[j+1].bt)
            		swap(&p[j],&p[j+1]);	
            }
            else if (code == 3){
                if(p[j].pri > p[j+1].pri)
                    swap(&p[j],&p[j+1]);
            }
        }
    }
}
// SCHEDULING FUNCTIONS

//First come first serve
void fcfs(){
    
    clear();
    int t=0;
    bubble(1);
    for(int i=0; i<n;i++){
        if (p[i].at > t){
            t = p[i].at;
        }
        if (p[i].status == 0){
            p[i].st[0] = t;
            p[i].ct = p[i].bt + t;
            t = p[i].ct;
            p[i].tat = p[i].ct - p[i].at;
            p[i].wt = p[i].tat - p[i].bt;
            p[i].status = 2;
        }
    }
    bubble(0);
    display();
    print_avg();
}

// shortest job first 
void sjf(){
    
    clear();
    int t=0;
    bubble(2);
    bubble(1);
    for(int i=0;i<n;){
        if (p[i].at > t){
            t = p[i].at;
        }
        if (p[i].status == 0){
            p[i].st[0] = t;
            p[i].ct = p[i].bt + t;
            t = p[i].ct;
            p[i].tat = p[i].ct - p[i].at;
            p[i].wt = p[i].tat - p[i].bt;
            p[i].status = 2;

            for(int x=0;x<n-1;x++){
                for(int y=0;y<n-i-1;y++){
                    if(p[y].bt > p[y+1].bt && p[y].at < t)
                        swap(&p[y],&p[y+1]);
                }
            }
            i=0;
        }
        else i++;
    }
    bubble(0);
    display();
    print_avg();
}

// priority
void pri(){
    clear();
    int t=0;
    bubble(3);
    bubble(1);
    for(int i=0;i<n;){
        if (p[i].at > t){
            t = p[i].at;
        }
        if (p[i].status == 0){
            p[i].st[0] = t;
            p[i].ct = p[i].bt + t;
            t = p[i].ct;
            p[i].tat = p[i].ct - p[i].at;
            p[i].wt = p[i].tat - p[i].bt;
            p[i].status = 2;

            for(int x=0;x<n-1;x++){
                for(int y=0;y<n-i-1;y++){
                    if(p[y].p > p[y+1].p && p[y].at < t)
                        swap(&p[y],&p[y+1]);
                }
            }
            i=0;
        }
        else i++;
    }
    bubble(0);
    display();
    print_avg();
}

// Round Robin
void rr(){

    int quant;
    printf("Enter Time Quantum : ");
    scanf("%d",&quant);

    // Declaring variables
    int c=n,s[n][20];
    float time=0,mini=INT_MAX,b[n],a[n];

    // Initializing burst and arrival time arrays
    int index=-1;
    for(int i=0;i<n;i++){
            b[i]=p[i].bt;
            a[i]=p[i].at;
            for(int j=0;j<20;j++){
            s[i][j]=-1;
            }
    }

    int tot_wt,tot_tat;
    tot_wt=0;
    tot_tat=0;
    bool flag=false;

    while(c!=0){

        mini=INT_MAX;
        flag=false;

        for(int i=0;i<n;i++){
            float p=time+0.1;
            if(a[i]<=p && mini>a[i] && b[i]>0){
                index=i;
                mini=a[i];
                flag=true;
            }
        }
        // if at =1 then loop gets out hence set flag to false
        if(!flag){
            time++;
            continue;
        }

        //calculating start time
        int j=0;

        while(s[index][j]!=-1){
            j++;
        }

        if(s[index][j]==-1){
            s[index][j]=time;
            p[index].st[j]=time;
        }

        if(b[index]<=quant){
            time+=b[index];
            b[index]=0;
        }
        else{
            time+=quant;
            b[index]-=quant;
        }

        if(b[index]>0)
            a[index]=time+0.1;

        // calculating arrival,burst,final times
        if(b[index]==0){
            c--;
            p[index].ct=time;
            p[index].wt=p[index].ct-p[index].at-p[index].bt;
            tot_wt+=p[index].wt;
            p[index].tat=p[index].bt+p[index].wt;
            tot_tat+=p[index].tat;

        }
    }
    display();
    print_avg();
}

void main(){
   
    printf("-----------CPU SCHEDULING---------\n\n");
    printf("Enter the number of Processes (Maximum %d) : ",MAX);
    scanf("%d",&n);

    def();
    int ch,run=1;
    while(run){
        printf("Choose the CPU scheduling algorithm :\n1. FCFS\n2. SJF\n3. Round Robin\n4. Priority\n0. Exit\nEnter Choice : ");
        scanf("%d",&ch);
        
        switch (ch){
        case 1:
            fcfs();
            break;
        case 2:
            sjf();
            break;
        case 3:
            rr();
            break;
        case 4:
            pri();
            break;
        case 0:
            run=0;
            break;
        default:
            printf("INVALID - \nPlease choice enter again : \n");
            break;  
        }
    }
}


