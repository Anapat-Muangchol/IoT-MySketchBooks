#include <Servo.h>
Servo myservo; 

static const uint8_t D4 = 2;

void setup() {
  Serial.begin(9600);
  myservo.attach(D4);
}


void loop() {
  int degree = 0;
  myservo.write(degree);
  Serial.print("Degree : ");
  Serial.println(degree);
  delay(1000); 

  degree = degree + 45;
  myservo.write(degree);
  Serial.print("Degree : ");
  Serial.println(degree);
  delay(1000);
  
  degree = degree + 45;
  myservo.write(degree);
  Serial.print("Degree : ");
  Serial.println(degree);
  delay(1000);
  
  degree = degree + 45;
  myservo.write(degree);
  Serial.print("Degree : ");
  Serial.println(degree);
  delay(1000);
  
  degree = degree + 45;
  myservo.write(degree);
  Serial.print("Degree : ");
  Serial.println(degree);
  delay(1000);
  
  Serial.println("===========================");
}
