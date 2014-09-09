const int button = 8;
const int led1 = 1;
const int led2 = 2;
const int led3 = 3;

int pushCount = 0;
int buttonCurrent = 0;
int buttonPrevious = 0;

void setup () {
  pinMode(button, INPUT);
  pinMode(led1, OUTPUT);
  Serial.begin(9600);
}


void loop () {
  buttonCurrent = digitalRead(button);

  if (buttonCurrent == LOW) {
    digitalWrite(led1, HIGH);
  } 
  else {
    digitalWrite(led1, LOW);
    
      pushCount++;
      Serial.print("push count: ");
      Serial.println(pushCount);
    }
    
    Serial.println("nothing is happening");
  }



/*
  if (buttonCurrent != buttonPrevious) {
    
    if (buttonCurrent == HIGH) {
      pushCount++;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(pushCount);
    }
    else {
      Serial.println("off");
    }
  }
  
  buttonPrevious = buttonCurrent;
  
  if (pushCount % 4 == 0) {
    digitalWrite(led1, HIGH);
  } else {
    digitalWrite(led1, LOW);
  }
  
  */
}
