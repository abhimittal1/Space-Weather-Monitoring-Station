/*
  
  Components used:
  - Arduino Uno
  - DHT22 (Temperature & Humidity sensor)
  - BMP280 (Pressure sensor) 
  - LCD 16x2 Display
  - LEDs for status indication
  - Potentiometer for manual calibration
*/

#include <LiquidCrystal.h>
#include <DHT.h>

// Pin definitions
#define DHT_PIN 2
#define DHT_TYPE DHT22
#define LED_GREEN 8
#define LED_RED 9
#define LED_BLUE 10
#define BUZZER_PIN 11
#define POTENTIOMETER A0

// LCD pins (RS, Enable, D4, D5, D6, D7)
LiquidCrystal lcd(12, 13, 4, 5, 6, 7);

// DHT sensor
DHT dht(DHT_PIN, DHT_TYPE);

// Variables for sensor readings
float temperature = 0;
float humidity = 0;
float pressure = 0;
int altitude_simulation = 0;
unsigned long lastReading = 0;
unsigned long lastDisplay = 0;
int displayMode = 0;

// Threshold values for space environment simulation
const float TEMP_MIN = -40;  // Minimum operational temperature
const float TEMP_MAX = 85;   // Maximum operational temperature
const float HUMIDITY_MAX = 95; // Maximum humidity threshold
const float PRESSURE_MIN = 300; // Simulated low pressure (space-like)

void setup() {
  Serial.begin(9600);
  
  // Initialize LCD
  lcd.begin(16, 2);
  lcd.print("Space Weather");
  lcd.setCursor(0, 1);
  lcd.print("Station v1.0");
  
  // Initialize DHT sensor
  dht.begin();
  
  // Initialize LED pins
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  
  // Startup sequence
  startupSequence();
  
  delay(2000);
  lcd.clear();
  
  Serial.println("Space Weather Monitoring Station Initialized");
  Serial.println("Simulating satellite environmental data...");
  Serial.println("=====================================");
}

void loop() {
  // Read sensors every 2 seconds
  if (millis() - lastReading > 2000) {
    readSensors();
    checkThresholds();
    lastReading = millis();
  }
  
  // Update display every 3 seconds
  if (millis() - lastDisplay > 3000) {
    updateDisplay();
    lastDisplay = millis();
  }
  
  // Send data to serial monitor every 5 seconds
  if (millis() % 5000 < 100) {
    sendTelemetry();
  }
  
  delay(100);
}

void readSensors() {
  // Read DHT22 sensor
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();
  
  // Simulate pressure reading (since BMP280 not available in free Wokwi)
  // Using potentiometer to simulate pressure variations
  int potValue = analogRead(POTENTIOMETER);
  pressure = map(potValue, 0, 1023, 200, 1200); // Simulate pressure range
  
  // Simulate altitude based on pressure
  altitude_simulation = map(pressure, 200, 1200, 50000, 0); // Inverted relationship
  
  // Check for sensor errors
  if (isnan(temperature) || isnan(humidity)) {
    temperature = -999;
    humidity = -999;
    Serial.println("DHT sensor error!");
  }
}

void checkThresholds() {
  bool alertCondition = false;
  
  // Temperature check
  if (temperature < TEMP_MIN || temperature > TEMP_MAX) {
    alertCondition = true;
  }
  
  // Humidity check
  if (humidity > HUMIDITY_MAX) {
    alertCondition = true;
  }
  
  // Pressure check (low pressure indicates high altitude/space-like conditions)
  if (pressure < PRESSURE_MIN) {
    alertCondition = true;
  }
  
  // Update status LEDs
  if (alertCondition) {
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_BLUE, LOW);
    
    // Sound alert
    tone(BUZZER_PIN, 1000, 200);
  } else {
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_BLUE, LOW);
  }
  
  // Blue LED blinks to show system is active
  digitalWrite(LED_BLUE, (millis() / 1000) % 2);
}

void updateDisplay() {
  lcd.clear();
  
  switch (displayMode % 3) {
    case 0:
      // Temperature and Humidity
      lcd.setCursor(0, 0);
      lcd.print("Temp: ");
      if (temperature != -999) {
        lcd.print(temperature, 1);
        lcd.print("C");
      } else {
        lcd.print("ERROR");
      }
      
      lcd.setCursor(0, 1);
      lcd.print("Humid: ");
      if (humidity != -999) {
        lcd.print(humidity, 1);
        lcd.print("%");
      } else {
        lcd.print("ERROR");
      }
      break;
      
    case 1:
      // Pressure and Altitude
      lcd.setCursor(0, 0);
      lcd.print("Press: ");
      lcd.print(pressure, 0);
      lcd.print("hPa");
      
      lcd.setCursor(0, 1);
      lcd.print("Alt: ");
      lcd.print(altitude_simulation);
      lcd.print("m");
      break;
      
    case 2:
      // System Status
      lcd.setCursor(0, 0);
      lcd.print("System Status:");
      
      lcd.setCursor(0, 1);
      if (temperature != -999 && humidity != -999) {
        lcd.print("OPERATIONAL");
      } else {
        lcd.print("SENSOR ERROR");
      }
      break;
  }
  
  displayMode++;
}

void sendTelemetry() {
  Serial.println("=== TELEMETRY DATA ===");
  Serial.print("Timestamp: ");
  Serial.println(millis());
  
  Serial.print("Temperature: ");
  if (temperature != -999) {
    Serial.print(temperature);
    Serial.println(" °C");
  } else {
    Serial.println("SENSOR ERROR");
  }
  
  Serial.print("Humidity: ");
  if (humidity != -999) {
    Serial.print(humidity);
    Serial.println(" %");
  } else {
    Serial.println("SENSOR ERROR");
  }
  
  Serial.print("Pressure: ");
  Serial.print(pressure);
  Serial.println(" hPa");
  
  Serial.print("Simulated Altitude: ");
  Serial.print(altitude_simulation);
  Serial.println(" m");
  
  Serial.print("Status: ");
  if (digitalRead(LED_RED)) {
    Serial.println("ALERT - Environmental limits exceeded!");
  } else {
    Serial.println("NOMINAL - All systems operational");
  }
  
  Serial.println("====================");
  Serial.println();
}

void startupSequence() {
  // LED startup sequence
  for (int i = 0; i < 3; i++) {
    digitalWrite(LED_RED, HIGH);
    delay(200);
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_GREEN, HIGH);
    delay(200);
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_BLUE, HIGH);
    delay(200);
    digitalWrite(LED_BLUE, LOW);
  }
  
  // Startup beep
  tone(BUZZER_PIN, 2000, 100);
  delay(150);
  tone(BUZZER_PIN, 2500, 100);
}
