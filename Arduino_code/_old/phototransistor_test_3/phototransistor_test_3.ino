/*
 * This sketch has been created in order to work with the
 * shool protototype version 2.
 * This version of the prototype uses two sheets instead of only one.
 * The electronics is made of:
 *  - 2x Optek OPB815L optical switches
 *  - 2x 220 Ohm resistors
 *  - 2x 1KOhm resistors
 */

const int SHEET0 = A0;
const int SHEET1 = A1;
bool sheet0_status, sheet1_status;

const int DELAY_TIME = 10;

// hysteresis thresholds
int TH_HI = 500;
int TH_LOW = 150;

// filter stuff
float tmp=0.0, value0=0.0, value1=0.0;
float B, A = 0.125;

// SETUP ///////////////////////////////////////////////////
void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  B = 1.0 - A;  
  sheet0_status = false;
  sheet1_status = false;
}

// LOOP ////////////////////////////////////////////////////
void loop()
{
  tmp = analogRead(SHEET0);
  // filter out spourious values
  value0 = A*tmp + B*value0;
  //Serial.print(value0);Serial.print("\t");
  tmp = analogRead(SHEET1);
  // filter out spourious values
  value1 = A*tmp + B*value1;
  //Serial.print(value1);Serial.println("\t");

  // 5 volts / 1024 ADC levels of quantization =>
  // each step measure 4.88 mV;
  // We are using a 1K resistor so, on the phototransitor
  // is flowing a current of (value*4.88mV)/1K (mA)
  //float current = value*4.88 / 1000;
  //Serial.println( current );

  // send data to vvvv/Processing
  if(value0 > TH_HI)
  {
    //Serial.print(0); Serial.print(" ");
    //Serial.println(1);
    //Serial.write(0);
    //Serial.write(1);
    sheet0_status = true;
  }
  else if(value0 < TH_LOW)
  {
    //Serial.print(0); Serial.print(" ");
    //Serial.println(0);
    //Serial.write(0);
    //Serial.write(0);
    sheet0_status = false;
  }

  // send data to vvvv/Processing
  if(value1 > TH_HI)
  {
    //Serial.print(1); Serial.print(" ");
    //Serial.println(1);
    //Serial.write(1);
    //Serial.write(1);
    sheet1_status = true;
  }
  else if(value1 < TH_LOW)
  {
    //Serial.print(1); Serial.print(" ");
    //Serial.println(0);
    //Serial.write(1);
    //Serial.write(0);
    sheet1_status = false;
  }

  Serial.print(sheet0_status); Serial.print(sheet1_status); Serial.println();

  delay(DELAY_TIME);
}
