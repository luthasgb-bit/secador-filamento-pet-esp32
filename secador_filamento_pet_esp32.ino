/*
 * PROYECTO: Módulo de secado de filamento PET
 * PLATAFORMA: ESP32
 * LENGUAJE: C++ (Arduino Framework)
 * VISUALIZACIÓN: OLED I2C 128x64 integrada
 */

// -------- LIBRERÍAS --------
#include <Wire.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <DHT.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// -------- OLED --------
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define OLED_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// -------- PINES --------
#define PIN_DS18B20 4
#define PIN_DHT22   15
#define PIN_RELE    26
#define PIN_FAN     27
#define PIN_LED     2
#define PIN_BUZZER  25

// -------- SENSORES --------
#define DHTTYPE DHT22
DHT dht(PIN_DHT22, DHTTYPE);

OneWire oneWire(PIN_DS18B20);
DallasTemperature ds18b20(&oneWire);

// -------- PARÁMETROS --------
float TEMP_MIN = 40.0;
float TEMP_MAX = 60.0;
float HUM_MAX  = 30.0;

// -------- VARIABLES --------
float tempPET;
float tempAmb;
float humedad;

void setup() {
  Serial.begin(115200);

  pinMode(PIN_RELE, OUTPUT);
  pinMode(PIN_FAN, OUTPUT);
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BUZZER, OUTPUT);

  digitalWrite(PIN_RELE, LOW);
  digitalWrite(PIN_FAN, LOW);

  dht.begin();
  ds18b20.begin();

  Wire.begin(21, 22);

  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)) {
    while (true);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Secador PET");
  display.println("Iniciando...");
  display.display();

  delay(2000);
}

void loop() {

  // ---- LECTURA DE SENSORES ----
  ds18b20.requestTemperatures();
  tempPET = ds18b20.getTempCByIndex(0);

  tempAmb = dht.readTemperature();
  humedad = dht.readHumidity();

  // ---- CONTROL DE CALEFACCIÓN ----
  if (tempPET < TEMP_MIN) {
    digitalWrite(PIN_RELE, HIGH);
    digitalWrite(PIN_LED, HIGH);
  } else if (tempPET >= TEMP_MAX) {
    digitalWrite(PIN_RELE, LOW);
    alarma();
  }

  // ---- CONTROL DE VENTILACIÓN ----
  if (humedad > HUM_MAX || tempPET > TEMP_MIN) {
    digitalWrite(PIN_FAN, HIGH);
  } else {
    digitalWrite(PIN_FAN, LOW);
  }

  // ---- MONITOREO OLED ----
  display.clearDisplay();
  display.setCursor(0, 0);

  display.print("PET: ");
  display.print(tempPET);
  display.println(" C");

  display.print("Amb: ");
  display.print(tempAmb);
  display.println(" C");

  display.print("Hum: ");
  display.print(humedad);
  display.println(" %");

  display.print("Calef: ");
  display.println(digitalRead(PIN_RELE) ? "ON" : "OFF");

  display.print("Fan: ");
  display.println(digitalRead(PIN_FAN) ? "ON" : "OFF");

  display.display();

  delay(3000);
}

// -------- ALARMA --------
void alarma() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(PIN_BUZZER, HIGH);
    delay(200);
    digitalWrite(PIN_BUZZER, LOW);
    delay(200);
  }
}
