/*
 * This sketch is meant to work with a white LED
 * placed in front of a OSRAM SFH309 phototransistor.
 *
 * We are going to make the LED blink and measure the analogue
 * current from the ADC.
 *
 * # Connections
 * connect LED cathode to GND through a 70 Ohm resistor;
 * connect LED anode to Vcc (5V);
 * connect Phototransistor Collector to Vcc (5V);
 * connect Phototransistor Emitter to GND through a 620 KOhm resistor;
 * connect Arduino A0 pin to Phototransistor Emitter;
 */

const int PHOTO = A0;
bool ledState;

// hysteresis thresholds
int TH_HI = 300;
int TH_LOW = 150;

// filter stuff
float tmp=0.0, value=0.0;
float B, A = 0.125;


// SETUP ///////////////////////////////////////////////////
void setup()
{
  Serial.begin(9600);

  ledState = false;
  pinMode(13, OUTPUT);
  digitalWrite(13, ledState);
  B = 1.0 - A;  
}


// LOOP ////////////////////////////////////////////////////
void loop()
{
  tmp = analogRead(PHOTO);
  // filter out spourious values
  value = A*tmp + B*value;
  Serial.print(value);Serial.println("\t");

  // 5 volts / 1024 ADC levels of quantization =>
  // each step measure 4.88 mV;
  // We are using a 100K resistor so, on the phototransitor
  // is flowing a current of (value*4.88mV)/100K (mA)
  //float current = value*4.88 / 100000;
  //Serial.println( current );

  /*
  // send data to vvvv/Processing
  if(value > TH_HI)
  {
    //Serial.println(1);
    Serial.write(1);
  }
  else if(value < TH_LOW)
  {
    //Serial.println(0);
    Serial.write(0);
  }
  */
  

  delay(10);
}
