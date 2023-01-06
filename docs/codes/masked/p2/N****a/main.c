#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>


void get_ppid(const pid_t pid, pid_t * ppid) {
   char buffer[1024];
   sprintf(buffer, "/proc/%d/stat", pid);
   FILE* fp = fopen(buffer, "r");
   if (fp) {
      size_t size = fread(buffer, sizeof (char), sizeof (buffer), fp);
      if (size > 0) {
         strtok(buffer, " "); 
         strtok(NULL, " "); 
         strtok(NULL, " "); 
         char * s_ppid = strtok(NULL, " "); 
         *ppid = atoi(s_ppid);
      }
      fclose(fp);
   }
}

char* get_name(const pid_t pid){
    char paket[1024] = "";
    char pd[20];
    sprintf(pd, "%d", pid);

    strcat(paket, "/proc/");
    strcat(paket, pd);
    strcat(paket, "/cmdline");

    FILE* fp = fopen(paket, "r");
    if(fp == NULL){
      printf("Cannot open the file!");
      exit(1);
   }

   char* namess = malloc(1024);
   fscanf(fp, "%s", namess);
   return namess;
}

void print_process_info(const pid_t pid, pid_t ppid, char* namess){
    printf("%-20d%-20d%-50s\n", pid, ppid, namess);
}

void print_header(){
    printf("%-20s%-20s%-50s\n", "ID", "Parent ID", "Command");
}


int main(int argc, char *argv[])
{
   int pid =  getpid();
   int ppid;
   get_ppid(pid, &ppid);
   char* namess = get_name(pid);

   print_header();
   print_process_info(pid, ppid, namess);
   free(namess);
   
   while(ppid!=0){	
   	
   	pid = ppid; 
   	
   	get_ppid(pid, &ppid); 
   	
   	char* namess = get_name(pid); 
   	
   	print_process_info(pid, ppid, namess); 
   	
   	free(namess);
   }
}
