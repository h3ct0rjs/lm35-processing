void drawGraph(){  
  for (int i=0; i<arrayAltura.length-1; i++){
     arrayAltura[i] = arrayAltura[i+1];
   }

  temperaturaActual = int(inDataArduino);
  arrayAltura[arrayAltura.length-1] = int(map(temperaturaActual, 0, 1023, 0, height));       // set the rightmost pixel to the new data point value
  stroke(0,200,250);
  strokeWeight(2);
  noFill(); 
  beginShape();
  for (int i=0; i < arrayAltura.length-1; i++){  
    vertex(i, height- arrayAltura[i]);   // dibuja los vertices, y conecta los diferentes puntos.             
  }
  endShape();
}