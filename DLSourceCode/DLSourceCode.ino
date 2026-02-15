#include <Adafruit_MPU6050.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>


#define SCREEN_WIDTH 128      
#define SCREEN_HEIGHT 64     
#define BUZZER_PIN 13        
#define LEVEL_THRESHOLD 0.30 


Adafruit_MPU6050 mpu; 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1); 

void setup() {
  
  Serial.begin(19200); 


  Wire.begin(21, 22); 
 
  if (!mpu.begin()) {
    Serial.println("Blad MPU6050: Sensor init failed");
    while (1) yield();
  }
  

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("Blad OLED: SSD1306 allocation failed"));
    for (;;) yield(); 
  }


  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, HIGH); 


  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(2);
  display.setCursor(0, 0);
  display.println("POZIOMICA ON");
  display.display();
  delay(1000);
  display.setTextSize(3); 
}

void loop() {

  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);


  display.clearDisplay();
  display.setCursor(0, 0);
  

  display.print("X: "); 
  display.println(a.acceleration.x, 1);
  display.print("Y: "); 
  display.println(a.acceleration.y, 1);
  

  bool isLevel = abs(a.acceleration.x) < LEVEL_THRESHOLD && abs(a.acceleration.y) < LEVEL_THRESHOLD;

  if (isLevel) {

    display.setCursor(0, 48);
    display.setTextSize(2);
    display.print(">>POZIOM<<");
    
 
    digitalWrite(BUZZER_PIN, LOW); 
  } else {
 
    digitalWrite(BUZZER_PIN, HIGH); 
  }
  display.display();
  delay(100);
}