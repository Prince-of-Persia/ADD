
void setup() 
{
  Serial.begin(9600);
  
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(0, INPUT_PULLUP);

  pinMode(4, OUTPUT);   /* define  pin (4,5,6,7) out*/
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void motor_c(int motor_n,int direction_m,int speed_m ) /* motor_n: the motor number to drive(0 stands for M1;1 stands for M2)*/
/* direction_m : the motor rotary direction(0 is clockwise and 1 is counter-clockwise).*/
/* speed_m: to control the motor rotation speed(from 0 to 255 ), the speed_m value is larger, the rotation speed is faster;*/
{  
  if(motor_n==1){   
    if(direction_m==1)
    {
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
    }
    else
    {
      digitalWrite(4,LOW);
      digitalWrite(5,HIGH);
    }   
  }
 else{
    if(direction_m==1)
    {
      digitalWrite(7,HIGH);
      digitalWrite(6,HIGH);
    }
    else
    {
      digitalWrite(7,LOW);
      digitalWrite(6,HIGH);
    }
 }
}

  
void loop() 
{
  Serial.println("Cycle");


  if(digitalRead(3)==LOW)
  {
    Serial.println("Front Switch");
  }

  if(digitalRead(2)==LOW)
  {
    Serial.println("Back Switch");
  }
  

 if(digitalRead(0)==LOW)
 {
  // Magnet
  motor_c(1, 1, 255);

  // Motor
  motor_c(0, 0, 100);
  delay(500);
  motor_c(0, 1, 100);
  delay(500);
 }
 else
 {
  motor_c(1, 0, 0);
  motor_c(0, 0, 0);
 }
 
 
}
