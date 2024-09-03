#include<stdio.h>
#include<conio.h>
#include<string.h>

int k=0,z=0,i=0,j=0,len=0;
char str1[20],str2[20],str3[15],act[10];
void check();
void main()
   {
      printf("GRAMMAR is E -> E+E\nE -> E*E\nE -> (E)\nE -> E-E\nE -> E/E\nE -> i\n");
      printf("Enter input string : ");
      scanf("%s",str1);

      len = strlen(str1);


      printf("STACK \t INPUT \t ACTION\n");
	  printf("$ \t %s$\t \n",str1);

      for(i=0; j<len; i++,j++){
         if(str1[j]=='i'){
              str3[i]=str1[j];
              str1[j]=' ';
              printf("$%s\t%s$\tSHIFT -> i\n",str3,str1);
              check();
           }
         else{
              str3[i]=str1[j];
              str3[i+1]='\0';
              str1[j]=' ';
              printf("$%s\t%s$\tSHIFT -> %c\n",str3,str1,str3[i]);
              check();
           }
       }
	   if (strcmp(str3,"E") == 0){
		printf("String accepted\n");
	   }
	   else{
		printf("String not accepted\n");
	   }

   }
void check()
   {
     for(z=j; z<len; z++){
       if(str3[z]=='i')
         {
           str3[z]='E';
           printf("$%s\t%s$\tREDUCE i TO E\n",str3,str1);
         }
       else if(str3[z]=='E' && str3[z+1]=='+' && str3[z+2]=='E')
         {
           str3[z]='E';
           str3[z+1]='\0';
           printf("$%s\t%s$\tREDUCE E+E TO E\n",str3,str1);
           i=i-2;
         }
       else if(str3[z]=='E' && str3[z+1]=='*' && str3[z+2]=='E')
         {
           str3[z]='E';
           str3[z+1]='\0';
           printf("$%s\t%s$\tREDUCE E*E TO E\n",str3,str1);
           i=i-2;
         }
       else  if(str3[z]=='(' && str3[z+1]=='E' && str3[z+2]==')')
         {
           str3[z]='E';
           str3[z+1]='\0';
           printf("$%s\t%s$\tREDUCE (E) TO E\n",str3,str1);
           i=i-2; 
         }
   	}
   }