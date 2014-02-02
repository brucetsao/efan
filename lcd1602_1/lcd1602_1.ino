	/*
	LiquidCrystal Library - Hello World

	Use a 16x2 LCD display The LiquidCrystal
	library works with all LCD displays that are compatible with the 
	Hitachi HD44780 driver. 
	This sketch prints "Hello World!" to the LCD
	and shows the time.
	*/
	// include the library code:
	#include <LiquidCrystal.h>

	// initialize the library with the numbers of the interface pins
	LiquidCrystal lcd(12, 11,10, 5, 4, 3, 2);   //use db4-db7 as pin 5-2
	//LiquidCrystal(rs, rw, enable, d4, d5, d6, d7) 
        void setup() {
	// set up the LCD's number of columns and rows: 
	Serial.begin(9600);
         Serial.println("start here");
        lcd.begin(16, 2);
	// Print a message to the LCD.
	lcd.setCursor(4, 0);
	lcd.print("superman...");
        
	}
	void loop() {
	lcd.setCursor(6, 1);
//   lcd.setCursor(　行, 　列) ;
         Serial.print("now number is :");
         Serial.println(millis()/1000);
	lcd.print(millis()/1000);
        delay(800) ;
	}

