class Menu {
  //int 
  const byte menuBtn;
  const byte leftBtn;
  const byte rightBtn;
  const byte selectBtn;     
  

  public:
    Menu(byte attachMenuBt, byte attachLeftBt, byte attachRightBt, byte attachSelectBt) :
      menuBtn(attachMenuBt),
      leftBtn(attachLeftBt),
      rightBtn(attachRightBt),
      selectBtn(attachSelectBt){     
    }

  enum stateL1 {
    MAISCH = 0,
    KOOK = 1,
    COMBI = 2
  };
  
  enum stateL2 {
    STANDAARD = 0,
    DROOG = 1,
    WEIZEN = 2,
    ZESTIG = 3,
    NEGENTIG = 4
  };

  enum menulevel{
    L1 = 1,
    L2 = 2,
  };

  struct menustate {
    stateL1 StateL1;
    stateL2 StateL2;
    menulevel Level;
  }MenuState;
  // virtual ~Menu() = 0; //a pure virtual function to make the class abstract
  
  boolean InMenu = true;

    void setup() {
      //pinMode(9, OUTPUT);
      //pinMode(10, OUTPUT);
      MenuState.StateL1 = MAISCH;
      MenuState.StateL2 = STANDAARD;
      MenuState.Level = 1;
      
    }
    void loop() {   
    }
    void Click(byte pin){
      if (pin == menuBtn){
        if (!InMenu){
          InMenu = true; //Niet in menu: Ga naar menu
          MenuState.Level = 1;
        }
        else if (InMenu){
          if (MenuState.Level == 1){  // In top level menu: ga naar pogram
            InMenu = false;
          }else if (MenuState.Level == 2) {
            MenuState.Level = 1;      // In botom level menu: ga naar top level menu
          }
        }
          // menu
          // In program: pause program, switch off heating
          // In top menu: continue program 
          // In lower menu: go up in menu

      } else if (pin == leftBtn) { 
        if (MenuState.Level == 1) { 
          switch (MenuState.StateL1) {  // in top level menu: scroll door top level menu.
            case MAISCH :
              MenuState.StateL1 = COMBI;
              MenuState.StateL2 = STANDAARD;
              break;
            case KOOK   :
              MenuState.StateL1 = MAISCH;
              MenuState.StateL2 = STANDAARD;
              break;
            case COMBI  :
              MenuState.StateL1 = KOOK;
              MenuState.StateL2 = ZESTIG;
              break;
          }
        }else if (MenuState.Level == 2) {
          switch (MenuState.StateL1){
            case MAISCH:
              switch (MenuState.StateL2){ //In botom level: door  Maisch schemas scrollen
                case STANDAARD:
                  MenuState.StateL2 = WEIZEN;
                  break;
                case DROOG:
                  MenuState.StateL2 = STANDAARD;
                  break;
                case WEIZEN:
                  MenuState.StateL2 = DROOG;
                  break;
              }
              break;
            case KOOK:
              switch (MenuState.StateL2){ // In Kook schema: door kook schemas scrollen
                case ZESTIG:
                  MenuState.StateL2 = NEGENTIG;
                  break;
                case NEGENTIG:
                  MenuState.StateL2 = ZESTIG;
                  break;
              }
              break;
            case COMBI:
              switch (MenuState.StateL2){ //In botom level: door  Maisch schemas scrollen
                case STANDAARD:
                  MenuState.StateL2 = WEIZEN;
                  break;
                case DROOG:
                  MenuState.StateL2 = STANDAARD;
                  break;
                case WEIZEN:
                  MenuState.StateL2 = DROOG;
                  break;
              }
              break;
            }
          }
          // left
          // If in menu
      } else if (pin == rightBtn) {
        if (MenuState.Level == 1) { 
          switch (MenuState.StateL1) {  // in top level menu: scroll door top level menu.
            case MAISCH :
              MenuState.StateL1 = KOOK;
              MenuState.StateL2 = ZESTIG;
              break;
            case KOOK   :
              MenuState.StateL1 = COMBI;
              MenuState.StateL2 = STANDAARD;
              break;
            case COMBI  :
              MenuState.StateL1 = MAISCH;
              MenuState.StateL2 = STANDAARD;
              break;
          }
        }else if (MenuState.Level == 2) {
          switch (MenuState.StateL1){
            case MAISCH:
              switch (MenuState.StateL2){ //In botom level: door  Maisch schemas scrollen
                case STANDAARD:
                  MenuState.StateL2 = DROOG;
                  break;
                case DROOG:
                  MenuState.StateL2 = WEIZEN;
                  break;
                case WEIZEN:
                  MenuState.StateL2 = STANDAARD;
                  break;
              }
              break;
            case KOOK:
              switch (MenuState.StateL2){ // In Kook schema: door kook schemas scrollen
                case ZESTIG:
                  MenuState.StateL2 = NEGENTIG;
                  break;
                case NEGENTIG:
                  MenuState.StateL2 = ZESTIG;
                  break;
              }
              break;
            case COMBI:
              switch (MenuState.StateL2){ //In botom level: door  Maisch schemas scrollen
                case STANDAARD:
                  MenuState.StateL2 = DROOG;
                  break;
                case DROOG:
                  MenuState.StateL2 = WEIZEN;
                  break;
                case WEIZEN:
                  MenuState.StateL2 = STANDAARD;
                  break;
              }
              break;
            }
          }
        
          // right
      } else if (pin == selectBtn) {
        if (MenuState.Level == 1){
          MenuState.Level = 2;
        }else if (MenuState.Level == 2){
          InMenu = false;
          // start selectie
          states.CurrentProgStateL1 = MenuState.StateL1;
          states.CurrentProgStateL2 = MenuState.StateL2;
          switch (MenuState.StateL1) {
            case MAISCH:
              states.CurrentState = 1;
              break;
            case KOOK:
              states.CurrentState = 4;
              break;
            case COMBI:
              states.CurrentState = 1;
              break;
          }
          
        }
         
          
          
          // select
               
      }
    }
}menu(6,7,8,9);
