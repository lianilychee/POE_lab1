const int button = 8;
const int led1 = 11;
const int led2 = 12;
const int led3 = 13;
const float pot = A2;

float potVal = 0;
int pushCount = 0;
int buttonCurrent = 0;
int buttonPrevious = 0;

void setup () {
  pinMode(button, INPUT);
  pinMode(pot, INPUT);
  pinMode(led2, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led3, OUTPUT);
  Serial.begin(9600);
}

void loop () {

  buttonCurrent = digitalRead(button);
  potVal = analogRead(pot) * 2;
  Serial.println(potVal);

  if (buttonCurrent != buttonPrevious) {
    if (buttonCurrent == HIGH) {
      pushCount++;
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

  if (pushCount == 1) {
    //Serial.println("all on");
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
  } 
  else if (pushCount == 2) {
    //Serial.println("all off");
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led1, LOW);
  }
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
  

