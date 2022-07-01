// C++ code
//
#include <Adafruit_NeoPixel.h>
int dist = 0;
int aviso = 0;
int aviso_arriba=0;

Adafruit_NeoPixel pixels_abajo = Adafruit_NeoPixel(8,3,NEO_RGB + NEO_KHZ800); 
Adafruit_NeoPixel pixels_arriba = Adafruit_NeoPixel(8,2,NEO_RGB + NEO_KHZ800); 

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}



void setup()
{
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(8, OUTPUT); //timbre
  pinMode(10,INPUT); //led abajo
  pinMode(11,INPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(9,OUTPUT);//pin led del medio
  pixels_abajo.begin();
  pixels_abajo.show();
  pixels_arriba.begin();
  pixels_arriba.show();
}

void loop()
{
  pixels_abajo.setBrightness(255);
  pixels_arriba.setBrightness(255);
  
  dist = 0.01723 * readUltrasonicDistance(A0, A0);
  //digitalWrite(3,LOW);
  digitalWrite(9,LOW);
  //digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  if (dist < 100 && dist > 50) {
    digitalWrite(13, HIGH); //VERDE
    tone(8, 523, 150); // play tone 60 (C5 = 523 Hz)
    delay(150);
  }else
    if (dist < 50 && dist > 30) {
      digitalWrite(9, HIGH);//MORADO
      digitalWrite(13, HIGH);//VERDE
      tone(8, 523, 100); // tone(pin,frequency,duration)
      delay(100);
    }else
    if (dist < 30) {
      //digitalWrite(11, HIGH);
      digitalWrite(9, HIGH);//GRIS
      digitalWrite(12, HIGH);//MORADO
      digitalWrite(13, HIGH);//VERDE
      tone(8, 523, 25); // play tone 80 (G#6 = 1661 Hz)
      delay(50);
  }
  
  if (digitalRead(11) == HIGH && aviso==0) {
    aviso=1;
    pixels_abajo.setPixelColor(0, 255, 255, 1);
    delay(10);
    pixels_abajo.show();
    if (digitalRead(11) == HIGH && aviso==1) {
      aviso=2;
      //digitalWrite(12, HIGH);
      pixels_abajo.setPixelColor(0, 255, 255, 1);
      delay(50);
      pixels_abajo.setPixelColor(1, 255, 255, 1);
      pixels_abajo.show();
      if (digitalRead(11) == HIGH || aviso==2) {
        aviso=3;
        //digitalWrite(12, HIGH);
        pixels_abajo.setPixelColor(0, 255, 255, 1);
        delay(50);
        pixels_abajo.setPixelColor(1, 255, 255, 1);
        delay(50);
        pixels_abajo.setPixelColor(2, 255, 255, 1);
        pixels_abajo.show();
        if (digitalRead(11) == HIGH || aviso==3) {
          aviso=4;
          pixels_abajo.setPixelColor(0, 255, 255, 1);
          delay(10);
          pixels_abajo.setPixelColor(1, 255, 255, 1);
          delay(10);
          pixels_abajo.setPixelColor(2, 255, 255, 1);
          delay(10);
          pixels_abajo.setPixelColor(3, 255, 255, 1);
          pixels_abajo.show();
          if (digitalRead(11) == HIGH && aviso==4) {
            aviso=5;
         
            pixels_abajo.setPixelColor(0, 255, 255, 1);
            delay(10);
            pixels_abajo.setPixelColor(1, 255, 255, 1);
            delay(10);
            pixels_abajo.setPixelColor(2, 255, 255, 1);
            delay(10);
            pixels_abajo.setPixelColor(3, 255, 255, 1);
            delay(10);
            pixels_abajo.setPixelColor(4, 255, 255, 1);
            pixels_abajo.show();
            if (digitalRead(11) == HIGH || aviso==5) {
              aviso=6;
              pixels_abajo.setPixelColor(0, 255, 255, 1);
              delay(10);
              pixels_abajo.setPixelColor(1, 255, 255, 1);
              delay(10);
              pixels_abajo.setPixelColor(2, 255, 255, 1);
              delay(10);
              pixels_abajo.setPixelColor(3, 255, 255, 1);
              delay(10);
              pixels_abajo.setPixelColor(4, 255, 255, 1);
              delay(10);
              pixels_abajo.setPixelColor(5, 255, 255, 1);
              pixels_abajo.show();
              if (digitalRead(11) == HIGH || aviso==6) {
                aviso=7;
                pixels_abajo.setPixelColor(0, 255, 255, 1);
                delay(10);
                pixels_abajo.setPixelColor(1, 255, 255, 1);
                delay(10);
                pixels_abajo.setPixelColor(2, 255, 255, 1);
                delay(10);
                pixels_abajo.setPixelColor(3, 255, 255, 1);
                delay(10);
                pixels_abajo.setPixelColor(4, 255, 255, 1);
                delay(10);
                pixels_abajo.setPixelColor(5, 255, 255, 1);
                delay(10);
                pixels_abajo.setPixelColor(6, 255, 255, 1);
                pixels_abajo.show();
                if (digitalRead(11) == HIGH || aviso==7) {
                  aviso=0;
                  pixels_abajo.setPixelColor(0, 255, 255, 1);
                  delay(10);
                  pixels_abajo.setPixelColor(1, 255, 255, 1);
                  delay(10);
                  pixels_abajo.setPixelColor(2, 255, 255, 1);
                  delay(10);
                  pixels_abajo.setPixelColor(3, 255, 255, 1);
                  delay(10);
                  pixels_abajo.setPixelColor(4, 255, 255, 1);
                  delay(10);
                  pixels_abajo.setPixelColor(5, 255, 255, 1);
                  delay(10);
                  pixels_abajo.setPixelColor(6, 255, 255, 1);
                  delay(10);
                  pixels_abajo.setPixelColor(7, 255, 255, 1);
                  pixels_abajo.show();
                  pixels_abajo.clear();
                }else{
                digitalWrite(12,LOW);
                aviso=0;
                pixels_abajo.clear();
                pixels_abajo.show();

                }
              }else{
                digitalWrite(12,LOW);
                aviso=0;
                pixels_abajo.clear();
                pixels_abajo.show();

              }
            }else{
              digitalWrite(12,LOW);
              aviso=0;
              pixels_abajo.clear();
              pixels_abajo.show();

            }
                
          }else{
            digitalWrite(12,LOW);
            aviso=0;
            pixels_abajo.clear();
            pixels_abajo.show();

          }
        }else{
          digitalWrite(12,LOW);
          aviso=0;
          pixels_abajo.clear();
          pixels_abajo.show();

        }
      }else{
        digitalWrite(12,LOW);
        aviso=0;
        pixels_abajo.clear();
        pixels_abajo.show();

      }
    }else{
      digitalWrite(12,LOW);
      aviso=0;
      pixels_abajo.clear();
      pixels_abajo.show();

    }
    
  }else{
    digitalWrite(12,LOW);
    aviso=0;
    pixels_abajo.clear();
    pixels_abajo.show();
  
  }
  
  if (digitalRead(10) == HIGH && aviso_arriba==0) {
    aviso=1;
    pixels_arriba.setPixelColor(7, 255, 255, 1);
    delay(10);
    pixels_arriba.show();
    if (digitalRead(10) == HIGH && aviso==1) {
      aviso=2;
      pixels_arriba.setPixelColor(7, 255, 255, 1);
      delay(50);
      pixels_arriba.setPixelColor(6, 255, 255, 1);
      pixels_arriba.show();
      if (digitalRead(10) == HIGH || aviso==2) {
        aviso=3;
        //digitalWrite(12, HIGH);
        pixels_arriba.setPixelColor(7, 255, 255, 1);
        delay(50);
        pixels_arriba.setPixelColor(6, 255, 255, 1);
        delay(50);
        pixels_arriba.setPixelColor(5, 255, 255, 1);
        pixels_arriba.show();
        if (digitalRead(10) == HIGH || aviso==3) {
          aviso=4;
          pixels_arriba.setPixelColor(7, 255, 255, 1);
          delay(10);
          pixels_arriba.setPixelColor(6, 255, 255, 1);
          delay(10);
          pixels_arriba.setPixelColor(5, 255, 255, 1);
          delay(10);
          pixels_arriba.setPixelColor(4, 255, 255, 1);
          pixels_arriba.show();
          if (digitalRead(10) == HIGH && aviso==4) {
            aviso=5;
         
            pixels_arriba.setPixelColor(7, 255, 255, 1);
            delay(10);
            pixels_arriba.setPixelColor(6, 255, 255, 1);
            delay(10);
            pixels_arriba.setPixelColor(5, 255, 255, 1);
            delay(10);
            pixels_arriba.setPixelColor(4, 255, 255, 1);
            delay(10);
            pixels_arriba.setPixelColor(3, 255, 255, 1);
            pixels_arriba.show();
            if (digitalRead(10) == HIGH || aviso==5) {
              aviso=6;
              pixels_arriba.setPixelColor(7, 255, 255, 1);
              delay(10);
              pixels_arriba.setPixelColor(6, 255, 255, 1);
              delay(10);
              pixels_arriba.setPixelColor(5, 255, 255, 1);
              delay(10);
              pixels_arriba.setPixelColor(4, 255, 255, 1);
              delay(10);
              pixels_arriba.setPixelColor(3, 255, 255, 1);
              delay(10);
              pixels_arriba.setPixelColor(2, 255, 255, 1);
              pixels_arriba.show();
              if (digitalRead(10) == HIGH || aviso==6) {
                aviso=7;
                pixels_arriba.setPixelColor(7, 255, 255, 1);
                delay(10);
                pixels_arriba.setPixelColor(6, 255, 255, 1);
                delay(10);
                pixels_arriba.setPixelColor(5, 255, 255, 1);
                delay(10);
                pixels_arriba.setPixelColor(4, 255, 255, 1);
                delay(10);
                pixels_arriba.setPixelColor(3, 255, 255, 1);
                delay(10);
                pixels_arriba.setPixelColor(2, 255, 255, 1);
                delay(10);
                pixels_arriba.setPixelColor(1, 255, 255, 1);
                pixels_arriba.show();
                if (digitalRead(10) == HIGH || aviso==7) {
                  aviso=0;
                  pixels_arriba.setPixelColor(7, 255, 255, 1);
                  delay(10);
                  pixels_arriba.setPixelColor(6, 255, 255, 1);
                  delay(10);
                  pixels_arriba.setPixelColor(5, 255, 255, 1);
                  delay(10);
                  pixels_arriba.setPixelColor(4, 255, 255, 1);
                  delay(10);
                  pixels_arriba.setPixelColor(3, 255, 255, 1);
                  delay(10);
                  pixels_arriba.setPixelColor(2, 255, 255, 1);
                  delay(10);
                  pixels_arriba.setPixelColor(1, 255, 255, 1);
                  delay(10);
                  pixels_arriba.setPixelColor(0, 255, 255, 1);
                  pixels_arriba.show();
                  pixels_arriba.clear();
                }else{
                aviso=0;
                pixels_arriba.clear();
                pixels_arriba.show();

                }
              }else{       
                aviso=0;
                pixels_arriba.clear();
                pixels_arriba.show();

              }
            }else{             
              aviso=0;
              pixels_arriba.clear();
              pixels_arriba.show();

            }
                
          }else{
            aviso=0;
            pixels_arriba.clear();
            pixels_arriba.show();

          }
        }else{  
          aviso=0;
          pixels_arriba.clear();
          pixels_arriba.show();

        }
      }else{
        aviso=0;
        pixels_arriba.clear();
        pixels_arriba.show();

      }
    }else{
      aviso=0;
      pixels_arriba.clear();
      pixels_arriba.show();

    }
    
  }else{
    aviso=0;
    pixels_arriba.clear();
    pixels_arriba.show();
  
  }
  
}
