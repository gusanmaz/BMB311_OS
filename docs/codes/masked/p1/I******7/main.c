#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	for(int i=0;i<1023;i++) 
	{
		if(fork() == 0)
		{
			printf("child pid %d from parent pid %d\n",getpid(),getppid());
			exit(0);
		}
	}
	for(int i=0;i<1023;i++) wait(NULL);
	
}


