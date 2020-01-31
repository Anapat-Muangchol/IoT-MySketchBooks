
#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>

// Import Lib : URL Here -> http://www.mediafire.com/file/3szq0oevu0dt5hg/TridentTD_LineNotify-master.zip/file
#include <TridentTD_LineNotify.h>

// Map NodeMCU GPIO
static const uint8_t D0 = 16;
static const uint8_t D1 = 5;
static const uint8_t D2 = 4;
static const uint8_t D3 = 0;
static const uint8_t D4 = 2;
static const uint8_t D5 = 14;
static const uint8_t D6 = 12;
static const uint8_t D7 = 13;
static const uint8_t D8 = 15;
static const uint8_t D9 = 3;
static const uint8_t D10 = 1;

char WIFI_SSID[] = "JAFOM-WIFI";
char WIFI_PASSWORD[] = "57160033";

// Line config
#define LINE_TOKEN_NO_1 "dvYaCu39rIH9FKcbSgbaIjrkysJAn9klptiynq2sCbI"

void setup()
{
  Serial.begin(9600);

  // Wifi Setup
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Wifi : connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.print("\nconnected: ");
  Serial.println(WiFi.localIP());

}

void loop()
{
  sendLineNotify(LINE_TOKEN_NO_1, "Test Send To Line.");
  
  delay(60000) ;  // 1 Min
}

void sendLineNotify(String lineToken, String message) {
  // Set Line Token
  LINE.setToken(lineToken);
  
  // Send Message
  // Thai Message Encoding : https://meyerweb.com/eric/tools/dencoder/
  LINE.notify(message);

  // Send Line Sticker : Document here https://devdocs.line.me/files/sticker_list.pdf
  // LINE.notifySticker(3, 240);          // send sticker : PackageID 3 , StickerID 240
  // LINE.notifySticker("Message", 1, 2); // send sticker and message

  // Send Picture
  // LINE.notifyPicture("https://preview.ibb.co/j6G51n/capture25610417181915334.png");                // send picture
  // LINE.notifyPicture("Message", "https://www.fotoaparat.cz/storage/pm/09/10/23/670915_a5351.jpg"); // send picture and message
  
}
