# Project Pemetaan 2D Berbasis Arduino Uno dengan Sensor HCSR-04

> [!NOTE]  
>  Project ini bertujuan untuk melakukan pemetaan 2D menggunakan Arduino Uno sebagai mikrokontroller dengan sensor HCSR-04 yang akan mendeteksi objek lalu dipetakan ke dalam LCD I2C 128x64.

## Daftar Isi
    
- [Diargam Rangkaian](https://github.com/FillahAlamsyah/Project-Radar/blob/main/README.md#cDiargam-Rangkaian)
- [Cara Kerja](https://github.com/FillahAlamsyah/Project-Radar/blob/main/README.md#cara-kerja)
- [Kode Arduino](https://github.com/FillahAlamsyah/Project-Radar/blob/main/README.md#kode-arduino)
- [Kode Processing](https://github.com/FillahAlamsyah/Project-Radar/blob/main/README.md#kode-processing)
- [Referensi](https://github.com/FillahAlamsyah/Project-Radar/blob/main/README.md#Referensi)


## Diargam Rangkaian

![Circuit-Diagram.png](https://github.com/FillahAlamsyah/Project-Radar/blob/main/Circuit-Diagram.png)
[Simulasi Rangkaian di wokwi.com](https://wokwi.com/projects/376864616405893121)

## Cara Kerja


## Kode Arduino
    
```c++
#include <Servo.h> 

// Defines Trig and Echo pins of the Ultrasonic Sensor
const int trigPin = 10;
const int echoPin = 11;
const int servoPin = 12;
// Variables for the duration and the distance
long duration;
int distance;

Servo myServo; // Creates a servo object for controlling the servo motor

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  myServo.attach(servoPin); // Defines on which pin is the servo motor attached
}
void loop() {
  for(int i=15;i<=165;i++){ // rotates the servo motor from 15 to 165 degrees
    myServo.write(i);
    delay(30);
    distance = calculateDistance(); // Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
    Serial.print(i);Serial.print(",");Serial.println(distance);
  }
  for(int i=165;i>15;i--){  // Repeats the previous lines from 165 to 15 degrees
    myServo.write(i);
    delay(30);
    distance = calculateDistance();
    Serial.print(i);Serial.print(",");Serial.println(distance);
  }
}
// Function for calculating the distance measured by the Ultrasonic sensor
int calculateDistance(){ 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);  // Sets the trigPin on HIGH state for 10 micro seconds
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance = duration*0.034/2;
  return distance;
}
```

## Referensi
### HCSR-04
- https://lastminuteengineers.com/arduino-sr04-ultrasonic-sensor-tutorial/

### Servo
- https://lastminuteengineers.com/servo-motor-arduino-tutorial/

### I2C LCD
- https://lastminuteengineers.com/i2c-lcd-arduino-tutorial/

### OLED I2C Display Arduino
- https://startingelectronics.org/tutorials/arduino/modules/OLED-128x64-I2C-display/
- https://learn.adafruit.com/adafruit-gfx-graphics-library
- https://lastminuteengineers.com/oled-display-arduino-tutorial/

