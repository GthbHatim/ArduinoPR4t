#include <Servo.h>

// Definición de pines
const int trigPin = 7;
const int echoPin = 6;
Servo servoMotor;

// Variables de estado
int currentDistance = 0;
bool objectNear = false;
bool lastState = false;
int servoPosition = 0; // 0 = posición inicial, 60 = posición activada

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  servoMotor.attach(5);
  servoMotor.write(servoPosition); // Inicia en posición 0°
}

void loop() {
  currentDistance = ultrasonicRead();
  Serial.print("Distance: ");
  Serial.print(currentDistance);
  Serial.println(" cm");
  
  // Determinar si el objeto está cerca (menos de 20 cm)
  objectNear = (currentDistance < 20);
  
  // Solo actuar cuando cambia el estado (de lejos a cerca o viceversa)
  if (objectNear != lastState) {
    if (objectNear) {
      // Objeto acaba de acercarse (menos de 20 cm)
      if (servoPosition == 0) {
        servoPosition = 60;
        servoMotor.write(servoPosition);
        Serial.println("Objeto cerca - Servo a 60°");
      } else {
        servoPosition = 0;
        servoMotor.write(servoPosition);
        Serial.println("Objeto cerca - Servo a 0°");
      }
    }
    // Pequeña pausa para evitar rebotes
    delay(500);
  }
  
  // Actualizar el último estado
  lastState = objectNear;
  
  // Pequeño retardo entre lecturas
  delay(100);
}

int ultrasonicRead() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
  
  return distance;
}
