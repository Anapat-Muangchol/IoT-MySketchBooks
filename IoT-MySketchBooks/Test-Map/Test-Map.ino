
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

void setup() {
  Serial.begin(9600);
  
  pinMode(D0, INPUT);
  pinMode(D1, INPUT);
  pinMode(D2, INPUT);
  pinMode(D3, INPUT);
  pinMode(D4, INPUT);
  pinMode(D5, INPUT);
  pinMode(D6, INPUT);
  pinMode(D7, INPUT);
  pinMode(D8, INPUT);
  pinMode(D9, INPUT);
  pinMode(D10, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  Serial.println("===================================");
//  Serial.print("D0 : ");
//  Serial.println(digitalRead(D0));
//  Serial.print("D1 : ");
//  Serial.println(digitalRead(D1));
//  Serial.print("D2 : ");
//  Serial.println(digitalRead(D2));
//  Serial.print("D3 : ");
//  Serial.println(digitalRead(D3));
//  Serial.print("D4 : ");
//  Serial.println(digitalRead(D4));
//  Serial.print("D5 : ");
//  Serial.println(digitalRead(D5));
//  Serial.print("D6 : ");
//  Serial.println(digitalRead(D6));
//  Serial.print("D7 : ");
//  Serial.println(digitalRead(D7));
//  Serial.print("D8 : ");
//  Serial.println(digitalRead(D8));
//  Serial.print("D9 : ");
//  Serial.println(digitalRead(D9));
//  Serial.print("D10 : ");
//  Serial.println(digitalRead(D10));
//  Serial.println("===================================\n\n");
  delay(2000) ;
}
