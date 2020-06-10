
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

void motor_c(char motor_n, char direction_m, int speed_m ) /* motor_n: the motor number to drive(0 stands for M1;1 stands for M2)*/
/* direction_m : the motor rotary direction(0 is clockwise and 1 is counter-clockwise).*/
/* speed_m: to control the motor rotation speed(from 0 to 255 ), the speed_m value is larger, the rotation speed is faster;*/
{
  if (motor_n == 1) {
    if (direction_m == 1) {
      digitalWrite(4, HIGH);
      analogWrite(5, speed_m);
    }
    else {
      digitalWrite(4, LOW);
      analogWrite(5, speed_m);
    }
  }
  else {
    if (direction_m == 1) {
      digitalWrite(7, HIGH);
      analogWrite(6, speed_m);
    }
    else {
      digitalWrite(7, LOW);
      analogWrite(6, speed_m);
    }
  }
}


void loop()
{
  Serial.println("Cycle");


  if (digitalRead(3) == LOW) {
    Serial.println("Front Switch");
  }

  if (digitalRead(2) == LOW) {
    Serial.println("Back Switch");
  }


  if (digitalRead(0) == LOW) {
    // Magnet
    motor_c(0, 1, 255);

    // Motor
    motor_c(1, 0, 100);
    delay(500);
    motor_c(1, 1, 100);
    delay(500);
  }
  else
  {
    motor_c(1, 0, 0);
    motor_c(0, 0, 0);
  }


}
