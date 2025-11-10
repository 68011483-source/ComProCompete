// Motor control pins
const int ENA = 6;  // PWM for left motor
const int IN1 = 7;
const int IN2 = 8;

const int ENB = 11;  // PWM for right motor
const int IN3 = 12;
const int IN4 = 13;

// Speed settings (0–255)
int leftSpeed = 90;
int rightSpeed = 200;  // Reduced to compensate for faster motor

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  Path1A();
  turnLeft(100);
  moveBackward(100);
  turnLeft(100);
  moveBackward(100);
  turnLeft(100);
  moveBackward(100);
  while (true);
}

void moveForward(int duration) {
  analogWrite(ENA, leftSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  analogWrite(ENB, rightSpeed);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  delay(duration);
  stopMotors();
}
void moveBackward(int duration) {
  analogWrite(ENA, leftSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  analogWrite(ENB, rightSpeed);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  delay(duration);
  stopMotors();
}

void turnRight(int duration) {
  analogWrite(ENA, leftSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  analogWrite(ENB, rightSpeed);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  delay(duration);
  stopMotors();
}

void turnLeft(int duration) {
  analogWrite(ENA, leftSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  analogWrite(ENB, rightSpeed);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  delay(duration);
  stopMotors();
}

void stopMotors() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
void Path1A(){
  moveForward(500);
  turnRight(500);
  moveForward(1100);
  turnRight(550);
  moveForward(1000);
  moveBackward(500);
}
void Path1B(){
  moveForward(500);
  turnRight(500);
  moveForward(500);
  turnLeft(500);
  moveForward(500);
  turnLeft(500);
  moveForward(1000);
  moveBackward(500);
}