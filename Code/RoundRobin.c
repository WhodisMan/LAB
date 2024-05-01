// Ansif M Shamsu
// CSE-A, S4, 26

#include<stdio.h>
#include<stdlib.h>

#define STATE_UNKNOWN 0
#define STATE_READY 1
#define STATE_RUNNING 2
#define STATE_RETURNED 3

struct entry {
    int AT, BT, CT, TAT, WT, ST, state, rBT;
    char Name[20];
} pChart[10];
int n, readyQue[10], ready_f = 0, ready_r = 0, arrSort[10], tmQntm;
int gEntry[40][2], gTop;

void swap (int* list, int i1, int i2) {
    //printf("%d\n", i2);
    int temp = list[i1];
    list[i1] = list[i2];
    list[i2] = temp;
}

void enque(int id) {
    if (ready_f-ready_r >= n) { printf("Err: Que overflow\n"); return; }
    pChart[id].state = STATE_READY;
    readyQue[(ready_f++)%n] = id;
}

int nextProcessId() {
    if (ready_r == ready_f) return -1; // Queue empty
    int id = readyQue[ready_r++];
    if (ready_r >= n) { ready_f %= n; ready_r %= n; }
    return id;
}

void printChar(char c, int count) { 
    for (int i = 0; i < count; i++) printf("%c", c); 
}

void printGanttChart(int startPoint, int endPoint) {
    printChar('-', (endPoint-startPoint)*8+1); printf("\n|");
    for (int i = startPoint; i < endPoint; i++) 
        if (gEntry[i][0] == -1) printf("||||||||");
        else printf("%s\t|", pChart[gEntry[i][0]].Name);
    printf("\n");
    printChar('-', (endPoint-startPoint)*8+1); printf("\n");
    if (startPoint == 0 || gEntry[startPoint-1][0] == -1) 
        printf("%d", pChart[gEntry[startPoint][0]].ST);
    else printf("%d", gEntry[startPoint-1][1]);
    for (int i = startPoint; i < endPoint; i++) 
        if (gEntry[i][0] == -1) printf("\t%d", pChart[gEntry[i+1][0]].ST);
        else printf("\t%d", gEntry[i][1]);
    printf("\n");
    
}

int main () {
    //Fetching process table
    printf("Enter the time quantum: ");
    scanf("%d", &tmQntm);
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Process %d Details (Name, AT, BT): ", i);
        scanf("%s%d%d", pChart[i].Name, &pChart[i].AT, &pChart[i].BT);
        arrSort[i] = i;
        pChart[i].state = STATE_UNKNOWN;
        pChart[i].Name[7] = '\0';
    }

    //Sort Array based on AT (Insertion sort)
    for (int i = 1; i < n; i++)
    for (int j = i; j > 0 && pChart[arrSort[j-1]].AT > pChart[arrSort[j]].AT; j--)
        swap(arrSort, j-1, j);

    
    //Trailing processes
    int t_TAT = 0, t_WT = 0, target = 0, cTime = 0, pid = -1;
    gTop = 0;
    while (target < n || ready_f != ready_r) {
        while (target < n && pChart[arrSort[target]].AT <= cTime) {
            int id = arrSort[target++];
            if (pChart[id].state != STATE_UNKNOWN) continue;
            if (pChart[id].AT > cTime) break;
            pChart[id].rBT = pChart[id].BT;
            pChart[id].state = STATE_READY;
            enque(id);
        }

        if (pid != -1 && pChart[pid].state == STATE_RUNNING) {
            enque(pid);
            pChart[pid].state = STATE_READY;
        }

        pid = nextProcessId();
        struct entry *cp = &pChart[pid];

        if (pid > -1) {
            pChart[pid].state = STATE_RUNNING;
            if (cp->BT == cp->rBT) cp->ST = cTime;
            if (cp->rBT > tmQntm) {
                cp->rBT -= tmQntm;
                cTime += tmQntm;
            } else {
                cTime += cp->rBT;
                cp->rBT = 0;
                cp->CT = cTime;
                cp->TAT = cp->CT - cp->AT;
                cp->WT = cp->TAT - cp->BT;
                t_TAT += cp->TAT;
                t_WT += cp->WT;
                cp->state = STATE_RETURNED;
            } 

            gEntry[gTop][0] = pid;
            gEntry[gTop++][1] = cTime;
        } else {
            if (gEntry[gTop-1][0] != -1) gEntry[gTop++][0] = -1;
            cTime++;
        }
    }

    printf("\n------Gantt Chart------\n");
    for (int i = 0; i <= (gTop-1)/10; i++) {
        int endPoint = 10*(i+1);
        if (endPoint>=gTop) endPoint = gTop;
        printGanttChart(10*i, endPoint);
    }

    printf("\n ");
	for(int i=0;i<6*16;i++) printf("-");
    printf("\n|   PROCESS\t|\tAT\t|\tBT\t|\tCT\t|\tTAT\t|\tWT\t|\n");
    printf(" ");
	for(int i=0;i<6*16;i++) printf("-");
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("|\t%s\t|\t%d\t|\t%d\t|", pChart[i].Name, pChart[i].AT, pChart[i].BT);
        printf("\t%d\t|\t%d\t|\t%d\t|\n", pChart[i].CT, pChart[i].TAT, pChart[i].WT);
    }
    printf(" ");
	for(int i=0;i<6*16;i++) printf("-");
    printf("\n");
    
    printf("\nAvg TAT: %f\nAvg WT: %f\n", (float)t_TAT/n, (float)t_WT/n);
}