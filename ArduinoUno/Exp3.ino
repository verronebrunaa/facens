// C++ code
//
void setup()
{
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
  digitalWrite(12, HIGH);
  digitalWrite(6, HIGH);
  delay(1000); 
  digitalWrite(12, LOW);
  digitalWrite(6, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(7, HIGH);
  delay(1000); 
  digitalWrite(10, LOW);
  digitalWrite(7, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(5, HIGH);
  delay(1000);
  digitalWrite(11, LOW);
  digitalWrite(5, LOW);
  delay(500);
}
