const int ProxSensor=5;
int LED = 16;

void setup() 
{                
  pinMode(LED, OUTPUT);          // Pin 13 has an LED connected on most Arduino boards:  
  pinMode(ProxSensor,INPUT);    //Pin 2 is connected to the output of proximity sensor
  Serial.begin(9600);
}

void loop() 
{
  long state = digitalRead(ProxSensor);
  if(state == HIGH)      //Check the sensor output
  {
    digitalWrite(LED, HIGH);   // set the LED on
    Serial.println(state);
    delay(1000);
  }
  else
  {
    digitalWrite(LED, LOW);    // set the LED off
    Serial.println(state);
    delay(1000);
  }

}
