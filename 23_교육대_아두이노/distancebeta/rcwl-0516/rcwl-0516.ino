// https://rockjjy.tistory.com/2803

#define Sensor 9

void setup() {

pinMode(Sensor,INPUT);
Serial.begin(9600);

}

void loop() {

Serial.println(digitalRead(Sensor));
//Serial.println(analogRead(Sensor));
delay(100);

}