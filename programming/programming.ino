#define NUM_MOTORS 4
int motorPins[NUM_MOTORS] = { 6, 9, 10, 11 };

void control_drone_propellers(byte speed, byte prop) {
  byte pwm = map(speed, 0, 200, 0, 255);  // Mapping range from 0-200 to 0-255
  // Serial.println(pwm);
  analogWrite(motorPins[prop], pwm);
}

void setupMotors() {
  for (byte i = 0; i < NUM_MOTORS; i++) { pinMode(motorPins[i], OUTPUT);}
}

void setup() {
  setupMotors();
  // Serial.begin(9600);
}

void loop() {
  control_drone_propellers(0, 0);  // Example usage with a byte value
}