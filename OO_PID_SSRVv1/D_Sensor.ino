//This still needs to be tested!!
class Sensor{
    const byte SensorNum;
    float RawTempC = 0.0;


  public:
    Sensor(byte attachTo) :
      SensorNum(attachTo){
    }
    float TempC = 0.0;


  void setup(){

  }
  void loop(){
    sensors.requestTemperatures(); // send the command to get temperature
    RawTempC = sensors.getTempCByIndex(SensorNum);
    if (RawTempC != DEVICE_DISCONNECTED_C) {
      TempC = simpleKalmanFilter.updateEstimate(RawTempC);  
    }else {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Sensor Error");
      delay(1000);
    }
    
    
  }
}sensor(0);
