#include <unistd.h> 
#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h> 


void get_ppid(const pid_t pppid, pid_t *ppid) {
char buffer[1024];

sprintf(buffer, "/proc/%d/stat", pppid);
FILE* fp = fopen(buffer, "r");
if (fp) {
size_t size = fread(buffer, sizeof (char), sizeof(buffer),
fp);

if (size > 0)
{
    
 ->/proc/[pppid]/stat
strtok(buffer, " "); 
strtok(NULL, ""); 
strtok(NULL, ""); 
char *s_ppid = strtok(NULL, ""); 
*ppid = atoi(s_ppid);
}
fclose(fp);
}
}

char* get_name(const pid_t pppid){

char path[1024] = "";
char pids[20];
sprintf(pids, "%d", pppid);
strcat(path, "/proc/");
strcat(path, pids);
strcat(path, "/cmdline");

FILE* fp = fopen(path, "r");
if(fp == NULL){
printf("dosya açılamadı"); 
exit(1);
}

char* pname = malloc(1024); 
fscanf(fp, "%s", pname);
return pname;
}

void print_header(){
 printf("%-20s%-20s%-50s\n", "id", "Parent id", "c");
}

void print_process_info(const pid_t pppid, pid_t ppid, char* pname){
 printf("%-20d%-20d%-50s\n",pppid,ppid,pname);
}



int main(int argc, char *argv[])
{
int pppid = getpid();
int ppid;
print_header();
while(1){
get_ppid(pppid, &ppid);
char* pname = get_name(pppid);
print_process_info(pppid, ppid, pname);
free(pname);
    
if(pppid==1)
{ break;} 
pppid=ppid;
}
}
