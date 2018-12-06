void drawTextState(){
  fill(192,192,192);
    textFont(font,30);
    text("Estado", width - 120, height-100);
    if (temperaturaActual<300){
    textFont(font,20);
        fill(0,128,255);
        text(states.get(0), width - 120, height-70);
      }
  else if(temperaturaActual>300 && temperaturaActual<700){
    textFont(font,20);
        fill(128,255,100);
        text(states.get(1), width - 120, height-70);
      }
  else {
    textFont(font,18);
        fill(255,0,0);

    text(states.get(2), width - 130, height-70);
      }
  stroke(255,255,255);
    line(Xmaxgraph, 0, Xmaxgraph, height);

}
