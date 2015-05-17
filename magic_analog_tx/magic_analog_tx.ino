/*
  Example Bluetooth Serial Passthrough Sketch
 by: Jim Lindblom
 SparkFun Electronics
 date: February 26, 2013
 license: Public domain

 This example sketch converts an RN-42 bluetooth module to
 communicate at 9600 bps (from 115200), and passes any serial
 data between Serial Monitor and bluetooth module.
 */

#include <SoftwareSerial.h>

int TX = 8;  // cxn to RX pin of bluetooth mate, Arduino D8
int RX = 9;  // cxn to TX pin of bluetooth mate, Arduino D9

SoftwareSerial bluetooth(RX, TX);
int sensorPin = A0;
  int sensorValue = 0;
  String sensorValueString = "";

void setup()
{
  pinMode(13, OUTPUT);  // this pin will pull the HC-05 pin 34 (key pin) HIGH to switch module to AT mode
  digitalWrite(13, HIGH);
  pinMode(3, OUTPUT);
  analogWrite(3, 127);
  delay(2000);
  Serial.begin(9600);  // Begin the serial monitor at 9600bps
  
  //bluetooth.begin(38400);  // The Bluetooth Mate defaults to 115200bps
  bluetooth.begin(9600);  // The Bluetooth Mate defaults to 115200bps
  //bluetooth.println("AT+ROLE=1");  // Temporarily Change the baudrate to 9600, no parity
  // 115200 can be too fast at times for NewSoftSerial to relay the data reliably
  //bluetooth.begin(9600);  // Start bluetooth serial at 9600
}

void loop()
{
  sensorValue = analogRead(sensorPin);
  sensorValueString = String(sensorValue, DEC);
  bluetooth.print(sensorValueString);
  if (bluetooth.available()) // If the bluetooth sent any characters
  {

  }
  if (Serial.available()) // If stuff was typed in the serial monitor
  {
    // Send any characters the Serial monitor prints to the bluetooth
    //bluetooth.println((char)Serial.read());
  }
  bluetooth.print("\n");
  delay(500);
  // and loop forever and ever!
}


