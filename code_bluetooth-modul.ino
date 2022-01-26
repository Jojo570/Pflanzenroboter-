#include <SoftwareSerial.h>

int bluetoothPinTXD = 2;
int bluetoothPinRXD = 3;

SoftwareSerial EEBlue(bluetoothPinTXD, bluetoothPinRXD); // RX | TX
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  EEBlue.begin(9600);  //Default Baud for comm, it may be different for your Module. 
  Serial.println("The bluetooth gates are open.\n Connect to HC-05 from any other bluetooth device with 1234 as pairing key!.");
  digitalWrite(LED_BUILTIN, HIGH);
}
 
void loop()
{ 
  if (EEBlue.available()) {
    if (EEBlue.read() == '1') {
      digitalWrite(LED_BUILTIN, HIGH);
    }
    if (EEBlue.read() == '0') {
      digitalWrite(LED_BUILTIN, LOW);
    }
  }
 
  // Feed any data from bluetooth to Terminal.
//  if (EEBlue.available())
//    Serial.write(EEBlue.read());
// 
//  // Feed all data from termial to bluetooth
//  if (Serial.available())
//    EEBlue.write(Serial.read());
} 
