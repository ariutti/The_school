import processing.serial.*;
Serial myPort;
boolean raised = false;

// SETUP //////////////////////////////////
void setup()
{
  size(200, 200);
  //printArray(Serial.list());
  String port = Serial.list()[3];
  myPort = new Serial(this, port, 9600);
}

// DRAW ///////////////////////////////////
void draw()
{
  background(255);
  pushStyle();
  if(raised)
    fill(255, 0, 0);
  else
    noFill();
  noStroke();
  rect(0, 0, width, height);
  popStyle();
}

// SERIAL EVENT ///////////////////////////
void serialEvent(Serial s)
{
  int v = s.read();
  if(v == 1)
    raised = true;
  else if (v == 0)
    raised = false;
}