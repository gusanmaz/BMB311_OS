#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

char* getName(int pid) 
   {
   char* name="Null";
   char buffer[1024];
   sprintf(buffer, "/proc/%d/stat", pid);
   FILE* fp = fopen(buffer, "r");
   if (fp) 
         {   
         size_t size = fread(buffer, sizeof (char), sizeof (buffer), fp);
         if (size > 0) 
            {         
            strtok(buffer, " "); // (1) pid  %d
            name=strtok(NULL, " "); // (2) comm  %s          
            for(int i=1;i<strlen(name)-1;i++)
            name[i-1]=name[i];         
            name[strlen(name)-2]='\0';       
            }
         fclose(fp);     
         }
   return name;
   }

int main(int argc, char *argv[])
    {
    char* name=getName(atoi(argv[1]));
    printf("%s\n",name);
    return 0;
    }
