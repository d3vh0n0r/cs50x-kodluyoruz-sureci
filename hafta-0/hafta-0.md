0.Hafta:

Videolu Ders Notları:
- 2lik sayı sistemi, 10luk sayı sistemi, aslında bilgisayarların 0 ve 1 ile çalıştığını tekrar hatırladım.
- Programlama input olarak sorunları alıp kara kutu(input>O>output) dediğimiz orta kısımda algoritmalar ile sorunu çözüp, çözüm olarak output vermektir.
- Bilgisayarda 0 ve 1'ler depolanarak değişkenleri ifade ettiğini gördük.
- transistörler sistemsel(belli bir düzene tabi olarak yani) bir elektrik kesintisi yaparak 0 ve 1'i ifade eden değerleri bunlarda 2lik sayı sisteminde değerler, bunlarda ASCII(Amerikan Standar Karakter Seti), Unicode(UTF-8) gibi sistemlere convert edilerek günümüz de ki içerikleri(A harfi gibi, emoji gibi) oluşturur.
- Peki 0101 bazı uygulamalarda emoji iken bazı yerlerde farklı şeyleri ifade ediyor bunu nasıl açıklayabiliriz? Bunu o uygulamaların o veri giriş durumunda ilişkilendiği setlerle alakalıdır. Emoji gönderirken emoji seti devreye girerek 0101'i emoji olarak yorumlar.
- soyutlama(mesela 00101011'in 26'yı ifade etmesi ve 26'yı gördüğümüzde bilinçaltından 00101011'i aslında düşünmemiz soyutlamadır. Yada gülme emojisi aslında pixellerden oluşur ve pixellerde RGB sisteminden oluşur RGB 3 bytelık bir sistemdir ve ilk byte da kırmızı ikinci byte da yeşil ve üçüncüde de mavinin tonunu belirterek yeni renkler oluşturmaya yarar. Onlukta 255'e kadar bir sayı sistemi kabul edersek RGB'de R: 60 G:160 B:20 yeşilin ağır baskın olduğu sadece 1 pixel oluşturacaktır ve emojiler de binlerce pixelden oluşur. Pixellerin emojiyi oluşturması ve emojinin aslında pixellerden oluşan bir bütün olduğunu bilmek bir nevi soyutlamadır.
- true false ifadesini gördük
- cümlede ki fiilerin yazılımda eylemleri ifade etmesi mesela say("merhaba"); burda ki say fonksiyondur yani eylemdir.
- birden fazla işlem yapmak istersek onu tek tek yazmak yerine for döngüsünde kullanmamız. Mesela 3 kere yapılacak şeyi 5 kere yapmak istersek 2 defa daha aynı kod bloğunu eklememiz gerekir ama döngü işleminde sadece 3'ü, 5 yaparak işlemi gerçekleştirebiliriz.
- threads yani iş parçacıklarını gördük. 1 kod bloğu 1 iş parçacığı olarak düşünürsek bunlar birlikte senkron veya asenkron olarak çalışabilir bunu baya yüzeysel gördük.
- events denilen olayın "x olduğunda event(durum gerçekleşsin) olsun" ifadesini gördük.
- fonksiyon yazmayı gördük. böylelikle herhangi bir değişiklik yapıldığında bu kod bloğu üzerinde(döngüdeki olay gibi bkz; 5.madde) daha kolay düzenleyebiliriz.

