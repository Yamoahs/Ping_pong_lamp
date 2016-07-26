/*******************************************************************************
@file     Controller_A_refactor.ino
@author   Samuel Yamoah
@date     29.06.2016
@modified 27.06.2016
@brief    Main Code for Ping POng Ball Lamp. Each Ping Pong Ball will have an
          RGB LED (72 total). Program will have solid RED, GREEN, BLUE, WHITE,
          pulse WHITE & pulse RGB Spectrum.
*******************************************************************************/

// constants setup:
const int RED =  0;            //RED LED pin
const int GREEN =  1;          //GREEN LED pin
const int BUTTON = 2;          //Push button pin
const int OUTPUT_A = 3;        //Output A to Controller 2
const int OUTPUT_B = 4;        //Output B to Controller 2
const int MAX_COLOUR_STATES = 7;

// variables will change:
int buttonState = 0;          // variable for reading the pushbutton status
int lastButtonState = LOW;
int colourState = 0;              //Determining which light to turn on
int debounce = 0;           //Counter for the debounce time
boolean buttonPressed = false;
boolean toggle = false;

void setup() {
  // initialize RED LED pin as an output:
  pinMode(RED, OUTPUT);
  // initialize the GREEN LED pin as an output:
  pinMode(GREEN, OUTPUT);
  // initialize Output A pin as an output:
  pinMode(OUTPUT_A, OUTPUT);
  // initialize Output B pin as an output:
  pinMode(OUTPUT_B, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(BUTTON, INPUT);
}

void loop(){
  debounceFunct();

  if(buttonPressed == true && toggle == false){
    toggle = true;
    colourState++;
    if(colourState == MAX_COLOUR_STATES) colourState = 0;
    toggle_funct();
  }
}

//Function selects the colour state
void toggle_funct(){
  switch(colourState){
    case 0:
      all_off();
      break;
      
    case 1:
      red();
      break;

    case 2:
      green();
      break;

    case 3:
      blue();
      break;

    case 4:
      white();
      break;

    case 5:
      white_pulse();
      break;

    case 6:
      rgb();
      break; 
  }
}


//ALL LIGHTS OFF
void all_off(){
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(OUTPUT_A, LOW);
  digitalWrite(OUTPUT_B, LOW);
}

//RED LIGHT SOLID
void red(){
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(OUTPUT_A, LOW);
  digitalWrite(OUTPUT_B, LOW);
}

//GREEN LIGHT SOLID
void green(){
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, HIGH);
  digitalWrite(OUTPUT_A, LOW);
  digitalWrite(OUTPUT_B, LOW);
}

//BLUE LIGHT SOLID
void blue(){
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(OUTPUT_A, HIGH);
  digitalWrite(OUTPUT_B, LOW);
}

//WHITE LIGHT SOLID
void white(){
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(OUTPUT_A, HIGH);
  digitalWrite(OUTPUT_B, LOW);
}

//WHITE LIGHT PULSE
void white_pulse(){
  //bool quit = false;
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(OUTPUT_A, LOW);
  digitalWrite(OUTPUT_B, HIGH);

  // fade in from min to max in increments of 5 points:
  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) {
    // sets the value (range from 0 to 255):
    analogWrite(RED, fadeValue);
    analogWrite(GREEN, fadeValue);
    // wait for 50 milliseconds to see the dimming effect
    delay(50);
 }

  // fade out from max to min in increments of 5 points:
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) {
    // sets the value (range from 0 to 255):
    analogWrite(RED, fadeValue);
    analogWrite(GREEN, fadeValue);
    // wait for 50 milliseconds to see the dimming effect
    delay(50);

    //if (digitalRead(BUTTON) == HIGH) quit = true;
  }

  analogWrite(RED, 0);
  analogWrite(GREEN, 0);
  delay(100);
}

//RGB SPECTRUM
void rgb(){
  //bool quit = false;
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(OUTPUT_A, HIGH);
    digitalWrite(OUTPUT_B, HIGH);

    // fade in from min to max in increments of 5 points: FADE IN RED
    for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
      // sets the value (range from 0 to 255):
      analogWrite(RED, fadeValue);
      // wait for 50 milliseconds to see the dimming effect
      delay(50);
    }

    // fade in from min to max in increments of 5 points: FADE IN GREEN [RED]
    for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
      // sets the value (range from 0 to 255):
      analogWrite(GREEN, fadeValue);
      // wait for 50 milliseconds to see the dimming effect
      delay(50);
    }

    // fade out from max to min in increments of 5 points: FADE OUT RED [GREEN]
    for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
      // sets the value (range from 0 to 255):
      analogWrite(RED, fadeValue);
      // wait for 50 milliseconds to see the dimming effect
      delay(50);
    }

    // fade in from min to max in increments of 5 points: FADE IN BLUE [GREEN]
    for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
      // wait for 50 milliseconds to see the dimming effect
      delay(50);
    }

     // fade out from max to min in increments of 5 points: FADE OUT GREEN [BLUE]
    for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
      // sets the value (range from 0 to 255):
      analogWrite(GREEN, fadeValue);
      // wait for 50 milliseconds to see the dimming effect
      delay(50);
    }

    // fade in from min to max in increments of 5 points: FADE IN RED [BLUE]
    for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
      // sets the value (range from 0 to 255):
      analogWrite(RED, fadeValue);
      // wait for 50 milliseconds to see the dimming effect
      delay(50);
    }

    // fade in from min to max in increments of 5 points: FADE IN GREEN [BLUE, RED]
    for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
      // sets the value (range from 0 to 255):
      analogWrite(GREEN, fadeValue);
      // wait for 50 milliseconds to see the dimming effect
      delay(50);
    }

     // fade out from max to min in increments of 5 points: FADE OUT ALL
    for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
      // sets the value (range from 0 to 255):
      analogWrite(RED, fadeValue);
      analogWrite(GREEN, fadeValue);
      // wait for 50 milliseconds to see the dimming effect
      delay(50);
    }    
}


void debounceFunct(){
  if (digitalRead(BUTTON) == HIGH)
  {
    debounce++;
  }
  else{
    debounce = 0;
    buttonPressed = false;
    toggle = false;
  }
  if(debounce >= 5000) //Indicates how long you need to wait
                      //before accepting that the BUTTON was pressed
  {
    buttonPressed = true;
  }
}
