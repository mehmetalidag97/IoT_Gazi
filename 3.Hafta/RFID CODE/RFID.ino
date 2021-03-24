#include <SPI.h>
#include <MFRC522.h>

int RST_PIN = 9;
int SS_PIN = 10;
#define kirmiziled 11
#define yesilled 13

MFRC522 rfid(SS_PIN, RST_PIN); 
byte ID[4] = {227 , 211 , 39 , 21};

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
}

void loop() {

  if ( ! rfid.PICC_IsNewCardPresent())
    return;

  if ( ! rfid.PICC_ReadCardSerial())      
    return;

  if (rfid.uid.uidByte[0] == ID[0] &&
      rfid.uid.uidByte[1] == ID[1] &&
      rfid.uid.uidByte[2] == ID[2] &&
      rfid.uid.uidByte[3] == ID[3] ) {

    ekranaYaz();
    digitalWrite(yesilled, HIGH);
    Serial.println("Yesil Led Yandi");
    Serial.println(" ");
    delay(2000);
    digitalWrite(yesilled, LOW);
  }
 
  else {
    Serial.println("Kart Tanimli Degil");
    ekranaYaz();
    digitalWrite(kirmiziled, HIGH);
    Serial.println("Kirmizi Led Yandi");
    Serial.println(" ");
    delay(1000);
    digitalWrite(kirmiziled, LOW);
  }
  rfid.PICC_HaltA();
}
void ekranaYaz() {
  Serial.print("ID Numarasi: ");
  for (int sayac = 0; sayac < 4; sayac++) {
    Serial.print(rfid.uid.uidByte[sayac]);
    Serial.print(" ");
  }
  Serial.println("");
}
