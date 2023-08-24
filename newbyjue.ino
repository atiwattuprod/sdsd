// #define PINBUZZER  10
// #define PINBOTON  11

// int base = 225;
// int maxspeed = 250;
// float Kprop = 4.5887;
// float Kderiv = 11.95;
// float Kinte = 0.0001;

int base = 200; 
int maxspeed = 250;
float Kprop = 3.347;
float Kderiv = 10.55;
float Kinte = 0.0001;
int pos;
int x = 0;
int FLsensor = 2;
int FRsensor = 12;

// int base = 200;
// int maxspeed = 250;
// float Kprop = 4.547;
// float Kderiv = 10.55;
// float Kinte = 0.0001;
// int pos;
// int x = 0;

//short
// int base = 230;  
// int maxspeed = 250; 
// float Kprop = 5.188;
// float Kderiv = 18.288;
// float Kinte = 0.0001;

////
// int base = 230;  
// int maxspeed = 250; 
// float Kprop = 5.187;
// float Kderiv = 18.28;
// float Kinte = 0.0001;
//////  

// int base = 250;
// int maxspeed = 250; 
// float Kprop = 6.187;
// float Kderiv = 18.98;
// float Kinte = 0.0001;

// int pos;
// int x = 0;
// long
#define AIN1 8  // pin 1 de dirección del Motor Izquierdo
#define AIN2 9  // pin 2 de dirección del Motor Izquierdo
#define PWMA 5  // pin PWM del Motor Izquierdo


#define BIN1 4  // pin 1 de dirección del Motor Derecho
#define BIN2 7  // pin 2 de dirección del Motor Derecho
#define PWMB 6  // pin PWM del Motor Derecho

#define STBY 3

//short
// #define AIN1 9  // pin 1 de dirección del Motor Izquierdo
// #define AIN2 10  // pin 2 de dirección del Motor Izquierdo
// #define PWMA 11  // pin PWM del Motor Izquierdo


// #define BIN1 7  // pin 1 de dirección del Motor Derecho
// #define BIN2 6  // pin 2 de dirección del Motor Derecho
// #define PWMB 5  // pin PWM del Motor Derecho
// #define STBY 8 





