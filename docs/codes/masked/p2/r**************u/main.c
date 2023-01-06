#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>


void get_ppid(const pid_t pid, pid_t * ppid) {
   char arabellek[1024];
   sprintf(arabellek, "/proc/%d/stat", pid);
   FILE* rk = fopen(arabellek, "r");
   if (rk) {
      size_t buyukluk = fread(arabellek, sizeof (char), sizeof (arabellek), rk);
      if (buyukluk > 0) {
         strtok(arabellek, " "); 
         strtok(NULL, " "); 
         strtok(NULL, " "); 
         char * parcali = strtok(NULL, " "); 
         *ppid = atoi(parcali);
      }
      fclose(rk);
   }
}

char* get_name(const pid_t pid){
    char path[1024] = "";
    char pids[20];
    sprintf(pids, "%d", pid);

    strcat(path, "/proc/");
    strcat(path, pids);
    strcat(path, "/cmdline");

    FILE* rk = fopen(path, "r");
    if(rk == NULL){
      printf("Cannot open the file!");
      exit(1);
   }

   char* pisim = malloc(1024);
   fscanf(rk, "%s", pisim);
   return pisim;
}

void print_process_info(const pid_t pid, pid_t ppid, char* pisim){
    printf("%-20d%-20d%-50s\n", pid, ppid, pisim);
}

void print_header(){
    printf("%-20s%-20s%-50s\n", "ID", "Parent ID", "Command");
}


int main(int argc, char *argv[])
{
   int pid =  getpid();
   int ppid;
   get_ppid(pid, &ppid);
   char* pisim = get_name(pid);

   print_header();
   print_process_info(pid, ppid, pisim);
   free(pisim);

   while(ppid!=0){  

        pid = ppid;

        get_ppid(pid, &ppid); 

        char* pisim = get_name(pid); 

        print_process_info(pid, ppid, pisim);

        free(pisim);
   }
}
