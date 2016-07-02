/*
  Button

 Turns on and off a light emitting diode(LED) connected to digital
 pin 13, when pressing a pushbutton attached to pin 2.


 The circuit:
 * LED attached from pin 13 to ground
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground


 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Button
 */

// constants won't change. They're used here to
// set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin
const int ledPin2 =  12;      // the number of the LED pin
const int MAX_COLOUR_STATES = 2;

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int lastButtonState = LOW;
int colourState = 0;              //Determining which light to turn on

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the LED pin as an output:
  pinMode(ledPin2, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() { 
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  if (debounceButton(buttonState) == HIGH && buttonState == LOW)
  {
    colourState++;
    if (colourState == MAX_COLOUR_STATES) colourState = 0;
    buttonState = HIGH;
    
    Serial.begin(9600);
    Serial.print("Colour State: ");
    Serial.println(colourState);
   // delay(100);
  }
  else
  {
    buttonState = LOW;
  }

  if (colourState == 0){
     digitalWrite(ledPin, HIGH);
     digitalWrite(ledPin2, LOW);
  }
  else if (colourState == 1){
     digitalWrite(ledPin, LOW);
     digitalWrite(ledPin2, HIGH);
  }
  

  

  
/*
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }*/
}

boolean debounceButton(boolean state)
{
  boolean stateNow = digitalRead(buttonPin);
  if (buttonState != stateNow){
    delay(10);
    stateNow = digitalRead(buttonPin);
  }
  return stateNow;
}

