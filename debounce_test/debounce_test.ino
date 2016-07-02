int button = 2;
boolean buttonPressed = false;
int led1 = 13;
int led2 = 12;
int debounce = 0;
boolean toggle = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(button, INPUT);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);

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
    toggle_funct();
  }
}

void toggle_funct()
{
  digitalWrite(led1, !digitalRead(led1));
  digitalWrite(led2, !digitalRead(led2));
}

