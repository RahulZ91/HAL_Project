# STM32 MPU6050 Roll Angle Control with PWM

## Overview
This project demonstrates firmware-level integration of an MPU6050 accelerometer
with an STM32F446RE microcontroller. Accelerometer data is acquired via I2C,
processed to calculate the roll angle, and mapped to a PWM signal that controls
the brightness of external LEDs.

The project focuses on robust embedded behavior, signal handling, and
hardware-near integration.

## Hardware & Tools
- MCU: STM32F446RE (Nucleo board)
- Sensor: MPU6050 (accelerometer)
- Interface: I2C
- Output: External LEDs controlled via PWM
- IDE / Tools: STM32CubeIDE, HAL drivers, STM32CubeMonitor

## Firmware Functionality
- I2C-based acquisition of accelerometer data
- Offset calibration of raw sensor values
- Roll angle calculation using atan2
- Implementation of a dead-zone to suppress noise around 0°
- Mapping of roll angle magnitude to PWM duty cycle
- Direction-dependent LED control based on roll orientation

## Testing & Validation
- Integration testing of sensor interface, signal processing, and PWM output on target hardware
- Boundary and robustness testing of roll angle limits and dead-zone behavior
- Visual validation using external LEDs and real-time monitoring via STM32CubeMonitor

## Notes
More detailed documentation, photos, and a demo video will be added.
