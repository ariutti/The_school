/*
 * This sketch is a test meant to work with 1
 * IR fork switch GP1A58HRJ00F.
 */

const int FORK = 8;
const int  LED = 13;

void setup() 
{
  Serial.begin(9600);
  
  // turn off this annoying LED
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  pinMode(FORK, INPUT);
}

void loop()
{
  int value = digitalRead(FORK);
  digitalWrite(LED, value);
  Serial.print(value);Serial.println();
  delay(10);
}
