#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
int kelime (char a[200])
{
    int i=0;
    int k=0;
    int karakter;
    karakter=32;
    while (a[i] != ´\0´)
    {
	  if (a[i]==karakter)
	  {
	      k++;
	  }
       i++;
    }
	return k;
}
int karakter_sayisi_bul(char *pcumle,char p);
main()
{
	char cumle[200];
	int i,sayac,k,t,x,karakter_sayisi;
	printf("\n Cumleyi giriniz=");
	gets(cumle);
	printf("\n Aranacak Karakteri Giriniz=");
	scanf("%c",&t);
	for(i=0;i<200;i++)
	{
	       cumle[i]=tolower(cumle[i]);
	}
	printf("\n Girilen cumle %s ",cumle);
	x= kelime(cumle);
	x=x+1;
	printf("\n Girilen cumle %d kelimeden olusuyor.",x);
	karakter_sayisi=karakter_sayisi_bul(cumle,t);
	printf("\n Girilen cumlede %c karakteri %d tane bulunuyor.",t,karakter_sayisi);
	getch();
	return 0;

}
int karakter_sayisi_bul(char *pcumle,char p)
{
   int sayac=0;

   while(*pcumle!=´\0´){
   if(*pcumle==p){
       sayac++;
	 }
	 pcumle++;         }
	 return sayac;

}
