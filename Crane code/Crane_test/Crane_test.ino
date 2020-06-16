#include <Stepper.h>

int hoist_pos = 0;

unsigned long startMillis = 0;

int seq = 0;

const int stepsPerRevolution = 500;
Stepper myStepper(stepsPerRevolution, A5, A3, A4, A2);

void setup()
{
  Serial.begin(9600);

  pinMode(A5, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A2, OUTPUT);

  myStepper.setSpeed(60);
  
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);

  pinMode(3, OUTPUT); //Motor A PMV
  pinMode(12, OUTPUT); // A Dir
  pinMode(9, OUTPUT); // Brake A
  
  pinMode(11, OUTPUT); // Motor B PMV
  pinMode(13, OUTPUT); // B Dir
  pinMode(8, OUTPUT); // Brake B
  
  pinMode(7, INPUT_PULLUP);
}  

void motor_c(char motor_n, char direction_m, int speed_m ) /* motor_n: the motor number to drive(0 stands for M1;1 stands for M2)*/
/* direction_m : the motor rotary direction(0 is clockwise and 1 is counter-clockwise).*/
/* speed_m: to control the motor rotation speed(from 0 to 255 ), the speed_m value is larger, the rotation speed is faster;*/
{
  if (((digitalRead(5) == LOW)||(digitalRead(4) == HIGH))&&(motor_n == 0)&&(direction_m == 1)){
    speed_m = 0;
  }
  
  if (((digitalRead(6) == LOW)||(digitalRead(4) == HIGH))&&(motor_n == 0)&&(direction_m == 0)){
    speed_m = 0;
  }  
  
  if (motor_n == 1) {
    if (direction_m == 1) {
      digitalWrite(12, HIGH);
      if (speed_m == 0){
        digitalWrite(9, HIGH);
      }
      else{
        digitalWrite(9, LOW);
      }
      analogWrite(3, speed_m);
    }
    else {
      digitalWrite(12, LOW);
      if (speed_m == 0){
        digitalWrite(9, HIGH);
      }
      else{
        digitalWrite(9, LOW);
      }
      analogWrite(3, speed_m);
    }
  }
  else {
    if (direction_m == 1) {
      digitalWrite(13, HIGH);
      if (speed_m == 0){
        digitalWrite(8, HIGH);
      }
      else{
        digitalWrite(8, LOW);
      }
      analogWrite(11, speed_m);
    }
    else {
      digitalWrite(13, LOW);
      if (speed_m == 0){
        digitalWrite(8, HIGH);
      }
      else{
        digitalWrite(8, LOW);
      }
      analogWrite(11, speed_m);
    }
  }
}


void loop()
{
  
  Serial.println(seq);
  Serial.println(hoist_pos);
  
  // Wait at start
  if (seq == 0){
    delay(100);
    if(digitalRead(7) == LOW) {
      seq++;   
    }    
  }
  
  // Move to start pos
  if (seq == 1){
    motor_c(0, 0, 150);
    if (digitalRead(6) == LOW){
      motor_c(0, 0, 0);
      seq++;
    }
  }
  
  // Wait for ball ready
  if (seq == 2){
    delay(100);
    if(digitalRead(7) == LOW){
      seq++; 
    }    
  }
  
  // Pick up ball 1
  if (seq == 3){
    motor_c(1, 0, 255);
    myStepper.step(-10);
    hoist_pos = hoist_pos - 10;
    if (hoist_pos < -1900){
      delay(500);
      seq++;  
    }
  }
  
  // Lift ball
  if (seq == 4){
    motor_c(1, 0, 255);
    myStepper.step(10);
    hoist_pos = hoist_pos + 10;
    if (hoist_pos > -1000){
      seq++;  
    }
  }
  
  // To Target 1
  if (seq == 5){
    if (startMillis == 0){
      startMillis = millis();
    }
     
     motor_c(1, 0, 255);
     motor_c(0, 1, 100);
     
     if (hoist_pos < -1000){
       myStepper.step(10);
       hoist_pos = hoist_pos + 10;
     }
     
     if ((millis()-startMillis) > 1400)
     {
       startMillis = 0;
       motor_c(0, 1, 0);
       delay(500);
       motor_c(1, 0, 0);
       delay(500);
       seq++;
     }
  }
  
  // Move across above stack
  if (seq == 6){
    if (startMillis == 0){
      startMillis = millis();
    }
    
    motor_c(0, 1, 100);
    
    if (hoist_pos < -100){
       myStepper.step(10);
       hoist_pos = hoist_pos + 10;
    }
    
    if ((millis()-startMillis) > 1000){
      startMillis = 0;
      motor_c(0, 1, 0);
      seq++;
    }
  }
  
   // Lower to ready pos
  if (seq == 7){
    myStepper.step(-10);
    hoist_pos = hoist_pos - 10;
    if (hoist_pos < -1000){
      seq++;  
    }
  }
  
  // Wait for ball to reach t2
  if (seq == 8){
    delay(100);
    if(digitalRead(7) == LOW){
      seq++;   
    }    
  }
  
  
  // Pick up ball 2
  if (seq == 9){
    motor_c(1, 0, 255);
    myStepper.step(-10);
    hoist_pos = hoist_pos - 10;
    if (hoist_pos < -2000){
      delay(500);
      seq++;  
    }
  }
  
  // To drop 2
  if (seq == 10){
    motor_c(1, 0, 255);
    motor_c(0, 1, 100);
    
    if (hoist_pos < -1000){
       myStepper.step(10);
       hoist_pos = hoist_pos + 10;
    } 
    
    if (digitalRead(5) == LOW){
      motor_c(0, 1, 0);
      seq++;
    }
  }
  
  // Lower and drop
  if (seq == 11){
    motor_c(1, 0, 255);
    myStepper.step(-10);
    hoist_pos = hoist_pos - 10;
    if (hoist_pos < -1200){
      delay(500);
      motor_c(1, 0, 0);
      delay(500);
      seq++; 
    } 
  }
  
  // Up Reset
  if (seq == 12){
    myStepper.step(10);
    hoist_pos = hoist_pos + 10;
    if (hoist_pos >= 0){
      seq++; 
    }
  }   
  
  
  if (seq == 13){
    if (startMillis == 0){
      startMillis = millis();
    }
    
    motor_c(0, 0, 150);
    
    if (hoist_pos < -100){
       myStepper.step(10);
       hoist_pos = hoist_pos + 10;
    }
    
    if ((millis()-startMillis) > 1000){
      startMillis = 0;
      motor_c(0, 1, 0);
      seq = 0;
    }
  }
  
  // Motor Stoppers
  if (digitalRead(5) == LOW) {
    Serial.println("Front Switch");
    motor_c(0, 0, 0);
  }

  if (digitalRead(6) == LOW) {
    Serial.println("Back Switch");
    motor_c(0, 0, 0);
  }

  if (digitalRead(4) == HIGH){
    motor_c(0, 0, 0);    
  } 
}
