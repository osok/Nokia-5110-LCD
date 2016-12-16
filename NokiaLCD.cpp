/**
 * NokiaLCD.cpp - Library for interface to the Nokia 5110 84x48 LCD.
 * Created by osok
 * github https://github.com/osok/Nokia-5110-LCD
 * 
 */
#include "NokiaLCD.h"

NokiaLCD::NokiaLCD(int pin)
{
  lcdPin = pin;
  pinMode(lcdPin, OUTPUT);
  pinMode(PIN_RESET, OUTPUT);
  pinMode(PIN_DC, OUTPUT);
  pinMode(PIN_SDIN, OUTPUT);
  pinMode(PIN_SCLK, OUTPUT);
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_RESET, LOW);
  digitalWrite(PIN_RESET, HIGH);
  digitalWrite(PIN_LED, HIGH);
  writeWire(LCD_C, 0x21 );  // LCD Extended Commands.
  writeWire(LCD_C, 0xB1 );  // Set LCD Vop (Contrast). 
  writeWire(LCD_C, 0x04 );  // Set Temp coefficent. //0x04
  writeWire(LCD_C, 0x14 );  // LCD bias mode 1:48. //0x13
  writeWire(LCD_C, 0x20 );  // LCD Basic Commands
  writeWire(LCD_C, 0x0C );  // LCD in normal mode.
  
}

void NokiaLCD::writeCharacter(char character)
{
  writeWire(LCD_D, 0x00);
  for (int index = 0; index < 5; index++)
  {
    writeWire(LCD_D, ASCII[character - 0x20][index]);
  }
  writeWire(LCD_D, 0x00);
}

void NokiaLCD::clear(void)
{
  for (int index = 0; index < LCD_X * LCD_Y / 8; index++)
  {
    writeWire(LCD_D, 0x00);
  }
}

void NokiaLCD::writeString(char *characters)
{
  while (*characters)
  {
    writeCharacter(*characters++);
  }
}

void NokiaLCD::writeWire(byte dc, byte data)
{
  digitalWrite(PIN_DC, dc);
  digitalWrite(lcdPin, LOW);
  shiftOut(PIN_SDIN, PIN_SCLK, MSBFIRST, data);
  digitalWrite(lcdPin, HIGH);
}

