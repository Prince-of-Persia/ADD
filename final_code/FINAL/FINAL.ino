// Define pins:
#define fsr1pin A0
#define fsr2pin A1
#define fsr3pin A2
#define fsr4pin A3
#define crane 5
#define dcmotor 2
#define limits A8
//LEDs
int ledPin[] = {22,23,24,25,40,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53};

#include <Stepper.h>
#include <Servo.h>

const int stepsPerRevolution = 500;
Stepper myStepper(stepsPerRevolution, A13, A11, A12, A10);

Servo servo; 
Servo servo2;
Servo servo3;
int seq = -1;
int angle = 10;
int fsrreading1; // The current reading from the first FSR
int fsrreading2;
int fsrreading3;
int fsrreading4;

int delayTime = 20;

void setup() 
{
  Serial.begin(9600);
  
  servo.attach(8);
  servo.write(angle);
  
  myStepper.setSpeed(60);
  
  servo2.attach(10);
  servo2.write(95); 
  
  servo3.attach(11);
  servo3.write(0); 
  
  pinMode(fsr1pin, INPUT);
  pinMode(fsr2pin, INPUT);
  pinMode(fsr3pin, INPUT);
  pinMode(fsr4pin, INPUT);
  
  pinMode(ledPin[0], OUTPUT);
  pinMode(ledPin[1], OUTPUT);
  pinMode(ledPin[2], OUTPUT);
  pinMode(ledPin[3], OUTPUT);
  pinMode(ledPin[4], OUTPUT);
  pinMode(ledPin[5], OUTPUT);
  pinMode(ledPin[6], OUTPUT);
  pinMode(ledPin[7], OUTPUT);
  pinMode(ledPin[8], OUTPUT);
  pinMode(ledPin[9], OUTPUT);
  pinMode(ledPin[10], OUTPUT);
  pinMode(ledPin[11], OUTPUT);
  pinMode(ledPin[12], OUTPUT);
  
  pinMode(limits, INPUT_PULLUP);
  
  pinMode(crane, OUTPUT);
  digitalWrite(crane, HIGH);
  
  pinMode(dcmotor, OUTPUT);
  analogWrite(dcmotor, 0);

}
void loop() 
{ 
   
  if (seq == -1)
  {
    digitalWrite(ledPin[0], LOW);
    digitalWrite(ledPin[1], LOW);
    digitalWrite(ledPin[2], LOW);
    digitalWrite(ledPin[3], LOW);
    digitalWrite(ledPin[4], LOW);
    digitalWrite(ledPin[5], LOW);
    digitalWrite(ledPin[6], LOW);
    digitalWrite(ledPin[7], LOW);
    digitalWrite(ledPin[8], LOW);
    digitalWrite(ledPin[9], LOW);
    digitalWrite(ledPin[10], LOW);
    digitalWrite(ledPin[11], LOW);
    
    delay(3000);
    digitalWrite(crane, LOW);
    delay(500);
    digitalWrite(crane, HIGH);  
    seq++;  
  }
  //fsrreading1 = analogRead(fsr1pin);
  //Serial.println(fsrreading1);
  //fsrreading2 = analogRead(fsr2pin);
  //Serial.println(fsrreading2);
  fsrreading2 = analogRead(fsr2pin);
  Serial.println(fsrreading2);
  if (seq == 0) // First FSR (start of CMP)
  {
    digitalWrite(ledPin[0], HIGH);
    fsrreading1 = analogRead(fsr1pin);
    if (fsrreading1 > 150)
    {
      delay(2000);
      fsrreading1 = analogRead(fsr1pin);
        if (fsrreading1 > 150) 
        {
          seq++;
          servo3.write(0);  
        }
    }
  }
  
  if (seq == 1) // Opening first servo gate
  {
    digitalWrite(ledPin[1], HIGH); 
    for(angle = 10; angle < 90; angle++)  
    {                                  
      servo.write(angle);              
      delay(delayTime);              
    }
    seq++;
  }
  
  if (seq == 2) // Closing first servo gate
  {
    digitalWrite(ledPin[2], HIGH); 
    angle = 10;
    servo.write(angle);           
    delay(delayTime); 
    seq++;
  }
  
  if (seq == 3) // Second FSR (end of ramp)
  {
    digitalWrite(ledPin[3], HIGH); 
    fsrreading2 = analogRead(fsr2pin);
    if (fsrreading2 > 100)
    {
      delay(2000);
      fsrreading2 = analogRead(fsr2pin);
        if (fsrreading2 > 100) 
        {
          digitalWrite(crane, LOW);
          delay(1000);
          digitalWrite(crane, HIGH);        
          seq++;
        }
    }
  }
  
  if (seq == 4) //  FSR 
  {
    digitalWrite(ledPin[4], HIGH);  	
    fsrreading3 = analogRead(fsr3pin);
    if (fsrreading3 > 100)
    {
      seq++;
    }
  }
  
  if (seq == 5) // Opening servo2 gate
  {
    digitalWrite(ledPin[5], HIGH);  	
    delay(3000);
    servo2.write(30);
    seq++;        
  }
  
  if (seq == 6) // Closing servo2 gate
  {
    digitalWrite(ledPin[6], HIGH);  	
    delay(1000);
    servo2.write(95); 
    seq++;
  }
  
  if (seq == 7) // Truck FSR (start of CMP)
  {
    digitalWrite(ledPin[7], HIGH);
    fsrreading4 = analogRead(fsr4pin);
    if (fsrreading4 > 150)
    {
      delay(500);
      seq++;
    }
  }
  
  if (seq == 8)  // Truck move
  {
    digitalWrite(ledPin[8], HIGH);
    analogWrite(dcmotor, 200);
    
    if (digitalRead(limits) == LOW)
    {
      analogWrite(dcmotor, 0); 
      seq++;
    }
  }
  
  if (seq == 9) // Tell crane to pick up
  {
    digitalWrite(ledPin[9], HIGH);
    digitalWrite(crane, LOW);
    delay(500);  
    digitalWrite(crane, HIGH);
    seq++;
  } 

  if(seq == 10) // Run magic steps
  {
    digitalWrite(ledPin[10], HIGH);
    delay(17000);
    myStepper.step(-4000);
    seq++;
  }

  if(seq == 11) //
  {
    servo3.write(180); 
    digitalWrite(ledPin[11], HIGH);
    seq = -1;
  }
  
}
