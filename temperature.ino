// RGB Light
#define LED_R 3
#define LED_G 5
#define LED_B 6

// LED lights
#define LED_10 11
#define LED_20 10
#define LED_30 9

// Temp Sensor
#define SENSOR 13
// Include libraries for temperature sensor
#include <OneWire.h>
#include <DallasTemperature.h>
OneWire oneWire(SENSOR);
DallasTemperature sensors(&oneWire);

// Include NewPing Library for distance sensor
#include "NewPing.h"
#define TRIGGER_PIN 8
#define ECHO_PIN 12  // Maximum distance we want to ping for (in centimeters).
#define MAX_DISTANCE 400
// NewPing setup of pins and maximum distance.
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

// setup code here, to run once:
void setup() {
  // Setup RGB pins as OUTPUT
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  // turn light off to start
  colorRGB(255, 255, 255);

  // Setup LED Pins as OUTPUT
  pinMode(LED_10, OUTPUT);
  pinMode(LED_20, OUTPUT);
  pinMode(LED_30, OUTPUT);

  // Start DallasTemperature Library
  sensors.begin();

  // Setup Serial console so we can see output
  Serial.begin(9600);
}

// put your main code here, to run repeatedly:
void loop() {
  sensors.requestTemperatures();
  int temp_c = sensors.getTempCByIndex(0);
  unsigned long distance = sonar.ping_cm();
  Serial.print("temp c as int: ");
  Serial.println(temp_c);
  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");

  // if nobody is around turn off and wait
  if (distance == 0 || distance > 200) {
    off();
    delay(500);
    return;
  }

  // we're higher than 10 degress, turn on LED_10
  if (temp_c >= 10) {
    digitalWrite(LED_10, HIGH);
  } else {
    digitalWrite(LED_10, LOW);
  }

  // we're higher than 20 degress, turn on LED_20
  if (temp_c >= 20) {
    digitalWrite(LED_20, HIGH);
  } else {
    digitalWrite(LED_20, LOW);
  }

  // we're higher than 30 degress, turn on LED_30
  if (temp_c >= 30) {
    digitalWrite(LED_30, HIGH);
  } else {
    digitalWrite(LED_30, LOW);
  }

  int ones_temp = temp_c % 10;

  if (ones_temp == 0) {
    temp0();
  }
  if (ones_temp == 1) {
    temp1();
  }
  if (ones_temp == 2) {
    temp2();
  }
  if (ones_temp == 3) {
    temp3();
  }
  if (ones_temp == 4) {
    temp4();
  }
  if (ones_temp == 5) {
    temp5();
  }
  if (ones_temp == 6) {
    temp6();
  }
  if (ones_temp == 7) {
    temp7();
  }
  if (ones_temp == 8) {
    temp8();
  }
  if (ones_temp == 9) {
    temp9();
  }

  delay(500);
}


void off() {
  // tunring off the RGB led light
  colorRGB(255, 255, 255);

  // turn off 10s lights
  digitalWrite(LED_10, LOW);
  digitalWrite(LED_20, LOW);
  digitalWrite(LED_30, LOW);
}

void colorRGB(int red, int green, int blue) {
  // colors: 0 == full brightness, 255 == off.
  analogWrite(LED_R, red);
  analogWrite(LED_G, green);
  analogWrite(LED_B, blue);
}

// set colors blue -> red representing 0-9
void temp0() {
  colorRGB(255, 255, 0);
}
void temp1() {
  colorRGB(255, 255, 50);
}
void temp2() {
  colorRGB(255, 255, 100);
}
void temp3() {
  colorRGB(255, 255, 150);
}
void temp4() {
  colorRGB(255, 255, 250);
}
void temp5() {
  colorRGB(250, 255, 250);
}
void temp6() {
  colorRGB(200, 255, 220);
}
void temp7() {
  colorRGB(150, 255, 220);
}
void temp8() {
  colorRGB(100, 255, 220);
}
void temp9() {
  colorRGB(0, 255, 255);
}
