/*******************************************************************************
@file     Ping_pong_lamp.ino
@author   Samuel Yamoah
@date     29.06.2016
@modified 10.06.2016
@brief    Main Code for Ping POng Ball Lamp. Each Ping Pong Ball will have an
          RGB LED (72 total). Program will have solid RED, GREEN, BLUE, WHITE,
          pulse WHITE & pulse RGB Spectrum.
*******************************************************************************/

// constants setup:
const int button = 2;     // the number of the pushbutton pin
const int led1 =  13;      // the number of the LED pin
const int led2 =  12;      // the number of the LED pin
const int led3 =  11;      // the number of the LED pin
const int MAX_COLOUR_STATES = 6;

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int lastButtonState = LOW;
int colourState = 0;         //Determining which light pattern to turn on
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


void toggle_funct()
{
   Serial.begin(9600);
   Serial.print("Colour State: ");
   Serial.println(colourState);
   Serial.print("Debounce: ");
   Serial.println(debounce);
   // delay(100);

  
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
     // fade in from min to max in increments of 5 points:
    for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) { 
      // sets the value (range from 0 to 255):
      analogWrite(led3, fadeValue);         
      // wait for 30 milliseconds to see the dimming effect    
      delay(30);                            
    } 
    
    // fade out from max to min in increments of 5 points:
      for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) { 
      // sets the value (range from 0 to 255):
      analogWrite(led3, fadeValue);         
      // wait for 30 milliseconds to see the dimming effect    
      delay(30);                            
    }
  }
}

