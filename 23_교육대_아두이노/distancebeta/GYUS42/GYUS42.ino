
const int S1_TriggerPin = 4;
const int S1_EchoPin = 5;

long Duration = 0;
float Distance;

const float d = 500; //측정 딜레이 조정
int i = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(S1_TriggerPin, OUTPUT);
  pinMode(S1_EchoPin, INPUT);

  Serial.println("CLEARDATA"); //데이터 리셋
  Serial.println("LABEL, No., Distance"); //엑셀 첫행 데이터 이름 설정
}

void loop() {

  digitalWrite(S1_TriggerPin, HIGH); 
  delay(15); 
  digitalWrite(S1_TriggerPin, LOW);
 
  Duration = pulseIn(S1_EchoPin, HIGH);
  //Distance = ((340 * Duration) / 10000) / 2;
  //Duration = analogRead(S1_EchoPin);
  Distance = Duration;
    
  Serial.print("DATA,"); //데이터 행에 데이터를 받음
  Serial.print(i++); // No. 데이터 출력
  Serial.print(","); // 구분자: ','
  Serial.println(Distance); // Distance 데이터 출력
  
  delay(d); //0.5초마다 측정

}