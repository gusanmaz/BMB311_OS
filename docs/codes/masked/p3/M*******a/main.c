#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

// mainden threade parametre geçişi için kullanıyorum
struct mainargs
{
    char *path;
};

// threadden maine parametre geri döndürmek için kullanıyorum.
struct rtrnargs
{
    int value;
};

void *mythread(void *arg)
{
    struct mainargs *args = (struct mainargs *)arg;             // mainden gelen pathi okumak için argumanı çektik
    struct rtrnargs *rtrnval = malloc(sizeof(struct rtrnargs)); // değer döndürmek için yer ayırdık.
    FILE *filep = fopen((args->path), "r");                     // path ile belirtilen dosya pointeri

    if (filep == NULL) // dosya mevcut değilse value 0 olsun
    {
        rtrnval->value = 0;
    }
    else // dosya mevcutsa value stringdeki 1 sayısını hesaplar.
    {
        assert(rtrnval != NULL);
        int data;
        int one_counter = 0;
        while (!feof(filep))
        {
            data = fgetc(filep);

            if (data == EOF)
                break;
            else if (data == 49) // 1'in ascii kodu 49 olduğu için
            {
                one_counter++;
            }
        }
        rtrnval->value = one_counter;
        fclose(filep);
    }
    return (void *)rtrnval;
}

int main(int argc, char *argv[])
{
    pthread_t p;
    int i;
    int sum_of_ones = 0;
    struct rtrnargs *rtrnval;
    for (i = 1; i < argc; i++)
    {
        struct mainargs args = {argv[i]};
        pthread_create(&p, NULL, mythread, &args);
        pthread_join(p, (void **)&rtrnval);
        sum_of_ones += (rtrnval->value);
        free(rtrnval);
    }
    printf("Total Number of Ones in All Files: %d\n", sum_of_ones);
    exit(0);
}
