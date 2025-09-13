int SensorNo = 0;

// 센서 01
const int S1_EchoPin = 5;

long Duration = 0;
float Distance;
int i = 1;
int j = 0;

const float d = 500; //측정 딜레이 조정

void setup() {
  Serial.begin(9600);
  pinMode(S1_EchoPin, INPUT);
  
  Serial.println("CLEARDATA"); //데이터 리셋
  Serial.println("LABEL, No., SensorNo., Distance"); //엑셀 첫행 데이터 이름 설정
}

void loop() {
  SensorNo = 1;

    Distance = digitalRead(S1_EchoPin);

    Serial.print("DATA,"); //데이터 행에 데이터를 받음
    Serial.print(i++); // No. 데이터 출력
    Serial.print(","); // 구분자: ','
    Serial.print(SensorNo);
    Serial.print(","); // 구분자: ','
    Serial.println(Distance); // Distance 데이터 출력
    
    delay(d); //0.5초마다 측정
}