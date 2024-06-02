#include <NewPing.h>

char command;
int LEDBUZZER = 13;
int LEDSTART = 12;
int LEDBACK = 11;

int ENA = 3;
int in1 = 2;
int in2 = 4;

int ENB = 5;
int in3 = 6;
int in4 = 7;

NewPing sonar(10, 9, 20);

void setup() {
  Serial.begin(9600);
  delay(50);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT); 
  pinMode(LEDBUZZER, OUTPUT); 
  pinMode(LEDSTART, OUTPUT); 
   pinMode(LEDBACK, OUTPUT); 
}
void ledbuzzing(){
        digitalWrite(LEDBUZZER,HIGH); 
        delay(500);
        digitalWrite(LEDBUZZER,LOW); 
        delay(500);
        digitalWrite(LEDBUZZER,HIGH); 
        delay(500);
        digitalWrite(LEDBUZZER,LOW); 
        delay(500);
        digitalWrite(LEDBUZZER,HIGH); 
        delay(500);
        digitalWrite(LEDBUZZER,LOW); 
        delay(500);
}
void forwardright(){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW); 
  digitalWrite(LEDSTART,HIGH);
}
void backwardright(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH); 
  digitalWrite(LEDBACK,HIGH);
}
void forwardleft(){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW); 
  digitalWrite(LEDSTART,HIGH);
}
void backwardleft(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH); 
  digitalWrite(LEDBACK,HIGH);
}

void stop(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  digitalWrite(LEDSTART,LOW);
  digitalWrite(LEDBACK,LOW);
  digitalWrite(LEDBUZZER,LOW);
}

void forward(){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  digitalWrite(LEDSTART,HIGH);
}

void backward(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  digitalWrite(LEDBACK,HIGH);
 
}

void left(){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  digitalWrite(LEDSTART,HIGH);

}

void right(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  digitalWrite(LEDSTART,HIGH);
}

void loop() {
  
  if(Serial.available())
  {
  command = Serial.read();
  }
  if (command == 'F' || command == 'U' )
     {
              forward();
       if (sonar.ping_cm() >= 1 && sonar.ping_cm() <9)
       {
        stop();  
        ledbuzzing();
       }
     }

  else if (command == 'B' || command == 'D')
     {
        backward();
     }

  else if (command == 'S')
     {
       stop();
     }
  else if (command == 'R')
     {
       right();
     }
  else if (command == 'L')
     {
       left();
     }
  else if (command == 'G')
     {
       forwardleft();
     }
  else if (command == 'H')
     {
       backwardleft();
     }
  else if (command == 'I')
     {
       forwardright();
     }
  else if (command == 'J')
     {
       backwardright();
     }
  else if (command == 'w')
     {
       digitalWrite(LEDBUZZER,HIGH);
     }
  else if (command == 'W')
     {
       digitalWrite(LEDBUZZER,LOW);
     }
  else if (command == '1' || command == '2'|| command == '3' || command == '4')
     {
        analogWrite(ENA, 80);
        analogWrite(ENB,118);
     }
  else if (command == '5' || command == '6'|| command == '7' || command == '8')
     {
        analogWrite(ENA, 130);
        analogWrite(ENB,168);
     }
  else if (command == '9' || command == 'q')
     {
        analogWrite(ENA, 255);
        analogWrite(ENB,255);
     }
  else if (command == '0')
     {
        analogWrite(ENA, 0);
        analogWrite(ENB,0);
     }
}