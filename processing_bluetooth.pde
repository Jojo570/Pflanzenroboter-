import processing.serial.*;

Serial port; // Deklaration des Objektes Port
String string; // epfaengt Daten vom arduino

void setup() {
  port = new Serial(this, "COM7", 9600); // oeffnet den seriellen Port
  port.bufferUntil('\n'); // serial input wartet bis newline character
}

void draw() {
  printArray(string);
}

void keyPressed() {
  if (key=='1') {
    port.write('1');
  }
  if (key=='0') {
    port.write('0');
  }
}

void serialEvent(Serial port) {
  string = port.readStringUntil('\n');
}
