// -------------------------------------------------------------------------------------------------
// Pin map for the custom MaxESP4 controller (ESP32-WROOM-32UE)
#pragma once

#if defined(ESP32)

// Serial0: RX Pin GPIO3, TX Pin GPIO1 (to USB serial adapter)
// Serial1 is remapped below for the TMC2209 UART bus

#if SERIAL_A_BAUD_DEFAULT != OFF
  #define SERIAL_A              Serial
#endif
// Use the following settings for any TMC UART driver (TMC2209) that may be present
#if defined(STEP_DIR_TMC_UART_PRESENT) || defined(SERVO_TMC2209_PRESENT)
  #define SERIAL_TMC_HARDWARE_UART
  #define SERIAL_TMC            Serial1          // Shared hardware UART for both drivers
  #define SERIAL_TMC_BAUD       460800           // Baud rate
  #define SERIAL_TMC_RX         36               // RXTMC (input-only GPIO)
  #define SERIAL_TMC_TX         4                // Transmit data
  #define SERIAL_TMC_ADDRESS_MAP(x) ((x==4)?2 : x) // Axis1(0) is 0, Axis2(1) is 1, Axis3(2) is 2, Axis4(3) is 3, Axis5(4) is 2
#endif

// Specify the ESP32 I2C pins
#define I2C_SDA_PIN             26
#define I2C_SCL_PIN             14

// No general-purpose auxiliary pins are routed on this PCB
#define AUX2_PIN                OFF
#define AUX3_PIN                OFF
#define AUX4_PIN                OFF
#define AUX5_PIN                OFF
#define AUX6_PIN                OFF
#define AUX7_PIN                OFF
#define AUX8_PIN                OFF

// Misc. pins
#define ONE_WIRE_PIN            OFF
#define PEC_SENSE_PIN           OFF

// STA LED is active low
#ifdef STATUS_LED_ON_STATE
  #undef STATUS_LED_ON_STATE
#endif
#define STATUS_LED_ON_STATE LOW
#define STATUS_LED_PIN          13
#ifdef MOUNT_LED_ON_STATE
  #undef MOUNT_LED_ON_STATE
#endif
#define MOUNT_LED_ON_STATE      LOW
#define MOUNT_LED_PIN           STATUS_LED_PIN
#define RETICLE_LED_PIN         OFF

#define STATUS_BUZZER_PIN       OFF

// The PPS pin is a 3.3V logic input, OnStep measures time between rising edges and adjusts the internal sidereal clock frequency
#define PPS_SENSE_PIN           27
#define LIMIT_SENSE_PIN         OFF
#define PARK_SIGNAL_PIN         OFF

#define SHARED_ENABLE_PIN       5                // Hint that the enable pins are shared

// Axis1 RA/Azm step/dir driver
#define AXIS1_ENABLE_PIN        SHARED           // Enable pin control
#define AXIS1_M0_PIN            OFF              // hardwired for TMC UART address 0
#define AXIS1_M1_PIN            OFF              // hardwired for TMC UART address 0
#define AXIS1_M2_PIN            OFF              // UART TX
#define AXIS1_M3_PIN            OFF              // UART RX
#define AXIS1_STEP_PIN          25
#define AXIS1_DIR_PIN           23
#define AXIS1_SENSE_HOME_PIN    22
#define AXIS1_SENSE_LIMIT_MIN_PIN 21
#define AXIS1_SENSE_LIMIT_MAX_PIN 21

// Axis2 Dec/Alt step/dir driver
#define AXIS2_ENABLE_PIN        SHARED
#define AXIS2_M0_PIN            OFF              // hardwired for TMC UART address 1
#define AXIS2_M1_PIN            OFF              // hardwired for TMC UART address 1
#define AXIS2_M2_PIN            OFF              // N/C
#define AXIS2_M3_PIN            OFF              // UART RX
#define AXIS2_STEP_PIN          19
#define AXIS2_DIR_PIN           18
#define AXIS2_SENSE_HOME_PIN    17
#define AXIS2_SENSE_LIMIT_MIN_PIN 16
#define AXIS2_SENSE_LIMIT_MAX_PIN 16

// For rotator stepper driver
#define AXIS3_ENABLE_PIN        OFF
#define AXIS3_M0_PIN            OFF              // hardwired for TMC UART address 2
#define AXIS3_M1_PIN            OFF              // hardwired for TMC UART address 2
#define AXIS3_M2_PIN            OFF              // N/C
#define AXIS3_M3_PIN            OFF              // UART RX
#define AXIS3_STEP_PIN          OFF
#define AXIS3_DIR_PIN           OFF

// For focuser1 stepper driver
#define AXIS4_ENABLE_PIN        OFF
#define AXIS4_M0_PIN            OFF              // hardwired for TMC UART address 3
#define AXIS4_M1_PIN            OFF              // hardwired for TMC UART address 3
#define AXIS4_M2_PIN            OFF              // N/C
#define AXIS4_M3_PIN            OFF              // UART RX
#define AXIS4_STEP_PIN          OFF
#define AXIS4_DIR_PIN           OFF

// For focuser2 stepper driver
#define AXIS5_ENABLE_PIN        OFF
#define AXIS5_M0_PIN            OFF              // hardwired for TMC UART address 2
#define AXIS5_M1_PIN            OFF              // hardwired for TMC UART address 2
#define AXIS5_M2_PIN            OFF              // N/C
#define AXIS5_M3_PIN            OFF              // UART RX
#define AXIS5_STEP_PIN          OFF
#define AXIS5_DIR_PIN           OFF

// ST4 interface
#define ST4_RA_W_PIN            33               // RA- West
#define ST4_DEC_S_PIN           35               // DEC- South (input-only GPIO)
#define ST4_DEC_N_PIN           32               // DEC+ North
#define ST4_RA_E_PIN            34               // RA+ East (input-only GPIO)

#else
#error "Wrong processor for this configuration!"

#endif
