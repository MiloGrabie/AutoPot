// A CHANGER
#include "conf.h"
#include "arduino.h"
#include <SoftwareSerial.h>
 String message;
    // Boucle de lecture sur le BT
    // Reading BT
    while (BTSerial.available()){
      // Lecture du message envoyÃ© par le BT
      // Read message send by BT
      message = BTSerial.readString();
      // Ecriture du message dans le serial usb
      // write in serial usb
      Serial.println(message);
    }
    // Boucle de lecture sur le serial usb
    // Reading serial usb
    void test1() {
    while (Serial.available()){
      // Lecture du message envoyÃ© par le serial usb
      // Read message send by serial usb
      message = Serial.readString();
      // Ecriture du message dans le BT
      // write in BT 
      BTSerial.println(message);
    }
    }
  // si mon message est egal a "on"  ( + retour chariot et nouvelle ligne )
  // if message equal to "on" (+ carriage return and newline )
  void test2 () {
    if(message == "on\r\n"){
      digitalWrite(PIN_LED,HIGH); // led on
    }// else if message off
    else if(message == "off\r\n"){
      digitalWrite(PIN_LED,LOW); } // led off 
  }
