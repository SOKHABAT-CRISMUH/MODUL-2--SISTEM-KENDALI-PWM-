// PRATIKUM MODUL 2 SISTEM PWM //
// KELOMPOK 13 SOKHABAT CRISMUH//
// NAMA ANGGOTA : MUHAMMAD BAMBANG CHURNIAWAN (6702194066)
//					CRISTIAN YULMA WIBOWO 
// 
//Deklarasi Pin yang digunakan untuk sensor
int sensor1 = A0;
int sensor2 = A1;
int sensor3 = A2;
int sensor4 = A3;
int sensor5 = A4;
int sensor6 = A5;
int baca_sensor[6];

//Variable bantuan untuk menyimpan memory a.k.a Error Detection Memory(EDM)
int LastError = 0;

//pin penggerak Motor
int pinEnable = 4; //Pin 1&2 harus HIGH
int pinEnable2 = 2; //Pin 3&4 harus HIGH

//pin Motorkiri 
int motor_kiri1 = 5; //input motor driver
int motor_kiri2 = 6; //input motor driver

//pin Motorkanan
int motor_kanan1 = 3;
int motor_kanan2 = 11;

void setup(){
// Keenam Sensor Photodiode sebagai INPUT yaitu sensor cahaya
pinMode(sensor1, INPUT);
pinMode(sensor2, INPUT);
pinMode(sensor3, INPUT);
pinMode(sensor4, INPUT);
pinMode(sensor5, INPUT);
pinMode(sensor6, INPUT);

  //Motor sebagai OOUTPUT pengerak
pinMode(pinEnable, OUTPUT);
pinMode(pinEnable2, OUTPUT);
pinMode(motor_kiri1, OUTPUT);
pinMode(motor_kiri2, OUTPUT);
pinMode(motor_kanan1, OUTPUT);
pinMode(motor_kanan2, OUTPUT);

Serial.begin(9600);
}

//Membaca sinyal analog dari sensor
void readsensor(){
 	baca_sensor[0] = analogRead(sensor1); 
	baca_sensor[1] = analogRead(sensor2); 
  	baca_sensor[2] = analogRead(sensor3);
  	baca_sensor[3] = analogRead(sensor4); 
  	baca_sensor[4] = analogRead(sensor5);
  	baca_sensor[5] = analogRead(sensor6); 
  
  delay(100);
  // Menampilkan data sensor ke Serial Monitor
  // Data sensor 1-6
  // Formatting tampilkan sensor
  for(int i=0; i<=5; i++){
  	Serial.println(baca_sensor[i]);
  }
  
}

void loop(){
	readsensor();
  
  //kondisi 1 jika sensor 1 dan 2 mendeteksi gelap maka motor kanan menyala
  if(baca_sensor[0] < 34 && baca_sensor[1] < 34 && 
     baca_sensor[2] > 34 && baca_sensor[3] > 34 && 
     baca_sensor[4] > 34 && baca_sensor[5] > 34)
  {
 	digitalWrite(pinEnable, HIGH);
    //analogWrite(pin,value 0-255)
  	analogWrite(motor_kiri1,0);  
    analogWrite(motor_kiri2,0);
    
    digitalWrite(pinEnable2, HIGH);
  	analogWrite(motor_kanan1,127);  
    analogWrite(motor_kanan2,0);
  }
  
  
  if(baca_sensor[0] > 34 && baca_sensor[1] < 34  && 
     baca_sensor[2] < 34 && baca_sensor[3] > 34  && 
     baca_sensor[4] > 34 && baca_sensor[5] > 34)
  {
 	digitalWrite(pinEnable, HIGH);
    //analogWrite(pin,value 0-255)
  	analogWrite(motor_kiri1,0.2*255);  
    analogWrite(motor_kiri2,0);
    
    digitalWrite(pinEnable2, HIGH);
  	analogWrite(motor_kanan1,0.5*255);  
    analogWrite(motor_kanan2,0);
  }
  
  //kondisi 2 jika sensor 3 dan 4 mendeteksi gelap maka motor kiri dan kanan menyala
 if(baca_sensor[0] > 34 && baca_sensor[1] > 34  && 
     baca_sensor[2] < 34 && baca_sensor[3] < 34  && 
     baca_sensor[4] > 34 && baca_sensor[5] > 34)
  {
 	digitalWrite(pinEnable, HIGH);
    //analogWrite(pin,value 0-255)
  	analogWrite(motor_kiri1,0.6*255);  
    analogWrite(motor_kiri2,0);
    
    digitalWrite(pinEnable2, HIGH);
  	analogWrite(motor_kanan1,0.6*255);  
    analogWrite(motor_kanan2,0);
  }
  
  //kondisi 3 jika sensor 5 dan 6 mendeteksi gelap maka motor kiri menyala
  if(baca_sensor[0] > 34 && baca_sensor[1] > 34  && 
     baca_sensor[2] > 34 && baca_sensor[3] < 34  && 
     baca_sensor[4] < 34 && baca_sensor[5] > 34)
  {
 	digitalWrite(pinEnable, HIGH);
    //analogWrite(pin,value 0-255)
  	analogWrite(motor_kiri1,0.5*255);  
    analogWrite(motor_kiri2,0);
    
    digitalWrite(pinEnable2, HIGH);
  	analogWrite(motor_kanan1,0.2*255);  
    analogWrite(motor_kanan2,0);
  }
  
  //kondisi 4 jika ke-6 sensor diterangkan semua maka motor tidak akan menyala
  if(baca_sensor[0] > 34 && baca_sensor[1] > 34  && 
     baca_sensor[2] > 34 && baca_sensor[3] > 34  && 
     baca_sensor[4] < 34 && baca_sensor[5] < 34)
  {
 	digitalWrite(pinEnable, HIGH);
    //analogWrite(pin,value 0-255)
  	analogWrite(motor_kiri1,0.5*255);  
    analogWrite(motor_kiri2,0);
    
    digitalWrite(pinEnable2, HIGH);
  	analogWrite(motor_kanan1,0);  
    analogWrite(motor_kanan2,0);
  }
  if(baca_sensor[0] > 34 && baca_sensor[1] > 34  && 
     baca_sensor[2] > 34 && baca_sensor[3] > 34  && 
     baca_sensor[4] > 34 && baca_sensor[5] > 34)
  {
 	digitalWrite(pinEnable, HIGH);
    //analogWrite(pin,value 0-255)
  	analogWrite(motor_kiri1,0);  
    analogWrite(motor_kiri2,0);
    
    digitalWrite(pinEnable2, HIGH);
  	analogWrite(motor_kanan1,0);  
    analogWrite(motor_kanan2,0);
  }
  

  
}