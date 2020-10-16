Videolu Ders Notları:
- Bir fonksiyon string döndürdüğün de aslında stringin ilk pointer adresini döndürür ve o pointer adresinin bitişine kadar bir döngü içerisin de değerleri alarak bize string yani karakter dizisini bütün bir halde verir.
	- Peki sonunu nasıl anlıyor? örneğin onur karakter dizisi |o|n|u|r| olarak 4 byte olarak söylenebilir fakat daha detaylı bakarsak onur karakter dizisinin bitişini belirtmek için ek olarak bellekte /0 sözel adıyla null değeri kullanılır ki bu da karakter dizimii 5 bytelık bir dizi haline getirir. Programımız da pointer ile aldığı başlangıç adresinden null değerini bulana kadar değerleri alacak, null'a geldiğin de ise bittiğini anlayacak ve aldığı değerleri bir bütün halinde(herhangi bir döngü ile yapılabilir) yazdıracak.
- Bilgisayarlar sayısal tabanlı çalıştığı için bir string ile diğer stringi karşılaştırdığımızda aslında 1.stringin bellekte ki ilk adresini(mesela 0x100) ile diğer stringin bellekte ki adresini (0x900)ü karşılaştırır - string değerleri aynı olsa bile!(örn: 1.string onur, 2.string onur)-. Bu yüzden biz işaretçileri kullanarak o stringin yani karakter dizisinin adresini bulup, içerisin de ki değeri alarak; aynı işlemi 2.string için yapıp, değerleri karşılaştırarak bir sonuca vararız. 
- string diye bir şeyin C için olmadığını öğrendik. Aslında char *string yaparak, * ile string değişkenimizin başlangıç değerini tutan bir değişken oluşturduğumuzu ve derleyici tarafından nerede bittiği algılanarak; dolaylı, teknik yoldan bir string yapmış olduk.
- NULL'un kullanımını ve tanımını öğrendik. NULL hiçbir şey demektir. Yani 0, bir şeydir; 0, bir değerdir ama NULL, hiçbir değer değildir. Bellekte NULL, 0x0 olarak gösterilir. Yani bellekten 0x0 değeri alırsak, ulaşmak istediğimiz yerde herhangi bir değer yok demektir.
- malloc() fonksiyonunu yani Memory Allocation fonksiyonunu gördük. Örnek olarak malloc(strlen("onur") +1 * sizeof(char)); olarak kullanabiliriz burda onur karakterinin uzunluğunda ve /0 yani null alanı için de bir alan ekleyerek bize char değerinden yani hücre başı 1 byte olacak şekilde bir alan ayırdı. yani 5*1 den 5 bytlık bir alan oluşturdu.
- dizileri döngü kullanarak kopyalayabilirken, modern çözüm olarak strcpy(dizi1, dizi2); fonksiyonunu kullanabiliriz. 
- memory leaking dediğimiz, malloc ile bellek alanı oluşturulması ve daha sonrasın da bu alanın serbest BIRAKILMAYARAK, birden fazla kez bu işlemin yapılması sonucun da belleğimizin dolması olayına denir.
	- Bu olaya çözüm olarak free(değişken-veya-dizi); fonksiyonunu kullanarak bellekte ki alanı boşaltabiliriz.
- scanf("%i", &x); kullanarak girilen değerin %i yazdığımız için int olarak formatlanıp, x'in bellek adresini tespit edip içine yazmasını belirtiiyoruz.
	- fakat bu durumda x, char *x olarak tanımlanmışsa & ifadesini yazmaya gerek yoktur çünkü &, işaretçi olmayan değişkenlerin bellek adresini almamız için kullanılır(reference operator). char *x yaparsak, x zaten bir bellek adresi tutuyordur.
