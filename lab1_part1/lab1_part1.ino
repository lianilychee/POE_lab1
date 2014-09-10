// Assign pins to components.
const int button = 8;
const int led1 = 11;
const int led2 = 12;
const int led3 = 13;

// Variables to monitor pushbutton state.
int pushCount = 0;
int buttonCurrent = 0;
int buttonPrevious = 0;

// Assign pin types.
void setup () {
  pinMode(button, INPUT);
  pinMode(led2, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led3, OUTPUT);
  Serial.begin(9600);
}


void loop () {
  buttonCurrent = digitalRead(button);

  if (buttonCurrent != buttonPrevious) {
    if (buttonCurrent == HIGH) {
      pushCount++;
      
      // Reset pushCount to avoid dealing with modulus.
      if (pushCount == 5) { 
        pushCount = 1; 
      }; 
      
      Serial.println("on");
      Serial.print("Button state: ");
      Serial.println(pushCount);
    }
    else {
      Serial.println("off");
    }
  }

  buttonPrevious = buttonCurrent;

  // State 1: all on.
  if (pushCount == 1) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
  } 
  // State 2: all off.
  else if (pushCount == 2) {
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led1, LOW);
  }
  // State 3: flashing w delay of 400 ms.
  else if (pushCount == 3) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    delay(400);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led1, LOW);
    delay(400);
  }
  // State 4: bouncing w delay of 400 ms.
  else if (pushCount == 4) {
    digitalWrite(led1, HIGH);
    delay(400);
    digitalWrite(led1, LOW);
    delay(400);
    digitalWrite(led2, HIGH);
    delay(400);
    digitalWrite(led2, LOW);
    delay(400);
    digitalWrite(led3, HIGH);
    delay(400);
    digitalWrite(led3, LOW);
    delay(400);
  }
  
}
  

