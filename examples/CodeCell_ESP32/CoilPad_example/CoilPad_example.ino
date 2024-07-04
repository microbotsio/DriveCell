/*Learn more at microbots.io*/
/*In this example we intialize a CoilPad and vibrate it at 20Hz*/

#include <DriveCell.h>

#define IN1_pin1 2
#define IN1_pin2 3

DriveCell CoilPad(IN1_pin1, IN1_pin2);

uint16_t flap_counter = 0;

void setup() {
  CoilPad.Init();
  CoilPad.Tone();
}

void loop() {
  CoilPad.Run(0, 100, 25); /*Vibrate the CoilPad at 20Hz - Set to to your desired frequency with this formula (time = 0.5/Frequency)*/
}