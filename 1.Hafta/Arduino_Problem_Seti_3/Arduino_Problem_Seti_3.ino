#include <dht11.h>
#define dht11pin 4

dht11 DHT11;

void setup()
{
  Serial.begin(9600);
  pinMode(4,INPUT);
}

void loop()
{
  delay(500);
  int chk = DHT11.read(dht11pin);

  Serial.print("Humidity (%): ");
  Serial.println((float)DHT11.humidity, 2);

  Serial.print("Celcius: ");
  Serial.println((float)DHT11.celcius(), 2);

  Serial.print("Kelvin : ");
  Serial.println((double)DHT11.kelvin(), 2);

  Serial.print("Fahrenheit : ");
  Serial.println((double)DHT11.fahrenheit(), 2);

  Serial.println("-------------------");


  delay(1000);

}
