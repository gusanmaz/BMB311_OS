#include <assert.h>
#include <stdio.h>
#include <pthread.h>

typedef struct {
    int x;
    int y;
} myarg_t;

void *mythread(void *arg) {
    myarg_t *args = (myarg_t *) arg;
    printf("%d %d\n", args->x, args->y);
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t p;
    myarg_t args = { 10, 20 };

    int r = pthread_create(&p, NULL, mythread, &args);
    assert(r == 0);
    (void) pthread_join(p, NULL);
    printf("done\n");
    return 0;
}


