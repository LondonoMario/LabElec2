#include "U8glib.h"
U8GLIB_SH1106_128X64 oled(U8G_I2C_OPT_NONE);
int a = 0;
int count=0;
float tempf;
float temp;
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
}

void loop(void) {
  //Variables
  count++;
  if(count == 5){
  temp = analogRead(A1);
  temp = (temp/1023)*5000 / 10;
  tempf = temp*(9/5)+32;
  sensorValor = analogRead(A0);
  sensorValor = sensorValor*100/1024;
  sensorValorGrados = map(sensorValor, 0, 100, 0, 290);
  count=0;
  }
  //Pantalla
  if(a==0){
   oled.firstPage();
  do {
    page1();
  } while (oled.nextPage());

  }
  if(a==1 || a>1){
    oled.firstPage();
  do {
    page2();
  } while (oled.nextPage());

  }

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
    a=0;
    }

//

  
}


void page1(void) {

  oled.setFont(u8g_font_profont12);
  oled.setPrintPos(0, 10);
  oled.print((String)"Temperatura C°: "+ temp);
  oled.setPrintPos(0, 25);
  oled.print((String)"Temperatura F°: "+ tempf);
  oled.setPrintPos(0, 40);
  oled.print(a);
  oled.setPrintPos(0, 55);
  oled.print("?");
}

void page2(void) {

  oled.setFont(u8g_font_profont11);
  oled.setPrintPos(0, 10);
  oled.print((String)"Angulo: " + sensorValorGrados);
  oled.setPrintPos(0, 25);
  oled.print(a);
  oled.setPrintPos(0, 40);
  oled.print("");
  oled.setPrintPos(0, 55);
  oled.print("");
}



