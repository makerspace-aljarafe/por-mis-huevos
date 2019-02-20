#include <DHT_U.h>
#include <DHT.h>

int SENSOR = 2;
#define RELAY 3
#define SENSOR2 4
#define TEMP 21.0

float t1, t2, h1, h2;
float HUMEDAD;

DHT dht(SENSOR, DHT22);
//DHT dht2(SENSOR2, DHT11);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  //dht2.begin();

  pinMode(RELAY, OUTPUT);
}

void loop() {

  t1 = dht.readTemperature();

  h1 = dht.readHumidity();
  /*
    t2 = dht2.readTemperature();
    h2 = dht2.readHumidity();
  */

  Serial.print("T1: ");
  Serial.print(t1);
  Serial.print(" H1: ");
  Serial.print(h1);
  Serial.print(" | ");

  Serial.print("T2: ");
  Serial.print(t2);
  Serial.print(" H2: ");
  Serial.print(h2);
  Serial.println();

  if (t1 > TEMP) {
    // switch relay OFF
    digitalWrite(RELAY, HIGH);
        Serial.println("Temperatura alta!");

  } else if (t1 < TEMP) {
    digitalWrite(RELAY, LOW);
    Serial.println("Temperatura baja!");
  } else {
    Serial.println("Temperatura correcta!");
  }

  delay(1000);


}
