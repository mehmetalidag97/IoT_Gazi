#include <Servo.h>

Servo motor;

int pos = 0;

void setup()
{
  motor.attach(3);
}

void loop()
{ 
  for (pos = 180; pos >= 0 ; pos -= 15)
  {
    motor.write(pos);
    delay(500);
  }

  for (pos = 0; pos <= 180 ; pos += 30)
  {
    motor.write(pos);
    delay(500);

  }


}
