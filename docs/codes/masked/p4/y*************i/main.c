#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *concatenate(const char *a, const char *b, const char *d)
{
    size_t len = strlen(a) + strlen(b) + strlen(d);
    char *str = malloc(len + 1);
    strcpy(str, a);
    strcat(str, b);
    strcat(str, d);
    return str;
}

int main(int argc, char *argv[])
{

    if (argv[1] != NULL)
    {
        const char a[] = "/proc/";
        const char d[] = "/comm";
        char *str = concatenate(a, argv[1], d);
        FILE *demo;
        int display;
        if (fopen(str, "r") != NULL)
        {
            demo = fopen(str, "r");
            while (1)
            {
                display = fgetc(demo);
                if (feof(demo))
                    break;

                printf("%c", display);
            }
            fclose(demo);
            // printf("%s\n", str);
            free(str);
        }else{
            printf("NULL\n");
        }
    }
    else
    {
        printf("NULL\n");
    }

    return 0;
}
