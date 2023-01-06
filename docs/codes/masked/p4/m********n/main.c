#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    int pidNumber;
    printf("Enter pid number: ");
    scanf("%d", &pidNumber);

    char procPath[1024];
    sprintf(procPath, "/proc/%d", pidNumber);
    struct stat sb;

    if (stat(procPath, &sb) == 0 && S_ISDIR(sb.st_mode)) {
        char commPath[1024];
        sprintf(commPath, "/proc/%d/comm", pidNumber);

        FILE *file = fopen(commPath, "r");
        char *commName = malloc(1024);
        fscanf(file, "%s", commName);

        printf("%s\n", commName);

        fclose(file);

    } else {
        printf("NULL\n");
    }

    return 0;
}
