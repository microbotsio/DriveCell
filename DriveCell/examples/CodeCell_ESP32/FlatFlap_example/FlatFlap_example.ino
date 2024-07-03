/*Learn more at microbots.io*/
/*In this example we intialize two FlatFlaps and flap them at different speeds*/

#include <DriveCell.h>

#define IN1_pin1 2
#define IN1_pin2 3
#define IN2_pin1 5
#define IN2_pin2 6

DriveCell FlatFlap1(IN1_pin1, IN1_pin2);
DriveCell FlatFlap2(IN2_pin1, IN2_pin2);

uint16_t flap_counter = 0;

void setup() {
  FlatFlap1.Init();
  FlatFlap2.Init();

  FlatFlap1.Tone();
  FlatFlap2.Tone();
}

void loop() {
  delay(1);
  flap_counter++;
  if (flap_counter < 2000U) {
    FlatFlap1.Run(0, 100, 100);
    FlatFlap2.Run(0, 100, 100);
  }
  else if (flap_counter < 8000U) {
    FlatFlap1.Run(1, 100, 1000);
    FlatFlap2.Run(1, 100, 1000);
  } else {
    flap_counter = 0U;
    FlatFlap1.Drive(0, 100);
    FlatFlap2.Drive(1, 100);
    delay(500);
    FlatFlap1.Drive(1, 100);
    FlatFlap2.Drive(1, 100);
    delay(500);
    FlatFlap1.Drive(1, 100);
    FlatFlap2.Drive(0, 100);
    delay(500);
    FlatFlap1.Drive(1, 100);
    FlatFlap2.Drive(1, 100);
    delay(500);
    FlatFlap1.Drive(0, 100);
    FlatFlap2.Drive(0, 100);
    delay(500);
    FlatFlap1.Drive(1, 100);
    FlatFlap2.Drive(1, 100);
    delay(500);
    FlatFlap1.Tone();
    FlatFlap2.Tone();
  }
}
