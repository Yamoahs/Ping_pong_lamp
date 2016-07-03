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
const int button = 2;     // the number of the pushbutton pin
const int led1 =  13;      // the number of the LED pin
const int led2 =  12;      // the number of the LED pin
const int led3 =  11;      // the number of the LED pin
const int MAX_COLOUR_STATES = 5;

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int lastButtonState = LOW;
int colourState = 0;              //Determining which light to turn on
int debounce = 0;           //Counter for the debounce time
boolean buttonPressed = false;
boolean toggle = false;

void setup() {
  // initialize the LED pin as an output:
  pinMode(led1, OUTPUT);
  // initialize the LED pin as an output:
  pinMode(led2, OUTPUT);
  // initialize the LED pin as an output:
  pinMode(led3, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(button, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(button) ==HIGH)
  {
    debounce++;
  }
  else{
    debounce = 0;
    buttonPressed = false;
    toggle = false;
  }
  if(debounce >= 5000) //Indicates how long you need to wait
                      //before accepting that the button was pressed
  {
    buttonPressed = true;
  }
  if(buttonPressed == true && toggle == false)
  {
    toggle = true;
    colourState++;
    if(colourState == MAX_COLOUR_STATES) colourState = 0;
    toggle_funct();
  }
}
/*
    
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
     digitalWrite(led, HIGH);
     digitalWrite(led2, LOW);
  }
  else if (colourState == 1){
     digitalWrite(led, LOW);
     digitalWrite(led2, HIGH);
  }
  
*/

void toggle_funct()
{
  if (colourState == 0){
     digitalWrite(led1, LOW);
     digitalWrite(led2, LOW);
     digitalWrite(led3, LOW);
  }

  else if (colourState == 1){
     digitalWrite(led1, HIGH);
     digitalWrite(led2, LOW);
     digitalWrite(led3, LOW);
  }

  else if (colourState == 2){
     digitalWrite(led1, LOW);
     digitalWrite(led2, HIGH);
     digitalWrite(led3, LOW);
  }

  else if (colourState == 3){
     digitalWrite(led1, LOW);
     digitalWrite(led2, LOW);
     digitalWrite(led3, HIGH);
  }

  else if (colourState == 4){
     digitalWrite(led1, HIGH);
     digitalWrite(led2, HIGH);
     digitalWrite(led3, HIGH);
  }
}

