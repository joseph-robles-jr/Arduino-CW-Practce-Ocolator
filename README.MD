### README.md

# Iambic Morse Code Practice Oscillator with Arduino

## Overview
This Arduino program allows you to create an iambic Morse code paddle. It generates Morse code signals using two paddles, a speaker, and an LED on the Arduino board. Additionally, you can adjust the duration of the "dah" and "dit" signals using a potentiometer.

## Components Needed
- Arduino board (e.g., Uno, Mega, etc.)
- Breadboard
- Jumper wires
- Two push buttons (for paddles)
- Resistors (10k ohm for pull-up configuration)
- Speaker or buzzer
- LED (optional, for visual indication)
- Potentiometer (for adjusting signal duration)

## Wiring Instructions
1. **Push Buttons (Paddles)**:
    - **Left Paddle (DIT)**:
        - Connect one terminal of the button to digital pin `2` on the Arduino.
        - Connect the other terminal to ground.
        - Connect a 10k ohm resistor between digital pin `2` and 5V (pull-up resistor).
    - **Right Paddle (DAH)**:
        - Connect one terminal of the button to digital pin `3` on the Arduino.
        - Connect the other terminal to ground.
        - Connect a 10k ohm resistor between digital pin `3` and 5V (pull-up resistor).

2. **Speaker/Buzzer**:
    - Connect the positive terminal of the speaker to digital pin `9` on the Arduino.
    - Connect the negative terminal to ground.

3. **LED (Optional)**:
    - Connect the anode (longer leg) of the LED to digital pin `13` on the Arduino.
    - Connect the cathode (shorter leg) to ground through a 220 ohm resistor.

4. **Potentiometer**:
    - Connect one terminal of the potentiometer to 5V.
    - Connect the opposite terminal to GND.
    - Connect the middle terminal (wiper) to analog pin `A0` on the Arduino.

## Usage
1. Connect your Arduino to your computer.
2. Open the Arduino IDE and paste the provided code into a new sketch.
3. Upload the sketch to the Arduino board.
4. Adjust the potentiometer to change the duration of the dah and dit signals.
5. Press the left and right paddles to generate Morse code signals.
6. The speaker will emit tones corresponding to the Morse code, and the built-in LED will blink in sync with the signals.

## License
This project is open-source and available under the GPL 3.0 License. Feel free to use, modify, and distribute it as you see fit.

---