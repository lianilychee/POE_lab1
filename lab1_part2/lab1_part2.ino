// Assign pins to components.
const int button = 8;
const int led1 = 11;
const int led2 = 12;
const int led3 = 13;
const float pot = A2;

// Variables to monitor pushbutton and pot state.
float potVal = 0;
int pushCount = 0;
int buttonCurrent = 0;
int buttonPrevious = 0;

// Assign pin types.
void setup () {
  pinMode(button, INPUT);
  pinMode(pot, INPUT);
  pinMode(led2, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led3, OUTPUT);
  Serial.begin(9600);
}

void loop () {

  // Scaling pot reading for better ms delay.
  buttonCurrent = digitalRead(button);
  potVal = analogRead(pot) * 2;
  Serial.println(potVal);

  if (buttonCurrent != buttonPrevious) {
    if (buttonCurrent == HIGH) {
      pushCount++;
      
      // Reset pushCount to avoid dealing with modulus.
      if (pushCount == 5) { 
        pushCount = 1; 
      }; 
      
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(pushCount);
    }
    else {
      Serial.println("off");
    }
  }

  buttonPrevious = buttonCurrent;

  // State 1: all on.
  if (pushCount == 1) {
    //Serial.println("all on");
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
  } 
  
  // State 2: all off.
  else if (pushCount == 2) {
    //Serial.println("all off");
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led1, LOW);
  }
  
  // State 3: flashing w delay dependent on pot.
  else if (pushCount == 3) {
    //Serial.println("flashing");
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    delay(potVal);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led1, LOW);
    delay(potVal);
  }
  
  // State 4: bouncing w delay dependent on pot.
  else if (pushCount == 4) {
    //Serial.println("bouncing");
    digitalWrite(led1, HIGH);
    delay(potVal);
    digitalWrite(led1, LOW);
    delay(potVal);
    digitalWrite(led2, HIGH);
    delay(pot);
    digitalWrite(led2, LOW);
    delay(potVal);
    digitalWrite(led3, HIGH);
    delay(potVal);
    digitalWrite(led3, LOW);
    delay(potVal);
  }
  
}
  

