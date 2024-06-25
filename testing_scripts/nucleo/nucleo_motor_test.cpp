#include "mbed.h"

// Define pins for motor control
PwmOut motorA_enable(D5);
DigitalOut motorA_in1(D6);
DigitalOut motorA_in2(D7);

PwmOut motorB_enable(D10);
DigitalOut motorB_in3(D8);
DigitalOut motorB_in4(D9);

int main() {
    // Initialize PWM period
    motorA_enable.period_ms(10);
    motorB_enable.period_ms(10);

    while (true) {
        // Motor A forward
        motorA_in1 = 1;
        motorA_in2 = 0;
        motorA_enable.write(0.5); // 50% speed

        // Motor B forward
        motorB_in3 = 1;
        motorB_in4 = 0;
        motorB_enable.write(0.5); // 50% speed

        wait_us(5000000); // Run motors for 5 seconds

        // Stop motors
        motorA_enable.write(0);
        motorB_enable.write(0);

        wait_us(5000000); // Stop for 5 seconds

        // Motor A backward
        motorA_in1 = 0;
        motorA_in2 = 1;
        motorA_enable.write(0.5); // 50% speed

        // Motor B backward
        motorB_in3 = 0;
        motorB_in4 = 1;
        motorB_enable.write(0.5); // 50% speed

        wait_us(5000000); // Run motors for 5 seconds

        // Stop motors
        motorA_enable.write(0);
        motorB_enable.write(0);

        wait_us(5000000); // Stop for 5 seconds
    }
}

