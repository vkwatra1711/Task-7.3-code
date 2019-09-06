int buzzerPin = 8;              // buzzzer signal pin attached to digital pin 8
int trigPin = 11;               // ultrasonic triggerPin connected to digital pin 11
int echoPin = 10;               // ultrasonic echoPin connected to digital pin 10
int ledPin = 13;                // LED positive connected to digital pin 13 
long duration;
float distanceMeters;

void setup() {                        
  pinMode(13, OUTPUT);                // LED pin as output
  pinMode(trigPin, OUTPUT);           // trigger pin as output because it sends signal
  pinMode(8, OUTPUT);                 // buzzer pin as output
  pinMode(echoPin, INPUT);            // echo pin as input becaue it recievs signals
  Serial.begin(9600);                  
}

void loop() {
  digitalWrite(trigPin, HIGH);       //transmits the signal from trigPin             
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);                

  distanceMeters = duration * 0.00034 / 2;        // This formula helps to calculate distance of object in metres
  Serial.print("Distance: ");                     // print distance in metres in serial monitor
  Serial.print(distanceMeters);
  Serial.println("  Meters");

  if (distanceMeters <= 1 )    {                  // if distance is lesser than or equal to 1 metre;LED turn on and there will be tone from the buzzer
    digitalWrite(13,HIGH);                        // with delay as interval
    tone(buzzerPin, 1200); 
    delay(300);                                           
  }
  else    {
    digitalWrite(13, LOW);                        //if distance is more than 1 then led will be off and there will be no tone from the buzzer
    noTone(buzzerPin);
  }
}
