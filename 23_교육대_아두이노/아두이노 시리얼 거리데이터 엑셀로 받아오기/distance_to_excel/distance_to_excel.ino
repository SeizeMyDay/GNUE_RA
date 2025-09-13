const int TriggerPin = 8;
const int EchoPin = 9;
long Duration = 0;
float Distance;
int i = 1;

const float d = 500; //측정 딜레이 조정

void setup() {
  Serial.begin(9600);
  
  pinMode(TriggerPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  
  Serial.println("CLEARDATA"); //데이터 리셋
  Serial.println("LABEL, No., Distance"); //엑셀 첫행 데이터 이름 설정
}

void loop() {
  digitalWrite(TriggerPin, HIGH); 
  delay(15); 
  digitalWrite(TriggerPin, LOW);
  
  //0.015초 자리 초음파 펄스를 발생시킨다
  Duration = pulseIn(EchoPin, HIGH);
  Distance = ((340 * Duration) / 10000) / 2;
  
  Serial.print("DATA,"); //데이터 행에 데이터를 받음
  Serial.print(i++); // No. 데이터 출력
  Serial.print(","); // 구분자: ','
  Serial.println(Distance); // Distance 데이터 출력
  
  delay(d); //0.5초마다 측정
}