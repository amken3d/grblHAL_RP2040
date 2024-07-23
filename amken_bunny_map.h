/*
  amken_bunny_map.h - driver code for RP2040 ARM processors

  Part of grblHAL

  Copyright (c) 2022-2024 Terje Io

  grblHAL is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  grblHAL is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with grblHAL. If not, see <http://www.gnu.org/licenses/>.
*/

#if N_ABC_MOTORS > 1
#error "Axis configuration is not supported!"
#endif

#if WIFI_ENABLE || BLUETOOTH_ENABLE == 1
#error "Wireless networking is not supported!"
#endif

#define BOARD_NAME "Amken Bunny"
#define BOARD_URL "https://www.amken3d.com"

#define SERIAL1_PORT 1

#undef TRINAMIC_ENABLE
#undef TRINAMIC_UART_ENABLE
#define TRINAMIC_ENABLE 2209
#define TRINAMIC_UART_ENABLE 1
#define TRINAMIC_STREAM 1
#undef TRINAMIC_MIXED_DRIVERS
#define TRINAMIC_MIXED_DRIVERS 0
#define HAS_BOARD_INIT

// Define step pulse output pins.
#define STEP_PORT                   GPIO_PIO_1 // Single pin PIO SM
#define X_STEP_PIN                  18
#define Y_STEP_PIN                  9
#define Z_STEP_PIN                  25

// Define step direction output pins.
#define DIRECTION_PORT              GPIO_OUTPUT
#define DIRECTION_OUTMODE           GPIO_MAP
#define X_DIRECTION_PIN             19
#define Y_DIRECTION_PIN             10
#define Z_DIRECTION_PIN             2

// Define stepper driver enable/disable output pin.
#define ENABLE_PORT                 GPIO_OUTPUT
#define X_ENABLE_PIN                8
#define Y_ENABLE_PIN                8
#define Z_ENABLE_PIN                8

// Define ganged axis or A axis step pulse and step direction output pins.
#if N_ABC_MOTORS > 0
#define M3_AVAILABLE
#define M3_STEP_PIN                 23
#define M3_DIRECTION_PIN            13
#define M3_ENABLE_PIN               8
#define M3_LIMIT_PIN                22  // Mapped to ES4
#endif

// Define homing/hard limit switch input pins.
#define X_LIMIT_PIN                 15  // Mapped to ES1
#define Y_LIMIT_PIN                 16  // Mapped to ES2
#define Z_LIMIT_PIN                 6   // Mapped to ES3

// Define driver spindle pins
// Define spindle enable and spindle direction output pins.
#define SPINDLE_PORT            GPIO_OUTPUT
#define SPINDLE_ENABLE_PIN      17  // Mapped to HB
#define SPINDLE_PWM_PORT        GPIO_OUTPUT
#define SPINDLE_PWM_PIN         AUXOUTPUT1_PIN

#define AUXINPUT0_PIN           18 // Y-
#define AUXINPUT1_PIN           19 // Y+
#define AUXINPUT2_PIN           20 // X-
#define AUXINPUT3_PIN           21 // X+
#define AUXINPUT4_PIN           26 // Pen U/D
#define AUXINPUT5_PIN           22 // Online

#define AUXOUTPUT0_PORT         GPIO_OUTPUT
#define AUXOUTPUT0_PIN          7  // MApped to HE
#define AUXOUTPUT1_PORT         GPIO_OUTPUT
#define AUXOUTPUT1_PIN          14 // Mapped to Fan1
#define AUXOUTPUT2_PORT         GPIO_OUTPUT
#define AUXOUTPUT2_PIN          11 // Mapped to Fan2

#define RESET_PIN               26 // Mapped to TH1 (Removed ADC circuit)
#define PROBE_PIN               27 // Mapped to TH1 (Removed ADC circuit)
#define FEED_HOLD_PIN           0  // Mapped to RPI Port TX
#define CYCLE_START_PIN         1  // Mapped to RPI Port RX


