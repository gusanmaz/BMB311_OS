#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>



void yeni_fnks(int height,int i){
	if(height==0) return;
	
	int pid=fork();
	if(pid>0){
		wait(NULL);
		printf("%d.process : %d,child%d\n",i,getpid(),pid);
		
		}
		else if(pid==0){
		yeni_fnks(--height,++i);
		}
	}

int main(){

yeni_fnks(1024,1);

}
