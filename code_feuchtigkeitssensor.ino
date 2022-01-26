int pinFeuchtigkeitMessen = A0; // analoger Pin, an dem der kapazitive Feuchtigkeitssensor angeschlossen ist
int pinGiessen; // Pin an dem die Wasserpumpe angeschlossen ist
int bodenfeuchtigkeit; // analoger Messwert der Feuchtigkeit der Erde

void setup() {
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() {
  bodenfeuchtigkeit = feuchtigkeitMessen();
  Serial.println(bodenfeuchtigkeit);
  delay(1000);

  if (bodenfeuchtigkeit > 500) {
    giessen();
  }
}

// misst die Feuchtigkeit im Boden
// Messwert bei trockener Umgebung: 625
// Messwert im Wasser: 315
int feuchtigkeitMessen() {
  int messwert = analogRead(pinFeuchtigkeitMessen);
  return messwert;
}

// giesst die Pflanze
void giessen() {
  Serial.println(":)");
}
