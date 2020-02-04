
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

#include "SPI.h"
#include "MFRC522.h"



//#define SS_PIN 10
//#define RST_PIN 9
//#define SP_PIN 8

#define SS_PIN D2
#define RST_PIN D1
#define SP_PIN 8

MFRC522 rfid(SS_PIN, RST_PIN);

MFRC522::MIFARE_Key key;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
    return;

  // Serial.print(F("PICC type: "));
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  // Serial.println(rfid.PICC_GetTypeName(piccType));

  // Check is the PICC of Classic MIFARE type
  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&
    piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
    piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
    Serial.println(F("Your tag is not of type MIFARE Classic."));
    return;
  }

  String strID = "";
  for (byte i = 0; i < 4; i++) {
    strID +=
    (rfid.uid.uidByte[i] < 0x10 ? "0" : "") +
    String(rfid.uid.uidByte[i], HEX) +
    (i!=3 ? ":" : "");
  }
  strID.toUpperCase();

  // เมื่อถึงส่วนนี้ ตัวแปร strID จะเก็บค่า UID ของแท็กไว้แล้ว
  // สามารถนำไปใช้งานได้เลย เช่น นำไปเข้า IF เพื่อให้หลอด
  // LED ติดสว่าง หรือดับได้
  Serial.print("Tap card key: ");
  Serial.println(strID);

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}
