/* Adding all the libraries and variables*/
#include <Servo.h>
#include <LiquidCrystal.h>
#include <Wire.h> 
#include <MPU6050.h> 
Servo myServo; 
MPU6050 mpu;  
LiquidCrystal lcd(8,9,10,11,12,13); 
const int servoPin=7; 
const int tiltPin=6;
const int buzzPin=5;
int tiltVal;
/* Variables to use the millis function*/
unsigned long LCDpreviousTime=0; 
const unsigned long LCDinterval=500; 
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200); 
Wire.begin();
mpu.initialize();
lcd.begin(16, 2); 
myServo.attach(servoPin); 
pinMode(tiltPin,INPUT_PULLUP);
pinMode(buzzPin,OUTPUT); 
/*For heading of what is gonna be printed on the serial monitor*/
Serial.print("Pitch, BuzzerState");
}

void loop() {
  // put your main code here, to run repeatedly:
 int16_t ax, ay, az;
mpu.getAcceleration(&ax, &ay, &az);
  
float ax_g = (float)ax;
float ay_g = (float)ay;
float az_g = (float)az;
/* Calculate pitch (in degrees) */
float pitch = atan2(ax_g, sqrt(ay_g * ay_g + az_g * az_g)) * 180 / PI;
if (pitch>=-0.8 && pitch<=0.8){ 
  pitch=0; 
}
int angle = map(pitch, -90, 90, 3000, 100); 
myServo.writeMicroseconds(angle); 
/*The below if statement is so that the LCD refreshes evry 500ms without interfering with the function of the servo,
 LCD cannot refresh instantly as it introduces flicker*/
if (millis()-LCDpreviousTime >= LCDinterval){ 
  LCDpreviousTime=millis(); 
  lcd.clear(); 
  lcd.print(pitch);
  lcd.setCursor(0, 0);
  lcd.print("Pitch: ");
  lcd.print(pitch);
}
/*tiltSwitch() function is mentioned below*/
tiltSwitch(); 
/*Printing all the values I need now*/
Serial.println(pitch); 
/*Using ternary operator below, IF tiltVal reads 1, print "ON", otherwise, print "OFF"
The syntax: condition ? value_if_true : value_if_false;
*/
Serial.println(tiltVal==1 ? "ON":"OFF");
}
/* this creates the function tiltSwitch which does what I want the tiltSwitch to do when tilted, i.e. turning on the buzzer */
void tiltSwitch(){ 
tiltVal=digitalRead(tiltPin); 
  if (tiltVal==1){ 
    digitalWrite(buzzPin,HIGH); 
  
  }
  else { 
    digitalWrite(buzzPin,LOW); 
  }
}
