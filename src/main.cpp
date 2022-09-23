// I, Damanpreet Singh, student number 000741359, certify that all code submitted is my own work;
// that I have not copied it from any other source.
// I also certify that I have not allowed my work to be copied by others.

#include <Arduino.h> 
 
void setup() { 
  // configure the USB serial monitor 
  Serial.begin(115200); 
} 
 
void loop() { 
  int iVal;  // variable to read agalog
  double val; // variable to get mapped value
  String condition;  //String value to map condition

  // read digitized value from the D1 Mini's A/D convertor 
  iVal = analogRead(A0); 

  // val = map(iVal, 0, 1023, 0,3300 );

  val = map(iVal, 0, 1023, 0,5000 );

  if (val < 1000) {
    condition = " Cold!";
  }
  else if (val > 1000 && val <1500) {
    condition = " Cool";
  }
  else if (val > 1500 && val <2500) {
    condition = " Perfect ";
  }
  else if (val > 2500 && val <3000) {
    condition = " Warm";
  }
  else if (val > 3000 && val <3500) {
    condition = " Hot";
  }
  else if (val > 3500) {
    condition = " Too Hot!";
  }

  // analogWrite(9,val);
  // print value to the USB port 
  Serial.println("Digitized Value = " + String(iVal)+ " is equivalent to Temperatue of "+ val/100 + " deg C. , Which is "+ condition); 
 
  // wait 0.5 seconds (500 ms) 
  delay(2000); 
} 

