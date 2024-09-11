//Leds Rojos
int Seccion1IngLed = 8;
int Seccion2IngLed = 9;
int Seccion3IngLed = 10;

int Seccion1LicLed = 11;
int Seccion2LicLed = 12;
int Seccion3LicLed = 13;

//Leds RGB
int reding = A5;  //Ingenieria
int blueing = A4;

int redlic = A3; //Licenciatura
int bluelic = A2;

//Seccion de Ingenieria
int infrarrojo1Ing = 2;
int infrarrojo2Ing = 3;
int infrarrojo3Ing = 4;

//Seccion de Licenciatura
int infrarrojo1Lic = 5;
int infrarrojo2Lic = 6;
int infrarrojo3Lic = 7; 

//estados del sistema de bicis
bool ingenieria = false;
bool Licenciatura = false;

void setup() {
  Serial.begin(9600);
   //LEDS ROJOS
   pinMode(Seccion1IngLed, OUTPUT); //Ingenieria
   pinMode(Seccion2IngLed, OUTPUT);
   pinMode(Seccion3IngLed, OUTPUT);
   
   pinMode(Seccion1LicLed, OUTPUT); //Licenciatura
   pinMode(Seccion2LicLed, OUTPUT);
   pinMode(Seccion3LicLed, OUTPUT);
  
   //RGB
   pinMode(reding, OUTPUT);
   pinMode(blueing, OUTPUT);

   pinMode(redlic, OUTPUT);
   pinMode(bluelic, OUTPUT);

  //Infrarrojo
  pinMode(INPUT, infrarrojo1Ing);
  pinMode(INPUT, infrarrojo2Ing);
  pinMode(INPUT, infrarrojo3Ing);
  pinMode(INPUT, infrarrojo1Lic);
  pinMode(INPUT, infrarrojo2Lic);
  pinMode(INPUT, infrarrojo3Lic);
}

void loop() {
//Lectura de sensores infrarrojos
int Seccion1Inge = digitalRead(infrarrojo1Ing);
int Seccion2Inge = digitalRead(infrarrojo2Ing);
int Seccion3Inge = digitalRead(infrarrojo3Ing);

int Seccion1Lic = digitalRead(infrarrojo1Lic);
int Seccion2Lic = digitalRead(infrarrojo2Lic);
int Seccion3Lic = digitalRead(infrarrojo3Lic);
//

//Seccion Ingenieria
if(Seccion1Inge){
//Encender LED especifico
//Enviar senal de cubiculo 
Serial.println("90");
digitalWrite(Seccion1IngLed, 1); //NO HAY BICI
} else {
Serial.println("09");
digitalWrite(Seccion1IngLed, 0);
}

if(Seccion2Inge){
//Encender LED especifico
//Enviar senal de cubiculo 1 inge
Serial.println("20");
digitalWrite(Seccion2IngLed, 1); 
} else {
Serial.println("02");
digitalWrite(Seccion2IngLed, 0);
}

if(Seccion3Inge){
//Encender LED especifico
//Enviar senal de cubiculo 1 inge
Serial.println("30");
digitalWrite(Seccion3IngLed, 1); 
} else {
Serial.println("03");
digitalWrite(Seccion3IngLed, 0);
}

///////////////////////////////////////////////////////
//Seccion Licenciatura

if(Seccion1Lic){
//Encender LED especifico
//Enviar senal de cubiculo 1 
Serial.println("40");
digitalWrite(Seccion1LicLed, 1); 
} else {
Serial.println("04");
digitalWrite(Seccion1LicLed, 0);
}

if(Seccion2Lic){
//Encender LED especifico
//Enviar senal de cubiculo 1 inge
Serial.println("50");
digitalWrite(Seccion2LicLed, 1); 
} else {
Serial.println("05");
digitalWrite(Seccion2LicLed, 0);
}

if(Seccion3Lic){
//Encender LED especifico
//Enviar senal de cubiculo 1 inge
Serial.println("60");
digitalWrite(Seccion3LicLed, 1); 
} else {
Serial.println("06");
digitalWrite(Seccion3LicLed, 0);
}


int ContadorInge = Seccion1Inge + Seccion2Inge + Seccion3Inge;
if (ContadorInge >= 2) {
    analogWrite(reding, 255);
    analogWrite(blueing, 255);
    Serial.println("100");
} else {
    analogWrite(reding, 0);
    analogWrite(blueing, 0);
    Serial.println("001");
}

// Seccion Licenciatura
int ContadorLic = Seccion1Lic + Seccion2Lic + Seccion3Lic;
if (ContadorLic >= 2) {
    Serial.println("202");
    analogWrite(redlic, 255);
    analogWrite(bluelic, 255);
} else {
    Serial.println("123");
    analogWrite(redlic, 0);
    analogWrite(bluelic, 0);
}


}