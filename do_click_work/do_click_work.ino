
int pins[] = {2, 3, 4};
int pinCount = sizeof(pins) / sizeof(int);
int G = 2;
int Y = 1;
int R = 0;
int sw = 7;

int curIndex = 0;
int swValue = 1;
bool doClickWork = false;

void setup() {
  for (int i = 0; i < pinCount; i++) {
    pinMode(pins[i], OUTPUT);
  }
  pinMode(sw, INPUT_PULLUP);
  curIndex = 0;

  Serial.begin(9600);
  pinMode(sw, INPUT_PULLUP);
}

void loop() {
  int curValue = digitalRead(sw);
  if (switchClicked(curValue)) {
    doClickWork = true;
  }

  if (doClickWork) {
    // must have set doClickWork to false
    clickWork();
  }
  delay(100);
}

void clickWork() {
  ledOn(curIndex, 100);
  ledOff(curIndex);

  curIndex++;
  if (curIndex >= pinCount) {
    curIndex = 0;
    doClickWork = false;
  }
}

void ledOn(int index, int howLong) {
  digitalWrite(pins[index], HIGH);
  delay(howLong);
}

void ledOff(int index) {
  digitalWrite(pins[index], LOW);
}

bool switchClicked(int newValue) {
  if (swValue != newValue) {
    swValue = newValue;
    if (swValue == 1) {
      return true;
    }
  }
  return false;
}
