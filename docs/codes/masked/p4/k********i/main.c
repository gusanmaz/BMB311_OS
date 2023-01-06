#include <stdio.h>
#include <stdlib.h>

int main (int argc,char *argv[])
{
char buffer[1024];
int pid;
  if(argc==2)
 {
  pid=atoi(argv[1]);   
 }
 else if(argc!=2)
 {
  printf("Hata:PID degeri girilmemis ya da Birden fazla PID degeri girilmis olabilir.\n");
  exit(1);
 }
 char ch;
 sprintf(buffer,"/proc/%d/comm",pid);
 FILE *fp=fopen(buffer,"r");
    
 if(fp==NULL)
 {
   printf("NULL\n");
   exit(1);
 }
 
 //ch=fgetc(fp);
    
 do
 {
   ch=fgetc(fp);
   printf("%c",ch);
 }while(ch!=EOF); //while(!feof(fp)) olabilir.
    
 fclose(fp);
 return 0;
      
}
