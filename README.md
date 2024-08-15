# Garden Watering

Automatic plant watering project using Arduino.

## Installation

Build the sketch with [Arduino IDE](https://www.arduino.cc/en/software) and upload to Arduino Nano.

## Usage

Connect power to the device.
Submerge the pump into water and connect hoses for watering.
Place humidity sensors into soil.

When connected to computer over USB-C, the device opens a 9600 baud serial connection, and handles these commands:

- `/s` show current status: date, time, humidity and settings
- `/h` show command help
- `/t HHMMSS` set new time, e.g. `/t 120403` for 12:04:03
- `/d YYMMDD` set new date, e.g. `/d 240815` for 2024-08-15
- `/w W` set weekday, e.g. `/w 4` for Thursday
- `/a HHMM HHMM` set watering times, e.g. `/a 1015 1830` to water at 10:15 and 18:30
  - watering times between 12:00 and 15:00 will be rejected
- `/b TT` set humidity treshold to skip watering, e.g. `/b 60` to not water if average soil humidity is bigger than 60%
- `/c S` set watering time duration in seconds
- `/l` print recent log in a machine and human-readable format

Each command ends with a new line character.

## Roadmap

- [x] Build and upload the code to Arduino
- [x] Connect the real-time clock
- [ ] Parse commands sent on the serial
- [ ] Update the real-time clock from commands
- [ ] Save configuration to external memory
- [ ] Measure humidity with sensors
- [ ] Detect pump running dry
  - [ ] Measure the current
- [ ] Implement the watering algorithm
- [ ] Log data into external memory:
  - [ ] Watering times
  - [ ] Pump running without water
  - [ ] Humidity throughout the day
- [ ] Process log data
  - [ ] Graph time history
  - [ ] Publish online