- Dizilere işaretçi gibi davranabiliriz.
- char s[6] gibi ifade kullandık.
- segmentation fault hatası bizim değişkenimize öyle bir değer girdik ki, ona ayırdığımız belleğin dışına çıkmaya çalıştı(çünkü daha büyük, fazla byte değerin de bir değer girdik) demek oluyor.
- %p formatı ile printf veya scanf veya formatlanmış fonksiyonlar da pointer değerini kullanabiliriz.
- bellek adresleri 16lık sistem olan hex taban düzenin de yazılır, kullanılırlar. hex to dec diyerek googlede gerçek bellek adresini bulabiliriz. Hex'i kullanmamızın nedeni daha kompakt, okunabilir değerler oluşturmak ve 2lik tabannın yani binary ile daha rahat çevrim(çünkü 16 2'nin 4.kuvveti)işlemi yapılması.
- dereference'i gördük. eğer pointerları int *a şeklinde tanımlarız fakat pointerlarla tanımlama değil işlem yaparken * kullanırsak bu dereference yani a'nın bellek adresin DE Kİ  değeri elde ederiz.
- ramde stack ve heap alanlarına değinildi, stack dediğimiz alan statik olarak tanımlama, heap dediğimiz dinamik bellek adreslerinin tutulduğu yerdir.
	- statik olarak derken mesela a = 5 yaptığımızda, a heap de yer alan dinamik bir alandır, stack de 5 tutulurken heap te a tutulur. sonrasında stack ile heap yani 5 ile a pointerlar ile bağlanarak değişkenimize değer atanmış olur.
- ram bellekte kötü bir tasarımı ele aldık.
	- örneğin int *x olarak bir x pointerı tanımladık.
	- sonrasında x = malloc(size(int));  diyerek x'imize int byte değerinde alan oluşturduk
	- sonrasında *x = 5; diyerek x değerimizin bulunduğu bellek adresinin içine 5 değerini atadık.
	- şimdi int *y; yi tanımladık.
	- malloc olmadan direk *y= 5; yaptık.
		- burada y'yi tanımlayıp malloc yapmadığımız için bize çöp değer yani bellekte ayrılmış olduğu yerde ki önceki değer veya random değer alıcak. Bu da pek güvenli bir yöntem değil.
- fonksiyonları çağırdığımız da bize değer döndürdüğü için ve bu değerler stack de tutulduğu için, çok fazla fonksiyon çağırırsak stack belleğimiz, ram bellek üzerinde fazla yer tutacaktır ki hatta o kadar fazla çağırırsak segmentation fault dediğimiz taşma olayını yaşayabiliriz.
- kendi veri türlerimizi yapabilceğimizi öğrendik:

typdef struct{
	char *adi;
	char * soyadi;
}ogrenci;

- ogrenci yeniKayit.adi = "Onur";
- ogrenci yeniKayit.soyadi = "YILDIZ";
Kısa Video 1(Recursion[Özyineleme]):
- Özyinelemeyi kodumuzu daha zarif bir şekilde gözükmesi için kullanabiliriz.
- Özyineleme de 2 katman vardır.
	- 1.base case dediğimiz tetiklendiğin de fonksiyonumuzu çağırmayı durdurucak etkendir. Bu olmadığı takdir de fact(5) = 5 * fact(4); gibi bir kod sonsuz döngüye girecektir değil mi?
	- 2.recursive case, özyineleme kısmı; yani yinelememizin ana kısmıdır.
- özyinelemeli bir fonksiyon tanımlarken iskeletimiz şu şekilde olmalıdır:
int funct(int n)
{
	//base case(yani fonksiyonumuzun durup, durmuyacağının kontrol edildiği yer
	if(n == 1)
		return 1;
	//recursive case, yani yineleme işleminin kendisi
	else
		return n * funct(n-1);    
	
	// daha okunabilir bir kod için koşulumuz sonucu gerçekleşecek sadece 1 dallanma olduğu için süslü parantezleri kullanmıyoruz.
}
- özyineleme kullanabildiğimiz yerde döngü vb. kullanmamızın programımızı daha az zarif ve karmaşık hale getirilceğinden bahsedildi.
Kısa Video 2(Hexadecimal[On Altılık Sayı Sistemi]):
- 2 tabanlı sayıların insanlar için daha anlaşılabilir olması için hexdecimal sayı tabanını kullanıoyurz
- 0-9 9-f şeklin de alfabetik düzeni vardır.
- 16, 2nin tam kuvveti olduğu için taban da 0'dan f'ye kadar her rakan; iki tabanında 4 rakamlı bir sayıya, 4 bite denk geliyor.
- decimalin 0'ı ile hexdecimal'in 0'ını yan yana yazarsak ayırt etmemiz mümkün mü? eh pek de değil. O yüzden hexdecimal sayıların, hexdecimal olduğunu belirtmek için önlerine 0x eki ekliyoruz.
- hexdecimal basamak sistemi şöyledir.
	- decimal yani 10luk sistemde 10^0 = birler basamağı, 10^1 = onlar basamağı 10^2, yüzler basamağı iken
	- hexdecimal de 16^0 = birler basamağı, 16^1 = onlar basamağı, 16^2 = yüzler basamağı diye gider.
	- 0x356, üç beş altı diye okunur, 356 değil. Çünkü bizim okuduğumuz üç yüz elli altı metni, 10luk basamak sistemine göredir.
