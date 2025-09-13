// 센서 3개 연결
// 1, 2, 3번 센서 데이터 각각 Sensor1, Sensor2, Sensor3 열에 출력

/**************************configuration*******************************/

/* 모드 선택 */
//const int mode = 0;  // Trig/Echo 핀이 있는 센서일 때 (Trig/Echo)
const int mode = 1;  // Trig/Echo 핀 없이 Output 핀만 있는 센서일 때 (Auto)

/* 모드가 1(Auto)일 때, 디지털로 신호 받을지 선택 */
//bool digit = false;
bool digit = true;

// 측정 딜레이 설정
const float d = 100; //측정 딜레이 조정

/***********************************************************************/

// 센서 01
const int S1_TriggerPin = 2;
const int S1_EchoPin = 3;
long S1_Duration = 0;
float S1_Distance = 0;

// 센서 02
const int S2_TriggerPin = 4;
const int S2_EchoPin = 5;
long S2_Duration = 0;
float S2_Distance = 0;

// 센서 03
const int S3_TriggerPin = 8;
const int S3_EchoPin = 9;
long S3_Duration = 0;
float S3_Distance = 0;

// No. 컬럼 데이터(카운팅)
int i = 1;


void setup() {
  Serial.begin(9600);
  
  if (mode == 0) {
    // 모드 0 (Trig/Echo)
    pinMode(S1_TriggerPin, OUTPUT);
    pinMode(S2_TriggerPin, OUTPUT);
    pinMode(S3_TriggerPin, OUTPUT);
    pinMode(S1_EchoPin, INPUT);
    pinMode(S2_EchoPin, INPUT);
    pinMode(S3_EchoPin, INPUT);
  } else if (mode == 1) {
    // 모드 1 (Auto)
    pinMode(S1_EchoPin, INPUT);
    pinMode(S2_EchoPin, INPUT);
    pinMode(S3_EchoPin, INPUT);
  }
  
  Serial.println("CLEARDATA");  // 데이터 리셋
  Serial.println("LABEL, No., Sensor1, Sensor2, Sensor3");  // 엑셀 첫 행 데이터 이름 설정
}


void loop() {
  // 모드 0 (Trig/Echo)
  if (mode == 0) {
    // S1
      // 0.015초짜리 펄스 생성(Trigger)
    digitalWrite(S1_TriggerPin, HIGH);
    delay(15); 
    digitalWrite(S1_TriggerPin, LOW);
      // 되돌아오는 신호 받아서 Distance에 저장 (Echo)
    S1_Duration = pulseIn(S1_EchoPin, HIGH);
    S1_Distance = ((340 * S1_Duration) / 10000) / 2;

    // S2
    digitalWrite(S2_TriggerPin, HIGH); 
    delay(15); 
    digitalWrite(S2_TriggerPin, LOW);
    S2_Duration = pulseIn(S2_EchoPin, HIGH);
    S2_Distance = ((340 * S2_Duration) / 10000) / 2;

    // S3
    digitalWrite(S3_TriggerPin, HIGH); 
    delay(15); 
    digitalWrite(S3_TriggerPin, LOW);
    S3_Duration = pulseIn(S3_EchoPin, HIGH);
    S3_Distance = ((340 * S3_Duration) / 10000) / 2;

    //출력
    Serial.print("DATA,");         //데이터 행에 데이터를 받음
      Serial.print(i++);           // No. 데이터 출력
      Serial.print(",");           // 구분자: ','
      Serial.print(S1_Distance);   // S1
      Serial.print(",");
      Serial.print(S2_Distance);   // S2
      Serial.print(",");
      Serial.println(S3_Distance); // S3
      
      delay(d);  // 측정 딜레이
  }
  
  // 모드 1 (Auto)
  else if (mode == 1) {
    if (digit == true) {
      // 디지털 신호 읽어옴
      S1_Distance = digitalRead(S1_TriggerPin);
      S2_Distance = digitalRead(S2_TriggerPin);
      S3_Distance = digitalRead(S3_TriggerPin);
    } else {
      // 아날로그 신호 읽어옴
      S1_Distance = analogRead(S1_TriggerPin);
      S2_Distance = analogRead(S2_TriggerPin);
      S3_Distance = analogRead(S3_TriggerPin);    
    }

    // 출력
    Serial.print("DATA,");      // 데이터 행에 데이터를 받음
    Serial.print(i++);          // No. 데이터 출력
    Serial.print(",");          // 구분자: ','
    Serial.print(S1_Distance);  // S1
    Serial.print(",");
    Serial.print(S2_Distance);  // S2
    Serial.print(",");
    Serial.println(S3_Distance);  // S3
    
    delay(d);
  }
}