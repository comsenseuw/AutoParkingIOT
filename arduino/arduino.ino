#include <Servo.h>

Servo myservo1;
Servo myservo2;

int IR1 = 2;
int IR2 = 3;

void setup() {
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  myservo1.attach(4);
  myservo2.attach(5);
}

void loop(){
  if(digitalRead (IR1) == HIGH){
    myservo1.write(0);
  }
  else{
    myservo1.write(90);   
  }
  
  if(digitalRead (IR2) == HIGH){
    myservo2.write(0);
  }
  else{
    myservo2.write(90);
  }
  delay(3000);
}
