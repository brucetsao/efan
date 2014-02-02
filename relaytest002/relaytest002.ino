#define buttonPin1 22
#define buttonPin2 24
#define buttonPin3 26
#define buttonPin4 28

#define relaypin1 32
#define relaypin2 34
#define relaypin3 36
#define relaypin4 38
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
if (digitalRead(buttonPin1)==LOW)
{
      digitalWrite(relaypin1,LOW);
}
else
{
      digitalWrite(relaypin1,HIGH);
}

if (digitalRead(buttonPin2)==LOW)
{
      digitalWrite(relaypin2,LOW);
}
else
{
      digitalWrite(relaypin2,HIGH);
}

if (digitalRead(buttonPin3)==LOW)
{
      digitalWrite(relaypin3,LOW);
}
else
{
      digitalWrite(relaypin3,HIGH);
}

if (digitalRead(buttonPin4)==LOW)
{
      digitalWrite(relaypin4,LOW);
}
else
{
      digitalWrite(relaypin4,HIGH);
}
 delay(250);
 }
