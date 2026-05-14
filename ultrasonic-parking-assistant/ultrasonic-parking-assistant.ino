#include <NewPing.h>  //the included library NewPing.h

#define triggerPin 11
#define echoPin 10
#define alert 5
#define buzzer 2

const int maxdistant = 200; //Max distance the ultrasonic sensor can measure, which is 200cm

NewPing sonar(triggerPin, echoPin, maxdistant);

void setup() {                //Setting up all inputs and outputs aswell as the serial monitor
  pinMode(buzzer, OUTPUT);
  pinMode(alert, OUTPUT);
  pinMode(triggerPin, INPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(9600);
}

int distanceGetCM(){                //First custom function measures distance and turns it into an intagure and stores it for later
  float pingCM = sonar.ping_cm();
  return pingCM;
}

void triggerAlert(int distance){        //Second custom function that is the if, if-else logic for the code
  if(distance < 20 && distance > 0){    //Distance less than 20 more than 0 cm will cause the buzzer and LED to be HIGH
    digitalWrite(buzzer, HIGH);
    digitalWrite(alert, HIGH);
      Serial.println("Danger! Stop!");
  }
  else if(distance < 50 && distance > 0){ //Distance under 50, over 0 cm then the buzzer and LED will alternate between HIGH and LOW every 500ms
    digitalWrite(buzzer, HIGH);
    digitalWrite(alert, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
    digitalWrite(alert, LOW);
    delay(500);
      Serial.println("Caustion");
  }
  else{                                 //Anything else the buzzer and LED will remain LOW
    digitalWrite(buzzer, LOW);
    digitalWrite(alert, LOW);
      Serial.println("Safe");
  }
}

void loop() {                             //Void loop
  int currentDistance = distanceGetCM();  //Calling currentDistance to be used to display the distance in the serial monitor
    Serial.println("Distance:   ");
    Serial.println(currentDistance);
  triggerAlert(currentDistance);          //Calling triggerAlert to loop the code with in the function
  delay(50);                              //Slight delay to not cause any errors
}
