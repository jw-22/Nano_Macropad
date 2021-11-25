/* Jason Watts
    3/20/21
    Arduino macropad code to be used by python script.
*/

//Sets time to delay sending output.
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 500;
unsigned long lastDebounceTime2 = 0;
unsigned long debounceDelay2 = 500;
unsigned long lastDebounceTime3 = 0;
unsigned long debounceDelay3 = 500;
unsigned long lastDebounceTime4 = 0;
unsigned long debounceDelay4 = 500;

//Keypad buttons to digital pins
const int buttonPin1 = 5;
const int buttonPin2 = 7;
const int buttonPin3 = 12;
const int buttonPin4  = 9;

int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;

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
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
  
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
  keyCheck3();
  keyCheck4();
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

void keyCheck3() {

  buttonState3 = digitalRead(buttonPin3);

  if ((millis() - lastDebounceTime3) < debounceDelay3) {
    return;
  }
  lastDebounceTime3 += debounceDelay3;

  if (buttonState3 == LOW) {
    Serial.write('c');
  }
}

void keyCheck4() {

  buttonState4 = digitalRead(buttonPin4);

  if ((millis() - lastDebounceTime4) < debounceDelay4) {
    return;
  }
  lastDebounceTime4 += debounceDelay4;

  if (buttonState4 == LOW) {
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
