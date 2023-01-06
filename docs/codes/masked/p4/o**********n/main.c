#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

void get_ppid(const pid_t pid, pid_t *ppid) {
  char buffer[1024];
  sprintf(buffer, "/proc/%d/stat", pid);
  FILE *fp = fopen(buffer, "r");
  if (fp) {
    size_t size = fread(buffer, sizeof(char), sizeof(buffer), fp);
    if (size > 0) {
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

char *get_name(const pid_t pid) {
  char path[1024] = "";
  char pids[20];
  sprintf(pids, "%d", pid);

  strcat(path, "/proc/");
  strcat(path, pids);
  strcat(path, "/cmdline");

  FILE *fp = fopen(path, "r");
  if (fp == NULL) {
    printf("NULL");
    exit(1);
  }

  char *pname = malloc(1024);
  fscanf(fp, "%s", pname);
  return pname;
}

void print_process_info(char *pname) { printf("%-20s", pname); }

int main(int argc, char *argv[]) {

  int pid = getpid();
  scanf("%d", &pid);

  int ppid;
  get_ppid(ppid, &ppid);
  char *pname = get_name(pid);

  print_process_info(pname);
  free(pname);
}
