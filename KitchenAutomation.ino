#include<Servo.h>
int ledPin = 13;        
int inputPin = 5;              
int pirState = LOW;  
 int trigPin = 9;
  int echoPin = 10;      
int val = 0;      
int counter =0;            
 Servo knob;
void setup() {
  pinMode(ledPin, OUTPUT);     
  pinMode(inputPin, INPUT); 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
knob.attach(9);
  Serial.begin(9600);
}
BLYNK_WRITE(V0){
  int froth = param.asInt();
}
 
void loop(){
mastercode();
}

 void mastercode(){

 val = digitalRead(inputPin); 
  if (val == HIGH) {         
    if (pirState == LOW) {
      Serial.println("Motion detected!");
      pirState = HIGH;
    }
  } else {

    if (pirState == HIGH){
      Serial.println("Motion ended!");
      pirState = LOW;

      if(forth == HIGH)
      {
      slave();
      }
    }
  }
 }
 void slave(){
   
 digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  int duration = pulseIn(echoPin, HIGH);

 int distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);
  if(distance<4){
     knob.write(-90);  
     counter++;
  }
  if(counter==2){
    knob.write(+90);
  }
 }