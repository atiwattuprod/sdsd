#define PWMA 6   //PWM Motor 1
#define AIN1 10  //Direction Motor 1
#define AIN2 9   //Direction2 Motor 1

#define PWMB 5   //PWM Motor 2
#define BIN1 11  //Direction Motor2
#define BIN2 7   //Direction2 Motor2

void Motor1(int speedmotor1) {  // Control Motor 1
  bool dir1 = (speedmotor1 >= 0 ? true : false);
  speedmotor1 = abs(speedmotor1);
  if (speedmotor1 > 255) {
    speedmotor1 = 255;
  }
  digitalWrite(AIN1, dir1);
  digitalWrite(AIN2, !dir1);
  analogWrite(PWMA, speedmotor1);
}

void Motor2(int speedmotor2) {  // Control Motor 2
  bool dir2 = (speedmotor2 >= 0 ? true : false);
  speedmotor2 = abs(speedmotor2);
  if (speedmotor2 > 255) {
    speedmotor2 = 255;
  }
  digitalWrite(BIN1, dir2);
  digitalWrite(BIN2, !dir2);
  analogWrite(PWMB, speedmotor2);
}

void Motor(int LeftSpd, int RightSpd) {
  Motor1(LeftSpd);
  Motor2(RightSpd);
}

void MotorStop() {
  analogWrite(PWMA, 0);
  analogWrite(PWMB, 0);
  delay(10);
}
