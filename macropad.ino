/* Jason Watts
    3/20/21
    Arduino macropad code to be used by python script.
*/
//Sets time to delay sending output.
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 500;
unsigned long lastDebounceTime2 = 0;
unsigned long debounceDelay2 = 500;
unsigned long lastDebounceTimeE = 0;
unsigned long debounceDelayE = 500;
unsigned long lastDebounceTimeR = 0;
unsigned long debounceDelayR = 500;

//Keypad Buttons
const int buttonPin1 = 5;
const int buttonPin2 = 7;
const int buttonPinr = 12;
const int buttonPinE  = 9;

int buttonState1 = 0;
int buttonState2 = 0;
int buttonStater = 0;
int buttonStateE = 0;

int lastbuttonstate = HIGH;

int rVal = 254;
int gVal = 1;
int bVal = 127;
int rDir = -1;
int gDir = 1;
int bDir = -1;

//RGB color pins
int rPin = A0;
int gPin = A1;
int bPin = A2;

void setup() {

//Pulls the keyswitches high
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPinr, INPUT_PULLUP);
  pinMode(buttonPinE, INPUT_PULLUP);
  
  Serial.begin(9600);

//Sets the RGB pins to an output
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);

}

void loop() {

  rgbcolor();
  keyCheck1();
  keyCheck2();
  keyCheckR();
  keyCheckE();


}


void keyCheck1() {

  buttonState1 = digitalRead(buttonPin1);
  if ((millis() - lastDebounceTime) < debounceDelay) {
    return;
  }
  lastDebounceTime += debounceDelay;
  if (buttonState1 == LOW) {
    Serial.write('a');
  }
}

void keyCheck2() {

  buttonState2 = digitalRead(buttonPin2);

  if ((millis() - lastDebounceTime2) < debounceDelay2) {
    return;
  }

  lastDebounceTime2 += debounceDelay2;

  if (buttonState2 == LOW) {
    Serial.write('b');
  }
}

void keyCheckR() {

  buttonStater = digitalRead(buttonPinr);

  if ((millis() - lastDebounceTimeR) < debounceDelayR) {
    return;
  }
  lastDebounceTimeR += debounceDelayR;

  if (buttonStater == LOW) {
    Serial.write('c');
  }
}

void keyCheckE() {

  buttonStateE = digitalRead(buttonPinE);

  if ((millis() - lastDebounceTimeE) < debounceDelayE) {
    return;
  }
  lastDebounceTimeE += debounceDelayE;

  if (buttonStateE == LOW) {
    Serial.write('d');
  }
}

void rgbcolor() {

  analogWrite(rPin, rVal);
  analogWrite(gPin, gVal);
  analogWrite(bPin, bVal);

  // change the values of the LEDs
  rVal = rVal + rDir;
  gVal = gVal + gDir;
  bVal = bVal + bDir;

  // for each color, change direction if
  // you reached 0 or 255
  if (rVal >= 255 || rVal <= 0) {
    rDir = rDir * -1;
  }

  if (gVal >= 255 || gVal <= 0) {
    gDir = gDir * -1;
  }

  if (bVal >= 255 || bVal <= 0) {
    bDir = bDir * -1;
  }

  // slight delay so it doesn't rotate color too quicky
  delay(33);
}
