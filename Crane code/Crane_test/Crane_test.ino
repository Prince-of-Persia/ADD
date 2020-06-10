int move_dir = 1;

void setup()
{
  Serial.begin(9600);

  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);

  pinMode(3, OUTPUT); //Motor A PMV
  pinMode(12, OUTPUT); // A Dir
  pinMode(9, OUTPUT); // Brake A
  
  pinMode(11, OUTPUT); // Motor B PMV
  pinMode(13, OUTPUT); // B Dir
  pinMode(8, OUTPUT); // Brake B
}

void motor_c(char motor_n, char direction_m, int speed_m ) /* motor_n: the motor number to drive(0 stands for M1;1 stands for M2)*/
/* direction_m : the motor rotary direction(0 is clockwise and 1 is counter-clockwise).*/
/* speed_m: to control the motor rotation speed(from 0 to 255 ), the speed_m value is larger, the rotation speed is faster;*/
{
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
  Serial.println("Cycle");

  if (digitalRead(5) == LOW) {
    Serial.println("Front Switch");
    move_dir = 0;
    
  }

  if (digitalRead(6) == LOW) {
    Serial.println("Back Switch");
    move_dir = 1;
  }


  if (digitalRead(4) == LOW) {
    // Magnet
    //motor_c(1, 1, 255);

    // Motor
    
    motor_c(0, move_dir, 100);
    
    //motor_c(0, 0, 100);
    //delay(1000);
    //motor_c(0, 1, 100); // dir 1 is forwards
    //delay(1000);
  }
  else
  {
    motor_c(1, 0, 0);
    motor_c(0, 0, 0);
  }
  
}
