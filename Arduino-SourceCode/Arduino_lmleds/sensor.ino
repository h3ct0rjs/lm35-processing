// Sensor Reader for LM35.
// Arduino uno, lm35, Felipe Cadavid.
// Definimos los pines para el led RGB
int ledBlue = 8;
int ledGreen = 9;
int ledRed = 10;

int val;                         // variables para retener el valor leido 
int tempPin = A0;                //definicion de variable para pin analogico de entrada.

//A0, and A1, will be the pin  port for the lm35.
// La funcion setup solo se ejecuta una sola vez.
void setup() {                
  // Inicializamos los pines como salidas.
  pinMode(ledBlue, OUTPUT);     
  pinMode(ledRed, OUTPUT);   
  pinMode(ledGreen, OUTPUT);   
  //Inicializamos el dispositivo serial con una velocidas de 9600bps.
  Serial.begin(9600);
}


// La rutina Loop es una funcion infinita que se ejecuta por siempre, 
// cada vez que el arduino detecte 5V,el ejecutara el programa de abajo.
void loop() {
  
  val = analogRead(tempPin);        // leemos el valor en mv del convertidor ADC.
  float mv = ( val/1024.0)*5000;    // convertimos el valor en un rando de 0 a 1023. siendo 0>>0° y 1023>>100°
  float temp = mv/10;                // obtenemos cuantos grados celsius son, cada grado se representa por 10mv
  
  //Enviamos el valor a processing.  https://www.arduino.cc/reference/en/language/functions/math/map/
  
  Serial.println(map(temp,0,100,0,1023));    // Leemos los datos del canal analogico, lo enviamos a processing.
  // por consistencia queremos enviar muchos datos a processing
  // esto mejorara la grafica presentada. toda la estabilidad 
  // grafica se realizara en processing.
  delay(2);  
  //Esto es un ejemplo de logica de lo que se podria hacer, si el sensor de la temperatura es > a algo, 
  // haga algo. En este caso 
  if(temp>30){
      digitalWrite(ledBlue, LOW);    // turn the LED off by making the voltage LOW  
      digitalWrite(ledGreen, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(200);               // wait for a second
  }
  else{
  DispositivoOperativo();  
  }
}

// Funcion para hacer el destello del Led Azul.
void DispositivoOperativo(){
  digitalWrite(ledGreen, LOW);    // turn the LED off by making the voltage LOW  
  digitalWrite(ledBlue, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);               // wait for a second
  digitalWrite(ledBlue, LOW);    // turn the LED off by making the voltage LOW  
  delay(100);               // wait for a second
}
