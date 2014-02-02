#include <Bounce.h>

#define buttonPin1 22
#define buttonPin2 24
#define buttonPin3 26
#define buttonPin4 28

#define relaypin1 32
#define relaypin2 34
#define relaypin3 36
#define relaypin4 38
Bounce btn1 = Bounce(buttonPin1,10 ); 
Bounce btn2 = Bounce(buttonPin2,10 ); 
Bounce btn3 = Bounce(buttonPin3,10 ); 
Bounce btn4 = Bounce(buttonPin4,10 ); 

void setup()
{
  pinMode(buttonPin1,INPUT) ;
  pinMode(buttonPin2,INPUT) ;
  pinMode(buttonPin3,INPUT) ;
  pinMode(buttonPin4,INPUT) ;
  pinMode(relaypin1,OUTPUT) ;
  pinMode(relaypin2,OUTPUT) ;
  pinMode(relaypin3,OUTPUT) ;
  pinMode(relaypin4,OUTPUT) ;

  Serial.begin(9600);
  Serial.println("program start here....");
}
void loop()
{
    btn1.update ( );
    btn2.update ( );
    btn3.update ( );
    btn4.update ( );
digitalWrite(relaypin1, btn1.read());
digitalWrite(relaypin2, btn2.read());
digitalWrite(relaypin3, btn3.read());
digitalWrite(relaypin4, btn4.read());

 delay(250);
 }
