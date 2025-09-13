// 센서 3개 연결
// 반복문 사용해서 1, 2, 3번 센서에서 10개씩 데이터 받아옴
int SensorNo = 0;

// 센서 01
const int S1_TriggerPin = 4;
const int S1_EchoPin = 5;

// 센서 02
const int S2_TriggerPin = 8;
const int S2_EchoPin = 9;

// 센서 03
const int S3_TriggerPin = 10;
const int S3_EchoPin = 11;

long Duration = 0;
float Distance;
int i = 1;
int j = 0;

const float d = 500; //측정 딜레이 조정

void setup() {
  Serial.begin(9600);
  
  pinMode(S1_TriggerPin, OUTPUT);
  pinMode(S2_TriggerPin, OUTPUT);
  pinMode(S3_TriggerPin, OUTPUT);
  pinMode(S1_EchoPin, INPUT);
  pinMode(S2_EchoPin, INPUT);
  pinMode(S3_EchoPin, INPUT);
  
  Serial.println("CLEARDATA"); //데이터 리셋
  Serial.println("LABEL, No., SensorNo., Distance"); //엑셀 첫행 데이터 이름 설정
}

void loop() {

  
  
  for (j=0; j<10; j++) {
    SensorNo = 1;

    digitalWrite(S1_TriggerPin, HIGH); 
    delay(15); 
    digitalWrite(S1_TriggerPin, LOW);

    Duration = pulseIn(S1_EchoPin, HIGH);
    Distance = ((340 * Duration) / 10000) / 2;
    
    Serial.print("DATA,"); //데이터 행에 데이터를 받음
    Serial.print(i++); // No. 데이터 출력
    Serial.print(","); // 구분자: ','
    Serial.print(SensorNo);
    Serial.print(","); // 구분자: ','
    Serial.println(Distance); // Distance 데이터 출력
    
    delay(d); //0.5초마다 측정
  }

  for (j=0; j<10; j++) {
    SensorNo = 2;
    
    digitalWrite(S2_TriggerPin, HIGH); 
    delay(15); 
    digitalWrite(S2_TriggerPin, LOW);

    Duration = pulseIn(S2_EchoPin, HIGH);
    Distance = ((340 * Duration) / 10000) / 2;
    
    Serial.print("DATA,");
    Serial.print(i++);
    Serial.print(",");
    Serial.print(SensorNo);
    Serial.print(",");
    Serial.println(Distance);
    
    delay(d);
  }

  for (j=0; j<10; j++) {
    SensorNo = 3;
    
    digitalWrite(S3_TriggerPin, HIGH); 
    delay(15); 
    digitalWrite(S3_TriggerPin, LOW);

    Duration = pulseIn(S3_EchoPin, HIGH);
    Distance = ((340 * Duration) / 10000) / 2;
    
    Serial.print("DATA,");
    Serial.print(i++);
    Serial.print(",");
    Serial.print(SensorNo);
    Serial.print(",");
    Serial.println(Distance);
    
    delay(d);
  }
}