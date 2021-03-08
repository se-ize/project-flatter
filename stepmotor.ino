#include <SoftwareSerial.h> //hc06 라이브러리
#include <Stepper.h>

SoftwareSerial hc06(3,2); //hc06(TXD,RXD)
const int dirPin = 10;
const int stepPin = 11; //1스텝모터 핀

const int dirPin2 = 6;
const int stepPin2 = 7; //2스텝모터 핀
const int stepsPerRevolution = 200; //스텝당 1.8도 회전 -> 360도 회전=360/1.8 

Stepper myStepper(stepsPerRevolution, 11,10);
Stepper myStepper2(stepsPerRevolution, 7,6);

void setup() 
{
  myStepper.setSpeed(60); //1분당 60바퀴, 12000(60*200)스텝
  myStepper2.setSpeed(60);
  
  Serial.begin(9600);   //시리얼 통신 시작
  hc06.begin(9600); //블루투스 통신 시작

  // Declare pins as Outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);

  digitalWrite(dirPin, HIGH); //high는 시계방향
  digitalWrite(stepPin, HIGH); 
  digitalWrite(dirPin2, HIGH);
  digitalWrite(stepPin2, HIGH); 
}

void loop()
{  
    char cmd = (char)hc06.read();
    if(cmd == '1'){ //1 입력하면 1스텝모터(입구) 작동
      Serial.write("1");
      
      for(int x = 0; x < stepsPerRevolution/2; x++) 
//stepsPerRevolution/n : 360도/n도, n=2이면 180도라 반바퀴
      {
        digitalWrite(stepPin, HIGH);
        delay(5);
        digitalWrite(stepPin, LOW);
        delay(5); 
  
//      myStepper.step(stepsPerRevolution);
//      myStepper.step(-stepsPerRevolution); //반대방향
      }
      
      delay(1000); //1초 대기

    }
    
    if(cmd == '2'){ //2 입력하면 2스텝모터 작동
      Serial.write("2");

      for(int x = 0; x < stepsPerRevolution; x++) 
      {
        digitalWrite(stepPin2, HIGH);
        delay(5);
        digitalWrite(stepPin2, LOW);
        delay(5); //한바퀴
      }
      
      delay(1000); //1초 대기
      
    }
    
    if(cmd == '3'){ //3 입력하면 2스텝모터 각도 변경
      Serial.write("3");
    }
    if(cmd == '4'){ //4 입력하면 2스텝모터 각도 변경
      Serial.write("4");
    }
    if(cmd == '5'){ //5 입력하면 2스텝모터 각도 변경
      Serial.write("5");
    }
    if(cmd == '6'){ //6 입력하면 2스텝모터 각도 변경
      Serial.write("6");
    }
    if(cmd == '7'){ //7 입력하면 2스텝모터 각도 변경
      Serial.write("7");
    }
}
