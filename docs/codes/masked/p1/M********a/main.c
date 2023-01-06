#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void process_olustur(int p_sayisi,int sayac)
{
	if(p_sayisi==0) {		
		printf("\nChild Process Sayısı: %d, Toplam Process Sayısı :%d\n",sayac-1,sayac);
		return;
		}
	
	int pid=fork();
	if(pid>0){
		wait(NULL);
		printf("%d.Child Process PID: %d - Parent Process PID: %d\n",sayac,pid,getpid());
		process_olustur(--p_sayisi,++sayac);
		}
}

int main()
{
	int a=1023;
	process_olustur(a,1);

}
