//Last update on 24 July 2018

#include <Servo.h>

Servo gc;

void setup() {   
  pinMode(2, INPUT); //LimitSwitch
  pinMode(7, INPUT); //CountSensor
  pinMode(8, OUTPUT); //Buzzer

  //booting sound is for human noticed when board is start/reboot
  tone(8, 2000, 500); //booting sound
  delay(500);
  
  gc.attach(9); //Servo
  gc.write(180); //initial 180

  delay(1500);

  tone(8, 2000, 200); //ready beep
  delay(220);
  tone(8, 2000, 200);
  delay(220);
}

int limitsw = 0;
int countsw = 0;
int coinin = 0;

void loop(){

  countsw = digitalRead(7);
  if (countsw == HIGH){ //if coin in
    coinin = 1;

    tone(8, 1500, 170);
    delay(180);
    tone(8, 1500, 170);
    delay(180);
  }

  limitsw = digitalRead(2);
  if (coinin == 1){
    
    if (limitsw == HIGH) { //if coin in and limit switch press
      tone(8, 2000, 300);
      delay(400);
      gc.write(0);
      delay(1500);
      gc.write(180);
      delay(0);
    } 
        
  }else{
    
    if (limitsw == HIGH) { //if limit switch press but coin not in
      tone(8, 1500, 170);
      delay(180);
      tone(8, 1500, 170);
      delay(180);
      tone(8, 1500, 170);
      delay(180);
    }
    
  }

  delay(20);
  
}
