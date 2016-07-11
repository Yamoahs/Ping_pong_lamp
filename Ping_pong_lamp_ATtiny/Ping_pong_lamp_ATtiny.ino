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
const int led1 =  3;      // the number of the LED pin
const int led2 =  4;      // the number of the LED pin
const int led3 =  1;      // the number of the LED pin
const int MAX_COLOUR_STATES = 6;

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
  debounceFunct();

  if(buttonPressed == true && toggle == false){
    toggle = true;
    colourState++;
    if(colourState == MAX_COLOUR_STATES) colourState = 0;
    toggle_funct();
  }
}

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

  else if (colourState == 5){
    boolean quit = false;
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);

    while(quit == false){
      // fade in from min to max in increments of 5 points:
      for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) { 
        // sets the value (range from 0 to 255):
        analogWrite(led3, fadeValue);         
        // wait for 30 milliseconds to see the dimming effect    
        delay(50);
        
       if (digitalRead(button) ==HIGH){
        quit = true;
       }
     } 
      
      // fade out from max to min in increments of 5 points:
      for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) { 
        // sets the value (range from 0 to 255):
        analogWrite(led3, fadeValue);         
        // wait for 30 milliseconds to see the dimming effect    
        delay(50);

        if (digitalRead(button) ==HIGH){
        quit = true;
       }                       
      }
      
       analogWrite(led3, 0);
       delay(100);
       if (digitalRead(button) ==HIGH){
        quit = true;
       }
    }
  colourState++;
  if(colourState == MAX_COLOUR_STATES) colourState = 0;
  }
}

void debounceFunct(){
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
}
