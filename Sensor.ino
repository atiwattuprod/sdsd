void ReadSensor() {  //ค่าดิบ
  for (int _sensor = 0; _sensor < NUM_SENSORS; _sensor++) {
    F[_sensor] = analogRead(F_PIN[_sensor]);
  }
}

void ReadCalibrate() {  //ค่าที่ Calibrate แล้ว
  ReadSensor();
  for (int i = 0; i < NUM_SENSORS; i++) {
    unsigned int calmin, calmax;
    long x = 0;
    calmax = MinValue[i];
    calmin = MaxValue[i];
    x = map(F[i], calmin, calmax, 0, 1000);
    if (x < 0) x = 0;
    if (x > 1000) x = 1000;
    F[i] = x;
  }
}


void CalibrateSensor(int pauseTime, int samples) {
  for (int i = 0; i < NUM_SENSORS; i++) {
    MinValue[i] = 1023;
    MaxValue[i] = 0;
  }
  for (int startSamp = 0; startSamp <= samples; startSamp++) {
    ReadSensor();
    for (int i = 0; i < NUM_SENSORS; i++) {
      MinValue[i] = (F[i] <= MinValue[i] ? F[i] : MinValue[i]);
      MaxValue[i] = (F[i] >= MaxValue[i] ? F[i] : MaxValue[i]);
    }
    delay(pauseTime);
  }
}

void ShowCalibrate() {  // Calibrate ค่าแสง
  Serial.println("Press OK to Start Calibrate Sensor");
  OK();
  Serial.println("Calibrating...");
  CalibrateSensor(20, 250);
  Serial.println("Finish");
  Serial.println("  ");

  Serial.print("int MinValue[NUM_SENSORS] = {");
  for (int i = 0; i < NUM_SENSORS; i++) {
    Serial.print(MinValue[i]);
    if (i < NUM_SENSORS - 1) Serial.print(",");
    else Serial.println("};");
  }

  Serial.print("int MaxValue[NUM_SENSORS] = {");
  for (int i = 0; i < NUM_SENSORS; i++) {
    Serial.print(MaxValue[i]);
    if (i < NUM_SENSORS - 1) Serial.print(",");
    else Serial.println("};");
  }
  while (1)
    ;
}


void SerialF() {
  while (1) {
    ReadSensor();
    for (int _serialF = 0; _serialF < NUM_SENSORS; _serialF++) {
      Serial.print(F[_serialF]);
      Serial.print("\t");
    }
    Serial.println("");
    delay(50);
  }
}

void SerialCalibrate() {
  while (1) {
    ReadCalibrate();
    for (int _serialF = 0; _serialF < NUM_SENSORS; _serialF++) {
      Serial.print(F[_serialF]);
      Serial.print("\t");
    }
    Serial.println("");
    delay(50);
  }
}

void AutoRef() {
  for (int i = 0; i < NUM_SENSORS; i++) {
    REF[i] = (MinValue[i] + MaxValue[i]) / 2;
  }
}


void OK() {
  while (1) {
    if (digitalRead(4) == 0){
      break;
    }
  }
}