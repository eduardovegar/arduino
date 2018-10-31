// Basic Ultrasonic Distance

const int trigPin = 9;
const int echoPin = 10;

float duration, distance;

void setup(){
  Serial.begin(9600); // Monitor the Input from the Sensor

  // Trigger and Echo initialized
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Reset the Trigger pin and wait half a second
  digitalWrite(trigPin, LOW);
}

void loop(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.343/2;
  
  Serial.print("Distance is: ");
  Serial.println(distance);
  delay(100);
}
