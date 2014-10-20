#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc,char *argv[])
{
	char n[100],tar[10]="./",*arglist[30];
	int i=0,num=0,j=0,t=0,c=argc-1;
	printf("HALF PROCESS ID :	%u\n",getpid());
	for(i=0;i<argc-2;i++){
		arglist[i]=(char *)malloc(8*sizeof(char));
		strcpy(arglist[i],argv[i+1]);
	}
	strcpy(n,argv[argc-1]);
	i=0;
	while(n[i]!='\0')
	{
		num=num*10+(int)n[i]-48;
		i++;
	}
	num=num/2;
	i=0;
	arglist[argc-1]=NULL;
	i=0;
	while(num)
	{
		n[i++]=num%10+48;
		num=num/10;
	}
	n[i]='\0';
	for(j=0;j<i/2;j++){
		t=n[j];
		n[j]=n[i-j-1];
		n[i-j-1]=t;
	}
	arglist[argc-2]=(char *)malloc(8*sizeof(char));
	strcpy(arglist[argc-2],n);
	if(c==1)
		printf("%s\n",arglist[c-1]);
	else
	{
		execvp(strcat(tar,arglist[0]),arglist);		
	}
}
