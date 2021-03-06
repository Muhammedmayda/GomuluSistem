# GomuluSistem / Mozilla Gateway -ESP8266 IOT

PROJE  - Mozilla Gateway ile IOT Cihazların Kontrolü ve İzlenmesi

Proje - Özeti
 
 Bu proje de amaçlanan Raspberry Pi -3 üzerine Mozilla Gateway kurulumu ve bu gateway ile özelleştirilmiş bir IOT(ESP8266) kartın haberleşmesi ve bu kart üzerine eklenen OLED ekrana tarayıcı üzerinden veri transferi, led açıp-kapama ve mail göndermesi yapılmıştır. daha sonra Python ile hazırlanan sanal IOT birimin kontrol edilmesi de eklenerek uygulama yapılmıştır.
 
 PROJE  - Donanım 

      Gateway - Raspberry Pİ 3B+

      Mozilla Gateway kurulumu için Raspberry Pİ 3 + seçilmiştir. Bu donanımın kullanılmasının nedenleri :
      Raspberry Pİ için özelleştirilmiş ISO dosyasının olması,
      Dahili Wifi  biriminin bulunması,
      Fiyat / Performans oranının iyi olması
      
      
      
      IOT Birimi 
      NodeMCU  - Lolin ESP8266 Kart

      IOT birim olarak NodeMCU kart seçilmiştir. Bu donanımın kullanımasının nedenleri : 
      Dahili bir Wifi modülünün olması,
      Mozilla Gateway için Library desteğinin olması,
      Fiyat ve güç tüketimi,
      Programlama kolaylığı
      Kart üzerine Oled Ekran ve Led eklenmiştir.
      
      

Proje Adımları :


 1 - Raspberry Pi için Gateway iso dosyasının kurulumu : 
       Mozilla Gateway

       Mozilla Gateway kurulumuna aşağıdaki link takip edilerek ulaşılabilir. Adımlar kısaca şöyledir:
       ISO dosyasının SD karta yüklenmesi,
       Raspberry Pi’ye güç verilmesi  ,
       Mozilla Gateway olarak Wifi ağı oluşması ve katılmak,
       Giriş yapıp cihaz taraması ve özelleştirme,
       Genel kullanım için hazırlanmış olmaktadır.
 Link : https://iot.mozilla.org/docs/gateway-getting-started-guide.html

2- Arduino veya Platform IO üzerinde, belirtilen link kullanılarak  https://iot.mozilla.org/framework/ kütüphanelerin indirilmesi ve belirtilen örnek koda göre istenilen formatta ve dizayn ile özel bir IOT birimin oluşturulması.


      PlatformIO / Arduino IDE

     NodeMCU kartını programlamak için  Arduino Ide si kullanılmıştır.
     Gerekli kütüphanelere aşağıdaki link aracılığıyla bulunabilir.
 Link : https://iot.mozilla.org/framework/
     Kod Adımları :
     
     Gateway formatına uygun HTTP Server başlatılıyor.
     
     Json encoding formatında IOT birim tanımlanıyor.
     
     IOT ismi, özellikleri, fonksiyonları tanımlanır 
     
     Http Server üzerine konulur.
     
     Main loop ile güncelleme yapılarak takip edilir.
     
     Gateway üzerinden gelen Tex metni OLED ekran üzerinde gösterilmiştir.
     
     Gateway üzerinden gelen  ON/OFF ile Led kontrolü yapılmıştır.
     
  3-  Gateway üzerine giriş yapılması ve giriş yapıldıktan sonra sağ alt köşede bulunan + işareti ile yeni cihazın eklenmesi.
  
  4-  Cihaz + işaretine basıldıktan sonra gözükmüyorsa Arduino kodu içerisinde verilen IP adresini el ile girilmesi gerekiyor.
  
  5- Cihazın eklenmesi ve Arduino kodu içerisinde belirtilen formata uygun iconun eklenmesi ve kontrol edilmesi .
  
  
  Örnek arduino koduna bu link üzerinden ulaşılabilir : https://github.com/Muhammedmayda/GomuluSistem/blob/master/Ardunio-NodeMCU/Mozilla-NodeMCU/Mozilla-NodeMCU.ino veya Arduino klasörü içerisine eklenmiştir.
  
  
  Daha detaylı bilgiye Sunum Klasöründen ulaşılabilir.
  
  Kısa Demo video linki : https://drive.google.com/file/d/1rgDISHl3n9aeUPhQE2INpdYeEuZYflrn/view?usp=sharing
  
  
  Örnek bir IOT cihazın eklendiği ve demosunun yapıldığı, sunumun yapıldığı Zoom linki : https://drive.google.com/file/d/1sE_osRRhyH4yI0R_v1NhNcYqvb7ENBNK/view?usp=sharing gibidir. 
  Veya Video bölümünde bulunan link ile ulaşılabilir.
  
  
     