void setup() {
  Serial.begin(115200);
  pinMode(13, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(FLsensor , INPUT);
  pinMode(FRsensor , INPUT);

  digitalWrite(13, LOW);
  Motores(0, 0);
  //  WaitBoton();
  digitalWrite(13, HIGH);
  //  Peripherals_init();
  TB6612FNG_init();

  delay(1000);
  calibracion();

  digitalWrite(13, LOW);
}


void loop() {
// while(analogRead(A0) == 100 && analogRead(A7) == 100){
//   int line_position = GetPos();
//   int Correction_power = PIDLambo(line_position, Kprop, Kderiv, Kinte);
//   int leftSpeed = base + Correction_power;
//   int rightSpeed = base - Correction_power;
//   if(leftSpeed > maxspeed){
//     leftSpeed = maxspeed;
//   }
//   if(rightSpeed > maxspeed){
//     rightSpeed = maxspeed;
//   }
//   Motores(leftSpeed, rightSpeed);
// }
Brl();
while(true){
  Motores(0,0);
}
delay(60);
// Serial.print(digitalRead(FLsensor));
// Serial.print("  ");
// Serial.println(digitalRead(FRsensor));

  // int line_position = GetPos();
  // int Correction_power = PIDLambo(line_position, Kprop, Kderiv, Kinte);
  // int leftSpeed = base + Correction_power;
  // int rightSpeed = base - Correction_power;
  // if(leftSpeed > maxspeed){
  //   leftSpeed = maxspeed;
  // }
  // if(rightSpeed > maxspeed){
  //   rightSpeed = maxspeed;
  // }
  // Motores(leftSpeed, rightSpeed);

 


  
  
  // while(true)
  // {
  //  Motores(0,0);
  // }

  
  // Serial.println(line_position);
  //  Serial.print("\t");
  //  Serial.println(Correction_power);
}

int v_s_min[8] = { 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023 };
int v_s_max[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
volatile int s_p[8];
boolean online;

int l_pos;



void calibracion() {

  int v_s[8];

  for (int j = 0; j < 200; j++) {
    delay(10);
    v_s[7] = analogRead(A7);
    v_s[6] = analogRead(A6);
    v_s[5] = analogRead(A5);
    v_s[4] = analogRead(A4);
    v_s[3] = analogRead(A3);
    v_s[2] = analogRead(A2);
    v_s[1] = analogRead(A1);
    v_s[0] = analogRead(A0);

    for (int i = 0; i < 8; i++) {

      Serial.print(v_s[i]);
      Serial.print("\t");
    }
    Serial.println();

    for (int i = 0; i < 8; i++) {
      if (v_s[i] < v_s_min[i]) {
        v_s_min[i] = v_s[i];
      }
    }


    for (int i = 0; i < 8; i++) {
      if (v_s[i] > v_s_max[i]) {
        v_s_max[i] = v_s[i];
      }
    }
  }

  //  beep();
  //  beep();

  Serial.println();
  Serial.print("Mínimos ");
  Serial.print("\t");

  for (int i = 0; i < 8; i++) {

    Serial.print(v_s_min[i]);
    Serial.print("\t");
  }
  Serial.println();
  Serial.print("Máximos ");
  Serial.print("\t");

  for (int i = 0; i < 8; i++) {

    Serial.print(v_s_max[i]);
    Serial.print("\t");
    
  }
  Serial.println();
  Serial.println();
  Serial.println();
}

void readSensors() {

  volatile int s[8];

  s[7] = analogRead(A7);
  s[6] = analogRead(A6);
  s[5] = analogRead(A5);
  s[4] = analogRead(A4);
  s[3] = analogRead(A3);
  s[2] = analogRead(A2);
  s[1] = analogRead(A1);
  s[0] = analogRead(A0);

  for (int i = 0; i < 8; i++) {
    if (s[i] < v_s_min[i]) {
      s[i] = v_s_min[i];
    }

    if (s[i] > v_s_max[i]) {
      s[i] = v_s_max[i];
    }
    s_p[i] = map(s[i], v_s_min[i], v_s_max[i], 100, 0);
  }


  volatile int sum = s_p[0] + s_p[1] + s_p[2] + s_p[3] + s_p[4] + s_p[5] + s_p[6] + s_p[7];
  if (sum > 100) {
    online = 1;

  } else {
    online = 0;
    sum = 100;
  }


  if (online) {
    for (int i = 0; i < 8; i++) {
      Serial.print(s_p[i]);
      Serial.print("\t");
    }
    //      Serial.println();
  }
}




int GetPos() {
  readSensors();
  int prom = -3.5 * s_p[0] - 2.5 * s_p[1] - 1.5 * s_p[2] - 0.5 * s_p[3] + 0.5 * s_p[4] + 1.5 * s_p[5] + 2.5 * s_p[6] + 3.5 * s_p[7];
  int sum = s_p[0] + s_p[1] + s_p[2] + s_p[3] + s_p[4] + s_p[5] + s_p[6] + s_p[7];

  if (online) {
    pos = int(100.0 * prom / sum);
  } else {
    if (l_pos < 0) {
      pos = -255;
    }
    if (l_pos >= 0) {
      pos = 255;
    }
  }
  l_pos = pos;
  return pos;
}






void TB6612FNG_init() {

  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(STBY, OUTPUT);
  digitalWrite(STBY, HIGH);
}

void MotorIz(int value) {
  if (value >= 0) {
    // si valor positivo vamos hacia adelante

    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
  } else {
    // si valor negativo vamos hacia atras

    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
    value *= -1;
  }

  // Setea Velocidad

  analogWrite(PWMA, value);
}


void MotorDe(int value) {
  if (value >= 0) {
    // si valor positivo vamos hacia adelante

    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
  } else {
    // si valor negativo vamos hacia atras

    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
    value *= -1;
  }

  // Setea Velocidad

  analogWrite(PWMB, value);
}


void Motores(int left, int right) {
  MotorIz(left);
  MotorDe(right);
}

int setpoint = 0;
int last_error = 0;
int pot_limite = 250;
int sum_error = 0;

int PIDLambo(int POS, float Kp, float Kd, float Ki) {

  int error = pos - setpoint;
  int derivative = error - last_error;
  last_error = error;
  sum_error += error;
  int pot_giro = ((error * Kp) + (derivative * Kd) + (Ki * sum_error));





  if (pot_giro > pot_limite)
    pot_giro = pot_limite;
  else if (pot_giro < -pot_limite)
    pot_giro = -pot_limite;
  return pot_giro;
}

void Brl() {

 
  while(x != 1) {
  //  digitalWrite(8, HIGH);
   int SL = digitalRead(FLsensor);
  int SR = digitalRead(FRsensor);
   int line_position = GetPos();
  int Correction_power = PIDLambo(line_position, Kprop, Kderiv, Kinte);
  int leftSpeed = base + Correction_power;
  int rightSpeed = base - Correction_power;
  if(leftSpeed > maxspeed){
    leftSpeed = maxspeed;
  }
  if(rightSpeed > maxspeed){
    rightSpeed = maxspeed;
  }
  Motores(leftSpeed, rightSpeed);
   if( SL == 1 && SR == 1  ) {
     Motores(base,base);
     delay(200);
     
     x = x + 1 ; 
   }
  }
}
void Left( int y ) {
    Motores(0,360);
    delay( y );
}

void Leaw() {
  
  while( x != 2 ) {

  Left(500);
  Motores(base,base);
  delay(500);
  // base = 100;
  int line_position = GetPos();
  int Correction_power = PIDLambo(line_position, Kprop, Kderiv, Kinte);
  int leftSpeed = base + Correction_power;
  int rightSpeed = base - Correction_power;
  if(leftSpeed > maxspeed){
    leftSpeed = maxspeed;
  }
  if(rightSpeed > maxspeed){
    rightSpeed = maxspeed;
  }
  Motores(leftSpeed, rightSpeed);

  }
}

void FL() {
  while( x != 3 ){
  int line_position = GetPos();
  int Correction_power = PIDLambo(line_position, Kprop, Kderiv, Kinte);
  int leftSpeed = base + Correction_power;
  int rightSpeed = base - Correction_power;
  if(leftSpeed > maxspeed){
    leftSpeed = maxspeed;
  }
  if(rightSpeed > maxspeed){
    rightSpeed = maxspeed;
  }
  Motores(leftSpeed, rightSpeed);

  }
}

