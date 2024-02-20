#include <Servo.h>

const int servoPin = 12;

Servo servo;

void setup(){
  Serial.begin(9600);
  servo.attach(servoPin);

  Serial.println("Uji Coba Servo");
  delay(2000);
}

void loop(){
  
  for(int i=15; i<165;i++){
    angle = i;
    servo.write(angle);

    Serial.print("Sudut Servo : ");
    Serial.println(angle);
    
    delay(100);
  }
  
  for(int i=165; i>15;i--){
    angle = i;
    servo.write(angle);

    Serial.print("Sudut Servo : ");
    Serial.println(angle);
    
    delay(100);
  }
}
