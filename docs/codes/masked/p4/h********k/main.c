#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <assert.h>

char *get_name(int pid)
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
      printf("NULL\n");
      exit(1);
   }

   char *pname = malloc(1024 * 4);
   fscanf(fp, "%s", pname);
   return pname;
}

int main(int argc, char *argv[])
{
   if (argc <= 1)
   {
      printf("NULL\n");
      return 0;
   }
   char *arguman = argv[1];
   int arguman2 = atoi(arguman);
   char *pAdi = get_name(arguman2);
   // printf("%s\n", pAdi);

   int i = 0;
   char *parcala = strtok(pAdi, "/");
   char *array[100];

   while (1)
   {
      if(parcala==NULL)
      {
         break;
      }
      array[i++] = parcala;
      parcala = strtok(NULL, "/");
   }

   printf("%s\n", array[i - 1]);
}
