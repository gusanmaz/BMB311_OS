#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

char *get_name(int pid) {
  char path[1024] = "";
  char pids[20];
  sprintf(pids, "%d", pid);

  strcat(path, "/proc/");
  strcat(path, pids);
  strcat(path, "/cmdline");

  FILE *fp = fopen(path, "r");
  if (fp == NULL) {
    printf("Null\n");
    exit(1);
  }

  char *pname = malloc(1024 * 4);
  fscanf(fp, "%s", pname);
  return pname;
}

int main(int argc, char *argv[]) {
  if (argc == 1 || argc < 1) {
    printf("NULL\n");
    return 0;
  }
  char *dosya = argv[1];
  int y = atoi(dosya);
  char *pAdi = get_name(y);
  printf("%s\n", pAdi);

  int i = 0;
  char *p = strtok(pAdi, "/");
  char *array[100];

  while (p != NULL) {
    array[i++] = p;
    p = strtok(NULL, "/");
  }

  printf("%s\n", array[i - 1]);
}
