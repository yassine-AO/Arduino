#include <NewPing.h>

char command;

int scanleft;
int scanright;

int LEDBUZZER = 13;
int LEDSTART = 12;
int LEDBACK = 11;

int ENA = 3;
int in1 = 2;
int in2 = 4;

int ENB = 5;
int in3 = 6;
int in4 = 7;

NewPing sonar(10, 9, 10);

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
void LEDBUZZING(){
        digitalWrite(LEDBUZZER,HIGH); 
        delay(300);
        digitalWrite(LEDBUZZER,LOW); 
        delay(300);
        digitalWrite(LEDBUZZER,HIGH); 
        delay(300);
        digitalWrite(LEDBUZZER,LOW); 
        delay(300);
        digitalWrite(LEDBUZZER,HIGH); 
        delay(300);
        digitalWrite(LEDBUZZER,LOW); 
        delay(300);
  }
void backslowly() {
  analogWrite(ENA,140);
  analogWrite(ENB,177);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}
void stop(){
  analogWrite(ENA,140);
  analogWrite(ENB,177);
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}

void forward(){
  analogWrite(ENA,140);
  analogWrite(ENB,177);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}

void backward(){
  analogWrite(ENA,140);
  analogWrite(ENB,177);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
 
}

void leftforward(){
  analogWrite(ENA,140);
  analogWrite(ENB,177);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);

}

void rightbackward(){
  analogWrite(ENA,140);
  analogWrite(ENB,177);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}

void rightforward(){
  analogWrite(ENA,140);
  analogWrite(ENB,177);
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}

void leftbackward(){
  analogWrite(ENA,140);
  analogWrite(ENB,177);
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}

void loop() 
{
  if (sonar.ping_cm() >= 1 && sonar.ping_cm() <= 5)
       {

        stop();       
        delay(1500);
        digitalWrite(LEDSTART, LOW);
        LEDBUZZING();

        digitalWrite(LEDBACK, HIGH);
        leftbackward();   // looking for an obstacle left side
        delay(500);
        stop();
        delay(500);
        scanright = sonar.ping_cm();
        delay(500);
        rightforward(); 
        delay(500);
        stop();
        delay(1000);


        rightbackward();    // looking for an obstacle right side
        delay(500);
        stop();
        delay(500);
        scanleft = sonar.ping_cm();
        delay(500);
        leftforward();
        delay(500);
        stop();
        digitalWrite(LEDBACK, LOW);
        digitalWrite(LEDSTART, HIGH);
        delay(1000);

        if(scanleft > scanright)    //choosing the best path
        {
          leftbackward();
          delay(500);
          stop();
          delay(400);
        }

        if(scanright > scanleft)
        {
        rightbackward();
        delay(500);
        stop();
        delay(400);
        }

        if (scanleft == scanright)
        {
        rightbackward();
        delay(500);
        stop();
        delay(400);
        }

       }
       digitalWrite(LEDSTART, HIGH);
       forward();

}