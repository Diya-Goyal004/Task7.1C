// Define the pins for the L298N motor driver
const int ENA = 5;
const int IN1 = 6;
const int IN2 = 7;
const int IN3 = 8;
const int IN4 = 9;
const int ENB = 10;

// Define the variables for storing the received commands
char robotID = 'A';
char command = 'S';

void setup() {
  // Set up serial communication for debugging
  Serial.begin(9600);
  
  // Set up the motor pins as outputs
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop() {
  // Check if a command has been received
  if (Serial.available()) {
    char receivedChar = Serial.read();

    // Parse the received command
    if (receivedChar == robotID) {
      // This command is meant for this robot
      if (Serial.available()) {
        command = Serial.read();
      }
    }
  }

  // Perform the appropriate action based on the command
  switch (command) {
    case 'F':
      // Move forward
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(ENA, 150);
      analogWrite(ENB, 150);
      break;

    case 'B':
      // Move backward
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      analogWrite(ENA, 150);
      analogWrite(ENB, 150);
      break;

    case 'L':
      // Turn left
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(ENA, 100);
      analogWrite(ENB, 100);
      break;

    case 'R':
      // Turn right
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      analogWrite(ENA, 100);
      analogWrite(ENB, 100);
      break;

    case 'S':
      // Stop moving
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      analogWrite(ENA, 0);
      analogWrite(ENB, 0);
      break;

    default:
      // Invalid command
      break;
  }
}


