
#include <LiquidCrystal.h>

#define relaypin1 32
#define relaypin2 34
#define relaypin3 36
#define relaypin4 38

#define lcdRS 8
#define lcdEnable 9
#define lcdD4 4
#define lcdD5 5
#define lcdD6 6
#define lcdD7 7
#define lcdKeyPin 0
int lcd_key = 0;
int adc_key_in = 0;
#define btnRIGHT 0
#define btnUP 1
#define btnDOWN 2
#define btnLEFT 3
#define btnSELECT 4
#define btnNONE 5


LiquidCrystal lcd(lcdRS, lcdEnable, lcdD4, lcdD5, lcdD6, lcdD7);  //　　產生LCD　元件

void setup()
{
  LCDClear();
  pinMode(relaypin1,OUTPUT) ;
  pinMode(relaypin2,OUTPUT) ;
  pinMode(relaypin3,OUTPUT) ;
  pinMode(relaypin4,OUTPUT) ;
       digitalWrite(relaypin1,HIGH);
       digitalWrite(relaypin2, HIGH);
      digitalWrite(relaypin3, HIGH);
      digitalWrite(relaypin4, HIGH);

  Serial.begin(9600);
  Serial.println("program start here....");
}
void loop()
{
  lcd_key = read_LCD_buttons(); // read the buttons
  if (lcd_key == btnLEFT)
  {
    // speed = 1
      LCDClear();
      lcd.setCursor(0,1);
      lcd.print("Fan Speed one"); // print a simple message
       digitalWrite(relaypin1,LOW);
       digitalWrite(relaypin2, HIGH);
      digitalWrite(relaypin3, HIGH);
      digitalWrite(relaypin4, HIGH);
    }
  if (lcd_key == btnUP)
  {
    // speed = 2
      LCDClear();
      lcd.setCursor(0,1);
      lcd.print("Fan Speed Two"); // print a simple message
       digitalWrite(relaypin1,HIGH);
       digitalWrite(relaypin2, LOW);
      digitalWrite(relaypin3, HIGH);
      digitalWrite(relaypin4, HIGH);
    }
  if (lcd_key == btnDOWN)
  {
    // speed = 3
      LCDClear();
      lcd.setCursor(0,1);
      lcd.print("Fan Speed Three"); // print a simple message
       digitalWrite(relaypin1,HIGH);
       digitalWrite(relaypin2, HIGH);
      digitalWrite(relaypin3, LOW);
      digitalWrite(relaypin4, HIGH);
    }
  if (lcd_key == btnRIGHT)
  {
    // speed = 4
      LCDClear();
      lcd.setCursor(0,1);
      lcd.print("Fan Speed Four"); // print a simple message
       digitalWrite(relaypin1,HIGH);
       digitalWrite(relaypin2, HIGH);
      digitalWrite(relaypin3, HIGH);
      digitalWrite(relaypin4, LOW);
    }
  if (lcd_key == btnSELECT)
  {
        // speed = 0
      LCDClear();
      lcd.setCursor(0,1);
        lcd.print("Fan Stop"); // print a simple message
       digitalWrite(relaypin1,HIGH);
       digitalWrite(relaypin2, HIGH);
      digitalWrite(relaypin3, HIGH);
      digitalWrite(relaypin4, HIGH);
    }
 delay(250);
 }
 
 int read_LCD_buttons()
{
  adc_key_in = analogRead(lcdKeyPin); // read the value from the sensor 
  // my buttons when read are centered at these valies: 0, 144, 329, 504, 741
  // we add approx 50 to those values and check to see if we are close
  if (adc_key_in > 1000) return btnNONE; // We make this the 1st option for speed reasons since it will be the most likely result
  // For V1.1 us this threshold
  if (adc_key_in < 50) return btnRIGHT; 
  if (adc_key_in < 250) return btnUP; 
  if (adc_key_in < 450) return btnDOWN; 
  if (adc_key_in < 650) return btnLEFT; 
  if (adc_key_in < 850) return btnSELECT; 
  return btnNONE; // when all others fail, return this...
}

void LCDClear()
{
    lcd.begin(16, 2); // start the library
  lcd.setCursor(0,0);
  lcd.print("Ready"); // print a simple message

} 
