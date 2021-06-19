#include <IRremote.h>
#include <Servo.h> // подключаем библиотеку для работы с сервоприводом


int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;
Servo servo1; // объявляем переменную servo типа "servo1"


void setup() {
// Инициализируем цифровой вход/выход в режиме выхода.
// Выход 13 на большинстве плат Arduino подключен к светодиоду на плате.
pinMode(13, OUTPUT);
servo1.attach(8);
Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
}

void loop() {
  if ( irrecv.decode( &results )) { // если данные пришли
    switch ( results.value ) {
    case 0x1689D02F:
        digitalWrite( 13, HIGH );
        servo1.write(160); // ставим угол поворота под 0
        break;
    case 0x1689E01F:
        digitalWrite( 13, LOW );
        servo1.write(60); // ставим угол поворота под 180
        break;
    }