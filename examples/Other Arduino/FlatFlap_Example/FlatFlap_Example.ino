/*Learn more at microbots.io*/
/*In this example we intialize a FlatFlap and flap it at high speed and low speed*/

#include <DriveCell.h>

#define IN1_pin1 2
#define IN1_pin2 3

DriveCell FlatFlap1(IN1_pin1, IN1_pin2);

uint16_t flap_counter = 0;

void setup() {
  FlatFlap1.Init();
  FlatFlap1.Tone();
}

void loop() {
  flap_counter++;
  if (flap_counter < 40U) {
    FlatFlap1.Run(100);
  }
  else if (flap_counter < 41U) {
    FlatFlap1.Tone();
  }
  else if (flap_counter < 50U) {
    FlatFlap1.Run(1000);
  } else {
    flap_counter = 0U;
    FlatFlap1.Tone();
  }
}
