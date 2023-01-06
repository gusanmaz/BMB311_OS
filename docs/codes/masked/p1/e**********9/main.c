#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>



void create_fonk(int sinir,int sayici)
{
	if(sinir==0) return;
	int PID=fork();
	if(PID>0)
	{
		wait(NULL);
		printf("%d.process : %d,child%d\n",sayici,getPID(),PID);
		
		}
		else if(PID==0)
		{
		create_fonk(--sinir,++sayici);
		}
	}
int main()
{
create_fonk(1024,1);
}
