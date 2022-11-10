int Button = 2;
int Button2 = 4;
boolean ButtonPressed = false;
boolean ButtonPressed2 = false;
boolean Toggle = false;
boolean Toggle2 = false;
int a=-1;
int b=-1;
int Debounce = 0;
int Debounce2 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Button, INPUT);
  pinMode(Button2, INPUT);
  pinMode(13, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT); //Pin 13 como salida
}

void loop() {

  if (digitalRead(Button)==HIGH){
    Debounce++;
  }else{
    Debounce = 0;
    ButtonPressed = false;
    Toggle = false;
  }

  if(Debounce >= 5){ // How long I have to wait
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

  if(Debounce2 >= 5){ // How long I have to wait
    ButtonPressed2 = true;
  }

  if (ButtonPressed2 == true && Toggle2 == false){
    Toggle2 = true;
    b=b+1;
    }

  if(a>3){
    a=0;
  }

  if (b>1){
    b=0;
  }
    if(a==0 || b== 0){
    digitalWrite(13, HIGH );
    digitalWrite(5, HIGH);
    digitalWrite(3, HIGH);
    Serial.println("Nada Encendido");

  }
  if(a==1 && b== 1){
    digitalWrite(13, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(3, HIGH);
    Serial.println("Bombillo Encendido");
  }


  if(a==2 && b == 1){
    digitalWrite(13, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(3, LOW);
    Serial.println("Trafo Encendido");
  }


  if(a==3 && b == 1){
    digitalWrite(13, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(3, HIGH);
    Serial.println("Motor Encendido");
  }
  

  Serial.println(a);
}
