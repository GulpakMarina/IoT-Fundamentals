#include <Wire.h>
#include <LiquidCrystal_I2C.h>

volatile int value;
LiquidCrystal_I2C mylcd (0x27,16,2); 

void setup () {
 value = 0;
 mylcd.init ();
 mylcd.backlight (); 
 mylcd.clear (); 
 pinMode (A2, INPUT);
}
void loop () {
 value = analogRead (A2);
  if (value <300)
  {
    display("dry soil");
  }
  else if ((value>=300) && (value <= 700))
  {
    display("humid soil"); 
  } else if (value> 700)
  {
    display("in water");
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
 
