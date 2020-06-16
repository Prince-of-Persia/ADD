// Define pins:
#define fsr1pin A0
#define fsr2pin A1
#define crane 4

#include <Servo.h>

Servo servo;
int seq = -1;
int angle = 10;
int fsrreading1; // The current reading from the first FSR
int fsrreading2;

void setup() {
  Serial.begin(9600);
  
  servo.attach(8);
  servo.write(angle);
  
  pinMode(fsr1pin, INPUT);
  pinMode(fsr2pin, INPUT);
  
  pinMode(crane, OUTPUT);
  digitalWrite(crane, HIGH);
}
void loop() 
{ 
  
  if (seq == -1){
    delay(3000);
    digitalWrite(crane, LOW);
    delay(500);
    digitalWrite(crane, HIGH);
    seq++;  
  }
  fsrreading1 = analogRead(fsr1pin);
  Serial.println(fsrreading1);
    //fsrreading2 = analogRead(fsr2pin);
  //Serial.println(fsrreading2);
  if (seq == 0) // First FSR (start of CMP)
  {
    fsrreading1 = analogRead(fsr1pin);
    if (fsrreading1 > 350)
    {
      delay(2000);
      fsrreading1 = analogRead(fsr1pin);
        if (fsrreading1 > 350) 
        {
          seq++;
        }
    }
  }
  
  if (seq == 1) // Opening first servo gate
  {
    for(angle = 10; angle < 90; angle++)  
    {                                  
      servo.write(angle);               
      delay(15);                   
    }
    seq++;
  }
  
  if (seq == 2) // Closing first servo gate
  {
    angle = 10;
    servo.write(angle); 
    seq++;
  }
  
  if (seq == 3) // Second FSR (end of ramp)
  {
    fsrreading2 = analogRead(fsr2pin);
    if (fsrreading2 > 100)
    {
      delay(2000);
      fsrreading2 = analogRead(fsr2pin);
        if (fsrreading2 > 100) 
        {
          digitalWrite(crane, LOW);
          delay(100);
          digitalWrite(crane, HIGH);
          seq++;
        }
    }
  }
  
  
  
}
