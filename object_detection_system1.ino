//------------------- set Ultrasonic Sensor  -------------------------------
//--define Ultrasonic_1 = left , Ultrasonic_2 = Mid , Ultrasonic_3 = right--
struct Ultrasonic_1{
       int echoPin=8;
       int trigPin=9;
};
struct Ultrasonic_2{
       int echoPin=10;
       int trigPin=11;
};
struct Ultrasonic_3{
       int echoPin=12;
       int trigPin=13;
};
//--------------------------------------------------------------------------
//-------set variable length--------------------
int dist_1=0;
int dist_2=0;
int dist_3=0;
//----------------------------------------------

void set_Ultra(int ch);
void Ultra_work(int x);

void setup() {
 
  set_Ultra(1);
  set_Ultra(2);
  set_Ultra(3);
  Serial.begin(9600); 
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); 
  Serial.println("with Arduino UNO R3");
}
void loop() {
  
  Serial.print("Ultrasonic_L = "); 
  Ultra_work(1);
  Serial.print(dist_1);
  Serial.print(" cm");
  Serial.print(" Ultrasonic_M = ");
  Ultra_work(2);
  Serial.print(dist_2);
  Serial.print(" cm");
  Serial.print(" Ultrasonic_R = ");
  Ultra_work(3);
  Serial.print(dist_3);
  Serial.println(" cm");
  delay(1000);
  
}
void set_Ultra(int ch) {
  if(ch == 1) {
     Ultrasonic_1 u1;
     pinMode(u1.trigPin, OUTPUT); 
     pinMode(u1.echoPin, INPUT); 
  }
  if(ch == 2) {
     Ultrasonic_2 u2;
     pinMode(u2.trigPin, OUTPUT); 
     pinMode(u2.echoPin, INPUT); 
  }
  if(ch == 3) {
     Ultrasonic_3 u3;
     pinMode(u3.trigPin, OUTPUT); 
     pinMode(u3.echoPin, INPUT); 
  }
}
void Ultra_work(int x) {
  long duration; 
  int distance;
 
  if(x == 1) {
      Ultrasonic_1 u1;
      digitalWrite(u1.trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(u1.trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(u1.trigPin, LOW);
      duration = pulseIn(u1.echoPin, HIGH); 
      distance = duration * 0.034 / 2; 
      //Serial.print(distance);
      dist_1 = distance;
  }
  if(x == 2) {
      Ultrasonic_2 u2;
      digitalWrite(u2.trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(u2.trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(u2.trigPin, LOW);
      duration = pulseIn(u2.echoPin, HIGH); 
      distance = duration * 0.034 / 2; 
     // Serial.print(distance);
      dist_2 = distance;
  }
  if(x == 3) {
      Ultrasonic_3 u3;
      digitalWrite(u3.trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(u3.trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(u3.trigPin, LOW);
      duration = pulseIn(u3.echoPin, HIGH); 
      distance = duration * 0.034 / 2; 
      //Serial.print(distance);
      dist_3 = distance;
   }

}