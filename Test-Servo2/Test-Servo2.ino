#include <Servo.h>
Servo myservo; 

static const uint8_t D4 = 2;

void setup() {
  Serial.begin(9600);
  myservo.attach(D4);
}


void loop() {
//  int degree = 0;
//  myservo.write(degree);
//  Serial.print("Degree : ");
//  Serial.println(degree);
//  delay(500); 
//
//  degree = degree + 90;
//  myservo.write(degree);
//  Serial.print("Degree : ");
//  Serial.println(degree);
//  delay(500);
//  
//  degree = degree + 90;
//  myservo.write(degree);
//  Serial.print("Degree : ");
//  Serial.println(degree);
//  delay(500);

  myservo.write(0);
  Serial.print("Degree : 0");
  delay(1500); 

  myservo.write(180);
  Serial.print("Degree : 180");
  delay(1500);
  
  Serial.println("===========================");
}
