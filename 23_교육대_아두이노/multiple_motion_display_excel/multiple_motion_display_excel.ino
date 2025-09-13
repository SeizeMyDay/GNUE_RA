// 센서 3개 연결
// 디지털 신호 받음
// 각각의 센서에서 모션 감지 시 LED  출력


/* 센서가 모션 감지됐을 때 0 출력하면 0, 1 출력하면 1 */
/* 모션 감지 시
 * 0 출력하는 센서: D80NK
 * 1 출력하는 센서: RCWL-0516, PIR
 */
//const int motion = 0;
//const int motion = 1;
int motion = 1;

/* 스위치, 연결되면 motion = 0, 연결 안 되면 motion = 1 */
/* 스위치 안 쓸 거면 주석처리 */
const int MotionSwitch = 13; 


/* 측정 딜레이 설정 */
const float d = 100;

// 센서 01
const int S1 = 3;
const int S1_LED = 10;
int S1_Motion = 0;

// 센서 02
const int S2 = 5;
const int S2_LED = 11;
int S2_Motion = 0;

// 센서 03
const int S3 = 9;
const int S3_LED = 12;
int S3_Motion = 0;

// cnt
int i = 0;

void setup() {
  Serial.begin(9600);

  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);

  pinMode(S1_LED, OUTPUT);
  pinMode(S2_LED, OUTPUT);
  pinMode(S3_LED, OUTPUT);

  pinMode(MotionSwitch, INPUT_PULLUP);

  if (digitalRead(MotionSwitch) == HIGH) {
    motion = 1;
  } else {
    motion = 0;
  }

  Serial.println("CLEARDATA");  // 데이터 리셋
  Serial.println("LABEL, No., Sensor1, Sensor2, Sensor3");  // 엑셀 첫 행 데이터 이름 설정
}


void loop() {
  S1_Motion = digitalRead(S1);
  S2_Motion = digitalRead(S2);
  S3_Motion = digitalRead(S3);

  if (S1_Motion == motion) {
    digitalWrite(S1_LED, HIGH); }
  else {
    digitalWrite(S1_LED, LOW); }

  if (S2_Motion == motion) {
    digitalWrite(S2_LED, HIGH); }
  else {
    digitalWrite(S2_LED, LOW); }

  if (S3_Motion == motion) {
    digitalWrite(S3_LED, HIGH); }
  else {
    digitalWrite(S3_LED, LOW); }

  // 출력
  Serial.print("DATA,");      // 데이터 행에 데이터를 받음
  Serial.print(i++);          // No. 데이터 출력
  Serial.print(",");          // 구분자: ','
  Serial.print(S1_Motion);  // S1
  Serial.print(",");
  Serial.print(S2_Motion);  // S2
  Serial.print(",");
  Serial.println(S3_Motion);  // S3

  delay(d);
}