#include <Pushbutton.h>

/* This example uses the Pushbutton library to demonstrate three
 * different methods for detecting a button press and release. It
 * blinks the yellow user LED on pin 13 each time the a button on
 * pin 12 is pressed and released.  A normally-open momentary
 * pushbutton should be connected between pin 12 and ground.  */

#define LED_PIN 13
#define BUTTON_PIN 12

/* Create a Pushbutton object with default settings, which
 * enables the internal pull-up on the pin and interprets a HIGH
 * pin value as the default (unpressed) state of the
 * button. (Optional arguments can be passed to the constructor
 * to specify other button types and connection methods; see the
 * documentation for details.) */
Pushbutton button(BUTTON_PIN);

int counter = 0;
boolean ledState = 0;

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Initializing...");
  
}

void loop()
{

  Serial.println("Loop X");



  /* Method 3: Call the getSingleDebouncedRelease() function
   * repeatedly in a loop, which returns true to report a single
   * button release or false otherwise. This function takes care
   * of button debouncing. If you have multiple buttons, you can
   * call getSingleDebouncedRelease() or
   * getSingleDebouncedPress() in a loop for all of them until
   * one of them returns true. */
  while (1)
  {
    Serial.println("Loop Y");
    if (button.getSingleDebouncedRelease())
    {

      counter++;
      
      // blink LED

      ledState = !ledState;

      if (ledState == 1) {
         digitalWrite(LED_PIN, HIGH);
         delay(2);
      } else {
        digitalWrite(LED_PIN, LOW);
        delay(2);
      }

      Serial.print("Counter = ");
      Serial.print(counter);
      Serial.println();
      
      break;
    }
  }
}
