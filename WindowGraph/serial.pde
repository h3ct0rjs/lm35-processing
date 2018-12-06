void serialEvent (Serial myPort) {
  inDataArduino = myPort.readStringUntil('\n');
  if (inDataArduino != null) {
    inDataArduino = trim(inDataArduino);
    }
}