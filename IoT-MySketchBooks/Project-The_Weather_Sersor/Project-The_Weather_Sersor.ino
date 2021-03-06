
#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
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

// WIFI_CONS
char *WIFI_SSID[] = { 
  "JAFOM-WIFI",
  "Datesiri-1 2.4GHZ"
};

char *WIFI_PASSWORD[] = { 
  "57160033",
  ""
};
// #define WIFI_SSID "JAFOM-WIFI"
// #define WIFI_PASSWORD "57160033"

// Blynk config
#define BLYNK_TOKEN "nhI9acucFYFwYs85zVqK3L6Vf_xSjMuQ"

// Line config
#define LINE_TOKEN_NO_1 "dvYaCu39rIH9FKcbSgbaIjrkysJAn9klptiynq2sCbI"

// DHT Setup
#include "DHT.h"
#define DHTPIN D1 // what pin we're connected to
#define DHTTYPE DHT11 // DHT 11 
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(9600);

  // Wifi Setup
  int indexOfWifi = wifiSetup();

  // Blynk Setup
  Blynk.begin(BLYNK_TOKEN, WIFI_SSID[indexOfWifi], WIFI_PASSWORD[indexOfWifi]);
  
  // DHT Setup
  dht.begin();

  // INPUT Setup
  pinMode(D4, INPUT);
  // OUTPUT Setup
  // pinMode(LED_BUILTIN, OUTPUT);
}

int wifiSetup() {
  
  WiFi.mode(WIFI_STA);

  // Scan Wifi
  while (true) {
    int numberOfNetworks = WiFi.scanNetworks();
    Serial.print("Number Of Networks Found: ");
    Serial.println(numberOfNetworks);
    for(int i=0; i<numberOfNetworks; i++){
      Serial.print("Network name: ");
      Serial.println(WiFi.SSID(i));
      Serial.print("Signal strength: ");
      Serial.println(WiFi.RSSI(i));
      Serial.println("-----------------------");

      int sizeOfWifi = sizeof(WIFI_SSID) / sizeof(WIFI_SSID[0]);
      // Serial.print("sizeof(WIFI_SSID) : ");
      // Serial.println(sizeOfWifi);
      for(int j=0; j<sizeOfWifi; j++){
        if (WiFi.SSID(i) == WIFI_SSID[j]) {
          WiFi.begin(WIFI_SSID[j], WIFI_PASSWORD[j]);
          Serial.print("Wifi : connecting");
          while (WiFi.status() != WL_CONNECTED) {
            Serial.print(".");
            delay(500);
          }
          Serial.print("\nconnected: ");
          Serial.println(WiFi.localIP());
          return j;
        }
      }
    }
    delay(1000);
  }
  
}

int cntRunTemp = 0;
int currentTemp = 0;
void loop()
{
  Blynk.run();

  // Test - Read
  int buttonState = digitalRead(D4);
//  Serial.print("buttonState :  ");
//  Serial.println(!buttonState);
  if (buttonState == 0) {
    currentTemp = 1;
  }
//  Serial.print("currentTemp :  ");
//  Serial.println(currentTemp);
  
  if (cntRunTemp >= 20) {
    cntRunTemp = 0;
    getTempAndHumi(currentTemp);
  }
  cntRunTemp++;
  
  delay(500) ;
}

int tempSession = -1;
void getTempAndHumi(int sendToLine) {
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // check if returns are valid, if they are NaN (not a number) then something went wrong!
  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT");
  } else {
    Serial.print("Temperature: "); 
    Serial.print(t);
    Serial.print(" *C");
    Blynk.virtualWrite(V1, t);
    
    Serial.print(" %\t");
    
    Serial.print("Humidity: "); 
    Serial.println(h);
    Blynk.virtualWrite(V2, h);

    int session = -1;
    int STK_ID, STKPKG_ID;

    if (t >= 30) {
      // HOT
      session = 2;
      STKPKG_ID = 2;
      STK_ID = 27;
    } else if (t < 25) {
      // COLD
      session = 1;
      STKPKG_ID = 2;
      STK_ID = 29;
    } else {
      // MID
      session = 0;
      STKPKG_ID = 2;
      STK_ID = 176;
    }
    
    // sendToLine : 0=no, 1=send
    if (sendToLine == 1 || session != tempSession) {
      LINE.setToken(LINE_TOKEN_NO_1);
      LINE.notifySticker("อุณหภูมิ " + String(t) + " ", STKPKG_ID, STK_ID);
      LINE.notify("ความชื้น " + String(h));
      currentTemp = 0;
      Serial.println("Sending to line.");
    }
    tempSession = session;
    
  }
}
