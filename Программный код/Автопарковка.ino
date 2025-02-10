#include <Servo.h> 
Servo porog; 
int codescannedtimes = 0; 
#include <arduino_encoder.h>  // Подключаем библиотеку  
// Создаем объекты для работы с: 
Encoder enc1;                 // первым энкодером 
int To = 295; 
int carlocation = 1; 
int current = 1; 
unsigned long time0 = 1200; 
unsigned long times; 
void setup() { 
  times = millis(); 
  // Базовая установка 
  Serial.begin(9600);         // Включаем монитор порта 
  porog.attach(11); 
  porog.write(180); 
  // Инициализируем энкодеры, указывая на каких пинах они находятся 
  enc1.setup(12, 13);           // Энкодер 1 подключен к пинам D5 и D6 (двунаправленный) 
  pinMode(4, OUTPUT); pinMode(5, OUTPUT); pinMode(6, OUTPUT); pinMode(7, OUTPUT); 
  // при необходимости можем обнулить энкодеры 
  //enc1.clear();               // Обнуляем энкодер 1 
 
} 
void go2(int povorotov) { 
  while (true) { 
    int R = analogRead(A0); 
    int T = 321; 
    int S = 135; 
    // porog.write(180); 
    go(S); 
    if (enc1.get() < -T*povorotov) { 
      if (millis() - times > time0) S++; else if (times < time0)S--; 
      times = millis(); 
      go(-S / 2); 
      delay(150); 
      porog.write(0); 
      delay(350); 
      go(-S / 2); 
      delay(100); 
      go(0); 
      delay(4000); 
      porog.write(180); 
      delay(1000); 
      enc1.clear(); 
      Serial.println("Всё"); 
      current++; 
      if (current == 8){ 
         current = 1; 
      } 
      break; 
    } 
    // считываем значения с энкодеров: 
    Serial.print(S); 
    Serial.print("\t"); 
    Serial.print(times); 
    Serial.print("\t"); 
    Serial.println(enc1.get()); // Выводим показания энкодера 
    To = T; 
  } 
} 
void go(int V) { 
  if (V > 0) { 
    digitalWrite(4, 1); 
    digitalWrite(7, 1); 
  } 
  else { 
    digitalWrite(4, 0); 
    digitalWrite(7, 0); 
  } 
  analogWrite(5, abs(V)); analogWrite(6, abs(V)); 
} 
void loop() { 
  if (Serial.parseInt() == 2 and codescannedtimes % 2 == 0) { 
    Serial.print("Разрешена загрузка"); 
    delay(1350); 
     
    carlocation = current; 
    codescannedtimes++; 
    go2(1); 
    current++; 
  } 
  if (Serial.parseInt() == 2 and codescannedtimes % 2 == 1) { 
    
    Serial.print("Разрешена выгрузка");
    Serial.println("Штрих-код на автомобиле: 3");
    Serial.println("Номер ячейки хранения автомобиля A: N");
    Serial.println("Карточка автомобиля: А");
    codescannedtimes++; 
    
     
     
    } 
    
  } 
   
}
