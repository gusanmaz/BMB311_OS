#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


int temp=0;

void *fonk(void *param)
{
/* char buffer[1024]; olarak tanimlanabilir fakat kac karakter geleceği bilinmiyor. Bu sebeple malloc() dinamik bellek yapilir */
char *buf=(char*)malloc(sizeof(char)); 
sprintf(buf,"%s",param);
FILE *fp = fopen(buf,"r");
char ch;

if(fp!=NULL)
{

do
{
ch=fgetc(fp);
//printf("%c",ch);   *** Dosya icerikleri yazdirilabilir.
if(ch=='1')temp++;
}
while(ch!=EOF);
}
free(buf);
// fclose(fp); (??) -- > Segmentation Fault(core dumped) hatasi veriyor.
}



int main(int argc,char *argv[])
{
	
        if(argc>1)
        {

        argc-=1;
        argv+=1;
        pthread_t thread[argc];
        for(int i=0;i<argc;i++)
        {
                pthread_create(&thread[i],NULL,fonk,argv[i]);
               	pthread_join(thread[i],NULL);
	       	//printf("%s\n",argv[i]); **** Girilen dosya isimleri yazdirilabilir. 
        }

        }
 	
	/*
        else
        {
        printf("Text dosyasi girilmemis, 1 sayisi : 0");
        }
	*/ 						//gereksiz kontrol kısmı
	
	printf("Girilen text dosyalarindaki toplam 1 sayisi : %d\n",temp);
}
