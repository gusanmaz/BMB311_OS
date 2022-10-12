# Projeler

## Proje 1 - B205 Guc Ayarlari Isinin Otomatize Edilmesi (Ekstra Proje)

* Bu projede istenilenleri yerine getiren ogrenciler ekstra odev puani alacaklardir. 
* Bu projenin yapilmasi istege baglidir. Bu projeyi yapmadan da dersin odev notundan 100 alabilmeniz mumkundur.
* Bu projede 4 kisiye kadar takim calismasi yapabilirsiniz.

### Problem Tanimi

B205 laboratuvarina yeni alinan makinalardaki Windows 11 sistemlere
[Deep Freeze](https://www.faronics.com/en-uk/products/deep-freeze) yazilimi kurulmustur. Windows sistemlere bu 
yazilimin kurulmasinin ana nedenleri:
* Bilgisayarlari kullanan ogrencilerin Windows sistemlere kalici olarak program yuklemesinin
* Diske kaydedilen ve sonradan silinmeyen dosyalarla diskin sismesinin
onune gecebilmektedir.

Sistemde Deep Freeze aktive edildikten (frozen durumu) sonra diskte yapilan degisikler kalici olmamaktadir. Bilgisayar
yeniden baslatildiginda Deep Freeze'in aktive edildigi zamandaki sisteme geri donulmektedir.

Bu durumda sistemde degisiklik yapabilmek icin once Deep Freze programini thawed durumuna 
(bilgisayari yeniden baslatmayi gerektiriyor - boot thawed) getirmek ve gerekli degisikleri
yapip sistemde Deep Freeze'i yeniden frozen duruma getirmek (bilgisayari yeniden baslatma gerektiriyor - boot frozen) gerekmektedir.
Deep Freeze'in calisma mantigini daha iyi anlamak icin bu programi kendi bilgisayarinizda denemeniz faydali olabilir.

B205'deki yeni Dell bilgisayarlara Windows sistemler kurulurken guc ayarlari dogru yapilmamistir. Monitor uzerindeki
guc tusuna basildiginda bilgisayarlar kendini uykuya almaktadir ama guc tusuna basildiginda bilgisayarin kendini kapamasi
istenmektedir. Bu degisikligin yapilabilmesi icin Deep Freeze once deaktive edilmelidir. Daha sonra sisteme bu degisiklik
uygulandiktan sonra Deep Freeze yeniden aktive edilmelidir. Bu adimlari her yeni Dell bilgisayar icin tekrarlamaktansa bu isi 
otomatize edecek bir script/program yazmak bu isin yapimini hizlandiracak ve vakit kaybinin onune gececektir.

### Ek Bilgiler

* Windows bilgisayarlarda SSH sunucusu calismaktadir. Windows bilgisayarlara lokal IP adresleri kullanilarak SSH ile 
baglanilabilir. Yazacaginiz script/program belirli bir prefix'e sahip (Ornegin `10.202.17.***`) tum IP adreslerine 
SSH ile baglanmaya calisabilir. Yazacaginiz program SSH taramasi yapilacak IP prefix'ini, Windows admin hesabinin
sifresini, Deep Freeze sifresini ve programin paralel mi, seri mi calistirilmak istendigini parametre olarak alabilir. 
Asagida programin nasil paralel islemler yapabilecegi anlatilmaktadir.
* Deep Freeze CLI'e [https://www.faronics.com/assets/DF_RemoteAdministration.pdf](https://www.faronics.com/assets/DF_RemoteAdministration.pdf)
baglantisindaki dokumandan erisebilirsiniz. Deep Freeze'i aktive, deaktive etmek ve sistemin ne durumda (frozen veya thawed)
tespit edebilmek icin bu dokumanda belirtilen komutlar kullanilabilir.
* Komut satirindan guc ayarlarini degistirmek icin [https://winaero.com/change-power-button-action-windows-10/](https://winaero.com/change-power-button-action-windows-10/)
dokumani incelenebilir.
* Yazacaginiz script veya programin Linux sistemler uzerinden kolayca calistirilabilmesi gerekmektedir. Size verilen laboratuvar sorununu cozmek
icin bir Bash scripti yazmaniz tercih edilir ama isterseniz bu sorunu cozecek kodu sevdiginiz bir programlama dilinde de 
kodlayabilirsiniz. 
   * Nasil Bash scriptleri yazabileceginizi ogrenmek icin 
[https://ryanstutorials.net/bash-scripting-tutorial/](https://ryanstutorials.net/bash-scripting-tutorial/) baglantisindaki notlari okuyabilirsiniz.
Bash scripti yazabilmek icin Linux komut satiri hakkinda da temel duzeyde bilgi sahibi olmaniz gerekmektedir.
   * Programlama dillerinin sagladigi kutuphaneleri kullanarak da terminal komutlarini calistirabilirsiniz.
Ornegin Python'da terminal komutlarinin nasil calistirilabilecegi
[https://janakiev.com/blog/python-shell-commands/](https://janakiev.com/blog/python-shell-commands/) dokumaninda aciklanmaktadir. 
* Yazacaginiz script veya programin paralel SSH baglantilari yapmasi tercih edilmektedir. Ornegin `10.202.17.1` adresine
yapilacak olan SSH baglantisi ile `10.202.17.15` adresine yapilacak olan SSH baglantisi es zamanli olabilir. Eger bir
bilgisayardaki guc ayarlari degistirildikten sonra baska bir bilgisayara SSH baglantisi yapilirsa her bir bilgisayarda
guc ayarlarini degistirmenin 5 dakika vakit aldigi varsayilirsa programiniz labdaki tum yeni bilgisayarlarin guc
ayarlarini degistirmesi 5 * 40 = 200 dakika surebilir. SSH baglantilari paralel yapilirsa programiniz tum yeni 
bilgisayarlarin guc ayarlarini degistirmesi yaklasik 5 dakikada tamamlanabilir.
* Bir bilgisayar yeniden baslatildiginda farkli bir lokal IP adresi alabilecegini goz onunde bulundurunuz. 
Her bilgisayarin B205A1, B205C5 gibi farkli bir hostname'i vardir. Hostname bilgisi ile bilgisayarlari birbirinden ayirt etmeye belki gerek duyabilirsiniz.
* Yazdiginiz script veya programin nasil derlenebilecegini (script degilse) ve calistirilabilecegini projenizde 
yer alacak `README.md` isimli bir dosyada ayrintili bir sekilde aciklayiniz. Ayni dosyada projenize katki saglayanlarin
(kendiniz ve varsa proje grup uyelerinin) isim soyisim ve ogrenci numara bilgilerine yer veriniz.
* Mumkunse laboratuvar kosullarini Deep Freeze yuklu birkac bilgisayari ayni lokal aga baglayarak simule ederek yazdiginiz kodun
cozmesi beklenen sorunu cozup cozemedigini test ediniz.

### Proje Gonderimi - Submission

* Son gonderim tarihi: `23 Ekim 2022 - 23:59`
* Proje reponuzu [https://classroom.github.com/a/tq66HZgD](https://classroom.github.com/a/tq66HZgD) 
davet linki (Github Classroom) uzerinden olusturunuz. Bu yolla olusturulacak repositoryler daha kolay izlenebilmekte
ve toplu olarak indirilebilmektedir.

