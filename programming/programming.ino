#include <SoftwareSerial.h> // Include if using GSM or GPS modules


const int gsmTXPin = 2;
const int gsmRXPin = 3;
const int gpsTXPin = 2; 
const int gpsRXPin = 3;  

int onGroundPin = 2;
int takeoffPin = 4;

int propeller1Pin = 3;
int propeller2Pin = 5;
int propeller3Pin = 6;
int propeller4Pin = 9;

const int coolerCircuitPin = 13;
const int temperatureSensorPin = A0;

int rainAnalogPin = A1;
int rainDigitalPin = 4;

const int windSpeedAnalogPin = A2;

// SoftwareSerial instances (if using GSM or GPS)
SoftwareSerial gsmSerial(gsmTXPin, gsmRXPin);
SoftwareSerial gpsSerial(gpsTXPin, gpsRXPin);

// Function prototypes (implement these based on your hardware and desired behavior)
// void setupGSM();
// void emergencyLanding();
// void takeoff(); 
// void goLeft();
// void goRight();
// void rotate();
// void verticalLanding();

float readTemperature();
void controlCooler(float temperature); 
float measureWindSpeed();
void measureRainfall();

void testGPS();  

void setup() {
  Serial.begin(9600);  // Serial communication for monitoring

  // Pin modes
  pinMode(onGroundPin, INPUT);
  pinMode(takeoffPin, INPUT);
  pinMode(propeller1Pin, OUTPUT);
  pinMode(propeller2Pin, OUTPUT);
  pinMode(propeller3Pin, OUTPUT);
  pinMode(propeller4Pin, OUTPUT);
  pinMode(coolerCircuitPin, OUTPUT);
  pinMode(temperatureSensorPin, INPUT);
  pinMode(rainAnalogPin, INPUT);
  pinMode(rainDigitalPin, INPUT);
  pinMode(windSpeedAnalogPin, INPUT);

}

void loop() {

  gsmSerial.println("AT");
  delay(500);
  
  while (gsmSerial.available()) {
    char c = gsmSerial.read();
    Serial.write(c);
 }

}


  
void emergencyLanding() {
  if (digitalRead(onGroundPin) == HIGH) {
    // Slow propeller rotation (adjust speed as needed)
    analogWrite(propeller1Pin, 64);
    analogWrite(propeller2Pin, 64);
    analogWrite(propeller3Pin, 64);
    analogWrite(propeller4Pin, 64);
    delay(10000);

    while (digitalRead(onGroundPin) == HIGH) {
      // Stop propellers until takeoff signal
      analogWrite(propeller1Pin, 0);
      analogWrite(propeller2Pin, 0);
      analogWrite(propeller3Pin, 0);
      analogWrite(propeller4Pin, 0);

      if (digitalRead(takeoffPin) == HIGH) {
        takeoff();  // Call takeoff function
        return;
      }
    }
  } else {
    // Medium propeller rotation (adjust speed as needed)
    analogWrite(propeller1Pin, 128);
    analogWrite(propeller2Pin, 128);
    analogWrite(propeller3Pin, 128);
    analogWrite(propeller4Pin, 128);
  }
}


void takeoff(){} 
void goLeft(){}
void goRight(){}
void rotate(){}
void verticalLanding(){}
