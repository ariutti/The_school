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

const int LED = 2;
const int PHOTOT = A0;

long startTime;
bool ledState;

// SETUP ///////////////////////////////////////////////////
void setup()
{
  Serial.begin(9600);

  ledState = false;
  pinMode(LED, OUTPUT);
  digitalWrite(LED, ledState);

  startTime = millis();
}


// LOOP ////////////////////////////////////////////////////
void loop()
{
  if(millis()-startTime >= 1000)
  {
    startTime = millis();
    ledState = !ledState;
    digitalWrite(LED, ledState);
  }

  int value = analogRead(PHOTOT);
  Serial.print(value);Serial.print("\t");

  // 5 volts / 1024 ADC levels of quantization =>
  // each step measure 4.88 mV;
  // We are using a 100K resistor so, on the phototransitor
  // is flowing a current of (value*4.88mV)/100K (mA)

  float current = value*4.88 / 100000;
  Serial.println( current );

  delay(10);
}
