int trigger_pin = 2;
int echo_pin = 3;
int buzzer_pin = 11; 
int buzzer_pin_2 = 12;
int IR_pin = 13;
int vibration_pin = 6;

#define POWER_PIN  7
#define SIGNAL_PIN A5

int value = 0; // variable to store the sensor value

int time;
int distance; 

int a = 0;
int b = 0;

int Gas_Strength = 0;
int c = 0;
int d = 0;

void setup() 
{
      Serial.begin (9600); 
      pinMode (trigger_pin, OUTPUT); 
      pinMode (echo_pin, INPUT);
      pinMode (buzzer_pin, OUTPUT);
      pinMode (buzzer_pin_2, OUTPUT);
      pinMode (IR_pin, OUTPUT);
      pinMode (vibration_pin, OUTPUT);
      pinMode(POWER_PIN, OUTPUT);   // configure D7 pin as an OUTPUT
      digitalWrite(POWER_PIN, LOW); // turn the sensor OFF
      
}
void loop() 
{
  
  // Ultrasonic Sensor
  
  digitalWrite (trigger_pin, HIGH);
  delayMicroseconds (10);
  digitalWrite (trigger_pin, LOW);
  time = pulseIn (echo_pin, HIGH);
  distance = (time * 0.034) / 2;

  if (distance <= 60) 
  {
      Serial.println ("Object is near ");
      Serial.print ("Distance = ");              
      Serial.println (distance);        
      digitalWrite (buzzer_pin, HIGH);
      delay (500);
   }
   else {
      Serial.println ("Object is far ");
      Serial.print ("Distance = ");              
      Serial.println (distance);        
      digitalWrite (buzzer_pin, LOW);
      delay (500);        
   }
  
  
  // IR sensor

  
  a = analogRead(A0);
  b = map(a, 0, 1023, 0, 255);
  
  if (b < 50)
  {
    Serial.print("b = ");
    Serial.println(b);
    Serial.println ("Motion Detected");
    //digitalWrite (buzzer_pin_2, HIGH);
    digitalWrite (vibration_pin, HIGH);
    delay (500);
  } 
  else
  {
    Serial.println ("Motion NOT Detected");
    digitalWrite (vibration_pin, LOW);
    delay (500);
  } 

  // Water Sensor
  
  digitalWrite(POWER_PIN, HIGH);  // turn the sensor ON
  delay(10);                      // wait 10 milliseconds

  value = analogRead(SIGNAL_PIN); // read the analog value from sensor

  Serial.print("Water level = ");
  Serial.println(value);
  
  if (value >= 300)
  {
      tone(buzzer_pin, 700, 200);
      digitalWrite (buzzer_pin, LOW);
      delay (5); 
      //digitalWrite (buzzer_pin, HIGH);
      //delay (500);
  }    
  else
  {
      digitalWrite (buzzer_pin, LOW);
      delay (500); 
  }  
  
}
