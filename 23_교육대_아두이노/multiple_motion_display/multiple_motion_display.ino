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

// 센서 02
const int S2 = 5;
const int S2_LED = 11;

// 센서 03
const int S3 = 9;
const int S3_LED = 12;



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
}


void loop() {
  
  if (digitalRead(S1) == motion) {
    digitalWrite(S1_LED, HIGH); }
  else {
    digitalWrite(S1_LED, LOW); }

  if (digitalRead(S2) == motion) {
    digitalWrite(S2_LED, HIGH); }
  else {
    digitalWrite(S2_LED, LOW); }

  if (digitalRead(S3) == motion) {
    digitalWrite(S3_LED, HIGH); }
  else {
    digitalWrite(S3_LED, LOW); }

  delay(d);
}