#include <Servo.h>

// Define pins
const int trigPin = 9;
const int echoPin = 10;
const int motorPin = 11;

// Define maximum distance to trigger the motor (in centimeters)
const int triggerDistance = 50;

// Create a servo object
Servo continuousServo;

void setup() {
  // Initialize pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Attach the servo to the motor pin
  continuousServo.attach(motorPin);
  
  // Start serial communication for debugging
  Serial.begin(9600);
  
  // Stop motor initially
  continuousServo.write(88);  // Neutral position (stop) for continuous rotation servos
}

void loop() {
  // Send a pulse from the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the pulse from the echoPin
  long duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance in centimeters
  long distance = duration * 0.034 / 2;

  // Output the distance for debugging
  Serial.print("Distance: ");
  Serial.println(distance);

  // If the distance is within the trigger distance, adjust speed proportionally
  if (distance < triggerDistance) {
    // Map distance to servo speed (0 for fast, 88 for stop)
    // int speed = map(distance, 0, triggerDistance, 0, 88);
    float proportion = min(distance, triggerDistance) / (float)triggerDistance;
    int s = sqrt(sqrt(sqrt(proportion))) * 88;
    continuousServo.write(s);  // Adjust motor speed based on distance
  } else {
    continuousServo.write(88);  // Stop the motor
  }
  
  delay(200);  // Small delay for readability
}
