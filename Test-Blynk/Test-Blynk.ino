/*
 *  This sketch demonstrates how to scan WiFi networks. 
 *  The API is almost the same as with the WiFi Shield library, 
 *  the most obvious difference being the different file you need to include:
 */
#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).

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

char auth[] = "nhI9acucFYFwYs85zVqK3L6Vf_xSjMuQ";
char ssid[] = "JAFOM-WIFI";
char password[] = "57160033";

int inputPin = D2;

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, password);

  // Setup For PIR Sensor
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  pinMode(inputPin, INPUT);
}

void loop()
{
  Blynk.run();

  // For PIR Sensor
  int value = digitalRead(inputPin);
  Serial.println("PIR Sensor : " + value);
  if (value == HIGH){
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
  delay(500) ;
}
