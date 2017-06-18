/******************************************
 * iotest
 * revision 1 shabaz June 2017
 * Header pin 13 is GPIO27 and is connected to a yellow LED
 * Header pin 15 is GPIO22 and is connected to a green LED
 * Header pin 11 is GPIO17 and is connected to a light dependent resistor
 ******************************************/

// includes
#include <stdio.h>
#include <wiringPi.h>

// definitions
#define YELLOW_PIN 27
#define GREEN_PIN  22
#define LIGHT_PIN 17

#define FOREVER 1
#define BRIGHT 0
#define DIM 1
#define LED_ON 1
#define LED_OFF 0

/******************************************
 * main program
 ******************************************/
int
main(void)
{
  // define the inputs and outputs
  wiringPiSetupGpio();
  pinMode(LIGHT_PIN, INPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);

  while(FOREVER) // do everything here in loop forever
  {
    if (digitalRead(LIGHT_PIN)==BRIGHT) // is it bright?
    {
      digitalWrite(YELLOW_PIN, LED_OFF); // turn the lights off
      digitalWrite(GREEN_PIN, LED_OFF);
    }
    else // otherwise it must be dark..
    {
      digitalWrite(YELLOW_PIN, LED_ON); // turn the lights on
      digitalWrite(GREEN_PIN, LED_ON);
    }
    delay(100); // wait 100milliseconds and then loop back
  }

  // the next line never executes
  return(0); // warning on this line is ok
}


