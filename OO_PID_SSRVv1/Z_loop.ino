Button button_6(6);
Button button_7(7);
Button button_8(8);
Button button_9(9);

/*
enum ProgramStatus{
  M = 0,
  MAISCH = 1,
  POMP = 2,
  KOOK = 3,
}
*/



//Button button(9);
//Button button(10);



void setup() {
  menu.setup();
  button_6.setup(); 
  button_7.setup(); 
  button_8.setup();
  button_9.setup();
  sensor.setup();
  control.setup();
  todisplay.setup();
  states.setup();

}
void loop() {
  menu.loop();
  button_6.loop();
  button_7.loop();
  button_8.loop();
  button_9.loop();
  sensor.loop();
  control.setup();
  todisplay.loop();
  states.loop();
}
