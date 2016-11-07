#include<stdio.h>
#include<stdlib.h>

int main()
{
	int pid; 
	int i;
	int status = 0;
	int sonid,parentid;

	for(i=0;i<3;i++)
	{
		pid=fork();
		if(pid!=0)
		{
			printf("parent son_pid%d\n",pid);
			pid = wait(&status);
		}
		else
		{
			sonid = getppid();
			parentid = getpid();
			printf("son parent_pid%d son_pid%d\n",parentid,sonid);
			exit(status);
		}
	}
	return 0;
}
