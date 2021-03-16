int ledler[5] = {3, 4, 5, 6, 7};
int buton = 2;
int buton_durumu = 0;

void setup()
{
  pinMode(buton, INPUT);
  Serial.begin(9600);
  for (int i = 0; i < 5; i++)
  {
    pinMode(ledler[i], OUTPUT);
  }
}

void loop()
{
  buton_durumu = digitalRead(buton);

  if (buton_durumu == 1) {
    {
      for (int i = 0; i < 5; i++)
      {
        digitalWrite(ledler[i], HIGH);

        Serial.print(String(i) + " Yandi");
        Serial.println();
        delay(500);
        digitalWrite(ledler[i], LOW);
        Serial.print(String(i) + " Sondu");
        Serial.println();
      }
    }
    for (int i = 5; i > -1; i--)
    {
      digitalWrite(ledler[i], HIGH);
      delay(500);
      digitalWrite(ledler[i], LOW);
    }
  }
  else  {
    digitalWrite(ledler[5], LOW);
  }
}
