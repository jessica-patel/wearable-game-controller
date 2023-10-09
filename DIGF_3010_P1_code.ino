/* DIGF-3010 Advanced Wearables 2023

  This code takes inspiration from the DIGF-3010_P1_4AnalogInputsKeyboard file provided on Canvas by Kate Hartman.
  It is written for 4 analog sensors (in series with 2 analog pressure sensors) to activate 4 keyboard keys.
  Based on Keyboard library examples.
*/

#include "Keyboard.h"

#define DEBOUNCE 100  // delay for ensuring that the sensor presses do not overlap

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // initialize Keyboard header file
  Keyboard.begin();
}

void loop() {
  // reading the input for each pin
  int sensorValue1 = analogRead(A10);
  int sensorValue2 = analogRead(A9);
  int sensorValue3 = analogRead(A6);
  int sensorValue4 = analogRead(A11);

  // setting int variable names for all 4 directional keys
  const int keyboardKey1 = KEY_UP_ARROW;
  const int keyboardKey2 = KEY_DOWN_ARROW;
  const int keyboardKey3 = KEY_LEFT_ARROW;
  const int keyboardKey4 = KEY_RIGHT_ARROW;

  // threshold value set based on AnalogReadSerial testing
  const int threshold = 300;

  // use the sensor values to control keyboard
  // comparing sensor values to all others in case other sensors are accidentally activated too, and ensuring that sensor is above threshold
  if ( (sensorValue1 > sensorValue2) && (sensorValue1 > sensorValue3) && (sensorValue1 > sensorValue4) && (sensorValue1 > threshold) )
  {
    Keyboard.press(keyboardKey1);
    delay(100);
    Keyboard.release(keyboardKey1);
    Serial.println("key up pressed");
  }
  if ( (sensorValue2 > sensorValue1) && (sensorValue2 > sensorValue3) && (sensorValue2 > sensorValue4) && (sensorValue2 > threshold) )
  {
    Keyboard.press(keyboardKey2);
    delay(100);
    Keyboard.release(keyboardKey2);
    Serial.println("key down pressed");
  }
  if ( (sensorValue3 > sensorValue2) && (sensorValue3 > sensorValue1) && (sensorValue3 > sensorValue4) && (sensorValue3 > threshold) )
  {
    Keyboard.press(keyboardKey3);
    delay(100);
    Keyboard.release(keyboardKey3);
    Serial.println("key left pressed");
  }
  if ( (sensorValue4 > sensorValue2) && (sensorValue4 > sensorValue3) && (sensorValue4 > sensorValue1) && (sensorValue4 > threshold) )
  {
    Keyboard.press(keyboardKey4);
    delay(100);
    Keyboard.release(keyboardKey4);
    Serial.println("key right pressed");
  } else {
    Keyboard.releaseAll();
  }

  delay(DEBOUNCE);  // delay in between reads for stability
}
