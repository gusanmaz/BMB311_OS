#include <assert.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>

unsigned long long global_count = 0;

void *mythread(void *arg) {
    unsigned long long local_count = 0;
    FILE *fp = fopen((char*)arg, "r");
    char next_char;
    if(NULL != fp) {
        do{
            next_char = (char)fgetc(fp);
            if('1' == next_char) {
                local_count+=1;
            }
        }while(EOF != next_char);
        fclose(fp);
    }
    global_count += local_count;
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t p_arr[argc-1];
    for(int i = 1; i < argc; i++) {
        int rc = pthread_create((p_arr+i-1), NULL, mythread, *(argv+i));
        assert(rc == 0);
    }
    for(int i = 0; i < argc-1; i++) {
        (void) pthread_join(p_arr[i], NULL);
    }
    printf("Total Number of Ones in All Files: %llu\n", global_count);
    return 0;
}
