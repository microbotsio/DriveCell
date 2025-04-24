/*Learn more at microbots.io*/
/*In this example we intialize two brush-motors to drive them at different speeds*/

#include <DriveCell.h>

#define IN1_pin1 2
#define IN1_pin2 3
#define IN2_pin1 5
#define IN2_pin2 6

DriveCell Motor1(IN1_pin1, IN1_pin2);
DriveCell Motor2(IN2_pin1, IN2_pin2);

uint8_t mode = 0;
uint8_t speed_percentage = 0;

void setup() {
  Motor1.Init();
  Motor2.Init();
  speed_percentage = 80; /*Set Motor to 80% power*/
}

void loop() {
  delay(3000);
  mode++;
  switch (mode) {
    case 1:
      /*Move forward*/
      Motor1.Drive(1, speed_percentage);
      Motor2.Drive(1, speed_percentage);
      break;
    case 2:
      /*Move backward*/
      Motor1.Drive(0, speed_percentage);
      Motor2.Drive(0, speed_percentage);
      break;
    case 3:
      /*Turn left*/
      Motor1.Drive(0, speed_percentage);
      Motor2.Drive(0, 0);
      break;
    case 4:
      /*Turn right*/
      Motor1.Drive(0, 0);
      Motor2.Drive(0, speed_percentage);
      break;
    case 5:
      /*Turn off both motors*/
      Motor1.Drive(1, 0);
      Motor2.Drive(1, 0);
      if (speed_percentage < 95) {
        speed_percentage = speed_percentage + 5; /*increment speed*/
      } else {
        speed_percentage = 80; /*Set Motor to 80% power*/
      }
      mode = 0;
      break;
  }
}
