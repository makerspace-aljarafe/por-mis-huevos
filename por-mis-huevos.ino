// Necessary for the temperature sensors
#include <DHT_U.h>
#include <DHT.h>

// For the task manager
#include <IoAbstraction.h>


// LCD library
#include <LiquidCrystal.h>


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

void onTimer() {
        Serial.println("hola hola\n");
}


/*
 * Global initializations
 */
IncubationProgramme ip;
IncubatorHardware ih;
Incubator incu(ih, ip);
HardwareEvent ev1(TEMPERATURE, 12.3);
HardwareEvent ev2(HUMIDITY, 80.0);
HardwareEvent ev3(SWING, 0);

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  uint8_t taskId = taskManager.scheduleOnce(3000, onTimer);

  //dht.begin();
  //dht2.begin();

  //pinMode(RELAY, OUTPUT);

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Por mis huevos");
}

void loop() {
  taskManager.runLoop();
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
