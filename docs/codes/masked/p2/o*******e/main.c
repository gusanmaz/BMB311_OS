#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

void get_ppid(const pid_t p_id, pid_t *pp_id)
{
    char buff[1024];
    sprintf(buff, "/proc/%d/stat", p_id);
    FILE *fp = fopen(buff, "r");
    if (fp)
    {
        size_t size = fread(buff, sizeof(char), sizeof(buff), fp);
        if (size > 0)
        {
            strtok(buff, " ");             
            strtok(NULL, " ");                
            strtok(NULL, " ");                
            char *s_pp_id = strtok(NULL, " ");
            *pp_id = atoi(s_pp_id);
        }
        fclose(fp);
    }
}

char *get_name(const pid_t p_id)
{
    char path[1024] = "";
    char p_ids[20];
    sprintf(p_ids, "%d", p_id);

    strcat(path, "/proc/");
    strcat(path, p_ids);
    strcat(path, "/cmdline");

    FILE *fp = fopen(path, "r");
    if (fp == NULL)
    {
        printf("Cannot open the file!");
        exit(1);
    }

    char *p_name = malloc(1024);
    fscanf(fp, "%s", p_name);
    return p_name;
}

void print_process_info(const pid_t p_id, pid_t pp_id, char *p_name)
{
    printf("%-20d%-20d%-50s\n", p_id, pp_id, p_name);
}

void print_header()
{
    printf("%-20s%-20s%-50s\n", "ID", "Parent ID", "Command");
}

int main(int argc, char *argv[])
{
    int p_id;
    int pp_id;

    print_header();
    p_id = getpid();

    do
    {
        get_ppid(p_id, &pp_id);
        print_process_info(p_id, pp_id, get_name(p_id));
        p_id = pp_id;

    } while (pp_id != 0);
}
