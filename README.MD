# Iambic Morse Code Paddle with Arduino

## Overview
This Arduino program allows you to create an iambic Morse code paddle. It generates Morse code signals using two paddles, a speaker, and an LED on the Arduino board.

## Components Needed
- Arduino board (e.g., Uno, Mega, etc.)
- Breadboard
- Jumper wires
- Two push buttons (for paddles)
- Resistors (10k ohm for pull-up configuration)
- Speaker or buzzer
- LED (optional, for visual indication)

## Wiring Instructions 1. **Push Buttons (Paddles)**: - **Left Paddle (DIT)**: - Connect one terminal of the button to digital pin `2` on the Arduino. - Connect the other terminal to ground. - Connect a 10k ohm resistor between digital pin `2` and 5V (pull-up resistor). - **Right Paddle (DAH)**: - Connect one terminal of the button to digital pin `3` on the Arduino. - Connect the other terminal to ground. - Connect a 10k ohm resistor between digital pin `3` and 5V (pull-up resistor). 2. **Speaker/Buzzer**: - Connect the positive terminal of the speaker to digital pin `9` on the Arduino. - Connect the negative terminal to ground. 3. **LED (Optional)**: - Connect the anode (longer leg) of the LED to digital pin `13` on the Arduino. - Connect the cathode (shorter leg) to ground through a 220 ohm resistor.