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
  pinMode(triggerPin, INPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(9600);
}

int distanceGetCM(){
  float pingCM = sonar.ping_cm();
  return pingCM;
}

void loop() {
  int distanceGetCM = sonar.ping_cm();
    Serial.println("Distance:  ");
    Serial.println(distanceGetCM);
  
  if(distanceGetCM < 20){
    digitalWrite(buzzer, HIGH);
    digitalWrite(alert, HIGH);
    Serial.println("Danger! Stop!");
  }
  else if(distanceGetCM < 50){
    digitalWrite(buzzer, HIGH);
    digitalWrite(alert, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
    digitalWrite(alert, LOW);
    delay(500);
    Serial.println("Caustion");
  }
  else{
    digitalWrite(buzzer, LOW);
    digitalWrite(alert, LOW);
    Serial.println("Safe");
  }
}
