/// 2018-07-'4

const int FORK0 = A0;
const int FORK1 = A1;
const int FORK2 = A2;

const int  LED = 13;

int value = 0;


void setup() 
{
  Serial.begin(9600);
  
  pinMode(FORK0, INPUT);
  pinMode(FORK1, INPUT);
  pinMode(FORK2, INPUT);
}


void loop()
{

  Serial.print("[ ");
  //read fork 0  
  value = digitalRead(FORK0);
  Serial.print(value);Serial.print(" - ");

  //read fork 1 
  value = digitalRead(FORK1);
  Serial.print(value);Serial.print(" - ");

  //read fork 2 
  value = digitalRead(FORK2);
  Serial.print(value);Serial.println(" ]");
  
  delay(100);
}
