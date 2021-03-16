int pot = A0;
int led = 13;
int motor = 6;
int potDeger;

void setup()
{
  pinMode(pot, INPUT);
  pinMode(led, OUTPUT);
  pinMode(motor, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  potDeger = analogRead(pot);
  potDeger = map(potDeger, 0 , 1023, 0, 255);
  analogWrite(motor, potDeger);

  Serial.print("Motor hızı:");
  Serial.println(potDeger);
  
  if (potDeger >= 200) {
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(100);

    Serial.println("Motor hız sınırını aştı, Led yandı.");
  }
  else
  {
    digitalWrite(13, LOW);
  }
}
