#include <Arduino.h>
#include <Thing.h>
#include <WebThingAdapter.h>

const char *ssid = "Mayda1";
const char *password = "5Fb2b6dE12878";

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET     LED_BUILTIN
#define ledPin  D0

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int textHeight = 8;
const int textWidth = 6;
const int width = 128;
const int height = 32;

WebThingAdapter *adapter;

const char *textDisplayTypes[] = {"TextDisplay", nullptr};
ThingDevice textDisplay("OLED-LED", "MyCustomIOT", textDisplayTypes);
ThingProperty text("Oled", "", STRING, nullptr);
ThingProperty ledOn("on", "", BOOLEAN, "OnOffProperty");

String lastText = "Enter";
String printtext;
void displayString(const String &str) {
  int len = str.length();
  int strWidth = len * textWidth;
  int strHeight = textHeight;
  int scale = width / strWidth;
  if (strHeight > strWidth / 2) {
    scale = height / strHeight;
  }
  int x = width / 2 - strWidth * scale / 2;
  int y = height / 2 - strHeight * scale / 2;

  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(scale);
  display.setCursor(x, y);
  display.println(str);
  display.display();
}

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  // by default, we'll generate the high voltage from the 3.3v line internally!
  // (neat!)
  display.begin(SSD1306_SWITCHCAPVCC);

  // display the splashscreen as requested :)
  display.display();
  delay(2000);

#if defined(ESP8266) || defined(ESP32)
  WiFi.mode(WIFI_STA);
#endif
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  adapter = new WebThingAdapter("textdisplayer", WiFi.localIP());

  displayString(lastText);

  ThingPropertyValue value;
  value.string = &lastText;
  text.setValue(value);

  textDisplay.addProperty(&text);
  textDisplay.addProperty(&ledOn);
  adapter->addDevice(&textDisplay);
  adapter->begin();
  Serial.println("HTTP server basladi:");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.print("/things/");
  Serial.println(textDisplay.id);
}

void loop() {

  adapter->update();
  if (printtext != lastText )
  {
    displayString(lastText);
    printtext = lastText;
    Serial.println(printtext);
  }

  bool test = ledOn.getValue().boolean;
  digitalWrite(ledPin, !test ? LOW : HIGH);

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.println("Wifi Error");
    Serial.print(".");
    WiFi.disconnect();
    delay(3000);
    WiFi.begin(ssid, password);
    Serial.println("");
    delay(3000);

  }
  delay(200);
}
