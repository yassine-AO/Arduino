# Arduino Bluetooth-Controlled Obstacle-Avoiding Car ✨

## Project Overview⭐

This project demonstrates an Arduino-based car that can be controlled via Bluetooth using a mobile app. It features two main modes of operation:

1. **Bluetooth Control Mode**: The car can be controlled using a mobile app.
2. **Autonomous Mode**: The car automatically avoids obstacles and chooses the best path to navigate around them.

## Hardware Components⭐

- Arduino Uno
- HC-06 Bluetooth Module
- Ultrasonic Sensor (for obstacle detection)
- Motor Driver Module
- DC Motors
- LEDs and Buzzer (for indicators)
- Battery Pack

## Software Components⭐

- Arduino IDE
- Mobile app for Bluetooth control (e.g., "Arduino Bluetooth RC Car")

## Features⭐

1. **Bluetooth Control Mode**:
    - **Forward/Backward Movement**: Controlled via mobile app commands.
    - **Left/Right Turns**: Controlled via mobile app commands.
    - **Speed Control**: Adjustable via the mobile app.
    - **Obstacle Detection**: The car stops and triggers a buzzer when an obstacle is detected.
2. **Autonomous Mode**:
    - **Obstacle Avoidance**: The car detects obstacles and chooses the best path to avoid them.
    - **Path Selection**: The car scans left and right to determine the best path when an obstacle is detected.

## Getting Started⭐

### Prerequisites

- Arduino IDE installed on your computer.
- "Arduino Bluetooth RC Car" mobile app installed on your smartphone.

### Hardware Setup

1. **Bluetooth Module**: Connect the TX pin of the HC-06 module to the RX pin of the Arduino and the RX pin of the HC-06 module to the TX pin of the Arduino. Connect VCC to 5V and GND to GND on the Arduino.
2. **Ultrasonic Sensor**: Connect the Trig and Echo pins to the designated digital pins on the Arduino. Connect VCC to 5V and GND to GND.
3. **Motor Driver Module**: Connect the motor driver inputs to the appropriate digital pins on the Arduino and connect the motors to the outputs of the motor driver. Connect the motor driver’s power inputs to the battery pack.
4. **LEDs and Buzzer**: Connect LEDs and buzzer to the designated digital pins on the Arduino.

## Usage⭐

### Bluetooth Control Mode

1. **Connect to the Car**: Pair your smartphone with the HC-06 Bluetooth module.
2. **Open the Mobile App**: Use the "Arduino Bluetooth RC Car" app or a similar app.
3. **Control the Car**: Use the app interface to send commands (e.g., 'F' for forward, 'B' for backward).

### Autonomous Mode

1. **Upload the Autonomous Mode Code**: Load the second code snippet into the Arduino IDE and upload it to the Arduino.
2. **Power On**: Ensure the car has power and is placed in an area with obstacles.
3. **Observe**: The car will start moving and avoiding obstacles automatically.

## License🧾

This project is licensed under the MIT License.
