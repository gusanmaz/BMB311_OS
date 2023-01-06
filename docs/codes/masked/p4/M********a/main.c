#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

char* p_ad_bul(const pid_t pid){
    char path[1024] = "";
    char pids[20];
    sprintf(pids, "%d", pid);

    strcat(path, "/proc/");
    strcat(path, pids);
    strcat(path, "/comm");

    FILE* fp = fopen(path, "r");
    if(fp == NULL){
      printf("NULL");
      exit(1);
   }

   char* p_ad = malloc(1024);
   fscanf(fp, "%s", p_ad);
   return p_ad;
}
 

int main(int argc, char *argv[])
{
	if (argv[1]==NULL){
		printf("\nUyarı: Lütfen PID değeri giriniz.(Örn:./main 935)\n");
		return 0;
	}
	
	int pid =atoi(argv[1]);

	char* p_ad = p_ad_bul(pid);

	printf("\nPID değeri: %d olan Process:\n\n%s\n",pid,p_ad);

}
