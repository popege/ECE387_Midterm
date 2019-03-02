#include <Keypad.h>
#include <LiquidCrystal.h>

#define greenLED 1
#define redLED 13

char password [4]= {'8', '3', 'E', '4'}; //initializing password
char keypadPW[4]; //password applied to keypad
int position = 0; //keypad position

const byte ROWS = 4; //rows and columns for keypad
const byte COLS = 4;
int passwordcount = 9; //beginning index on LCD to print inputted password characters

char keys[ROWS][COLS] = {
  {'1', '4', '7', '0'},
  {'2', '5', '8', 'F'},
  {'3', '6', '9', 'E'},
  {'A', 'B', 'C', 'D'}
};

byte rowPins[ROWS] = {A0, A1, A2, A3};

byte colPins[COLS] = {A4, A5, 3, 2};


Keypad newKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

LiquidCrystal disp (7, 8, 9, 10, 11, 12); //corresponding pins on LCD


int i = 0;





void setup() {
  // put your setup code here, to run once:
  disp.begin(16, 2);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  setLocked (true); //setting password to be locked

}

void loop() {
  // put your main code here, to run repeatedly:
  char customKey = newKeypad.getKey(); //defining the key that was pressed
 
  disp.setCursor(0, 0);
  disp.print("Welcome User :)");
  disp.setCursor(0, 1);
  disp.print("Password:");
  
  if(customKey) {
    //start at (9, 1)
    keypadPW[i] = customKey; //inputting the key pressed into an array
    disp.setCursor(passwordcount, 1);
    disp.print(customKey);
    i++; //incrementing array
    passwordcount++; //incrementing position to print next input
   position++; //move to next password input
  }
  
 
  if(position == 4) {
    
    if ((strncmp(password, keypadPW, 4) == 0)) {
      
    setLocked (false);
    disp.clear();
    disp.setCursor(0,0);
    disp.print("Welcome!!!");
    delay(2500);
    disp.clear();
    disp.setCursor(0,0);
    disp.print("ECE 287 Proj.");
    delay(10000);
    disp.clear();
    i = 0;
    
    }
    
    else {
      
      disp.clear();
      disp.setCursor(0,0);
      disp.print("Wrong!LOCKED");
      delay(30000);
      disp.clear();
      i = 0;
    }
    
  }
  
}


  void setLocked(int locked) {
    
    if(locked) {
      
      digitalWrite(greenLED, LOW);
      digitalWrite(redLED, HIGH);
    }
    
    else {
      
      digitalWrite(greenLED, HIGH);
      digitalWrite(redLED, LOW);
      
    }
    
  }

 


