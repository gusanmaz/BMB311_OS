# BMB311 Uygulama Notları, Projeleri ve Ödevleri

Bu repo'da uygulama derslerine ait materyallere (ders notlari, odev bilgileri, proje bilgileri, duyurular vb.) ulasabilirsiniz.

## DUYURU

***Proje 1 (Ekstra Proje) ilan edilmistir.***

[Detaylar](https://github.com/gusanmaz/BMB311_OS/blob/main/projects.md)

### Instructor

Ars. Gor. Güvenç Usanmaz

Oda: B207

Bolum: Bilgisayar Muhendisligi

Email: gusanmaz <att< nku nokta edu nokta tr

###

### Onerilen Kaynaklar

#### Isletim Sistemleri

* [Operating Systems: Three Easy Pieces](https://pages.cs.wisc.edu/~remzi/OSTEP/) ***Teorik Kaynak***
* [Advanced Linux Programming](https://mentorembedded.github.io/advancedlinuxprogramming/alp-folder/) ***Pratik Kaynak***
* [Operating Systems: Crash Course Computer Science #18](https://www.youtube.com/watch?v=26QPDBe-NB8) ***~10 dakikada isletim sistemleri***
* [Turkce Linux Dersleri](https://linux-dersleri.github.io/)
* [Belgeler.org (Muhtemelen Guncel Degil)](http://www.belgeler.org/)

#### Komut Satiri ve Kabuk Programlama

* [Linux Tutorial](https://ryanstutorials.net/linuxtutorial/)
* [Linux/Mac Tutorials - Corey Schafer](https://www.youtube.com/playlist?list=PL-osiE80TeTvGhHkpvfmKWOiIPF8UVy6c)
* [Bash Scripting](https://ryanstutorials.net/bash-scripting-tutorial/)
* [UNIX: Making Computers Easier To Use -- AT&T Archives film from 1982, Bell Laboratories](https://www.youtube.com/watch?v=XvDZLjaCJuw&t)

#### C Programlama

* [C Programming Language, 2nd Edition](https://www.amazon.com/Programming-Language-2nd-Brian-Kernighan/dp/0131103628/ref=sr_1_1?crid=YQFLRR2SUKAG&keywords=c+programming&qid=1665091837&qu=eyJxc2MiOiI1LjIxIiwicXNhIjoiNC42OCIsInFzcCI6IjQuNjMifQ%3D%3D&s=books&sprefix=c+programming%2Cstripbooks-intl-ship%2C275&sr=1-1)

* C dilinde kendini eksik goren ogrencilerimizin https://exercism.org/tracks/c sayfasindaki alistirmalari kodlamalari ve dogru kodladiklari alistirmalari baskalarinin nasil kodladigini incelemeleri tavsiye edilir.

### Onerilen Linux Dagitimlari

* [Distrowatch](https://distrowatch.com/)
* Ubuntu
* KDE Neon
* Pop!_OS
* OpenSuse
* Manjora

#### Linux Kurulumu
* Dual-boot
* Single-boot
* Sanal makine (Virtual Box, WMvare)
* Windows Subsystem for Linux (WSL)
* Virtual Private Server (VPS)
* B205 (?)
* Cygwin (?)
* [Repl.it](replit.com)

### AWS'de Linux Istance'i Olusturma

[https://github.com/Mona-Roza/Notes/tree/main/About%20Server%20%26%20About%20Linux](https://github.com/Mona-Roza/Notes/tree/main/About%20Server%20%26%20About%20Linux)

### Oracle VM VirtualBox Üzerine Debian Linux Kurulumu

[https://medium.com/@zeynepssasmaz953/oracle-vm-virtualbox-u%CC%88zerine-debian-linux-kurulumu-2c87dbe64aa9](https://medium.com/@zeynepssasmaz953/oracle-vm-virtualbox-u%CC%88zerine-debian-linux-kurulumu-2c87dbe64aa9)

#### Kurulumda Dikkat Edilecekler
* Onemli Verilerin Yedeklenmesi
* BIOS Boot Oncelikleri
* Disk Bicimlendirme (Gparted vb.)
* Once Windows, sonra Linux Kurulumu (?)
* USB ISO Creator (Etcher, UnetBootin)
* Legacy boot vs. UEFI
* Secure boot

#### Beklentiler
* Github hesabi acmak
* Bilgisayara Linux dagitimi kurmak
* Github Discussion sayfasinda aktif olmak
* Bu sayfayi duzenli araliklarla kontrol etmek
* Bu sayfada ilan edilecek proje ve odevlerde istenilenleri yapmak
* Universite email hesabinizi duzenli araliklarla kontrol etmek.

## Proje Notlandirmalari

* [Proje 1](https://gusanmaz.github.io/BMB311_OS/grades/p1.html)
* [Proje 2](https://gusanmaz.github.io/BMB311_OS/grades/p2.html)
* [Proje 3](https://gusanmaz.github.io/BMB311_OS/grades/p3.html)
* [Proje 4](https://gusanmaz.github.io/BMB311_OS/grades/p4.html)

* Tablolarda her satirda odev gonderen bir ogrencinin o projedeki testlerdeki basari durumu gorulebilir.
* REPO URL'sinden o ogrencinin proje icin gonderdigi `main.c` dosyasina ve uygulanan testlerle ilgili detayli bilgiler iceren json dosyasina erisilebilmektedir.
* Kodlari test etmek icin kullanilan programin kodlarina [https://github.com/gusanmaz/gracode](https://github.com/gusanmaz/gracode) baglantisindan erisebilirsiniz.

### Proje Test Dosyalari

* [Proje 1](https://github.com/gusanmaz/BMB311_OS/tree/main/docs/test_files/p1)
* [Proje 2](https://github.com/gusanmaz/BMB311_OS/tree/main/docs/test_files/p1)
* [Proje 3](https://github.com/gusanmaz/BMB311_OS/tree/main/docs/test_files/p1)
* [Proje 4](https://github.com/gusanmaz/BMB311_OS/tree/main/docs/test_files/p1)

* Test dosyalari `commands.sh` isimli Bash scripti dosyalarina yazilmistir.
* `gracode.json` isimli dosyada testlerin puan bilgisi, her test icin ogrencinin kodunun, referans kod ile karsilastirmasi icin hangi Python fonksiyonunun
kullanilacagi gibi bilgiler yer almaktadir.
* Referans kod ile ogrenci kodunun ciktilarinin (stdout ve stderr) karsilastirilmasi icin kullanilan Python fonksiyonlarini  [funcs.py](https://github.com/gusanmaz/gracode/blob/main/funcs.py) dosyasindan erisebilirsiniz.

### Referans Proje Kodlari

* [Proje 1](https://github.com/gusanmaz/BMB311_OS/blob/main/docs/codes/masked/p1/g******z/main.c)
* [Proje 2](https://github.com/gusanmaz/BMB311_OS/blob/main/docs/codes/masked/p2/g******z/main.c)
* [Proje 3](https://github.com/gusanmaz/BMB311_OS/blob/main/docs/codes/masked/p3/g******z/main.c)
* [Proje 4](https://github.com/gusanmaz/BMB311_OS/blob/main/docs/codes/masked/p4/g******z/main.c)

### Performans Analizi

* Her odev icin `perf` komutu ile performans analizi yapilmistir. Bu komutun kodunuz icin urettigi ciktiya ilgili json dosyasindan erisebilirsiniz.
* Kodlarin notlandirilmasinda kodlarin performansi kriter olarak kullanilmamistir.
* Bununla birlikte her testin belli bir surede tamamlanmasi beklenmektedir. Her test icin ayri belirlenen bu sureleri `commands.sh` dosyalarini inceleyerek gorebilirsiniz. Eger JSON dosyasinda bir test icin `timeout` degeri `True` gozukuyorsa ilgili kodun testte verilen maksimum sure icinde calismasini bitiremedigi anlasilmalidir.

### Tablo Okuma

* Mouse imlecini tablolarin basligindaki testlerin uzerine getirerek referans kodun o test icin urettigi ciktiyi (stdout, stderr) gorebilirsiniz.
* Ayni sekilde belirli bir sekilde ogrenci icin mouse imlecini testlerin uzerine getirerek ilgili kodun o test icin urettigi ciktiyi (stdout, stderr) gorebilirsiniz.
*  `stdout` ve `stderr` ciktilarinin cok uzun olmasi durumunda bu ciktilari tablo uzerinde goremeyebilirsiniz. Bu durumda ilgili ciktilara ilgili JSON dosyasindan erisebilirsiniz.
*  Tablolarda sadece kurallara uygun gonderim yapan ogrencilerin isimleri gozukmektedir.
*  Tablolardaki satirlar ogrenci numarasina gore siralidir.

### JSON

* `https://github.com/gusanmaz/BMB311_OS/blob/main/docs/codes/masked/` altindaki bir json dosyasini incelemek istiyorsaniz bu dosyayi once bilgisayariniza indirmeniz veya JSON verisinin tamamini bilgisayarinizda bir metin editorune kopyalayip, json uzantisiyla kaydetmeniz tavsiye edilir.
* Daha sonra bilgisayarindaki bu JSON dosyasini bir JSON Goruntuleyici program yardimiyla daha rahat goruntuleyebilirsiniz. 
* Pek cok ucretsiz JSON Goruntuleyici (JSON Viewer) program bulunmaktadir.
* JSON dosyalarinin goruntulemek icin `Mozilla Firefox` internet tarayicisini da kullanabilirsiniz.

### Beklenilenden Dusuk Not Alma Nedenleri

* Olusturulan repoya ogrenci_no.txt isimli dosya eklememek
* Olusturulan repodaki kodlari main.c isimli dosya haricinde bir dosyaya yazmak.
* Proje aciklamalarinda argumanlarin komut satirindan alinacagi belirtilmesine ragmen `scanf` gibi fonksiyonlarla kullanicidan input almaya calismak
* Her bir proje icin ayri bir repo davet linki verilmesine ragmen butun proje kodlarini tek bir repoya yuklemek

### Proje Notlandirma Detaylari

* 1. proje 100
* 2. proje 130
* 3. proje 145
* 4. proje 120

puan uzerinden degerlendirilmistir.















