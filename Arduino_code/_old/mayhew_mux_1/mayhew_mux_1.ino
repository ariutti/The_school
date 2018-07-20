/*
 * a sketch to be used with the 
 * Mayhew Labs Mux Shield.
 */

bool value = 0;
uint8_t sensorIdx = 0;

// SETUP //////////////////////////////////////////////
void setup() 
{
  Serial.begin(9600);
  for(int i=0; i<4; i++)
  {
    pinMode(i+2, OUTPUT);
    digitalWrite(i+2, LOW);
  }
}

// DRAW ///////////////////////////////////////////////
void loop() 
{
  // scan all the 16 available input for the muxs
  for(int i=0; i<16; i++)
  {
    // set the address of the pin we want to read
    // using the 4 S# pins
    for(int j=0; j<4; j++)
    {
      digitalWrite(j+2, (i>>j) & B00000001);
    }
    
    // read the output of each mux 
    // from the three S# pins
    for(int m=0; m<3; m++)
    {
      sensorIdx = 16*m +i;
      if(sensorIdx == 0 || sensorIdx == 16 || sensorIdx == 32)
      {
        // we can use digital read on analog pins too
        value = digitalRead(m+18); //anlog pin A0 on Leonard has number 18th
        Serial.print("id ");Serial.print(16*m+i);
        Serial.print(" - ");Serial.print(value);Serial.print("\t");
      }
    }
  }
  Serial.println();
}
