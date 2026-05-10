#include <Wire.h>
#include <LiquidCrystal_I2C.h>

volatile int value;
LiquidCrystal_I2C mylcd (0x27,16,2); 

void setup () {
 value = 0;
 mylcd.init ();
 mylcd.backlight (); 
 mylcd.clear (); 
 pinMode (A3, INPUT);
}
void loop () {
 value = analogRead (A3);
  if (value <100)
  {
    display("dry, no steam");
  }
  else if ((value>=101) && (value <= 400))
  {
    display("Light Steam"); 
  }  else if ((value>=401) && (value <= 700 ))
  {
    display("Moist"); 
  } else if (value> 700)
  {
    display("High Moisture");
  }
}

void display(String  msg){
    mylcd.clear ();
    mylcd.setCursor (0, 0);
    mylcd.print ("value:");
    mylcd.setCursor (6, 0);
    mylcd.print (value);
    mylcd.setCursor (0, 1);
    mylcd.print (msg);
    delay (300); 
}
 
