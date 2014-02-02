
#include <LiquidCrystal.h>
#include <IRremote.h>

#include <Wire.h>
#include "RTClib.h"

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
#define RECV_PIN 11

IRrecv irrecv(RECV_PIN);
decode_results results;
long IR_key = -1;

LiquidCrystal lcd(lcdRS, lcdEnable, lcdD4, lcdD5, lcdD6, lcdD7);  //　　產生LCD　元件

RTC_DS1307 RTC;

void setup()
{
  LCDClear();
  pinMode(relaypin1,OUTPUT) ;
  pinMode(relaypin2,OUTPUT) ;
  pinMode(relaypin3,OUTPUT) ;
  pinMode(relaypin4,OUTPUT) ;
  
   irrecv.enableIRIn(); // Start the receiver
  //pinMode(RECV_PIN,INPUT) ;
    Wire.begin();
    RTC.begin();
    
       digitalWrite(relaypin1,HIGH);
       digitalWrite(relaypin2, HIGH);
      digitalWrite(relaypin3, HIGH);
      digitalWrite(relaypin4, HIGH);
  LCDClear();

  Serial.begin(9600);
  Serial.println("program start here....");
}
void loop()
{
   showtime();
  lcd_key = read_LCD_buttons(); // read the buttons
  IR_key = IRcheck() ;
  if ((lcd_key == btnLEFT) or (IR_key == 1))
  {
    // speed = 1
      LCDClear();
      lcd.setCursor(0,1);
      lcd.print("Fan Speed one"); // print a simple message
       digitalWrite(relaypin1,LOW);
       digitalWrite(relaypin2, HIGH);
      digitalWrite(relaypin3, HIGH);
      digitalWrite(relaypin4, HIGH);
      Serial.println("fan speed set to One");
    }
  if ((lcd_key == btnUP) or (IR_key == 2))
  {
    // speed = 2
      LCDClear();
      lcd.setCursor(0,1);
      lcd.print("Fan Speed Two"); // print a simple message
       digitalWrite(relaypin1,HIGH);
       digitalWrite(relaypin2, LOW);
      digitalWrite(relaypin3, HIGH);
      digitalWrite(relaypin4, HIGH);
      Serial.println("fan speed set to Two");
    }
  if ((lcd_key == btnDOWN) or (IR_key == 3))
  {
    // speed = 3
      LCDClear();
      lcd.setCursor(0,1);
      lcd.print("Fan Speed Three"); // print a simple message
       digitalWrite(relaypin1,HIGH);
       digitalWrite(relaypin2, HIGH);
      digitalWrite(relaypin3, LOW);
      digitalWrite(relaypin4, HIGH);
      Serial.println("fan speed set to Three");
    }
  if ((lcd_key == btnRIGHT) or (IR_key == 4))
  {
    // speed = 4
      LCDClear();
      lcd.setCursor(0,1);
      lcd.print("Fan Speed Four"); // print a simple message
       digitalWrite(relaypin1,HIGH);
       digitalWrite(relaypin2, HIGH);
      digitalWrite(relaypin3, HIGH);
      digitalWrite(relaypin4, LOW);
      Serial.println("fan speed set to Four");
    }
  if ((lcd_key == btnSELECT) or (IR_key == 0))
  {
        // speed = 0
      LCDClear();
      lcd.setCursor(0,1);
        lcd.print("Fan Stop"); // print a simple message
       digitalWrite(relaypin1,HIGH);
       digitalWrite(relaypin2, HIGH);
      digitalWrite(relaypin3, HIGH);
      digitalWrite(relaypin4, HIGH);
      Serial.println("fan speed set to Stop");
    }
 delay(1000);
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
    showtime();
} 

long  IRcheck()
{
  // irrecv.enableIRIn(); // Start the receiver
  long tmp = -2 ;
    if (irrecv.decode(&results)) {
//    Serial.println(results.value, HEX);
 //   dump(&results);
       tmp = IRencode(&results) ;
    irrecv.resume(); // Receive the next value
    return (tmp) ;
   
  }
  else
  {
    irrecv.resume(); // Receive the next value
    return (tmp);
  }
} 
long IRencode(decode_results *code)
{
  long encodeno = -1 ;
  long   cc = code->value ; 
  switch (cc)
  {
   case 16738455 :   // for button "0" code
     encodeno = 0 ;   
       break ;
       
   case 16724175 :    // for button "1" code
     encodeno = 1 ;
       break ;
       
   case 16718055 :    // for button "2" code
     encodeno = 2 ;
       break ;
       
   case 16743045 :    // for button "3" code
     encodeno = 3 ;
       break ;
       
   case 16716015 :    // for button "4" code
     encodeno = 4 ;
       break ;
  default:
     encodeno = cc ;
  
  }
  return (encodeno) ;
  
} 

void showtime()
{
  lcd.setCursor(0,0);
  lcd.print(gettime()); // print a simple message
  
}  
String gettime()
{
    String tmp ="";
      DateTime now = RTC.now();
    tmp.concat(now.hour());
    tmp.concat(':');
    tmp.concat(now.minute());
    tmp.concat(':');
    tmp.concat(now.second());
    tmp.concat("   ");
    return   tmp ;
} 
String getdate()
{
    String tmp ="";
      DateTime now = RTC.now();
      tmp.concat(now.year()) ;
      tmp.concat('/') ;
    tmp.concat(now.month());
    tmp.concat('/');
    tmp.concat(now.day());
    return   tmp ;
} 
