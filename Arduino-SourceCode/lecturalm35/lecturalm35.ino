/*
Ejemplo de lectura de sensor de temperatura lm35
*/
int val;
int tempPin = A0;
void setup()
{
Serial.begin(9600);
}
void loop()
{
val = analogRead(tempPin);        // leemos el valor en mv del convertidor ADC.
float mv = ( val/1024.0)*5000;    // convertimos el valor en un rando de 0 a 1023. siendo 0>>0° y 1023>>100°
float cel = mv/10;                // obtenemos cuantos grados celsius son, cada grado se representa por 10mv
                                  // vease el datasheet : http://www.ti.com/lit/ds/symlink/lm35.pdf

Serial.print("TEMPRATURE = ");    // ponemos el valor en consola serial.
Serial.print(cel);
Serial.print("*C");
Serial.println();      
delay(1000);

}

