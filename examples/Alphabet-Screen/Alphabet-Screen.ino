#include "NokiaLCD.h"

#define ROWS 6
#define COLS 12
#define PIN_LCD 7

char screen[ROWS+1][COLS];

NokiaLCD lcd(PIN_LCD);

void initScreen(){
  for (int row = 0; row < ROWS; row++){
    for (int col = 0; col < COLS; col++){
      screen[row][col] = 0x20;
    }
  }
  screen[ROWS][0] = 0x00; // Last char has to remain a null byte
}

void replaceNull(){
  for (int row = 0; row < ROWS; row++){
    for (int col = 0; col < COLS; col++){
      if(!screen[row][col]){
        screen[row][col] = 0x20;
      }
    }
    screen[ROWS][0] = 0x00; // Last char has to remain a null byte
  }
}

void writeScreen(int row, int col, char c){
  screen[row][col] = c;
}

void paint(){
  replaceNull();
  lcd.writeString(screen[0]);
}

void setup(void)
{
  initScreen();
  paint();
}

void loop(void)
{
  char c = 'A';
  for (int row = 0; row < ROWS; row++){
    c = 'A';
    for (int col = 0; col < COLS; col++){
      screen[row][col] = c;
      c++;
      paint();
      delay(250);
    }
  }
  
}


