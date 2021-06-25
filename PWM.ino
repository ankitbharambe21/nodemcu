//Motor A
const int inputPin1  = 5;    // Pin 15 of L293D IC, D1 Pin of NodeMCU
const int inputPin2  = 16;    // Pin 10 of L293D IC, D0 Pin of NodeMCU
//Motor B
const int inputPin3  = 4;    // Pin  7 of L293D IC, D2 Pin of NodeMCU
const int inputPin4  = 0;    // Pin  2 of L293D IC, D3 Pin of NodeMCU
int EN1 = 12;                 // Pin 1 of L293D IC, D6 Pin of NodeMCU
int EN2 = 14;                 // Pin 9 of L293D IC, D5 Pin of NodeMCU
void setup()

{
  
    pinMode(EN1, OUTPUT);   // where the motor is connected to
    pinMode(EN2, OUTPUT);   // where the motor is connected to
    pinMode(inputPin1, OUTPUT);
    pinMode(inputPin2, OUTPUT);
    pinMode(inputPin3, OUTPUT);
    pinMode(inputPin4, OUTPUT);  
    Serial.begin(9600);
    Serial.println("Enter values between 0 - 255");
}

void loop()

{
  if(Serial.available())
    { 
      int speed = Serial.parseInt();
      Serial.println(speed)
        analogWrite(EN1, speed);//sets the motors speed
        analogWrite(EN2, speed);//sets the motors speed
        digitalWrite(inputPin1, HIGH);
        digitalWrite(inputPin2, LOW);
        digitalWrite(inputPin3, HIGH);
        digitalWrite(inputPin4, LOW);  
     }
}
