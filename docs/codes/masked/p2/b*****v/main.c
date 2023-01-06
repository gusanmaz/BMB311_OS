#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

// kullanilabilir.
void get_ppid(const pid_t pid, pid_t *ppid)
{
    char buffer[1024];
    sprintf(buffer, "/proc/%d/stat", pid);
    FILE *fp = fopen(buffer, "r");
    if (fp)
    {
        size_t size = fread(buffer, sizeof(char), sizeof(buffer), fp);
        if (size > 0)
        {
            // http://man7.org/linux/man-pages/man5/proc.5.html -> /proc/[pid]/stat
            strtok(buffer, " ");              // (1) pid  %d
            strtok(NULL, " ");                // (2) comm  %s
            strtok(NULL, " ");                // (3) state  %c
            char *s_ppid = strtok(NULL, " "); // (4) ppid  %d
            *ppid = atoi(s_ppid);
        }
        fclose(fp);
    }
}

// kullanilabilir.
char *get_name(const pid_t pid)
{
    char path[1024] = "";
    char pids[20];
    sprintf(pids, "%d", pid);

    strcat(path, "/proc/");
    strcat(path, pids);
    strcat(path, "/cmdline");

    FILE *fp = fopen(path, "r");
    if (fp == NULL)
    {
        printf("Cannot open the file!");
        exit(1);
    }

    char *pname = malloc(1024);
    fscanf(fp, "%s", pname);
    return pname;
}

// kullanilabilir.
void print_process_info(const pid_t pid, pid_t ppid, char *pname)
{
    printf("%-20d%-20d%-50s\n", pid, ppid, pname);
}

// kullanilabilir.
void print_header()
{
    printf("%-20s%-20s%-50s\n", "ID", "Parent ID", "Command");
}

int main(int argc, char *argv[])
{
    int pid;
    int ppid;

    // writes table header to stdin
    print_header();
    // get process id
    pid = getpid();

    do
    {
        // get parent process id
        get_ppid(pid, &ppid);
        // writes process id, parent process id, process name to stdin
        print_process_info(pid, ppid, get_name(pid));
        pid = ppid;

    } while (ppid != 0);
}