#include "U8glib.h"
U8GLIB_SH1106_128X64 oled(U8G_I2C_OPT_NONE);
int a = 0;
float sensorValor;
float sensorValorGrados;

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
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop(void) {
  //Variables
  sensorValor = analogRead(A0);
  sensorValor = sensorValor*100/1024;
  sensorValorGrados = map(sensorValor, 0, 100, 0, 290);
  analogWrite(11, sensorValorGrados*0.8);

  if(sensorValorGrados<80){
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH); //Verificar el relé
  //analogWrite(11, sensorValorGrados*0.6);

  }  
  if(sensorValorGrados>=80){
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH); //Verificar el relé
  //analogWrite(11, sensorValorGrados*0.6);

  }
  if(sensorValorGrados>=150){
  //digitalWrite(7, LOW);
  //digitalWrite(8, LOW);
  digitalWrite(10, LOW);
  //analogWrite(11, sensorValorGrados*0.6);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  //digitalWrite(9, LOW); //Verificar el relé
  }
  if(sensorValorGrados>=220){
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  //digitalWrite(10, LOW); //Verificar el relé
  //digitalWrite(9, LOW);
  //analogWrite(11, sensorValorGrados*0.5);
  }  

  //Pantalla

   oled.firstPage();
  do {
    page1();
  } while (oled.nextPage());
delay(10);

  
}


void page1(void) {

  oled.setFont(u8g_font_profont12);
  oled.setPrintPos(0, 10);
  oled.print((String)"Angulo °: "+ sensorValorGrados);
  if(sensorValorGrados<80){
    oled.setPrintPos(0, 25);
    oled.print((String)"Motor derecha ");
  }
  if(sensorValorGrados>=80 && sensorValorGrados<150){
    oled.setPrintPos(0, 25);
    oled.print((String)"Motor dere Trafo ON");
    }
  if(sensorValorGrados>=150 && sensorValorGrados<220){
    oled.setPrintPos(0, 25);
    oled.print((String)"Motor dere bomb ON");
  }
    if(sensorValorGrados>220){
    oled.setPrintPos(0, 25);
    oled.print((String)"Motor izq");
  }
  oled.setPrintPos(0, 40);
  oled.print(a);
  oled.setPrintPos(0, 55);
  oled.print("?");
  delay(100);
}



