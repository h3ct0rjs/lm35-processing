import processing.serial.*;
Serial myPort;
int xPos = 1; 
int temperaturaActual;         
float temperaturaPreviaAltura = 0;  
String inDataArduino;               
int []arrayAltura;
int Xmaxgraph;
StringList states = new StringList();
PFont font;        

/* 
Al igual que en arduino, processing tiene dos funciones principales: 
void setup(){}: Es donde configuramos todos los aspectos de los graficos, dispositivos a usar, 
por ejemplo se establece el tamaño de la ventana, si queremos colores de fondo etc.

void draw(){}: Esta es analoga a la funcion loop() de arduino, en este caso se llama draw, 
que es lo que el programa siempre estara  dibujando en la ventana. Esta funcion sera ejecutado por 
siempre, es decir demanera infinita, solo para cuando destruimos la ventana grafica.
*/
void setup () {
    
    size(600,600);
    Xmaxgraph = int(width-(width/4)); 
    frameRate(100);
    myPort = new Serial(this, Serial.list()[0], 9600);
    myPort.bufferUntil('\n');
    background(0);
    font = createFont("Arial",32,true); 
    arrayAltura = new int[Xmaxgraph];

    for(int i=0;i<arrayAltura.length;i++){
        arrayAltura[i] = 0;
    }
    states.append("::FRIO::");
    states.append("::MEDIO::");    
    states.append("::CALIENTE::");  
}

void draw (){
 drawTextTemp();  
 drawTextState(); 
 drawGraph();    
}