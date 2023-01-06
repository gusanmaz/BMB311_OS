#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>



void create_fonk(int height,int sayac){
	if(height==0) return;
	
	int pid=fork();
	if(pid>0){
		wait(NULL);
		printf("%d.process : %d,child%d\n",sayac,getpid(),pid);
		
		}
		else if(pid==0){
		create_fonk(--height,++sayac);
		}
	}

int main(){
//int a;
//printf("Birdeğer giriniz :");
//scanf("%d",&a);
create_fonk(1024,1);
//wait(NULL);
}
