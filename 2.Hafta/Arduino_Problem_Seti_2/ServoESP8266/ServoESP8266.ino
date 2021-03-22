#define BLYNK_PRINT Serial
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
#include <Servo.h>

Servo servo;

char auth[] = "7Y04JScgGL9WWfvEcwQQ5wL_Xr6P5qqT";
char ssid[] = "MAD";
char pass[] = "11223344";

ESP8266 wifi(&Serial1);

void setup() {
  Serial1.begin(115200);
  Serial.begin(9600);
  Blynk.begin(auth,wifi, ssid, pass);
  servo.attach(9);
}
void loop() {
  Blynk.run();
}
BLYNK_WRITE(V0) {
  servo.write(param.asInt()); // 0-179
  Serial.println(param.asInt());
}
