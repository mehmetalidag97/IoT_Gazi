const int kirmizi = 2;
const int sari = 3;
const int yesil = 4;

void setup() {
  pinMode(kirmizi, OUTPUT);
  pinMode(sari, OUTPUT);
  pinMode(yesil, OUTPUT);
}

void loop() {
  digitalWrite(kirmizi, HIGH);
  delay(22000);
  digitalWrite(sari, HIGH);
  delay(12000);
  
  digitalWrite(sari, LOW);
  digitalWrite(kirmizi, LOW);

  digitalWrite(yesil, HIGH);
  delay(5000);
  digitalWrite(yesil, LOW);
}
