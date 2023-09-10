#include <Joystick.h>

Joystick_ Joystick;

int button0;
int button1;
int button2;
int button3;
int button4;
int button5;
int button12;

int lastButton0;
int lastButton1;
int lastButton2;
int lastButton3;
int lastButton4;
int lastButton5;
int lastButton12;

int switch0a;
int switch0b;
int switch1a;
int switch1b;
int switch2a;
int switch2b;

int lastSwitch0;
int lastSwitch1;
int lastSwitch2;

int pitch;
int roll;
int throttle;
int rudder;

void setup() {
  pinMode(0, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);

  pinMode(15, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);

  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);

  Joystick.begin();
  Joystick.SetXAxisRange(0, 1024);
  Joystick.setYAxisRange(0, 1024);
  Joystick.setZAxisRange(0, 1024);
  Joystick.setThrottleRange(0, 1024);
}

void loop() {
  button0 = !digitalRead(2);
  button1 = !digitalRead(3);
  button2 = !digitalRead(4);
  button3 = !digitalRead(5);
  button4 = !digitalRead(6);
  button5 = !digitalRead(7);
  button12 = !digitalRead(0);

  switch0a = !digitalRead(15);
  switch0b = !digitalRead(14);
  switch1a = !digitalRead(16);
  switch1b = !digitalRead(10);
  switch2a = !digitalRead(8);
  switch2b = !digitalRead(9);

  pitch = analogRead(A3);
  roll = analogRead(A2);
  rudder = analogRead(A0);
  throttle = analogRead(A1);

  if (button0 != lastButton0) {
    Joystick.setButton(0, button0);
    lastButton0 = button0;
  }

  if (button1 != lastButton1) {
    Joystick.setButton(1, button1);
    lastButton1 = button1;
  }

  if (button2 != lastButton2) {
    Joystick.setButton(2, button2);
    lastButton2 = button2;
  }

  if (button3 != lastButton3) {
    Joystick.setButton(3, button3);
    lastButton3 = button3;
  }

  if (button4 != lastButton4) {
    Joystick.setButton(4, button4);
    lastButton4 = button4;
  }

  if (button5 != lastButton5) {
    Joystick.setButton(5, button5);
    lastButton5 = button5;
  }


  Joystick.setButton(6, switch0a);
  Joystick.setButton(7, switch0b);
  Joystick.setButton(8, switch1a);
  Joystick.setButton(9, switch1b);
  Joystick.setButton(10, switch2a);
  Joystick.setButton(11, switch2b);

  if (button12 != lastButton12) {
    Joystick.setButton(12, button12);
    lastButton12 = button12;
  }

  Joystick.setXAxis(roll);
  Joystick.setYAxis(pitch);
  Joystick.setThrottle(throttle);
  Joystick.setZAxis(rudder);
}
