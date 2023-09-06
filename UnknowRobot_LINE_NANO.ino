#define NUM_SENSORS 8  //จำนวนเซนเซอร์
uint8_t F_PIN[NUM_SENSORS] = { A7, A6, A5, A4, A3, A2, A1, A0 };
int F[NUM_SENSORS];
int REF[NUM_SENSORS];
int LastError;
///////////////////////////////////////////////////////////////////////////
int MinValue[NUM_SENSORS] = {57,52,47,39,50,50,57,51};
int MaxValue[NUM_SENSORS] = {834,675,639,603,783,650,656,534};
///////////////////////////////////////////////////////////////////////////

void setup() {
  Serial.begin(9600);
  digitalWrite(8, HIGH);
  pinMode(4, INPUT_PULLUP);
  // while(1){
  //   Serial.println(digitalRead(4));
  //   delay(50);
  // }


  OK();
  AutoRef();
  delay(500);
  //  SerialF();
  //  SerialCalibrate();
  //  ShowCalibrate();

  // Motor(100, -100);
  // delay(1000);
  // MotorStop();



  // TrackCross(100, 0.05, 0.5, 'r');
  // TrackCross(100, 0.05, 0.5, 'l');
  // TrackCross(100, 0.05, 0.5, 'r');
  // TrackCross(100, 0.05, 0.5, 'p');
  // TrackCross(100, 0.05, 0.5, 's');

  // TrackCross(120, 0.08, 0.9, 'p');
  // TrackCross(120, 0.05, 0.5, 's');
  // TrackCross(120, 0.05, 0.5, 'l');

  // ;


  TrackTime(120, 0.09, 0.5, 50);
  TrackTime(255, 0.09, 0.5, 550);
  TrackTime(150, 0.09, 0.5, 350);
  // TrackTime(255, 0.05, 0.5, 300);
  // TrackTime(120, 0.17, 0.8, 450);
  // TrackTime(255, 0.05, 0.5, 100);
  // TrackTime(120, 0.17, 0.8, 550);
  // TrackTime(250, 0.05, 0.5, 210);
  // TrackTime(140, 0.17, 0.8, 600);
  // TrackTime(230, 0.05, 0.5, 100);
  // TrackCross(120, 0.17, 0.8, 'r');
  // TrackCross(120, 0.17, 0.8, 'r');
  // TrackCross(120, 0.17, 0.8, 'l');
  // TrackTime(250, 0.05, 0.5, 150);
  // TrackTime(140, 0.17, 0.8, 600);
  // TrackTime(255, 0.05, 0.5, 100);
  // TrackCross(120, 0.18, 0.8, 'l');
  // TrackTime(255, 0.05, 0.5, 130);
  // TrackTime(120, 0.17, 0.8, 550);

  // TrackTime(120, 0.15, 0.8, 50);
  // TrackTime(255, 0.05, 0.6, 750);
  // TrackTime(120, 0.18, 0.8, 550);
  // TrackTime(255, 0.05, 0.5, 320);
  // TrackTime(120, 0.17, 0.8, 450);
  // TrackTime(255, 0.05, 0.5, 100);
  // TrackTime(120, 0.17, 0.8, 550);
  // TrackTime(250, 0.05, 0.5, 210);
  // TrackTime(140, 0.17, 0.8, 600);
  // TrackTime(230, 0.05, 0.5, 100);
  // TrackCross(120, 0.17, 0.8, 'r');
  // TrackCross(120, 0.17, 0.8, 'r');
  // TrackCross(120, 0.17, 0.8, 'l');
  // TrackTime(250, 0.05, 0.5, 150);
  // TrackTime(140, 0.17, 0.8, 600);
  // TrackTime(255, 0.05, 0.5, 100);
  // TrackCross(120, 0.18, 0.8, 'l');
  // TrackTime(255, 0.05, 0.5, 130);
  // TrackTime(120, 0.17, 0.8, 550);
  // TrackTime(255, 0.05, 0.5, 130);
  // TrackTime(120, 0.17, 0.8, 450);
  // TrackTime(255, 0.05, 0.5, 300);




  
  
}

void loop() {
  TrackTime(120, 0.1, 0.5, 700);
  // MotorStop();
}
