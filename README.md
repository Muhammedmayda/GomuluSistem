# GomuluSistem

PROJE  - Mozilla Gateway ile IOT Cihazların Kontrolü ve İzlenmesi

 Proje Raspberry Pi üzerine kurulan Mozilla Gateway ile gerekli olan(Json Format) formda IOT cihazın tanımlanması ve kontrol edilmesi.
NodeMCU kullanılarak hazırlanan IOT birimin üzerinde bulunan OLED ekran kontrolü ve üzerindeki Led’in kontrol edilmesi.
Python ile hazırlanan sanal IOT birimin kontrol edilmesi.
Gateway üzerinden IOT birimler arasındaki yapının düzenlenmesi ve çıktı olarak mail gönderilmesi, uyarı eklenmesi v.b.

PROJE  - Donanım
Raspberry Pİ 3B+

Mozilla Gateway kurulumu için Raspberry Pİ 3 + seçilmiştir. Bu donanımın kullanılmasının nedenleri :
Raspberry Pİ için özelleştirilmiş ISO dosyasının olması,
Dahili Wifi  biriminin bulunması,
Fiyat / Performans oranının iyi olması

PROJE  - Donanım 
NodeMCU Lolin ESP8266 Kart

IOT birim olarak NodeMCU kart seçilmiştir. Bu donanımın kullanımasının nedenleri : 
Dahili bir Wifi modülünün olması,
Mozilla Gateway için Library desteğinin olması,
Fiyat ve güç tüketimi,
Programlama kolaylığı
Kart üzerine Oled Ekran ve Led eklenmiştir.

Mozilla Gateway

Mozilla Gateway kurulumuna aşağıdaki link takip edilerek ulaşılabilir. Adımlar kısaca şöyledir:
ISO dosyasının SD karta yüklenmesi,
Raspberry Pi’ye güç verilmesi  ,
Mozilla Gateway olarak Wifi ağı oluşması ve katılmak,
Genel kullanım için hazırlanmış olmaktadır.
Link : https://iot.mozilla.org/docs/gateway-getting-started-guide.html




 PlatformIO / Arduino IDE

NodeMCU kartını programlamak için  Arduino Ide si kullanılmıştır.
Gerekli kütüphanelere aşağıdaki link aracılığıyla bulunabilir.
https://iot.mozilla.org/framework/
Kod Adımları :
Gateway formatına uygun HTTP Server başlatılıyor.
Json encoding formatında IOT birim tanımlanıyor. 
IOT ismi, özellikleri, fonksiyonları tanımlanır 
Http Server üzerine konulur.
Main loop ile güncelleme yapılarak takip edilir.
Gateway üzerinden gelen Tex metni OLED ekran üzerinde gösterilmiştir.
Gateway üzerinden gelen  ON/OFF ile Led kontrolü yapılmıştır.s




