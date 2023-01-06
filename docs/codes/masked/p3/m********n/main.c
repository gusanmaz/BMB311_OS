#include <stdio.h>
#include <pthread.h>
#include <glob.h>
#include <stdlib.h>
#include <string.h>


struct results {
    int count;
};

struct readerArgs {
    char fileName[100];
};

void *reader(struct readerArgs *args) {
    FILE *file  = fopen(args->fileName, "r");
    int c;
    struct results *total = malloc(sizeof (struct total *));
    total->count = 0;

    while ((c = fgetc(file)) != EOF)
    {
        if(c == (int) '1') {
            total->count++;
        }
    }

    fclose(file);
    pthread_exit(total);
}



int main(int argc, char *argv[]) {
    int argIndex, globIndex, i, threadCount = 0, total = 0;
    pthread_t *threads;

    for (argIndex = 1; argIndex < argc; argIndex++) {
        glob_t globbuf;
        if (!glob(argv[argIndex], 0, NULL, &globbuf)) {
            threads = malloc(globbuf.gl_pathc * sizeof (struct pthread_t *));
            struct readerArgs *args[globbuf.gl_pathc];

            for (globIndex=0;  globIndex < globbuf.gl_pathc; globIndex++) {

                args[threadCount] = malloc(sizeof (struct readerArgs *));
                strcpy(args[threadCount]->fileName, globbuf.gl_pathv[globIndex]);

                printf("Reading %s\n", args[threadCount]->fileName);
                pthread_create (&threads[threadCount], NULL, reader, args[threadCount]);

                threadCount++;
            }
            printf("\n");
            globfree(&globbuf);
        }
    }

    struct results *results[threadCount];

    for (i = 0; i < threadCount; i++) {
        pthread_join (threads[i], (void **)&results[i]);
        total = total + results[i]->count;
    }

    printf("Total %d\n", total);

    return 0;
}







