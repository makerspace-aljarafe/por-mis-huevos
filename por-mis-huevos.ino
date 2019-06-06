#include <DHT_U.h>
#include <DHT.h>

/**
 * Constants
 */
  
#define TEMPERATURE 1
#define HUMIDITY 2
#define SWING 3
    
/*
 * 

int incubationTemps[21] = {37.7, 37.7, 37.7, 37.7, 37.7};

int SENSOR = 2;
#define RELAY 3
#define SENSOR2 4
#define TEMP 21.0

float t1, t2, h1, h2;
float HUMEDAD;

DHT dht(SENSOR, DHT22);
//DHT dht2(SENSOR2, DHT11);

class Day {
  int temperature;
  int humidity;
  int swings;
};
*/

class IncubatorHardware {
  public:
    void setTemp() {}
    void getTemp() {}
    void setHumidity() {}
    void getHumidity() {}
};

class HardwareEvent {
  private:
    int type;
    double value;
    
  public:
    HardwareEvent(int type, double value) {
      this->type = type;
      this->value = value;
    }

    String getInfo() {
      switch(this->type) {
        case TEMPERATURE:
          return "TEMPERATURE";
          break;
        case HUMIDITY:
          return "HUMIDITY";
          break;
        case SWING:
          return "SWING";
          break;
      }
    }
   
};

class IncubationProgramme {
  public:

    String getProgrammeInfo() {}
};

class IncubationProgrammeTest {};
class IncubationProgrammeChicken {};

class Incubator {
  private:
    double objectiveTemp;
    double actualTemp;
    int objectiveHumidity;
    int actualHumidity;
    IncubatorHardware ih;
    IncubationProgramme ip;
    
  public:
    Incubator(IncubatorHardware ih, IncubationProgramme ip) {
      this->ih = ih;
      this->ip = ip;
    }
    
    void getInfo() {}
};




IncubationProgramme ip;
IncubatorHardware ih;
Incubator incu(ih, ip);
HardwareEvent ev1(TEMPERATURE, 12.3);
HardwareEvent ev2(HUMIDITY, 80.0);
HardwareEvent ev3(SWING, 0);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //dht.begin();
  //dht2.begin();

  //pinMode(RELAY, OUTPUT);
}

void loop() {
Serial.print(ev1.getInfo());
Serial.print(ev2.getInfo());
Serial.print(ev3.getInfo());


/*
  t1 = dht.readTemperature();

  h1 = dht.readHumidity();
  
    t2 = dht2.readTemperature();
    h2 = dht2.readHumidity();
  

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

*/
}
