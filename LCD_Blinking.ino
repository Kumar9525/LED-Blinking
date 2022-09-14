/*
 * SerialReceive sketch
 * Blink the LED at a rate proportional to the received digit value
*/
const int ledPin = 13; // pin the LED is connected to
const int ledPin1 = 11;
const int ledPin2 = 12;
int   blinkRate=0;     // blink rate stored in this variable

void setup()
{
  Serial.begin(9600); // Initialize serial port to send and receive at 9600 baud
  pinMode(ledPin, OUTPUT); // set this pin as output
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop()
{
  if ( Serial.available()) // Check to see if at least one character is available
  {
    char ch = Serial.read();
    if(ch >= '0' && ch <= '9') // is this an ascii digit between 0 and 9?
    {
       blinkRate = (ch - '0');      // ASCII value converted to numeric value
       blinkRate = blinkRate * 100; // actual blinkrate is 100 mS times received
    }
  }
  blink();
}

// blink the LED with the on and off times determined by blinkRate
void blink()
{
  digitalWrite(ledPin,HIGH);
  delay(blinkRate); // delay depends on blinkrate value
  digitalWrite(ledPin,LOW);
  delay(blinkRate);
  digitalWrite(ledPin1,HIGH);
  delay(blinkRate); // delay depends on blinkrate value
  digitalWrite(ledPin1,LOW);
  delay(blinkRate);
  digitalWrite(ledPin2,HIGH);
  delay(blinkRate); // delay depends on blinkrate value
  digitalWrite(ledPin2,LOW);
  delay(blinkRate);
}
