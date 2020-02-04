
#include <ESP8266WiFi.h>
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

#define WIFI_SSID "JAFOM-WIFI"
#define WIFI_PASSWORD "57160033"

// Blynk config
#define BLYNK_TOKEN "nhI9acucFYFwYs85zVqK3L6Vf_xSjMuQ"

// Line config
#define LINE_TOKEN_NO_1 "dvYaCu39rIH9FKcbSgbaIjrkysJAn9klptiynq2sCbI"


#include <SPI.h>
#include <RFID.h>

#define SS_PIN D2
#define RST_PIN D1

RFID rfid(SS_PIN, RST_PIN);

int buzzPin = D4;

// Setup variables:
int serNum0;
int serNum1;
int serNum2;
int serNum3;
int serNum4;

void setup() {
  Serial.begin(9600);
  Serial.println("Serial begin : 9600");
  SPI.begin();
  Serial.println("SPI begin.");
  rfid.init();
  Serial.println("RFID Init.");
}

void loop() {
//  Serial.println("----- loop Start -----");

  if (rfid.isCard()) {
    Serial.println("RFID isCard.");
    if (rfid.readCardSerial()) {
      Serial.println("RFID readCardSerial.");
      if (rfid.serNum[0] != serNum0
          && rfid.serNum[1] != serNum1
          && rfid.serNum[2] != serNum2
          && rfid.serNum[3] != serNum3
          && rfid.serNum[4] != serNum4
         ) {
        /* With a new cardnumber, show it. */
        Serial.println(" ");
        Serial.println("Card found");
        serNum0 = rfid.serNum[0];
        serNum1 = rfid.serNum[1];
        serNum2 = rfid.serNum[2];
        serNum3 = rfid.serNum[3];
        serNum4 = rfid.serNum[4];

        //Serial.println(" ");
        Serial.println("Cardnumber:");
        Serial.print("Dec: ");
        Serial.print(rfid.serNum[0], DEC);
        Serial.print(", ");
        Serial.print(rfid.serNum[1], DEC);
        Serial.print(", ");
        Serial.print(rfid.serNum[2], DEC);
        Serial.print(", ");
        Serial.print(rfid.serNum[3], DEC);
        Serial.print(", ");
        Serial.print(rfid.serNum[4], DEC);
        Serial.println(" ");

        Serial.print("Hex: ");
        Serial.print(rfid.serNum[0], HEX);
        Serial.print(", ");
        Serial.print(rfid.serNum[1], HEX);
        Serial.print(", ");
        Serial.print(rfid.serNum[2], HEX);
        Serial.print(", ");
        Serial.print(rfid.serNum[3], HEX);
        Serial.print(", ");
        Serial.print(rfid.serNum[4], HEX);
        Serial.println(" ");
        //buzzer
        analogWrite(3, 20);
        delay(500);
        analogWrite(3, 0);
      } else {
        /* If we have the same ID, just write a dot. */
        Serial.print(".");
      }
    }
  }

//  Serial.println("RFID halt.");
  rfid.halt();
//  Serial.println("----- loop End -----");
}
