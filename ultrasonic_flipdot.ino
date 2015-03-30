/*
HC-SR04 Ping distance sensor]
VCC to arduino 5v GND to arduino GND
Echo to Arduino pin 13 Trig to Arduino pin 12
Red POS to Arduino pin 11
Green POS to Arduino pin 10
560 ohm resistor to both LED NEG and GRD power rail
More info at: http://goo.gl/kJ8Gl
Original code improvements to the Ping sketch sourced from Trollmaker.com
Some code and wiring inspired by http://en.wikiversity.org/wiki/User:Dstaub/robotcar
*/

#define trigPin 13
#define echoPin 12

int pinflip = 10;

int pinflop = 11;
int fliptime = 2000;



void setup() {
  
Serial.begin (9600); 
                      
setup_flipdot();
setup_distance_sensor();

}
void loop() {
 long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 

//  delayMicroseconds(1000);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); 
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  
                                    

  if (distance < 8) 
  {  

  digitalWrite(pinflip,LOW);
  digitalWrite(pinflop,HIGH);
  
}
  else {
   digitalWrite(pinflop,LOW);
   digitalWrite(pinflip,HIGH);
  }
  if (distance >= 200 || distance <= 0){ 
    Serial.println("Out of range");
  }
  else {

    Serial.print(distance);
    Serial.println(" cm");
    
  }
  delay(500); 
} 


void setup_flipdot(){
  
  pinMode(pinflip, OUTPUT);
  pinMode(pinflop, OUTPUT);  
  digitalWrite(pinflip, HIGH); 
  digitalWrite(pinflop, LOW);
}


void setup_distance_sensor() {
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}
