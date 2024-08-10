#include <LiquidCrystal.h> // Include the LiquidCrystal library

// Create an LCD object, specifying the pins it's connected to
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

// Array to hold the IR sensor pins
int ir[2] = {9, 10};

// Array to hold the relay control pins
int re[2] = {11, 12};

void setup() {
  lcd.begin(16, 2); // Initialize the LCD: 16 columns, 2 rows
  lcd.clear(); // Clear the LCD screen
  lcd.setCursor(0, 0); // Set the cursor to the first row, first column
  lcd.print("Wireless Vehicle"); // Display "Wireless Vehicle" on the LCD
  lcd.setCursor(0, 1); // Set the cursor to the second row, first column
  lcd.print("Charging System"); // Display "Charging System" on the LCD

  // Set the IR sensor pins as INPUT
  pinMode(ir[0], INPUT);
  pinMode(ir[1], INPUT);

  // Set the relay control pins as OUTPUT
  pinMode(re[0], OUTPUT);
  pinMode(re[1], OUTPUT);

  delay(3000); // Wait for 3 seconds

  lcd.clear(); // Clear the LCD screen
  lcd.setCursor(1, 0); // Set the cursor to the first row, second column
  lcd.print("Spot1"); // Display "Spot1" at the specified location
  lcd.setCursor(10, 0); // Set the cursor to the first row, eleventh column
  lcd.print("Spot2"); // Display "Spot2" at the specified location
}

void loop() {
  // Check if IR sensor 1 detects an object
  if (digitalRead(ir[0])) {
    digitalWrite(re[0], HIGH); // If detected, turn ON the relay for Spot1
    lcd.setCursor(0, 1); // Set the cursor to the second row, first column
    lcd.print("Charge      "); // Display "Charge" indicating charging in Spot1
  } else {
    digitalWrite(re[0], LOW); // If not detected, turn OFF the relay for Spot1
    lcd.setCursor(0, 1); // Set the cursor to the second row, first column
    lcd.print(" OFF        "); // Display "OFF" indicating charging is off for Spot1
  }

  // Check if IR sensor 2 detects an object
  if (digitalRead(ir[1])) {
    digitalWrite(re[1], HIGH); // If detected, turn ON the relay for Spot2
    lcd.setCursor(9, 1); // Set the cursor to the second row, tenth column
    lcd.print("Charge      "); // Display "Charge" indicating charging in Spot2
  } else {
    digitalWrite(re[1], LOW); // If not detected, turn OFF the relay for Spot2
    lcd.setCursor(9, 1); // Set the cursor to the second row, tenth column
    lcd.print(" OFF        "); // Display "OFF" indicating charging is off for Spot2
  }

  delay(100); // Short delay to debounce sensor readings
}
