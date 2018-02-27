/*
 * This sketch is meant to work with 2 
 * IR fork switch GP1A51HRJ00F.
 * Connect them one near the other in 
 * order to create a sort of two channel encoder.
 */

const int chA = 2;
const int chB = 3;

void setup() 
{
  Serial.begin(9600);
  
  // turn off this annoying LED
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

void loop()
{
  uint8_t statusA = digitalRead(chA);
  uint8_t statusB = digitalRead(chB);

  Serial.print(statusA);Serial.print(" - ");Serial.println(statusB);
  delay(100);
}
