#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        int pid = atoi(argv[1]);
        char *procname = (char *)malloc(sizeof(char) * 1024);
        FILE *fp;
        char path[1024];
        sprintf(path, "/proc/%d/comm", pid);
        fp = fopen(path, "r");
        if (fp) {
            fgets(procname, 1024, fp);
            procname[strlen(procname)-1] = 0;
            printf("%s\n", procname);
            fclose(fp);
        } else {
            printf("NULL\n");
        }
    }
    return 0;
}
