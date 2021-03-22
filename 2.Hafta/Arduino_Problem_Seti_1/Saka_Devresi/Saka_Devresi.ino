#define BLYNK_PRINT Serial
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

char auth[] = "7Y04JScgGL9WWfvEcwQQ5wL_Xr6P5qqT";
char ssid[] = "MAD";
char pass[] = "11223344";

#define EspSerial Serial1
#define ESP8266_BAUD 115200
#define BLYNK_PRINT Serial

ESP8266 wifi(&EspSerial);

#define LED1 13
#define LED2 5
#define LED3 3

BLYNK_WRITE(V0)
{
  digitalWrite(LED1, HIGH);
  delay(5000);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, HIGH);
  delay(5000);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, HIGH);
  delay(5000);
  digitalWrite(LED3, LOW);

}

void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  Serial.begin(9600);
  delay(10);

  EspSerial.begin(ESP8266_BAUD);
  delay(10);
  Blynk.begin(auth, wifi, ssid, pass);
}

void loop()
{ 
  Blynk.run();
  Blynk.virtualWrite(V0,HIGH);

}
