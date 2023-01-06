#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

void get_ppid(const pid_t pid, pid_t * ppid)
    {
   	char buffer[1024];
   	sprintf(buffer, "/proc/%d/stat", pid);
   	FILE* fp = fopen(buffer, "r");  	
   	if (fp)
        {
      	size_t size = fread(buffer, sizeof (char), sizeof (buffer), fp);
        if (size > 0) 
            {
            strtok(buffer, " "); // (1) pid  %d
            strtok(NULL, " "); // (2) comm  %s
            strtok(NULL, " "); // (3) state  %c
            char * s_ppid = strtok(NULL, " "); // (4) ppid  %d
             *ppid = atoi(s_ppid);
            }
        fclose(fp);
        }
    }

char* get_name(const pid_t pid)
    {
    	char path[1024] = "";
    	char pids[20];
    	sprintf(pids, "%d", pid);
    	strcat(path, "/proc/");
    	strcat(path, pids);
    	strcat(path, "/cmdline");
    	FILE* fp = fopen(path, "r");
    	if(fp == NULL)
            {
    	 	printf("Cannot open the file!");
    	  	exit(1);
	        }
    char* pname = malloc(1024);
   	fscanf(fp, "%s", pname);
   	return pname;
    }

void print_process_info(const pid_t pid, pid_t ppid, char* pname)
    {
    printf("%-20d%-20d%-50s\n", pid, ppid, pname);
    }

void print_header()
    {
    printf("%-20s%-20s%-50s\n", "ID", "Parent ID", "Command");
    }

void show_info(int p_id)
    {
    if (p_id==0){return;}
    int pid =  p_id;
    int ppid;
    get_ppid(pid, &ppid);
    char* pname = get_name(pid);
    if (p_id>0)
        { 
        print_process_info(pid, ppid, pname);
        pid=ppid;
        free(pname);
        show_info(pid);	
        }
    }

int main(int argc, char *argv[])
    {
    int pid=getpid();
    print_header();
    show_info(pid);
    }
