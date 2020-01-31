#include <Servo.h>
Servo myservo; 

static const uint8_t D0 = 16;
static const uint8_t D1 = 5;
static const uint8_t D4 = 2;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output

  pinMode(D0, OUTPUT);
  pinMode(D1, INPUT);
  
  myservo.attach(D4);
}

// the loop function runs over and over again forever
int degree = 0;
boolean outTime = true;

void loop() {
  int valueD1 = digitalRead(D1);
  Serial.print("D1 : ");
  Serial.println(valueD1);
  digitalWrite(D0, valueD1);
  digitalWrite(LED_BUILTIN, !valueD1);
  
  if (valueD1 == 1) {
    if (outTime) {
      if (degree == 0) degree = 180;
      else degree = 0;
      myservo.write(degree);
      Serial.print("Degree : ");
      Serial.println(degree);
    }
    outTime = false;
  } else {
    outTime = true;
  }
  
  Serial.println("===========================");
  delay(250);                      // Wait for a second
}
