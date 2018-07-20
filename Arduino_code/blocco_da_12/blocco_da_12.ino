// 2018-07-11
// using an Arduino Leonardo and 12 SHARP GP1A58HRJ00F
// and a lot of custom PCBs!

// change this value to set one of the 4 blocks
const int block = 3;
// we are using 6 analog pins and 6 digital pins
const int pins[] = {18, 19, 20, 21, 22, 23, 2, 3, 4, 5, 6, 7};


struct sheet
{
  int pin;
  int id;
  bool state, prevState;
} sheets[12];


// serial stuff
bool bSendSerial = false;

// SETUP //////////////////////////////////////////////////////////
void setup() 
{
  Serial.begin(9600);


  // initialise all the sheets for the block
  for(int i=0; i<12; i++) 
  {
    // initialise the pin (pinMode)
    sheets[i].pin = pins[i];
    pinMode( sheets[i].pin, INPUT );
    // set the sheet id
    sheets[i].id = block*12 + i;
    // initialise the statuses
    sheets[i].state = true;
    sheets[i].prevState = true;
  }
  
}

// LOOP ///////////////////////////////////////////////////////////
void loop()
{

  // get data from serial port
  getSerialData();

  // get data from sensors
  for(int i=0; i<12; i++) 
  {
    sheets[i].state = digitalRead( sheets[i].pin );
    if( sheets[i].state != sheets[i].prevState )
    {
      if( bSendSerial )
      {
        // more verbose
        //Serial.print( "sheet " );
        //Serial.print( sheets[i].id );
        //Serial.print( ": " );
        //Serial.print( sheets[i].state );
        //Serial.println( ";" );

        Serial.print( sheets[i].id );
        Serial.print( "-" );
        Serial.print( sheets[i].state );
        Serial.println( ";" );
      }
      sheets[i].prevState = sheets[i].state;
    }
  }
  
  delay(25);
}

// SERIAL UTILITY /////////////////////////////////////////////////
void getSerialData()
{
  if(Serial.available()) 
  {
    char user_input = Serial.read(); 
      
    if (user_input =='1')  {
       bSendSerial = true;
    }
    else if(user_input =='0')  {
      bSendSerial = false;
    }
  }
}