- binary yani 2lik tabandaki her 4 basamaklı sayı, hexdecimal tabanında 1 sayıya eşit(çünkü hexdecimal 16 üzerine yani 2nin 4.kuvveti uzerine kurulu bir sistem). Binary bir sayı dizisi görürsek yapmamız gereken sağdan sola binary'leri ayırmak ve bunları hexdecimal tablosunda ki değerler ile eşleştirmek. 
Kısa Video 2(File Pointers[Dosya İşaretçileri]):
- FILE* ptr1 = fopen("file.text", "r"); yaparak bir dosya işaretçisi oluşturup ona dosya yolunu ve hangi izinle açacağını atayabiliriz.
- fclose(); ile işimizin bittiği bu pointer'ın bağlantısını stackden heap'e(memory konusu) kesebiliriz.
- fgetc(ptr1) ile dosyamızın karakterlerini alabiliriz.
	- char ch;
	- while((ch = fgetc(ptr1) != EOF)
		- printf("%c", ch);
	- burada EOF stdio.h->FILE içerisin de bulunan özel bir deyimdir ve metnin son karakterini ifade eder. Yani bu kod ile metnimiz de ki tüm karakterleri birnevi dosyamızın içinde ki herşeyi yazdırmış oluyoruz.
- fputc("koyulacakmetin", ptr1); yaparak ptr1'in içine koyulacakmetin yazısını koyabiliriz. Eğer fopen("file.text", "a") ile açarsak ki bu append anlamına gelen bir yetkidir, koyulacakmetin dosyanın sonuna yazılır.
	- char ch;
	- while((ch = fgetc(ptr1) != EOF)
		- fputc("%c", PTR2); yaparak ptr1 de ki herşeyi PTR2 ye kopyalamış oluruz.
- Not: iterasyon; tekerrür, tekrarlama manasına gelir. Programlama da bir dizi işlemin döngü kullanılarak yazılması anlamına geliyor.
- Not 2: declare etmek; değişken, dizi oluşturmak.
- fread ve fwrite; fgetc ile fputs'un daha fonskiyonel halidir.
- fread(<buffer>, <size>, <qty>, <file pointer>); olarak 4 adet argüman verilir.
	- buffer dediğimiz yer okunacak bilginin saklanacağı yer. İşaretçi olmalı
		- int arr[10] dediğimiz de önceki notlarımıza bakarsak diziler işaretçi gibi davranabilir yani arr yazarsak bir yere, bu arr[0]'ın bellekte ki yerini işaret eder.
		- double* arr = malloc(sizeof(double) * 80); yaparak arr'ı atayabiliriz alternatif olarak.
		- char c; gibi c'yi atamak istersek &c yazarak, yani c'nin bellek adresini yollarak bunu fread de kullanabiliriz.
	- size, sizeof(char yada double yada int) artık saklayacağımız adresin veri türü neyse onu kullanıyoruz
	- qty, büyüklüğü yani arr kullancaksak mesela size'a sizeof(int) qty olarak da 10 böylece 4*10dan 40 bytelık bir yer okuyacağız demek oluyor.
	- file poniter, dosya işaretçimiz.
- fwrite(<buffer>, <size>, <qty>, <file pointer>);
	- örn:
		- int arr[10];
		- fwrite(arr, sizeof(int), 10, ptr1);
- fgets, fputs, char olarak değilde string yani karakter dizi olarak okur, yazar.
- ftell() ile dizi içersiinde kaçıncı byte da olduğumuzu görürüz böylelikle duruma göre işlemler yapabiliriz.
Kısa Video 3(Call Stack[Çağrı Yığını]):
- Call stack, programlama da fonksiyonların çalışma mantığını anlamamız için önemli bir konudur. recursive functions yani özyinelemeli fonksiyonlar da tamamen fonksiyon mantığı ile çalıştığı için, recursive functionsları anlamak için de gayet önemli.
- Call stack, programımızın fonksiyonları çağırma, düzenleme, çalıştırma düzeninin yapıldığı mantıktır.
	- int main(){
		- printf("%i", recursive_func(5));
	- }
- call stacki üsten aşağı, 1-9 sisteminde düşünürsek. main şuan tek çağırılan fonksiyon bu yüzden call stackimizde 1.sırada yalnız. Her bir katmana stack frame veya function frame deriz. Aktif olan frame en üstteki frame'dir ve active frame olarak adlandırılır, diğer frameler, yani fonksiyonlar sonlanmaz! Sadece bir alt kademeye geçerek hazırda beklerler. Sonlanma return işlemi olursa gerçekleşir.
	- sonrasında printf() fonksiyonu çağırılıyor, şuan 1.sırada printf var 2. yani alt sırada main var.
	- printf recursive_func'u çağırıyor ve ondan bir değer bekliyor, şuan recursive_func 1, printf 2, main 3.sırada
	- recursive_func'umuzu şöyle düşünürsek.
recursive_func(int n)
{
	if(n == 1)
		return 1;
	return n * recursive_func(n-1);
}
	- recursive 2 değerini verdik diyelim
	- recursive_func'a girdiğimizde returne geldiğimizde yine recursive_func() çağırılıyor
	- 1.sırada recursive_func(), 2.sırada recursive_func(), 3.sırada printf, 4.sırada main var şuan
	- recursive_func() n == 1 olduğu için artık funcu çağırmıyor ve 1 döndürüyor
	- EĞER BİR FONKSİYON RETURN İŞLEMİ YAPARSA O FONKSİYONUN GÖREVİ BİTMİŞTİR VE CALL STACK DEN ATILARAK DUZEN 1 2 3 4 > 2, 1; 3,2; 4,3'E GEÇER.
	- call stack de 3 frame kalıyor 1.recursive_func() 2.printf 3.main, 1.sırada olan recursive_func()'a 1 değeri dönmüştü o yüzden n * recursive_func() yerine 1 gelerek n * 1 oluyor, n olarak da 2 girmiştik 2*1 olarak 2 RETURN YAPIYOR. RETURN YAPTIYSA ARTIK CALL STACKDEN ATILIR.
	- printf'imiz 2'yi aldı ve ekrana bastırdı, YANİ İŞLEMİNİ BİTİRDİ CALL STACKDEN ATILDI
	- main fonksiyonumuz da herhangi bir sorun yok diyerek 0 döndürdü ve o da call stackden atılarak programımız sonlandı.
Kısa Video 4(Pointers[İşaretçiler]):
- Tüm dosyalarımızı sabit disk yani HDD veya SSD'de saklarız fakat burda ki bilgilere direk erişip, değiştiremeyiz. Bunun için burada ki bilgiyi RAM belleğe göndeririz. RAM bellek değişken verileri içerir. Bu da demek oluyor ki biz veri değiştirmek istediğimiz de RAM üzerin de işlem yaparız.
- İşaretçiler olmasa fonksiyonları düzgün kullanamazdık. Bu haftanın videosunda da gördüğümüz üzere fonksiyonlara işaretçi, yani RAM de ki adresi belirten bir değişken yollamaz isek fonksiyon, gönderdiğimiz değişkenin kopyasını alarak; kopyası ile işlem yapacak ve gönerdiğimiz değişkene herhangi bir etki etmeyecektir. Fonksiyonlar bizim fiilimiz gibi düşünürsek, aslında işaretçiler olmaz ise bir programı efektif bir şekilde yazamayız!
- RAM bellekte herşey 1 bytelık hücre(betimleme için)lerde tutulur. Eğer bir ram de int türünde bir veri tutmak istersek, RAM bellekte bize 4 adet 1 bytlık(çünkü int 4 byte) hücreyi o değişkene ayırır ve bu ayrı hüceler, tek bir hücre gibi davranır. Bilgisayar binary sistem üzerine kurulu olduğunu biliyoruz. Bizim girdiğimiz değer de ki 01leri rastgele yazalım, varsayalım 01010101010101010101010101011010010101010101010 olduğunu düşünürsek, bunları hepsini 4 hücreye, yani 1 byte olan 4 hücreye bölerek; tek bir hücreymiş gibi davranıyor.
- string saklarken mesela onur değerini bellekte tutacaksak, onur bir karakter dizisi yani her bir karakter aslında bir char ve 1 bytelık bir değerde. Bu yüzden RAM'de 4 bytelık bir değer alanı oluşturulur değil mi? HAYIR! stringlerin bittiğini belirten son byte olan NULL yani RAM'de ki gösterimi /0'ı UNUTMA! En nihayetin de 5 adet 1 bytelık hücreye tek bir hücre gibi ele alır ve bize 5 bytlık alan ayırmış olur.
- BİR İŞARETÇİ BİR ADRESDEN(RAM ADRESİ) BAŞKA BİŞİY DEĞİLDİR!
- NULL basit bir işaretçidir. Boş bir değere işaret eder. Bir pointer tanımaldığımız da ve tanımlarken herhangi bir değer vermiyorsak; ona NULL işaretçisini atayarak boşa, yani hiçbirşeye işaret etmesi gerektiğini belirtiriz. Aksi takdir de ram de trash value dediğimiz, silinen değerlerin olduğu kısımdan bir değeri kendine alabilir.
- Diziler işaretçiler üzerine kurulmuş bir yapıdır(data structre). Dolayısıyla bir fonksiyona diziyi gönderdiğimiz de asıl adresin de olan değeri de fonksiyonun yapacağı işlemlere göre değişir.
- Not: dereferencing: adresin, ters reference işlemi yaparak değerini alırız.
- * dereference(referans çözümleme) ve reference(referanslama) operatorüdür. int *p = 0x25362, *p dersek adresin içinde ki veriye ulaşırız. p dersek adrese ulaşırız.
- int* px, *py, *pz; diyerek toplu pointer tanımlaması yapabiliriz.
- 64 bit makine demek, bellekte ki her adresin 64 bit uzunluğunda olduğudur.
- 32 bit makine ise bellekte ki her adresin 32 bit olduğu anlamına gelir ki bu da daha az bellek boyutumuzun olması demektir.

Kısa Video 5(Dynamic Memory Allocation[Dinamik Bellek Atama]):
- Programımızın ne kadar bellek kullanacağını tahmin edememe vb. sorunlar için çözüm olarak DMA kullanılıyor.
- belleğimizde bir alan vardır ki bu alanda heap ve stack dediğimiz alanlar, alanlarını paylaşır, heap(betimleme açısından) yukardan aşağı basar, stack aşağıdan yukarı doğru basar(doldurur). Heap ve stackden bahsederken aynı yığından bahsediyoruz sadece kendi içerisinde farklı alanları.
- malloc(4) dediğimiz de malloc bize 4 bytelık alan tutan bir işaretçi döner, yani bir bellek adresi. Bellek dönmez(?), tamsayı veya başka birşey dönmez.
	- Eğer ki malloc null dönerse, demek ki istediğimiz kadar alan belleğimiz de bulunmuyor.
	- dolayısıyla malloc cağırdığımız da null dönüp, dönmediğini kontrol etmeliyiz yoksa segmentation fault alarak programımız çöker.
- malloc kullandıktan sonra işlem yaptıysak bu değerimiz ile free() ile serbest bırakmamız gerekir yoksa bu malloc verdiğimiz değişkenler ramde fazlaca byte yer kaplayarak memory leak dediğimiz ram bellekte alan bırakmama sorununa, programın çökmesine neden olur.
- Özet int* a = malloc(sizeof(int));'ı betimlersek
	- int türünde a bellek adresi oluşur, bunu bir kutu diye düşünelim ama kullanılmıyor yani içi yok.
	- malloc(sizeof(int)); 4 bytlık bir bellek adresini döndürdü. şimdi bu bellek adresini a işaretçisine atayarak
	- a, malloc'un döndürdüğü 4 bytelık bellek adresini işaret ediyor. Biz int *b = a; yaparsak b a'yı DEĞİL, işaretçi a'da ki malloc ile oluşturulan bellek adresini işaret eder.
Walkthroughs:
- Bitmapler, herhangi bir dosyanın byte dizilişine verilen isim.
- Bitmapler ile oynadığımız da dosyanın header'ını da güncelleriz.
- header güncellemek ne demek?
	- dosya boyutu
	- resim boyutu
	- genişlik
	- yükseklik
	- değerlerinin değişmesini ifade eder.
- BITMAPINFOHEADER da
	- biWidth dediğimiz dolgu(padding) harici resmin genişliğini saklayan bir fonksiyona sahibiz.
	- aynı durum yüksekliğini yani heightini saklayan biHeight için de geçerli.
	- biSizeImage ile dolgu ve pixel dahil bir şekilde bitmap'in büyüklüğünü elde ederiz.
		- bi.biSizeImage = ((sizeof(RGBTRIPLE) * bi.biWidth) + padding) * abs(bi.biHeight));
	- bfSize
		- toplam boyutu dosyanın
		- pixel, header, padding dahil!
		- bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
	- fread ile dosyamızı okuruz
	- biz değerlerimizi n ile değiştirmek istsersek ve n'e 2 değerini atarsak
	- 3 bytelık bir dosyamız var ise, 1.byte kırmızı diyelim, 2.byte mavi, 3.byte mor ise 1*2 + 1*2 + 1*2 diyerek 2 kırmızı 2 mavi 2 mor olaraktan 6 bytlık bir yeni veri oluşturmuş oluruz.
	-   fwrite ile yeni değerlerimizi yazarız.
- padding
	- bitmap(byte ları ifade etmenin bir pattern'i)de her pixel 3 byte olarak temsil edilir ve buna isim olarak RGBtriple denir.
	- bir bitmapin her satırının uzunluğu ise 4'ün katı olmalıdır.
	- eğer pixel sayısı 4'ün katı değilse dolgu(boşluk) eklememiz gerekir. Boşluklar (0x00) yani null değerlerdir.
	- denklem: padding = (4 - (bi.Width * sizeof(RGBTRIPLE)) % 4) % 4;
	- giriş ile çıkış dosyaları farklı olduğu için paddingleri de farklı olur(?)
	- padding bir RGBTRIPLE değildir. fread ile padding okuyamayız.
	- dolgu yazmak için fputc(chr, outptr); ÖRNEK: fputc(0x00, outptr); kullanırız.
- boyutlandırma da her pixel n(girdi) kadar tekrarlanır(artı olarak eklenir yani).
- mesela yatay 1 pixelimiz var bu yatay olarak 3 kere tekrarlanarak
	-  1 pixel 1 pixel 1 pixel 
- ve dikey olarak ta
	- 1 pixel 1 pixel 1 pixel 
	- 1 pixel 1 pixel 1 pixel 
	- 1 pixel 1 pixel 1 pixel 
- olarak tekrarlanır.
- mesela yatay olarak 2 satırlık bir pixel dizinini ele aldığımızda ilk olarak 1.dizindeki yatay olarak *n yapılır sonra dikey olarak *n yapılır sonra 2.dizindeki için aynı işlemler yapılır.
- File position indicator'a yani dosya pozisyon göstergesi tanımlamamız gerekecek.
	- fseek(inptr, offset, from);
		- inptr, dosya işaretcisi
		- offset, kaç byte taşınacağı, ilerleyeceği(imlecin)
		- from, dosyanın neresinden hareket edeceği;
			- SEEK_CUR (current position in file)
			- SEEK_SET (beginning of the file)
			- SEEK_END (end of the file)
