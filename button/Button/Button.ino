const int buttonPin = 10;
const int ledPin =  0;

int buttonState = HIGH;
int newButtonState;
int ledState = LOW;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  newButtonState = digitalRead(buttonPin);

  if (newButtonState == LOW && newButtonState != buttonState) {
    buttonState = newButtonState;
    ledState = ledState == LOW ? HIGH : LOW;
    digitalWrite(ledPin, ledState);
  } else if (newButtonState == HIGH && newButtonState != buttonState) {
    buttonState = newButtonState;
  }
}
