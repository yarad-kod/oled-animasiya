#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64


Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// HC-SR04 pins
#define TRIG_PIN 9
#define ECHO_PIN 10

long duration;
int distance;

void setup() {
  Serial.begin(9600);


  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);


  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
}

void loop() {

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);


  distance = duration * 0.034 / 2;


  Serial.print("Mesafe: ");
  Serial.print(distance);
  Serial.println(" sm");


  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0, 10);
  display.print("Mesafe:");
  display.setCursor(0, 35);
  display.print(distance);
  display.print(" sm");
  display.display();

  delay(500);
}
