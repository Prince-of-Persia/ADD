
void setup() 
{
  Serial.begin(9600);
  pinMode(4,OUTPUT);   /* define  pin (4,5,6,7) out*/
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
}

void motor_c(char motor_n,char direction_m,int speed_m ) /* motor_n: the motor number to drive(0 stands for M1;1 stands for M2)*/
/* direction_m : the motor rotary direction(0 is clockwise and 1 is counter-clockwise).*/
/* speed_m: to control the motor rotation speed(from 0 to 255 ), the speed_m value is larger, the rotation speed is faster;*/
{  
  if(motor_n==1)
  {   
    if(direction_m==1)
    {
        digitalWrite(4,HIGH);    // pin 4 controls M2 rotary direction analogWrite(5,speed_m);  //pin 5 controls M2 rotation speed
    }
    else
    {
      digitalWrite(4,LOW);
    }
    analogWrite(5,speed_m);
   }
   else
   {
     if(direction_m==1)
      {
        digitalWrite(7,HIGH);  // pin 7 controls M1 rotary direction
      }
      else
      {
        digitalWrite(7,LOW); 
      }
      analogWrite(6,speed_m);
    }

 }
  
void loop() 
{
 Serial.println("Cycle");
 motor_c(1,0, 100);// M1 rotate in clockwise of 127 component velocity(total as 225)
 delay(1000);        //delay for 1s
 motor_c(1,1, 100);// M1 rotate in counter-clockwise of 200 component velocity(total as 225)
 delay(1000);      //delay for 5s
}
