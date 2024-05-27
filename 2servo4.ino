
#include <Servo.h>

Servo servo1;
//servo 1 pulls tentacles in
Servo servo2;
//servo 2 pulls tentacles open

const int trigPin = 3;
const int echoPin = 2;
const int threshold = 50;

int distance;
long duration;
unsigned long reset;
int pos;

bool open = true;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servo1.attach(5);
  servo2.attach(9);

  delay(500);

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.0344/2;


  if (distance < threshold){
    servo1.write(180);
    servo2.write(180);
    delay(10);
    open = false;

  }

  else if(millis() - reset > 4000 && distance > threshold && !open) {

    for(pos = 180; pos> 0; pos -= 1) {
    servo1.write(pos);
    servo2.write(pos);

    delay(60);
  }
  open = true;
  }

  Serial.print("Distance: ");
    Serial.print(distance); // Print the output in serial monitor
    delay(100);

}
