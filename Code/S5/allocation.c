#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int fc=0; // file count

struct node{
	int data;
	struct node* next;
};

struct data_block{
	int data;
	struct node* next;
}d[MAX];


struct files{
	char name[20];
	int size;
	int start;
}f[MAX];

void clear(){
	for(int i=0;i<MAX;i++){
		d[i].data = 0;
		d[i].next = 0;
	}
}

void display(){
	printf("block_no\tdata\tnext\tfile_name\n");
	for(int i=0;i<MAX;i++){
		printf("\t%d\t%d\t%d\t%s\n",i,d[i].data,d[i].next,f[d[i].data].name);
	}
}

void sequential(int fc){
	int flag=0;
	if ((f[fc].size + f[fc].start) > MAX)
		flag=1;
	for(int i=f[fc].start;i<(f[fc].size + f[fc].start);i++){
		if (d[i].data != 0){
			flag = 1;
			break;
		}
	}
	if (flag == 0){
		for(int i=f[fc].start;i<(f[fc].size + f[fc].start);i++){
			d[i].data = fc;
		}
	}
	else{
		printf("File cannot be allocated \n");
		fc--;
	}
}

void indexed(int fc){
	int temp = f[fc].size;
	int i = f[fc].start;
	while(temp != 0 && i < MAX){
		if (d[i].data == 0){
			d[i].data = fc;
			i++;
			temp--;
		}
		else i++;
	}
	if (temp != 0){
		for(int i=0;i<MAX;i++){
			if(d[i].data == fc)
				d[i].data = 0;
		}
		printf("File cannot be allocated \n");
		fc--;
	}
}

void files(int fc){
	int temp[MAX]={0};
	int idx=0;
	for(int i=1;i<=fc;i++){
		printf("%s = ",f[i].name);
		for(int j=0;j<MAX;j++){
			if (d[j].data == i){
				temp[idx++] = j;
				printf("%d -> ",j);

			if (d[j].next !=0 && d[j].data == i)
				printf("Linked list");
			}
			
		}
		printf("\n");
	}
}


void linked(int fc){
	struct node	*head = NULL;
	for(int i=0;i<f[fc].size;i++){
		struct node* l = (struct node*) malloc(sizeof(struct node));
		l -> data = fc;
		l -> next = head;
		head = l; 
	}

	d[f[fc].start].next = head;
	d[f[fc].start].data = fc;
}



// 
void main(){
	int choice;
	int run=1;
	clear();


	while(run){
		
		printf("Choose file allocation algorithm : \n1.Sequential\n2.Indexed\n3.Linked\n>>> ");
		scanf("%d",&choice);

		fc++;
		printf("Enter file name : ");
		scanf("%s",f[fc].name);
		printf("Enter the starting index : ");
		scanf("%d",&f[fc].start);
		printf("Enter the size of the file : ");
		scanf("%d",&f[fc].size);

		switch(choice){
			case 1:
				sequential(fc);
				break;
			case 2:
				indexed(fc);
				break;
			case 3:
				linked(fc);
				break;
		}

		display();
		printf("\n");
		files(fc);
	}


	
}
