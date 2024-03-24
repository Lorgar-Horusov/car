#include "Ultrasonic.h"

#define PIN_ENA 8 // Вывод управления скоростью вращения мотора №1
#define PIN_ENB 13 // Вывод управления скоростью вращения мотора №2
#define PIN_IN1 10 // Вывод управления направлением вращения мотора №1
#define PIN_IN2 9 // Вывод управления направлением вращения мотора №1
#define PIN_IN3 12 // Вывод управления направлением вращения мотора №2
#define PIN_IN4 11 // Вывод управления направлением вращения мотора №2
#define ALARM_PIN 2
uint8_t power = 200; // 255 Значение ШИМ (или скорости вращения)

int speed = 250;
Ultrasonic ultrasonic(5, 6); // Trig - 12, Echo - 11
void setup() {
   Serial.begin(9600);
  // Установка всех управляющих пинов в режим выхода
  pinMode(PIN_ENA, OUTPUT);
  pinMode(PIN_ENB, OUTPUT);
  pinMode(PIN_IN1, OUTPUT);
  pinMode(PIN_IN2, OUTPUT);
  pinMode(PIN_IN3, OUTPUT);
  pinMode(PIN_IN4, OUTPUT);
  // Команда остановки двум моторам
  digitalWrite(PIN_IN1, LOW);
  digitalWrite(PIN_IN2, LOW);
  digitalWrite(PIN_IN3, LOW);
  digitalWrite(PIN_IN4, LOW);
  tone(ALARM_PIN, 2500, 10);

}
void loop() {

delay(100);
  analogWrite(PIN_ENA, speed); // Устанавливаем скорость 1-го мотора
  analogWrite(PIN_ENB, speed); // Устанавливаем скорость 2-го мотора

  move_forvard(1000);
  delay(500);

  turn_left(500);
  delay(1000);

  move_forvard(2000);
  delay(1000);

  turn_right(500);
  delay(1000);

  move_forvard(1000);
  delay(1000);

  turn_right(500);
  delay(1000);

  move_forvard(1000);
  delay(500);

  turn_left(500);
  delay(1000);
}


void alarm(){
  /*
  Функция при вызове включает сигнал тревоги
  */
  digitalWrite(ALARM_PIN, 1);
  delay(50);
  digitalWrite(ALARM_PIN, 0);
  delay(50);
  digitalWrite(ALARM_PIN, 1);
  delay(50);
  digitalWrite(ALARM_PIN, 0);
  delay(50);
  digitalWrite(ALARM_PIN, 1);
  delay(50);
  digitalWrite(ALARM_PIN, 0);
  delay(50);
  digitalWrite(ALARM_PIN, 1);
  delay(100);
  digitalWrite(ALARM_PIN, 0);
  delay(100);
  digitalWrite(ALARM_PIN, 1);
  delay(100);
  digitalWrite(ALARM_PIN, 0);
  delay(100);
  digitalWrite(ALARM_PIN, 1);
  delay(100);
  digitalWrite(ALARM_PIN, 0);
  delay(100);
  digitalWrite(ALARM_PIN, 1);
  delay(50);
  digitalWrite(ALARM_PIN, 0);
  delay(50);
  digitalWrite(ALARM_PIN, 1);
  delay(50);
  digitalWrite(ALARM_PIN, 0);
  delay(50);
  digitalWrite(ALARM_PIN, 1);
  delay(50);
  digitalWrite(ALARM_PIN, 0);
  delay(200);
}


bool check_dist(){
  float dist_cm = ultrasonic.Ranging(CM);
  Serial.println(dist_cm);
  if (dist_cm <= 20){
    return true;
  }
  return false;
}


void turn_right(int time){
  if (check_dist()){
    alarm();
    move_forvard(time);
 }
   digitalWrite(PIN_IN3, LOW);
    digitalWrite(PIN_IN4, HIGH);
    digitalWrite(PIN_IN1, HIGH);
    digitalWrite(PIN_IN2, LOW);
    delay(time);
    digitalWrite(PIN_IN3, LOW);
    digitalWrite(PIN_IN4, LOW);
    digitalWrite(PIN_IN1, LOW);
    digitalWrite(PIN_IN2, LOW);
}


void turn_left(int time){
  if (check_dist()){
    alarm();
    move_forvard(time);
 }
   digitalWrite(PIN_IN3, HIGH);
    digitalWrite(PIN_IN4, LOW);
    digitalWrite(PIN_IN1, LOW);
    digitalWrite(PIN_IN2, HIGH);
    delay(time);
    digitalWrite(PIN_IN3, LOW);
    digitalWrite(PIN_IN4, LOW);
    digitalWrite(PIN_IN1, LOW);
    digitalWrite(PIN_IN2, LOW);
}


void move_back(int time){
    digitalWrite(PIN_IN3, HIGH);
    digitalWrite(PIN_IN4, LOW);
    digitalWrite(PIN_IN1, HIGH);
    digitalWrite(PIN_IN2, LOW);
    delay(time);
    digitalWrite(PIN_IN3, LOW);
    digitalWrite(PIN_IN4, LOW);
    digitalWrite(PIN_IN1, LOW);
    digitalWrite(PIN_IN2, LOW);
}

void move_forvard(int time){
  if (check_dist()){
    alarm();
    move_forvard(time);
 }
    digitalWrite(PIN_IN3, LOW);
    digitalWrite(PIN_IN4, HIGH);
    digitalWrite(PIN_IN1, LOW);
    digitalWrite(PIN_IN2, HIGH);
    delay(time);
    digitalWrite(PIN_IN3, LOW);
    digitalWrite(PIN_IN4, LOW);
    digitalWrite(PIN_IN1, LOW);
    digitalWrite(PIN_IN2, LOW);
}
