
byte x;
byte w = 1;
String otvet = "";
String KOD = "";
// массив с вариантами кода
char* kod[6] = {"123", "132", "231", "213", "321", "312"};
// переменные для считывания нажатия на кнопки
boolean button1WasUp = true;
boolean button2WasUp = true;
boolean button3WasUp = true;

void setup() {
  Serial.begin(9600);
  // пины для подключения кнопок
  pinMode(5, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  // пины для подключения светодиодов
  pinMode(13, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {

/// ФУНКЦИЯ ГЕНЕРАЦИИ КОДА ///
  while (w == 1) {
    delay(500);
    digitalWrite(13, HIGH); digitalWrite(10, HIGH);
    delay(100);
    digitalWrite(13, LOW); digitalWrite(10, LOW);
    x = random(0, 5);
    KOD = String(kod[x]);
    Serial.print("KOD - "); 
    Serial.println(KOD);
    Serial.println("");
    Serial.print("OTVET - ");
    w = 2;
  }

/// ВВОДИМ ПЕРВОЕ ЧИСЛО ///
  while (w == 2) {
   // узнаем текущее состояние кнопок
   boolean button1IsUp = digitalRead(5);
   boolean button2IsUp = digitalRead(4);
   boolean button3IsUp = digitalRead(3);
    
   // если первая кнопка была нажата, добавляем к строке "1"
   if (button1WasUp && !button1IsUp) {
     delay(10);
     button1IsUp = digitalRead(5);
     if (!button1IsUp) { otvet = otvet + "1"; Serial.print("1"); w = 3;}
   }
   button1WasUp = button1IsUp; // запоминаем состояние первой кнопки
   
   // если вторая кнопка была нажата, добавляем к строке "2"
   if (button2WasUp && !button2IsUp) {
     delay(10);
     button2IsUp = digitalRead(4);
     if (!button2IsUp) { otvet = otvet + "2"; Serial.print("2"); w = 3;}
   }
   button2WasUp = button2IsUp; // запоминаем состояние второй кнопки
    
   // если третья кнопка была нажата, добавляем к строке "3"
   if (button3WasUp && !button3IsUp) {
     delay(10);
     button3IsUp = digitalRead(3);
     if (!button3IsUp) { otvet = otvet + "3"; Serial.print("3"); w = 3;}
   }
   button3WasUp = button3IsUp; // запоминаем состояние третьей кнопки
  }

/// ВВОДИМ ВТОРОЕ ЧИСЛО ///
  while (w == 3) {
   // узнаем текущее состояние кнопок
   boolean button1IsUp = digitalRead(5);
   boolean button2IsUp = digitalRead(4);
   boolean button3IsUp = digitalRead(3);
    
   // если первая кнопка была нажата, добавляем к строке "1"
   if (button1WasUp && !button1IsUp) {
     delay(10);
     button1IsUp = digitalRead(5);
     if (!button1IsUp) { otvet = otvet + "1"; Serial.print("1"); w = 4;}
   }
   button1WasUp = button1IsUp; // запоминаем состояние первой кнопки
   
   // если вторая кнопка была нажата, добавляем к строке "2"
   if (button2WasUp && !button2IsUp) {
     delay(10);
     button2IsUp = digitalRead(4);
     if (!button2IsUp) { otvet = otvet + "2"; Serial.print("2"); w = 4;}
   }
   button2WasUp = button2IsUp; // запоминаем состояние второй кнопки
    
   // если третья кнопка была нажата, добавляем к строке "3"
   if (button3WasUp && !button3IsUp) {
     delay(10);
     button3IsUp = digitalRead(3);
     if (!button3IsUp) { otvet = otvet + "3"; Serial.print("3"); w = 4;}
   }
   button3WasUp = button3IsUp; // запоминаем состояние третьей кнопки  
  }

/// ВВОДИМ ТРЕТЬЕ ЧИСЛО ///
  while (w == 4) {
   // узнаем текущее состояние кнопок
   boolean button1IsUp = digitalRead(5);
   boolean button2IsUp = digitalRead(4);
   boolean button3IsUp = digitalRead(3);
    
   // если первая кнопка была нажата, добавляем к строке "1"
   if (button1WasUp && !button1IsUp) {
     delay(10);
     button1IsUp = digitalRead(5);
     if (!button1IsUp) { otvet = otvet + "1"; Serial.println("1"); w = 5;}
   }
   button1WasUp = button1IsUp; // запоминаем состояние первой кнопки
   
   // если вторая кнопка была нажата, добавляем к строке "2"
   if (button2WasUp && !button2IsUp) {
     delay(10);
     button2IsUp = digitalRead(4);
     if (!button2IsUp) { otvet = otvet + "2"; Serial.println("2"); w = 5;}
   }
   button2WasUp = button2IsUp; // запоминаем состояние второй кнопки
    
   // если третья кнопка была нажата, добавляем к строке "3"
   if (button3WasUp && !button3IsUp) {
     delay(10);
     button3IsUp = digitalRead(3);
     if (!button3IsUp) { otvet = otvet + "3"; Serial.println("3"); w = 5;}
   }
   button3WasUp = button3IsUp; // запоминаем состояние третьей кнопки
  }

/// СРАВНИВАЕМ НАШ ОТВЕТ С КОДОМ ///
  if (KOD == otvet ) {
    Serial.println(""); Serial.println("DA!"); Serial.println("");
    digitalWrite(10, HIGH); delay(1000); digitalWrite(10, LOW);
    otvet = "";  // стираем строку
    w = 1;         // генерируем новый код
  }
  else  {
    Serial.println(""); Serial.println("HET!"); Serial.println("");
    Serial.print("OTVET - ");
    digitalWrite(13, HIGH); delay(1000); digitalWrite(13, LOW);
    otvet = "";  // стираем строку
    w = 2;         // новая попытка ввода кода
  }
}
