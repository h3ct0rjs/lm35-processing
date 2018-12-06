
void drawTextTemp(){
  fill(255, 0, 0);                  
  textFont(font,15);
  background(0);
  text("Temperatura", width - 120, 40);
  textFont(font,30);
  float value = map(temperaturaActual,0,1023,0,100);
  text(int(value), width - 110, 90);
}
