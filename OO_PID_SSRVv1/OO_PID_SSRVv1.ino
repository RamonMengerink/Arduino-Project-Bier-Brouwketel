#include <PID_v2.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <SimpleKalmanFilter.h>
//#include <EEPROM.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

// Data wire is plugged into port 6 on the Arduino
#define ONE_WIRE_BUS 6

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

SimpleKalmanFilter simpleKalmanFilter(0.5, 0.5, 0.01);

//Specify the links and initial tuning parameters
double Kp=2000.0, Ki=10.0, Kd=3000.0;
PID_v2 myPID(Kp, Ki, Kd, PID::Direct);


#define RELAY_PIN 7
