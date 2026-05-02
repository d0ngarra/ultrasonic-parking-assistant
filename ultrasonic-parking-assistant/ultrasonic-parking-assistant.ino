#include <NewPing.h>

#define triggerPin 11
#define echoPin 10
#define alert 5
#define buzzer 2

const int maxdistant = 200;

NewPing sonar(triggerPin, echoPin, maxdistant);

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(alert, OUTPUT);
}

void loop() {
  int distance = sonar.ping_cm();
    Serial.print("Distance:  ");
    Serial.print(distance);
    Serial.print("cm");
  
  if(distance < 100){
    digitalWrite(buzzer, HIGH);
    delay(1000);
    digitalWrite(buzzer, LOW);
    delay(1000);
  }
  else if(distance < 50){
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
    delay(500);
  }
  else if(distance < 25){
    digitalWrite(buzzer, HIGH);
    digitalWrite(alert, HIGH);
  }
  else{
    digitalWrite(buzzer, LOW);
    digitalWrite(alert, LOW);
  }
}
