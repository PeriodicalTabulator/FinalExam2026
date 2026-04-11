#include <LiquidCrystal_I2C.h>


// Pin definitions
const int BUTTON_PIN = 2;      // Button connected to pin 2
const int LED_PIN = 4;         // LED connected to pin 4
const int BUZZER_PIN = 3;      // Buzzer connected to pin 3

LiquidCrystal_I2C lcd(0x27, 16, 2);  // 16x2 LCD

// Variables
unsigned long pressStartTime = 0;
unsigned long holdDuration = 0;
bool buttonWasPressed = false;


void setup() {
 // Initialize
 pinMode(LED_PIN, OUTPUT);
 pinMode(BUZZER_PIN, OUTPUT);
 pinMode(BUTTON_PIN, INPUT_PULLUP);  //pull up rezistor
  // Initialize LCD
 lcd.init();
 lcd.backlight();
  // Serial is not needed but if you need to debug uncomment code
  //Serial.begin(9600);
}


void loop() {
 int buttonPressed = (digitalRead(BUTTON_PIN) == LOW);  // True when pressed (LOW due to INPUT_PULLUP)
  if (buttonPressed) {
   // Button is currently pressed
   if (!buttonWasPressed) {
     // Button was just pressed
     pressStartTime = millis();
     buttonWasPressed = true;
    
     //turn on
     digitalWrite(LED_PIN, HIGH);
     digitalWrite(BUZZER_PIN, HIGH);
    
    // Serial.println("LED and Buzzer ON");
   }
  
   // how long is holded
   holdDuration = (millis() - pressStartTime) / 1000;  // Convert to seconds (1s = 1000ms)
  
   // Update LCD with hold duration
   lcd.setCursor(0, 0);
   lcd.print("Button: PRESSED ");
   lcd.setCursor(0, 1);
   lcd.print("Hold Duration:");
   lcd.setCursor(14, 1);
   lcd.print("   ");  // Clear old number (if not used can be overlapped)
   lcd.setCursor(14, 1);
   lcd.print(holdDuration);
   lcd.print("s ");
  
   //Serial.print("Holding for: ");
   //Serial.print(holdDuration);
   //Serial.println(" seconds");
  
 } else {
   //not pressed
   if (buttonWasPressed) {
     // Button was just released
     buttonWasPressed = false;
    
     // Turn off LED and buzzer
     digitalWrite(LED_PIN, LOW);
     digitalWrite(BUZZER_PIN, LOW);
    
     // Show final hold time on LCD
     lcd.clear();
     lcd.setCursor(0, 0);
     lcd.print("Button RELEASED");
     lcd.setCursor(0, 1);
     lcd.print("Held for: ");
     lcd.print(holdDuration);
     lcd.print("s  ");
    
     //Serial.print("Button RELEASED - Held for ");
     //Serial.print(holdDuration);
     //Serial.println(" seconds");
    
     delay(1500);  // Show this message for 1.5 seconds
    
     // Return to ready state
     lcd.clear();
     lcd.setCursor(0, 0);
     lcd.print("Ready");
     lcd.setCursor(0, 1);
     lcd.print("Hold Duration:0s");
   }
 }
  delay(50);  // Small delay to prevent LCD flicker
}
