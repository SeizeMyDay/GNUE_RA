const int Sens = 3;
float distance = 0;
int i = 0;
const float d = 200;

//bool digit = False;
bool digit = true;

void setup() {

  pinMode(Sens,INPUT);
  Serial.begin(9600);

  Serial.println("CLEARDATA");
  Serial.println("LABEL, NO., Distance");

}

void loop() {
  if (digit == true) {
    distance = digitalRead(Sens);
  } else {
    distance = analogRead(Sens);
  }

  Serial.print("DATA, ");
  Serial.print(i++);
  Serial.print(",");
  Serial.println(distance);
  delay(d);

}