#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <pthread.h>

long unsigned int degisken = 0;

//thread fonksiyonu
void* counter(void* param){

        char *fileisim = (char*)param;

        FILE* rk = fopen(fileisim,"r");

            if (rk == NULL)//argüman boş
            {
                degisken = degisken;
            }
            else
            {
                int id;

                while((id=fgetc(rk))!= EOF){


                        if((int)id == 49){

                           degisken++;
                        }
                }

                pthread_exit(0);
            }


    }

int main(int argc, char *argv[])
{

    pthread_t *tid;  

    tid = (pthread_t *)malloc((argc - 1) * sizeof(pthread_t));

    //argümanın bir eksiği for döngüsü
    for(int i=1; i < argc; i++){

        pthread_create(&tid[i],NULL,counter,argv[i]); //thread creat
        pthread_join(tid[i],NULL);                      //thread wait
    }

    printf("Number of total '1' in all file --> %lu \n", degisken);



    return 0;
}
