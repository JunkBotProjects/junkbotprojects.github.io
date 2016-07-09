##Parts

- 5v DC Motor x 2
- Wheels x 2 
- any make-do body
- Arduino
- Bluetooth Module
- 5V Power Source

##Wiring

1. RX and TX of Bluetooth module *to* 2 and 3 pins of Arduino
2. +ve and -ve of first motor *to* +ve and -ve on m1 output of motor driver shield
3. +ve and -ve of second motor *to* +ve and -ve on m2 output of motor driver shield
4. +5v and gnd from power source *to* +ve and -ve on _pwr in_ of motor driver shield

##Procedure

1. Wire Up all points.
2. Fix the tires on the motor
3. Fix the motor(s), arduino, bluetooth module and power source on the body.
4. Upload the program to the arduino
5. Turn on the power source.
6. Open the _JB-Rover_ Bluetooth app.
7. Connect to a bluetooth device called HC-05
8. Use the controls to navigate the bot.