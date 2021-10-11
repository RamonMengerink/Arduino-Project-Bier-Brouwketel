//Temp control still needs to be tested!!
class Control{
  // ? Define Variables we'll be connecting to
  // ? double Setpoint, Input, Output;


  const int WindowSize = 5000;
  unsigned long WindowStartTime;

  public:
  
  boolean active = false;
  double output = 0.0;
  
  void setup(){
    WindowStartTime = millis();

    // tell the Pid to range between 0 and the full window size
    myPID.SetOutputLimits(0, WindowSize);

    // turn the PID on
    myPID.Start(sensor.TempC,    // input
                0,               // current output
                0);              // setpoint
  }
  void loop(){
    output = myPID.Run(sensor.TempC);

    while (millis() - WindowStartTime > WindowSize) {
      WindowStartTime += WindowSize;
    }
    if ((output < millis() - WindowStartTime) && (active))
      digitalWrite(RELAY_PIN, HIGH);
    else
      digitalWrite(RELAY_PIN, LOW);
  }
  
}control;
