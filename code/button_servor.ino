/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-button-servo-motor
 */

#include <Servo.h>
#include <ezButton.h>

// constants won't change
const int BUTTON_PIN = 7; // Arduino pin connected to button's pin
const int SERVO_PIN  = 9; // Arduino pin connected to servo motor's pin

ezButton button(BUTTON_PIN); // create ezButton object that attach to pin 7;
Servo servo;                 // create servo object to control a servo

// variables will change:
int angle = 0; // the current angle of servo motor

void setup() {
  Serial.begin(115200);         // initialize serial
  button.setDebounceTime(50); // set debounce time to 50 milliseconds
  servo.attach(SERVO_PIN);    // attaches the servo on pin 9 to the servo object

  servo.write(angle);
}

void loop() {
  button.loop(); // MUST call the loop() function first

  if(button.isPressed()) {
    Serial.println("The button is pressed");

    // change angle of servo motor
    if(angle == 0)
      angle = 100;
    else
    if(angle == 100)
      angle = 0;

    // control servo motor arccoding to the angle
    servo.write(angle);
  }
}
