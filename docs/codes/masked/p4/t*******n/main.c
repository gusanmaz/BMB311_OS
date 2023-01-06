#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char path[128];
     int piddegeri;
     char pidstring[5];
    
      printf("Bir Pid degeri girin!\n");
       scanf("%d", &piddegeri);
       sprintf(pidstring, "%d", piddegeri);
    strcpy(path, "/proc/");
    strcat(path, pidstring);
    strcat(path, "/comm");
   
    char c;

    FILE *fptr;
    fptr = fopen(path, "r");

    if (fptr == NULL)
    {
        printf("NULL\n");
        return 0;
    }

    do
    {
        c = fgetc(fptr);
        printf("%c", c);
    } while (c != EOF);

    fclose(fptr);

    printf("\n");

    return 0;
}
