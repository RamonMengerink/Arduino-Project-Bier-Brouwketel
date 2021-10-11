class Button {
    const byte pin;
    int state;
    unsigned long buttonDownMs;

  public:
    Button(byte attachTo) :
      pin(attachTo){
    }


    void setup() {
      pinMode(pin, INPUT_PULLUP);
      state = HIGH;
    }

    void loop() {
      int prevState = state;
      state = digitalRead(pin);
      if (prevState == HIGH && state == LOW) {
        buttonDownMs = millis();
      }
      else if (prevState == LOW && state == HIGH) {
        if (millis() - buttonDownMs < 50) {
          // ignore this for debounce
        }
        else if (millis() - buttonDownMs < 2000) {
          // short click
          // TEST BY TOGGLING PIN 8
          // digitalWrite(8, !digitalRead(8));
          menu.Click(pin);
        }
        else  {
          // long click
          // TEST BY TOGGLING PIN 9
          // digitalWrite(9, !digitalRead(9));
          
        }
      }
    }
};
