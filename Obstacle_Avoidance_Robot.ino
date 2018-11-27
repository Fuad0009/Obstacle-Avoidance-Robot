byte motorA = 10;
byte motorAdig1= 9;
byte motorAdig2= 6;
byte motorB = 3; 
byte motorBdig1= 5;
byte motorBdig2= A2;
int speed = 90;
int trigPin = 11;
int echoPin = 12;
int sound = 250;

 void setup() {
  Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 
//pinMode (motorA, OUTPUT);
analogWrite (motorA, speed);
pinMode (motorAdig1, OUTPUT);
pinMode (motorAdig2, OUTPUT);
//pinMode (motorB, OUTPUT);
analogWrite (motorB, speed);
pinMode (motorBdig1, OUTPUT);
pinMode (motorBdig2, OUTPUT);

//digitalWrite(motorA,HIGH);
//digitalWrite(motorB,HIGH);
 
}

void loop() {
long duration, distance;
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 distance = (duration/2) / 29.1;
 Serial.print(distance);
 Serial.println(" cm");
 //delay(500);

 if(distance<50){

  right(200);
 }

 else{
  forward();
 };
}
 
void forward(){
  
  digitalWrite(motorAdig1,150);
  digitalWrite(motorAdig2,LOW);
  digitalWrite(motorBdig1,150);
  digitalWrite(motorBdig2,LOW);

}
void backward(){
  digitalWrite(motorAdig1,LOW);
  digitalWrite(motorAdig2,HIGH);
  digitalWrite(motorBdig1,LOW);
  digitalWrite(motorBdig2,HIGH);
}
void left(int spe){
  analogWrite(motorA,spe);
  analogWrite(motorB,spe);
  digitalWrite(motorAdig1,LOW);
  digitalWrite(motorAdig2,HIGH);
  digitalWrite(motorBdig1,HIGH);
  digitalWrite(motorBdig2,LOW);
}
void right(int spe){
  analogWrite(motorA,spe);
  analogWrite(motorB,spe);
  digitalWrite(motorAdig1,HIGH);
  digitalWrite(motorAdig2,LOW);
  digitalWrite(motorBdig1,LOW);
  digitalWrite(motorBdig2,LOW);
}

void stoppo(){
  digitalWrite(motorAdig1,LOW);
  digitalWrite(motorAdig2,LOW);
  digitalWrite(motorBdig1,LOW);
  digitalWrite(motorBdig2,LOW);
}



