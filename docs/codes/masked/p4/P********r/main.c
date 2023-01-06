#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char path[128];
    strcpy(path, "/proc/");
    strcat(path, argv[1]);
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
