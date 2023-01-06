#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int count = 0;

void *readFile(void* file_name)
{
    FILE * file = fopen(file_name,"r");

    int tempCount = 0;
    if (file != NULL)
    {
       while (!feof(file))
       {
          char temp = fgetc(file);
          if (temp == '1')
          {
             tempCount = tempCount + 1;
          }
       }
       fclose(file);
       count = count + tempCount;
    }
}

int main(int argc, char *argv[])
{
    int file_count = argc - 1;
    
    pthread_t my_thread[file_count];
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    for (int i = 0; i < file_count; i++)
    {
      pthread_create(&(my_thread[i]), &attr, &readFile, argv[i + 1]);
    }

    pthread_attr_destroy(&attr);

    for (int i = 0; i < file_count; i++)
    {
      pthread_join(my_thread[i], NULL);
    }
    printf("Total Number of Ones in All Files: %d \n", count);
    pthread_exit(NULL);
}

