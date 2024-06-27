// Pin connections
const int motorPin1 = 23;   // IN1 of ULN2003A
const int motorPin2 = 24;   // IN2 of ULN2003A
const int motorPin3 = 25;   // IN3 of ULN2003A
const int motorPin4 = 26;   // IN4 of ULN2003A
char receivedChar;

const int ledPin = 17;     // Pin for the red LED

const int stepsPerRevolution = 200;  // Number of steps per revolution for the stepper motor
const int speedDelay = 2;            // Delay between steps (higher value slows down the motor)

void setup() {
  // Set motor pins as outputs
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);

  // Set LED pin as output
  pinMode(ledPin, OUTPUT);

  // Start serial communication
  Serial.begin(9600);
  delay(5000);
  digitalWrite(ledPin,HIGH);
  rotateClockwise(1);
}

void loop() {
  // Check if a character is available from the serial port
  if (Serial.available()) {
    char receivedChar = Serial.read();

    // Check if the received character is 'L'
    if (receivedChar='L') {
      // Activate the stepper motor and LED
      rotateClockwise(1);
      digitalWrite(ledPin,HIGH);

      // Delay for 2 seconds
      delay(1000);

      // Deactivate the stepper motor and LED
      rotateCounterClockwise(1);
      digitalWrite(ledPin, LOW);
    }
  }
}

// Function to rotate the motor clockwise
void rotateClockwise(float revolutions) {
  int stepsToMove = stepsPerRevolution * revolutions;

  for (int i = 0; i < stepsToMove; i++) {
    // Step sequence for clockwise rotation
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
    delay(speedDelay);

    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
    delay(speedDelay);

    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
    delay(speedDelay);

    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
    delay(speedDelay);
  }
}

// Function to rotate the motor counterclockwise
void rotateCounterClockwise(float revolutions) {
  int stepsToMove = stepsPerRevolution * revolutions;

  for (int i = 0; i < stepsToMove; i++) {
    // Step sequence for counterclockwise rotation
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
    delay(speedDelay);

    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
    delay(speedDelay);

    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
    delay(speedDelay);

    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
    delay(speedDelay);
  }
}
