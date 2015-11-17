/*
  Leonardo Joystick

  Use Leonardo to create 3-button arcade joystick.

  created 2015
  by Kaj Schmidt <http://www.kajschmidt.se>

  Instructions for joystick lib/settings: http://www.instructables.com/id/Add-USB-Game-Controller-to-Arduino-LeonardoMicro/
 */

int up_pin = 3;
int dw_pin = 6;
int lf_pin = 7;
int rt_pin = 4;

int b1_pin = 12;
int b2_pin = 10;
int b3_pin = 8;

int b_pins[] = {b1_pin, b2_pin, b3_pin}; //Button pins as array
boolean b_states[] = {1,1,1}; //Button states as array

void setup() {
  //Initiate inputs with pullup enabled
  pinMode(up_pin, INPUT_PULLUP);
  pinMode(dw_pin, INPUT_PULLUP);
  pinMode(lf_pin, INPUT_PULLUP);
  pinMode(rt_pin, INPUT_PULLUP);
  pinMode(b1_pin, INPUT_PULLUP);
  pinMode(b2_pin, INPUT_PULLUP);
  pinMode(b3_pin, INPUT_PULLUP);

  Joystick.begin();

  //Center Y & X axis
  Joystick.setYAxis(0);
  Joystick.setXAxis(0);
}

void loop() {
  //Check buttons
  for (int x = 0; x < 3; x++) { //Check buttons
    if(digitalRead(b_pins[x]) == LOW && b_states[x] == LOW) { // Holding

    }
    else if(digitalRead(b_pins[x]) == LOW && b_states[x] == HIGH) { // Positive flank
      b_states[x] == LOW;
      Joystick.pressButton((byte)x);
    }
    else if(digitalRead(b_pins[x]) == HIGH && b_states[x] == LOW) { // Negative flank
      b_states[x] == HIGH;
    }
    else if(digitalRead(b_pins[x]) == HIGH && b_states[x] == HIGH) { // Released
      Joystick.releaseButton((byte)x);
    }
  }

  //Check joystick
  if (digitalRead(dw_pin) == LOW) { //check down
    Joystick.setYAxis(-127);
  }
  else if (digitalRead(up_pin) == LOW) { //check up
    Joystick.setYAxis(127);
  }
  else {
    Joystick.setYAxis(0);
  }

  if (digitalRead(rt_pin) == LOW) { //check right
    Joystick.setXAxis(127);
  }
  else if (digitalRead(lf_pin) == LOW) { //check left
    Joystick.setXAxis(-127);
  }
  else {
    Joystick.setXAxis(0);
  }

}


