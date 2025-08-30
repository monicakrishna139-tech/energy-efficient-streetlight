// Smart Energy Efficient Street Light
// Dim at night, bright when vehicle detected
// Tools: Arduino IDE, LDR, Ultrasonic Sensor, LED

int ldrPin = A0;       // LDR sensor connected to analog pin A0
int ledPin = 9;        // LED connected to PWM pin 9

// Ultrasonic sensor pins
int trigPin = 6;
int echoPin = 7;

int ldrThreshold = 500;   // Adjust for darkness
int vehicleDistance = 500; // Distance threshold in cm (change if needed)

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

// Function to measure distance from ultrasonic
long getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.034 / 2; // Convert to cm
  return distance;
}

void loop() {
  int ldrValue = analogRead(ldrPin); // Read LDR
  long distance = getDistance();     // Read Ultrasonic

  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  if (ldrValue < ldrThreshold) { // It's dark
    if (distance < vehicleDistance) {
      // Vehicle detected → Bright
      analogWrite(ledPin, 255); // Full brightness
      Serial.println("Vehicle Detected: Street Light BRIGHT");
    } else {
      // No vehicle → Dim light
      analogWrite(ledPin, 80); // Dim brightness
      Serial.println("No Vehicle: Street Light DIM");
    }
  } else {
    // Daytime → Light OFF
    analogWrite(ledPin, 0);
    Serial.println("Daytime: Street Light OFF");
  }

  delay(500);
}
