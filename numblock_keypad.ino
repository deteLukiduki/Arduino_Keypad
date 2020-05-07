#include <Keypad.h>
#include <Keyboard.h>


bool numLock = false;
bool numMode = true;
byte makroMode = 0; //TODO implement makro mode

/*==== Keypad setup ====*/

const byte ROWS = 4;
const byte COLS = 5;

// key matrix mapping with all keycodes
byte numBlock[ROWS][COLS] = {
  {234, 225, 228, 231, 219},
  {235, 226, 229, 232, 220},
  {224, 227, 230, 233, 221},
  {223, 222, 0, 0, 0}
};

byte colPins[COLS] = {4, 5, 6, 7, 8};
byte rowPins[ROWS] = {0, 1, 2, 3};

Keypad customKeypad = Keypad(makeKeymap(numBlock), rowPins, colPins, ROWS, COLS);

void setup() {
  pinMode(13, OUTPUT);
  Keyboard.begin();
}

void loop() {
  byte customKey = customKeypad.getKey();
  if (customKey) {
    Keyboard.press(customKey);
    Keyboard.release(customKey);
    if (customKey == byte(219))
      switchNumLED();
  }
}


// enable/disable NumLock LED
void switchNumLED()
{
  numLock = !numLock;
  if (numLock) {
    analogWrite(13, 100);
  }
  else {
    analogWrite(13, 0);
  }
}
