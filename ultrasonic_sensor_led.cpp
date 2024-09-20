// Define pins
const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 13;

// Define maximum distance to trigger the LED (in centimeters)
const int triggerDistance = 10;

void setup() {
  // Initialize pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  // Start serial communication for debugging
  Serial.begin(9600);
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

  // If the distance is less than the trigger distance, turn on the LED
  if (distance < triggerDistance) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  
  delay(200);  // Small delay for readability
}
