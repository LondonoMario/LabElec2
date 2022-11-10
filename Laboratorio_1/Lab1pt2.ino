int ValorBoton = 0;
int ValorBoton2 = 0;
int a=0;
void setup() {
 Serial.begin(9600); //Iniciar conexión serial
 //Configurar el pin 2 como entrada y habilite la resistencia pull-up interna
 pinMode(2, INPUT_PULLUP);
 pinMode(4, INPUT_PULLUP);
 pinMode(13, OUTPUT);
 pinMode(3, OUTPUT);
 pinMode(5, OUTPUT); //Pin 13 como salida
}
void loop() {
 //Leer el valor del pulsador en una variable
  ValorBoton = digitalRead(2);
  ValorBoton2 = digitalRead(4);
  digitalWrite(13, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(5, HIGH);
 // Se enciende el pin 13 y se envía el estado por el puerto serial
  if (ValorBoton == LOW) {
    a = 1;
    digitalWrite(13, LOW);
    delay(5000);
    digitalWrite(13, HIGH);
    digitalWrite(3, LOW);
    delay(5000);
    digitalWrite(3, HIGH);
    digitalWrite(5, LOW);
    delay(5000);
    digitalWrite(5, HIGH);
    Serial.println("Presionado 1 ");
  }
  while (a == 1) {
    ValorBoton2 = digitalRead(4);
    Serial.println("Presionado 1 ");
    if (ValorBoton2 == LOW) {
      Serial.println("Presionado 2 apagando");
      digitalWrite(5, LOW);
      delay(5000);
      digitalWrite(3, LOW);
      delay(5000);
      digitalWrite(13, LOW);
      delay(5000);
      digitalWrite(5, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(13, HIGH);
      
      a = 0;
    //delay(1000);
 }
    //delay(1000);
 } 

  Serial.println("Sin presionar");

}