/*
  ESP8266 Blink by Simon Peter
  Blink the blue LED on the ESP-01 module
  This example code is in the public domain

  The blue LED on the ESP-01 module is connected to GPIO1
  (which is also the TXD pin; so we cannot use Serial.print() at the same time)

  Note that this sketch uses LED_BUILTIN to find the pin with the internal LED
*/

static const uint8_t D0 = 16;
static const uint8_t D1 = 5;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output

  pinMode(D0, OUTPUT);
  pinMode(D1, INPUT);
}

// the loop function runs over and over again forever
int current = 0;
void loop() {
  Serial.println("===========================");
//  if (current == HIGH) current = LOW;
//  else current = HIGH;
//  Serial.print("D0 : ");
//  Serial.println(current);
//  digitalWrite(D0, current);
  
  delay(100);                      // Wait for a second
  int valueD1 = digitalRead(D1);
  Serial.print("D1 : ");
  Serial.println(valueD1);
  digitalWrite(D0, valueD1);
  digitalWrite(LED_BUILTIN, !valueD1);
  
//  delay(1000);                      // Wait for two seconds (to demonstrate the active low LED)
}
