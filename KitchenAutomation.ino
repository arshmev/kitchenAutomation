#include<Servo.h>
#include <BlynkSimpleEsp8266.h>
int ledPin = 13;        
int inputPin = 5;              
int pirState = LOW;  
int trigPin = 9;
int echoPin = 10;      
int pir = 0;      
int counter = 0;  
int froth;     
int leakval;
int lpg;     
Servo knob;
 int settime;
void setup() {
  pinMode(ledPin, OUTPUT);     
  pinMode(inputPin, INPUT); 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
knob.attach(9);
  Serial.begin(9600);
}
BLYNK_WRITE(V0){
  Serial.print("click if the dish makes froth");
froth = param.asInt();
if(froth == HIGH)
      {
      slave();
      }
}
BLYNK_WRITE(V1){
  Serial.print("timer");
  settime = param.asInt();
  if(settime>0){
  timer();
  }
}

 
void loop(){
mastercode();
}

 void mastercode(){

 pir = digitalRead(inputPin); 
  if (pir == HIGH) {         
    if (pirState == LOW) {
      Serial.println("Motion detected!");
      pirState = HIGH;
    }
  } 
  else{

      if (pirState == HIGH){
      Serial.println("Motion ended!");
      pirState = LOW;
      //check if it has froth
      
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
     knob.write(-90); //sim 
     counter++;
  }
  if(counter==2){
    knob.write(90); //off
  }
 }
 void timer(){
   delay(6000*settime);
   knob.write(90);
 }


 void leak(){
   {
  lpg = digitalRead(leakval);
  if(lpg== HIGH)
  {
    Serial.print(" leak detected!");
  }
  
  delay(200);
}
 }