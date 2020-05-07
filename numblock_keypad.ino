#include <Keypad.h>
#include <Keyboard.h>

const byte ROWS = 4;
const byte COLS = 5;

bool numLock = false;
bool numMode = true;
byte makroMode = 0; //TODO implement makro mode

// 2d array with keys
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
  Serial.begin(9600);
  Keyboard.begin();
}

void loop(){
byte customKey = customKeypad.getKey();
  if (customKey){
    Keyboard.press(customKey);
    Keyboard.release(customKey);
    if (customKey == byte(219))
      switchNumLED();
  }
}

void switchNumLED()
{
    Serial.println("Hallo");
      numLock = !numLock;
      Serial.println(numLock);
      if (numLock){
        analogWrite(13, 100);
      }
      else{
          analogWrite(13, 0);
      }
}
