// 센서 3개 연결
// 반복문 사용해서 1, 2, 3번 센서에서 iter개씩 데이터 받아옴
int SensorNo = 0;

//센서
const int S1 = 5;
const int S2 = 9;
const int S3 = 11;

// 기타변수, 반복자
float Distance = 0;
int i = 1;
int j = 0;

//측정 딜레이 조정
const float d = 250;

//반복횟수 조정
const int iter = 50;

// 디지털로 신호 받을지
//bool digit = false;
bool digit = true;

void setup() {
  Serial.begin(9600);
  
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  
  Serial.println("CLEARDATA"); //데이터 리셋
  Serial.println("LABEL, No., SensorNo., Distance"); //엑셀 첫행 데이터 이름 설정
}

void loop() {

  
  
  for (j=0; j<iter; j++) {
    SensorNo = 1;
    
    if (digit == true) {
      Distance = digitalRead(S1);
    } else {
      Distance = analogRead(S1);      
    }
    
    Serial.print("DATA,"); //데이터 행에 데이터를 받음
    Serial.print(i++); // No. 데이터 출력
    Serial.print(","); // 구분자: ','
    Serial.print(SensorNo);
    Serial.print(","); // 구분자: ','
    Serial.println(Distance); // Distance 데이터 출력
    
    delay(d); //0.5초마다 측정
  }

  for (j=0; j<iter; j++) {
    SensorNo = 2;
    
    if (digit == true) {
      Distance = digitalRead(S2);
    } else {
      Distance = analogRead(S2);
    }
    
    Serial.print("DATA,");
    Serial.print(i++);
    Serial.print(",");
    Serial.print(SensorNo);
    Serial.print(",");
    Serial.println(Distance);
    
    delay(d);
  }

  for (j=0; j<iter; j++) {
    SensorNo = 3;
    
    if (digit == true) {
      Distance = digitalRead(S3);
    } else {
      Distance = analogRead(S3);
    }
    
    Serial.print("DATA,");
    Serial.print(i++);
    Serial.print(",");
    Serial.print(SensorNo);
    Serial.print(",");
    Serial.println(Distance);
    
    delay(d);
  }
}