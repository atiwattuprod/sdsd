int readPosition(int Track, int noise) { //อ่านค่า Position
  unsigned char i, online = 0;
  unsigned long avg = 0;
  unsigned int sum = 0;
  static int last_value = 0;
  ReadCalibrate();
  for (i = 0; i < NUM_SENSORS; i++) {
    int values = F[i];
    if (values > Track) {
      online = 1;
    }
    if (values > noise) {
      avg += (long)(values) * (i * 1000);
      sum += values;
    }
  }
  if (!online) {
    if (last_value < (NUM_SENSORS - 1) * 1000 / 2) {
      return 0;
    } else {
      return (NUM_SENSORS - 1) * 1000;
    }
  }
  last_value = avg / sum;
  return last_value;
}

void PID(int Speed, float Kp, float Kd) {  // คำสั่ง PID
  int Pos = readPosition(250, 50);
  int Error = Pos - 3500;
  int PID_Value = (Kp * Error) + (Kd * (Error - LastError));
  LastError = Error;
  int LeftPower = Speed + PID_Value;
  int RightPower = Speed - PID_Value;
  if (LeftPower > 255) LeftPower = 255;
  if (LeftPower < 0) LeftPower = -100;
  if (RightPower > 255) RightPower = 255;
  if (RightPower < 0) RightPower = -100;
  Motor(LeftPower, RightPower);
}

void TrackCross(int Speed, float Kp, float Kd, char select) { // PID เช็คแยก
  while (1) {
    PID(Speed, Kp, Kd);
    ReadCalibrate();
    if (F[1] > 550 && F[6] > 550) {
    break;
  }
}

if (select == 's') {
    MotorStop();
  } else if (select == 'p') {
    Motor(Speed, Speed);
    delay(100);
  } else if (select == 'l') {
    TurnLeft();
  } else if (select == 'r') {
    TurnRight();
  }
}

void TrackTime(int Speed, float Kp , float Kd, int TotalTime) { // Trackเส้นตามเวลาที่กำหนด
  unsigned long StartTime = millis();
  unsigned long EndTime   = StartTime + TotalTime;
  while (millis() <= EndTime) {
    PID(Speed, Kp, Kd);
  }
}
