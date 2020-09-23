**Videolu Ders Notları:**
- Soyutlama üzerinde biraz daha durduk. Şöyle ki; yolda yürürken elimizde su şişesi olduğunu varsayalım. Arkadaşımıız suyunu iç dediğinde, suyumuzu içeriz. Fakat bu konularda varsayım yaparız yoksa hayatımız da ki herşey daha kompleks olurdu. Yani aslında suyu direk içmek: şişeyi yukarı kaldır, kapağını çevir, kapağını aç, şişeyi ağzına götür, yukarı dikleyerek sıvı akışını sağla. Aslında su içerken yaptığımız olaylar bunlardır fakat "su iç" diyerek bunları varsayım haline getiririz. Programlama da ise bu varsayımları biraz daha belirtmemiz gerekir. Sayıyı topla diyerek bir program yazamayız değil mi? "int türünde bir sayı kaydet(belleğe) ve diğer int türünden kaydedilmiş sayı ile cebirsel işlem yap" diyerek programımızı yazarız.
- if, else, else if yapılarının basit kullanımı, printf(burdaki f, formatlanmış(resetlenmiş olan anlamı DEĞİL) bir değeri yazdır)'in kullanımını, ; ifadesinin kodlamada(C'de) nokta olarak kullanıldığını, \n kaçış ifadesini gördük, while ile (true) yazarak sonsuz döngüyü gördük. Yani sonsuz döngü için 50 = 50 gibi kafadan uydurma hep gerçekleşen bir ifade yerine boolean değerlerinin önemini anladım.
- get_string("What's your name?\n); diyerek kullanıcıdan bir değer alabiliriz. C'de kelimeler arasında(fonksiyonlarda) boşluk bırakamayız bu yüzden boşluğu  temsil eden '_' karakterini kullanırız.
- String bir karakter dizisidir. Yani string isim = onur aslında isim[4] = [0]=>"o",  [1]=>"n",  [2]=>"u",  [3]=>"r";  sistemselindedir.
- printf("%s", answer); answer'ı %s(ayrıca yer tutucu işlevi görür) yani string olarak formatlanmış şekilde yazdır. printf'in yani formatlanmış bir değeri yazdırmanın pratiğini işledik.
- Günümüzde neden terminal kullanalım GUI(kullanıcı arayüzü) varken sorusunun cevabını öğrendik; çünkü GUI'ler de koddan yazılan programlar olduğu için yazan kişi tarafından imkanlar sınırlandırılır ama terminalde direkt olarak bilgisayara kodlar göndererek istediğimiz şeyi daha imkanlı, açık bir şekilde elde edebiliriz.(bunun ucu 010101leri bizzat yazmaya kadar gider valla.)
- Komut satırı argümanları, varsayılanın dışnıda nasıl davranacağını söylemenin şeklidir. Mesela gcc hello.c varsıylansa, gcc -o(outputu ifade eder) hello hello.c komut satırı argümanlı bir terminal kodudur.
- Fonksiyonlar girdi alarak çalışabilirler ve bu girdiler argüman veya parametre olarak adlandırılır.
- Girdi ve çıktının ne anlama geldiğini ve çıktının üzerinde kod vasıtasıyla durduk. Girdi, mesela name değişkeninin printf'e girilmesi veya printf'e "merhaba" ifadesinin girilmesi girdidir. Çıktı ise get_string fonksiyonuna verdiğimi soru ile kullanıcıdan alınan veridir. Öyleyse printf çıktı verir mi? Hayır(şimdilik). Çünkü printf sadece baskı işlemi yapıyor ama bize(yazılımcıya) herhangi bir çıktı vermiyor.
- conditions(koşullar demek)
- bildiğimiz üzere float türünden bir değeri ele aldığımızda bu değer bellekte bir adres tutar. Float için bu 32 bit yani 4 bytedır. biz printf("%.50f", floatSayi) gibi bir kod yazdığımızda virgülden sonra 50 basamak hassasiyetin de sayımızı yazdıracaktır fakat floatSayi'yi 2 düşünürsek 2.0000...50 adet sıfır yazdırması gerekirken 7.sıfırdan sonra farklı değerler yazdırır. Peki bunun nedeni nedir? Bunun nedeni float floatSayi değişkenimiz bellekte 4 byte yer kaplar ve biz %.50f yaptığımız da ise istediğimiz hassasiyet daha fazla byte a ihtiyac duyar(bu hassasiyeti sağlamak için). Daha fazla byte verilerin compile yani 0-1lere dönüştürüldükten sonra işlemciyi daha çok yormak(bildiğimiz üzere kodlar eninde sonunda 0-1lere dönüşür işlemcinin 100 tane 0-1 ile 1000 tane 0-1 okuması arasinda tabi ki performans farkı olacaktır) ve bellekte daha çok yer tutmak demektir ama aynı zamanda daha hassas sayılar elde etmemize yarar. Bu yüzden 64 bitlik yani 8 bytlık double veri tipini kullanabiliriz.  
- tek bir harf ile koşul yapmak istediğimizde string yerine char kullanmamız daha doğru olur çünkü char tek karakter tutabilir ve stringe göre bellekte tuttuğu veri alanı daha azdır(byte durumu yine). 
- void'in ne olduğunu, nerede kullanıldığını öğrendik. Kendi fonkisoynumuzu yazarkan void(fonksiyonumuz herhangi bir çıktı vermicek demek oluyor) selam(void[yani fonksiyonumuz herhangi bir parametre(girdi), argüman almicak diyoruz]); tamamı aşağıda
- void selam(void) printf("merhaba"); aslında bu kod da soyutlamamıza bir örnek olabilir. biz gidip printf("selam"); yazmak yerine selam(); yazarak aynı işlemi varsayımlarla(ki bunları biz fonksiyonumuzu tanımlarken belirttik) birlikte daha da hızlı yazdirabiliriz.
- Eğer bir kodu birden çok kez tekrar etmeye başladıysak, yanlış yapıyoruz demektir. Çünkü ileride o kodu değiştrimek veya kodu  tercüme(en basitinden) etmek istersek birden çok kez bu işlemleri yapmak durumunda kalıcaz(birbiriyle tıpatıp aynı kodlar için bahsediyorum).
- Kod bloklarımızın üsten aşağı ve sağdan sola doğru okunduğunu öğrendik. Bu yüzden fonksiyonlarımızı oluştururken source'ımızın olabildiğince üst taraflarında oluşturmaya dikkat etmeliyiz.
- Evet üstteki tezi çürüttük hehe. Prototip fonksiyonu öğrendim. programın üst tarafında fonksiyonu veri tipi ve girdileriyle birlikte tanımlarsak artık fonksiyonumuzun detaylarını istediğimiz yere yazabiliyoruz.
- return ile fonksiyonlara değer döndürülmesi ve scope kavramına değindik. Scope, iki süslü parantezin arasında değişkenin(veya başka bir ifadenin) belirtildiği yerdir.
- do-while döngüsünü gördük. En büyük özelliğinin EN AZ 1 kere çalışması olduğunu öğrendik.
- Overflow kavramına değindik. Mesela 3 hane tutabilen bir Kronometremiz var. 999 saniyeye +1 saniye daha eklersek 9 9 9 10 olmaz. 9 evrilir ve elde dediğimiz durum haline gelerek soldaki basamağa gider ve böyle böyle elde kalmayana kadar işlem devam eder ve haliyle 1000 olur ama kronometremiz en fazla 3 hane tutabildiği için 000 gösterecektir. Bu olaya overflow yani taşma adı verilir. Bunu 2lik sayı sisteminde örnek verirsek 111'e 1 eklersek sırasıyla 110 > 100 > (elde var 1 yine) 000 > 1000 4 bitlik bir değer elde ederiz. int'in 32 bit olduğunu daha öncesinde değinmiştik. Peki kendi kendini toplayan bir döngü oluştursak ve değerimizi int içinde tutarsak 32 bitlik bir sayı oluştuktan sonra 33.biti oluşturmaya çalışırken overflow olacak ve bize hata verecektir.



**Videolu Ders Devam Notları:**

- Fonksiyonlar girdi alarak çalışabilirler ve bu girdiler argüman veya parametre olarak adlandırılır.
	
- Girdi ve çıktının ne anlama geldiğini ve çıktının üzerinde kod vasıtasıyla durduk. Girdi, mesela name değişkeninin printf'e girilmesi veya printf'e "merhaba" ifadesinin girilmesi girdidir. Çıktı ise get_string fonksiyonuna verdiğimi soru ile kullanıcıdan alınan veridir. Öyleyse printf çıktı verir mi? Hayır(şimdilik). Çünkü printf sadece baskı işlemi yapıyor ama bize(yazılımcıya) herhangi bir çıktı vermiyor.
	
	
- bildiğimiz üzere float türünden bir değeri ele aldığımızda bu değer bellekte bir adres tutar. Float için bu 32 bit yani 4 bytedır. biz printf("%.50f", floatSayi) gibi bir kod yazdığımızda virgülden sonra 50 basamak hassasiyetin de sayımızı yazdıracaktır fakat floatSayi'yi 2 düşünürsek 2.0000...50 adet sıfır yazdırması gerekirken 7.sıfırdan sonra farklı değerler yazdırır. Peki bunun nedeni nedir? Bunun nedeni float floatSayi değişkenimiz bellekte 4 byte yer kaplar ve biz %.50f yaptığımız da ise istediğimiz hassasiyet daha fazla byte a ihtiyac duyar(bu hassasiyeti sağlamak için). Daha fazla byte verilerin compile yani 0-1lere dönüştürüldükten sonra işlemciyi daha çok yormak(bildiğimiz üzere kodlar eninde sonunda 0-1lere dönüşür işlemcinin 100 tane 0-1 ile 1000 tane 0-1 okuması arasinda tabi ki performans farkı olacaktır) ve bellekte daha çok yer tutmak demektir ama aynı zamanda daha hassas sayılar elde etmemize yarar. Bu yüzden 64 bitlik yani 8 bytlık double veri tipini kullanabiliriz. 
	
- tek bir harf ile koşul yapmak istediğimizde string yerine char kullanmamız daha doğru olur çünkü char tek karakter tutabilir ve stringe göre bellekte tuttuğu veri alanı daha azdır(byte durumu yine).
	
- void'in ne olduğunu, nerede kullanıldığını öğrendik. Kendi fonkisoynumuzu yazarkan void(fonksiyonumuz herhangi bir çıktı vermicek demek oluyor) selam(void[yani fonksiyonumuz herhangi bir parametre(girdi), argüman almicak diyoruz]); tamamı aşağıda
	
- void selam(void) printf("merhaba"); aslında bu kod da soyutlamamıza bir örnek olabilir. biz gidip printf("selam"); yazmak yerine selam(); yazarak aynı işlemi varsayımlarla(ki bunları biz fonksiyonumuzu tanımlarken belirttik) birlikte daha da hızlı yazdirabiliriz.
	
- Eğer bir kodu birden çok kez tekrar etmeye başladıysak, yanlış yapıyoruz demektir. Çünkü ileride o kodu değiştrimek veya kodu  tercüme(en basitinden) etmek istersek birden çok kez bu işlemleri yapmak durumunda kalıcaz(birbiriyle tıpatıp aynı kodlar için bahsediyorum).
	
- Kod bloklarımızın üsten aşağı ve sağdan sola doğru okunduğunu öğrendik. Bu yüzden fonksiyonlarımızı oluştururken source'ımızın olabildiğince üst taraflarında oluşturmaya dikkat etmeliyiz.
	
- Evet üstteki tezi çürüttük hehe. Prototip fonksiyonu öğrendim. programın üst tarafında fonksiyonu veri tipi ve girdileriyle birlikte tanımlarsak artık fonksiyonumuzun detaylarını istediğimiz yere yazabiliyoruz.
	
- return ile fonksiyonlara değer döndürülmesi ve scope kavramına değindik. Scope, iki süslü parantezin arasında değişkenin(veya başka bir ifadenin) belirtildiği yerdir.
	
- do-while döngüsünü gördük. En büyük özelliğinin EN AZ 1 kere çalışması olduğunu öğrendik.
	
- Overflow kavramına değindik. Mesela 3 hane tutabilen bir Kronometremiz var. 999 saniyeye +1 saniye daha eklersek 9 9 9 10 olmaz. 9 evrilir ve elde dediğimiz durum haline gelerek soldaki basamağa gider ve böyle böyle elde kalmayana kadar işlem devam eder ve haliyle 1000 olur ama kronometremiz en fazla 3 hane tutabildiği için 000 gösterecektir. Bu olaya overflow yani taşma adı verilir. Bunu 2lik sayı sisteminde örnek verirsek 111'e 1 eklersek sırasıyla 110 > 100 > (elde var 1 yine) 000 > 1000 4 bitlik bir değer elde ederiz. int'in 32 bit olduğunu daha öncesinde değinmiştik. Peki kendi kendini toplayan bir döngü oluştursak ve değerimizi int içinde tutarsak 32 bitlik bir sayı oluştuktan sonra 33.biti oluşturmaya çalışırken overflow olacak ve bize hata verecektir.


**Kısa Videolar'a Ait Notlar:**

**Kısa Video 1(Veri Türleri):**
	
- int'in sadece tam sayılar tuttuğunu ve bellekte 4 byte'lık bir alan tuttuğunu hatırladık.
	
- 32bitlik sistem ile oluşturabileceğimiz sayıların yarısı(2 milyar) negatif, diğer yarısı(2 milyar) pozitif sayılardır.
	
- Niteleyicileri gördük. Niteleyiciler ile veri tiplerine daha spesifik özellikler kazandırabiliyoruz. unsigned niteleyecisi ile int'i sadece pozitif değerler alacak şekilde değiştirebilir bunun sonucunda 2 milyar yerine 4 milyar pozitif değer almasını sağlayabiliriz.
	
- char veri tipini öğrendik ve 1 byte(8 bit)lik bir bellek alanı kapladığını öğrendim.

- float'ın 4 byte(32 bitlik) bir bellek alanı tuttuğunu anımsadık ve noktalı(ondalıklı) sayıları tutabildiğini hatırladık.
	
- daha fazla ondalıklı hassasiyeti için(ders notlarında bahsettim) double veri tipini kullanırız. Bellekte 8 byte(64 bit) bellek alanı kaplar.
	 
- void türünün(veri türü değil, türdür) gördüğümüzde herhangi bir dönüş olmayacığını anlamamız gerektiğini ve bu sebeple kullanıldığını anımsadık.
	
- bool veri türünün türünün C'de primary bir veri türü olmadığını ama cs50.h kütüphanesi ile kullanabildiğimizi gördük. Boolean, true veya false olarak 2 değer alan bir veri türüdür ve ifadeleri karşılaştırmada kullanılır.
	 
- string veri türünün karakter koleksiyonu olduğunu anımsadık. Kelimeyi saklamak için(char harf tutar) -ki bunlar karakter dizisidir- string kullanmalıyız.


**Kısa Video 2(Operatörler):**
	 
- = operatörü ile atama yaptığımızı, bu operatörde sağdaki ifade soldaki ifadeye atandığını anımsadık.
	 
- operatörlerin kısaltılarak kullanılmasını( *=, +=, ++, -- vb.) gördük.
	 
- C'de 0 olmayan her değer(true, 0-1 sisteminde ki 1 gibi) olumlu, haliyle 0 olumsuzdur.
	
- AND( && ) mantıksal operatörünü ve hangi durumlarda(sadece tüm koşulların true olduğu ifadelerde çalıştığını) gördük. OR( || ) mantıksal operatörü ise herhangi bir koşulun doğru olması sonucunda çalıştığını ve son olarak ! mantıksal operatörünün kullanıldığı yerlerde ifadeleri zıt mantığa çevirdiğini anladık.
	 
- == eşit veya != eşit değilse operatörlerini gördük.


**Kısa Video 3(Koşullu Önermeler):**
	 
- if-else koşullu ifadesinin kullanımını gördük. if'de ki koşul doğru ise boolean olarak true ifade döndürerek if'in bloğunda ki kodları çalıştırır. false döndürürse; else tetiklenir.
	 
- Birden fazla koşullu ifadeler için else if yapısının kullanımını gördük. if-else if-else if-else gibi.
	 
- Bazen if-if-if-if-else gibi koşulların kullanımının da verimli olduğu görülür. ilk 3 daldan aşağı iner ve 4.dala göre durum son halini alır.
	 
- switch ifadesinin kullanımını gördük. case ve default özelliklerini inceledik. break kullanımının ifadeyi gerçekleştirdikten sonra durması için kullanılmasını gördüm.
	 
- ?: ternanry operatörünü gördük. örnek kullanımı, int x = (4>5) ? 1 : 0; eğer dört, beşten büyükse x 1 değerini, değilse x 0 değerini alacak. Çok fazla dallanma olmayan, basit koşullu ifadelerde kullanılır.


**Kısa Video 4(Döngüler):**
	 
- while, do-while, for döngüsünün yapısını ve kullanım yerlerini inceledik.
	 
- While döngüsü genelde tam olarak kaç kere döngü işleminin gerçekleşeceği kesin olmayan durumlar da(oyunlardan örnek: mesela kullanıcı W'ye basına karakter sağa -hareket etsin, ta ki bırakana kadar) kullanılması ile biliniyor.
	 
- do-while döngüsü koşul sonucunda çalışacak ifadenin en az 1 kere çalışması gerektiği yerlerde - ki kullanıcıya soru sormak en popüler işlem do-while için - kullanılır.
	 
- for döngüsü ise biraz daha kesin döngü ifadelerin de kullanılır. Yine oyundan örnek vermemiz gerekirse 5 kere düşman ard arda spawn(oluşturmak, ortaya çıkarmak) istersek for döngüsü kullanmamız doğru olacaktır.
	 
- Elbette katı bir kural yok şu olay için şu döngü gibi fakat döngüleri baskın olduğu özelliklerinin ihtiyaç olduğu yerler de kullanırsak, kodumuzun anlaşılması artar ki bu da daha verimli bir kod anlamına gelir.


**Kısa Video 5(Komut Satırı):**
	 
- UNIX tabanlı sistemlerde kullanmak üzere terminal komutlarını öğrendik
	 
- ls(list) komutu bulunduğumuz ortamda ki tüm klasör ve dosyaları dijital olarak görmemizi sağlar.
	
- cd(change directory) komutu ile klasörler arası geçiş yapabiliriz. Biraz daha detaya değinirsek .. ifadesi bir önceki klasörü belirtirken . ifadesi bulunduğumuz klasörü işaret eder.
	 
- pwd komutu ile terminalde bulunduğumuz klasörü görebiliriz.
	 
- mkdir(make directory) ile bulunduğumuz klasörde dizin oluşturabiliriz.
	 
- cp(copy) komutu ile dosyamızı bir yerden, başka(veya aynı ortamda) bir yere kopyalayabiliriz. Argümanlar cp <source> <destination>'dır. Klasörleri kopyalama işlemi yaparken cp komutu, klasör ile tam olarak ne yapacağını anlayamadığı için daha kesin bir komut kullanmamız gerekir ki bu da demek oluyor -r argümanını kullanmalıyız. Örnek kullanım: cp -r klasor1 klasorYeni
	
- rm komutu ile istediğimiz klasör veya dosyayı silebiliriz. -f argümanı ile doğrulamayı atlayabiliriz. -r argümanı ile belirttiğimiz tüm  klasörü silebiliriz.

- mv komutu ile bir dosyayı, başka bir yere taşımak için kullanabiliriz. Kullanım şekli; mv <source> <destination> şeklindedir. Fakat bu özelliği yeniden isimlendirmek için de kullanabiliriz. mv onur.txt yeniDosya.txt yaparsak aynı dosyayı kesip, ismini değiştirip yine aynı ortama yapıştırma işlemi yapacaktır.


