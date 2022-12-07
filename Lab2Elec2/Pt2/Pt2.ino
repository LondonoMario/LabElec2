#include "U8glib.h"
U8GLIB_SH1106_128X64 oled(U8G_I2C_OPT_NONE);
int a = 0;


float sv=0;
float svp=0;

int Button = 2;
int Button2 = 4;
boolean ButtonPressed = false;
boolean ButtonPressed2 = false;
boolean Toggle = false;
boolean Toggle2 = false;
int Debounce = 0;
int Debounce2 = 0;

void setup(void) {
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  Serial.begin(9600);
}

void loop(void) {
  
  //Pantalla

   oled.firstPage();
  do {
    page1();
  } while (oled.nextPage());



//Botones
  if (digitalRead(Button)==HIGH){
    Debounce++;
  }else{
    Debounce = 0;
    ButtonPressed = false;
    Toggle = false;
  }

  if(Debounce >= 2){ // How long I have to wait
    ButtonPressed = true;
  }

  if (ButtonPressed == true && Toggle == false){
    Toggle = true;
    a=a+1;
    }
  
// Boton 2

  if (digitalRead(Button2)==HIGH){
    Debounce2++;
  }else{
    Debounce2 = 0;
    ButtonPressed2 = false;
    Toggle2 = false;
  }

  if(Debounce2 >= 2){ // How long I have to wait
    ButtonPressed2 = true;
  }

  if (ButtonPressed2 == true && Toggle2 == false){
    Toggle2 = true;
    a=a-1;
    }

// Variables
  if ( a==1){

      sv=sv+32;
      digitalWrite(7, HIGH);
      digitalWrite(8, LOW);
      
      if(sv>255){
        sv=255;
      }
      analogWrite(10, sv);
  }

  if( a==-1){

      sv=sv-32;
      digitalWrite(7, HIGH);
      digitalWrite(8, LOW);
      
      if(sv<0){
       sv=0;
     }
     analogWrite(10, sv);
  }
  svp=map(sv, 0 ,650 , 0, 255);
a=0;
  
}


void page1(void) {

  oled.setFont(u8g_font_profont12);
  oled.setPrintPos(0, 10);
  oled.print((String)"Velocidad "+ sv);
  oled.setPrintPos(0, 25);
  oled.print((String)"Velocidad %: "+ svp);
  oled.setPrintPos(0, 40);
  oled.print(a);
  oled.setPrintPos(0, 55);
  oled.print("?");
}


