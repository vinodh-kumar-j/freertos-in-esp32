#include <Arduino.h>

// Use only core 1 for demo purposes
#if CONFIG_FREERTOS_UNICORE
static const BaseType_t app_cpu = 0;
#else
static const BaseType_t app_cpu = 1;
#endif

// Pin for the onboard LED
static const int led_pin = 2;

// Task 1: Blink an LED
void toggleLED(void *parameter) {
  while (1) {
    digitalWrite(led_pin, HIGH);
    vTaskDelay(500 / portTICK_PERIOD_MS);
    digitalWrite(led_pin, LOW);
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}

// Task 2: Print a message every 500ms
void printMessage(void *parameter) {
  while (1) {
    Serial.println("Hello from the second task!");
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}

void setup() {
  // Setup LED pin
  pinMode(led_pin, OUTPUT);

  // Start serial monitor
  Serial.begin(115200);
  while (!Serial); // Wait for serial to open (optional)

  // Create LED blink task
  xTaskCreatePinnedToCore(
    toggleLED, 
    "Toggle LED",
    1024, 
    NULL, 
    1, 
    NULL, 
    app_cpu
  );

  // Create second task to print a message
  xTaskCreatePinnedToCore(
    printMessage, 
    "Print Message",
    1024, 
    NULL, 
    1, 
    NULL, 
    app_cpu
  );
}

void loop() {
  // Nothing to do here
}
