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
  printf("Hata:PID degeri girilmemiş – Fazla PID girilmis\n");
  exit(1);
 }
 char ch;
 sprintf(buffer,"/proc/%d/comm",pid);
 FILE *f=fopen(buffer,"r");
    
 if(f==NULL)
 {
   printf("NULL\n");
   exit(1);
 }
 
    
 do
 {
   ch=fgetc(f);
   printf("%c",ch);
 } while(!feof(f)) ;
    
 fclose(f);
 return 0;
      
}
