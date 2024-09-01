# DriveCell

<img src="https://microbots.io/cdn/shop/files/P1098499_765e4081-5032-4a81-8611-a96e68ad8f4c_400x.jpg?v=1720079418" alt="CodeCell" width="300" align="right" style="margin-left: 20px;">
DriveCell is an ultra-compact driver that simplifies control of motors and actuators for your DIY projects. At just 0.8 x 1 cm, this tiny driver can control brushed motors, magnetic actuators, and high-power LED lights with ease using a simple Arduino-friendly library. Whether you want to control speed, direction, brightness, or create intricate behaviors, DriveCell is designed to make your prototyping fast and efficient!

## Getting Started with the DriveCell Library:

### Setting up your DriveCell

- To initialize the DriveCell, create an instance of the `DriveCell` class by specifying the input pins connected to your motor or actuator, then call the `Init()` function. Here’s how you can set it up:

  ```cpp
  #include "DriveCell.h"

  DriveCell myDriveCell(IN1, IN2);  // Replace IN1 and IN2 with your specific pins

  void setup() {
      myDriveCell.Init();  // Initializes the DriveCell
  }
  ```

### DriveCell Functions

Below are the functions provided by the `DriveCell` library. Basic functions work on all Arduino board + optimized PWM functions for CodeCell & other ESP32 devices

#### 1. **Init**
   - **Function:** `Init()`
   - **Description:** Initializes the DriveCell by setting up the GPIO pins and attaching the necessary timers.
     ```cpp
     myDriveCell.Init();  // Initializes the device
     ```

#### 2. **Run**
   - **Function for ESP32:** `Run(bool smooth, uint8_t power_percent, uint16_t flip_speed_ms)`
   - **Description for ESP32:** Uses PWM and hardware timers to flip the actuator or motor polarity every few milliseconds. The smooth parameter enables smoother transitions.
   - **Examples:**
     ```cpp
     myDriveCell.Run(true, 50, 500);  // Smooth operation at 50% power, flipping every 500 ms
     ```
   - **Function for Other Arduino Devices:** `Run(uint16_t flip_speed_ms)`
   - **Description for Other Arduino Devices:** Uses simple GPIO toggling with delay for timing.
   - **Examples:**
     ```cpp
     myDriveCell.Run(500);            // Flip every 500 milliseconds
     ```

#### 3. **Buzz**
   - **Function:** `Buzz(uint16_t us_buzz)`
   - **Description:** This function uses your Actuator to generates a buzzing sound by toggling the state of the actuator at specified microsecond intervals.
   - **Example:**
     ```cpp
     myDriveCell.Buzz(100);  // Buzz at 100 microseconds
     ```

#### 4. **Drive**
   - **Function for ESP32:** `Drive(bool direction, uint8_t power_percent)`
   - **Description for ESP32:** Uses PWM to control the speed and direction of the motor or actuator. 
   - **Examples:**
     ```cpp
     myDriveCell.Drive(true, 75);  // Drive forward at 75% power
     ```

#### 5. **Pulse**
   - **Function:** `Pulse(bool direction, uint8_t ms_duration)`
   - **Description:** Creates a short pulse in the specified polarity for the given duration.
   - **Example for All Devices:**
     ```cpp
     myDriveCell.Pulse(true, 10);  // Pulse forward for 10 milliseconds
     ```

#### 6. **Tone**
   - **Function:** `Tone()`
   - **Description:** Plays a tone by continuously toggling the motor state with varying frequencies.
   - **Example for All Devices:**
     ```cpp
     myDriveCell.Tone();  // Play a tone with varying frequencies
     ```

#### 7. **Toggle**
   - **Function for ESP32:** `Toggle(uint8_t power_percent)`
   - **Description for ESP32:** Toggles polarity or motor direction at a specified duty cycle using PWM.
   - **Examples:**
               
     ```cpp
     myDriveCell.Toggle(50);  // Toggle direction at 50% power
     ```
     
   - **Function for Other Arduino Devices:** `Toggle()`
   - **Description for Other Arduino Devices:** Toggles polarity or motor direction using simple GPIO toggling.
   - **Examples:**
     ```cpp
     myDriveCell.Toggle();    // Toggle direction or polarity
     ```


