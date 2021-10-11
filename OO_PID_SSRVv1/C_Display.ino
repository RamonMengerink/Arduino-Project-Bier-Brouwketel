//schrijft menu inputs naar scherm.
//programma output moet nog toegevoegd worden!
class ToDisplay {

  int ShownStateL1 = 0;
  int ShownStateL2 = 0;
  int ShownLevel = 0;
  int ShownInMenu = false;

  String LineOne = "";
  String LineTwo = "";

  public:
    void setup(){
      Serial.begin(9600);
    }

    void loop(){
      if (menu.InMenu == true) {
        if ((int(menu.MenuState.StateL1) != ShownStateL1) or (int(menu.MenuState.StateL2) != ShownStateL2) or (int(menu.MenuState.Level) != ShownLevel) or (menu.InMenu != ShownInMenu)){
          ShownStateL1 = (int) menu.MenuState.StateL1;
          ShownStateL2 = (int) menu.MenuState.StateL2;
          ShownLevel = (int) menu.MenuState.Level;
          
          if (menu.MenuState.Level == 1){
            LineOne = ">";
          }else if (menu.MenuState.Level == 2){
            LineTwo = ">";
          }
          
          switch (int(menu.MenuState.StateL1)){
            case 0:
              LineOne = LineOne + "Maisch";
              break;
            case 1:
              LineOne = LineOne + "Kook";
              break;
            case 2:
              LineOne = LineOne + "Combinatie";
              break;
          }
          //LineOne = LineOne + String(menu.MenuState.StateL1);
          switch (menu.MenuState.StateL2){
            case 0:
              LineTwo = LineTwo + "Standaard";
              break;
            case 1:
              LineTwo = LineTwo + "Droog";
              break;
            case 2:
              LineTwo = LineTwo + "Weizen";
              break;
            case 3:
              LineTwo = LineTwo + "60 minuten";
              break;
            case 4:
              LineTwo = LineTwo + "90 minuten";
              break;
          }
          //LineTwo = LineTwo + String(menu.MenuState.StateL2);
          Serial.println(LineOne);
          Serial.println(LineTwo);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print(LineOne);
          lcd.setCursor(0,1);
          lcd.print(LineTwo);
          LineOne = " ";
          LineTwo = " ";
        } 
      }else{ //niet in menu
        Serial.println("niet in menu");
      }//Serial.println("stateL2 " + String(menu.MenuState.StateL2));
       //Serial.println("level   " + String(menu.MenuState.Level)); 
       ShownInMenu = menu.InMenu;
    }

  
}todisplay;
