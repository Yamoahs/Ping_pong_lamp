/*******************************************************************************
@file     Controller_B.ino
@author   Samuel Yamoah
@date     13.06.2016
@modified 13.06.2016
@brief    Secondary Code for Ping POng Ball Lamp. Each Ping Pong Ball will have an
          RGB LED (72 total). Program will have solid RED, GREEN, BLUE, WHITE,
          pulse WHITE & pulse RGB Spectrum.
*******************************************************************************/

// constants setup:
const int BLUE =  0;            //BLUE LED pin
const int INPUT_A = 3;        //Input A to Controller 2
const int INPUT_B = 4;        //Input B to Controller 2
const int TEST = 1;        //Test


void setup() {
  // initialize BLUE LED pin as an output:
  pinMode(BLUE, OUTPUT);
  // initialize Input A pin as an output:
  pinMode(INPUT_A, INPUT);
  // initialize Input B pin as an output:
  pinMode(INPUT_B, INPUT);
  //test pin
  pinMode(TEST, OUTPUT);
  digitalWrite(TEST, LOW);
}

void loop(){
    digitalWrite(TEST, LOW); 
  delay(750);
//  if(digitalRead(INPUT_A) == HIGH && digitalRead(INPUT_B) == LOW){
//    solid_blue_white();
//  }
//  else if (digitalRead(INPUT_B) == HIGH && digitalRead(INPUT_A) == LOW){
//    pulse_white();
//  }
//  else if (digitalRead(INPUT_A) == HIGH && digitalRead(INPUT_B) == HIGH){
//    rgb();
//  }
//  else{
//    digitalWrite(BLUE, LOW);
//  }
  digitalWrite(TEST, HIGH); 
   delay(750);
  
}

void solid_blue_white(){
  digitalWrite(BLUE, LOW);
  //while(digitalRead(INPUT_A) == HIGH && digitalRead(INPUT_B) == LOW){
    digitalWrite(BLUE, HIGH);
  //}
  //digitalWrite(BLUE, LOW);
}

void pulse_white(){
  digitalWrite(BLUE, LOW);
  while(1){
      // fade in from min to max in increments of 5 points:
      for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) {
        // sets the value (range from 0 to 255):
        analogWrite(BLUE, fadeValue);
        // wait for 50 milliseconds to see the dimming effect
        delay(50);
     }

      // fade out from max to min in increments of 5 points:
      for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) {
        // sets the value (range from 0 to 255):
        analogWrite(BLUE, fadeValue);
        // wait for 50 milliseconds to see the dimming effect
        delay(50);
      }

      analogWrite(BLUE, 0);
      delay(100);
    }
}

//RGB SPECTRUM
void rgb(){
  digitalWrite(BLUE, LOW);

  while(1){
    // fade in from min to max in increments of 5 points: FADE IN RED
    for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
      // wait for 50 milliseconds to see the dimming effect
      delay(50);
    }

    // fade in from min to max in increments of 5 points: FADE IN GREEN [RED]
    for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
      // wait for 50 milliseconds to see the dimming effect
      delay(50);
    }

    // fade out from max to min in increments of 5 points: FADE OUT RED [GREEN]
    for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
      // wait for 50 milliseconds to see the dimming effect
      delay(50);
    }

    // fade in from min to max in increments of 5 points: FADE IN BLUE [GREEN]
    for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
      // sets the value (range from 0 to 255):
      analogWrite(BLUE, fadeValue);
      // wait for 50 milliseconds to see the dimming effect
      delay(50);
    }

     // fade out from max to min in increments of 5 points: FADE OUT GREEN [BLUE]
    for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
      // wait for 50 milliseconds to see the dimming effect
      delay(50);
    }

    // fade in from min to max in increments of 5 points: FADE IN RED [BLUE]
    for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
      // wait for 50 milliseconds to see the dimming effect
      delay(50);
    }

    // fade in from min to max in increments of 5 points: FADE IN GREEN [BLUE, RED]
    for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
      // wait for 50 milliseconds to see the dimming effect
      delay(50);
    }

     // fade out from max to min in increments of 5 points: FADE OUT ALL
    for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
      // sets the value (range from 0 to 255):
      analogWrite(BLUE, fadeValue);
      // wait for 50 milliseconds to see the dimming effect
      delay(50);
    } 
  }
}
