#include <NewPing.h>
#include <Servo.h>

Servo myMotorsS1;
Servo myMotorsS2;
Servo myMotorsS3;
Servo myMotorsS4;
Servo myMotorsS5;
Servo myMotorsS6;
Servo myMotorsS7;
Servo myMotorsS8;
Servo myMotorsS9;

NewPing ultrasonic(A1, A0, 100);

void setup() {
  Serial.begin(9600);

  // put your setup code here, to run once:
  myMotorsS1.attach(6);
  myMotorsS2.attach(2);
  myMotorsS3.attach(8);
  myMotorsS4.attach(4);
  myMotorsS5.attach(7);
  myMotorsS6.attach(5);
  myMotorsS7.attach(3);
  myMotorsS8.attach(9);


}

void loop() {
  // put your main code here, to run repeatedly:
  int distance = ultrasonic.ping_cm();
  checkDistance(distance);
  delay(500);
}

void checkDistance(int distance_max){
  int repeatMove = 0;

  Serial.println(distance_max);

  if(distance_max > 3 && distance_max < 10){
    scared();
  }else if(distance_max > 10 && distance_max < 30){
    do{
      walk();
      repeatMove++;
      delay(100);
    }while(repeatMove <= 4);
  }else if(distance_max > 30 && distance_max < 40){
    do{
      hello();
      repeatMove++;
    }while(repeatMove <= 2);
  }else if(distance_max > 40 && distance_max < 50){
    goodBye();
  }else{
    returnToDefault();
  }
}

void walk(){
  myMotorsS7.write(120);
  myMotorsS8.write(60);

  myMotorsS5.write(60);
  myMotorsS6.write(120);

  myMotorsS1.write(30);
  myMotorsS4.write(150);

  myMotorsS2.write(150);
  myMotorsS3.write(30);

  delay(200);
  returnToDefault();
}

void scared(){
  //Put the legs under the robot

  myMotorsS1.write(0);
  myMotorsS2.write(180);
  myMotorsS3.write(0);
  myMotorsS4.write(180);

  myMotorsS5.write(180);
  myMotorsS6.write(0);
  myMotorsS7.write(180);
  myMotorsS8.write(0);

  delay(5000);
}

void hello(){
  myMotorsS4.write(180);

  for(int i = 90; i >= 30; i--){
    myMotorsS5.write(i);
    delay(10);
  }

  if(myMotorsS5.read() == 30){
    int angle = 30;
    for(int i = 0; i < 90; i++){
      angle -= 1;
      myMotorsS5.write(angle);
      if(angle == 10){
        for(int j = angle; j <= 30; j++ ){
          myMotorsS5.write(j);
          delay(10);
        }
        angle = 30;
      }
      delay(10);
    }
  }
}

void goodBye(){
  //put legs in front
  myMotorsS1.write(20);
  myMotorsS4.write(160);

  //put legs down
  myMotorsS5.write(30);
  myMotorsS6.write(150);

  delay(1500);
}

void returnToDefault(){
  myMotorsS1.write(90);
  myMotorsS2.write(90);
  myMotorsS3.write(90);
  myMotorsS4.write(90);

  myMotorsS5.write(90);
  myMotorsS6.write(90);
  myMotorsS7.write(90);
  myMotorsS8.write(90);
}




