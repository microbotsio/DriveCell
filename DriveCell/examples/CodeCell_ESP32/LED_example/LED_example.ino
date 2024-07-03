/*Learn more at microbots.io*/
/*In this example we are going to use a DriveCell to adjust the brightness of a high power LED or a single color LED-strip light (1.8Amps maximum)*/
/*Make sure that the LED is connected to the correct output pin of the DriveCell in this case we are using input Pin2*/

#include <DriveCell.h>

#define IN1_pin1 2
#define IN1_pin2 3

DriveCell LED(IN1_pin1, IN1_pin2);/*Pin2 will output the PWM signal and Pin3 will be connected to 0V*/

uint16_t led_brightness = 0;
bool led_brightness_flag = 1;

void setup() {
  LED.Init();/*Initialize the LED*/
}

void loop() {
  delay(100);/*Varry the fading timing by adjust this delay*/
  if (led_brightness_flag == 1) {
    if (led_brightness < 100U) {
      led_brightness++;
    } else {
      led_brightness_flag = 0;
    }
  } else {
    if (led_brightness > 1U) {
      led_brightness--;
    } else {
      led_brightness_flag = 1;
    }
  }
  LED.Drive(0, led_brightness);/*Output the new brightness */
}
