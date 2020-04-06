/*
 * config.h
 * 
 * Configuration settings for the whole project
 *
 * Created: 29/03/20
 * Author : Richard Tomlinson G4TGJ
 */ 


#ifndef CONFIG_H_
#define CONFIG_H_

#include <avr/io.h>

// General definitions
typedef uint8_t bool;
#define true 1
#define false 0

#define ULONG_MAX 0xFFFFFFFF

// Processor definitions
// CPU clock speed
#define F_CPU 8000000UL

// Morse definitions
// Default, minimum and maximum morse speed in wpm
#define DEFAULT_MORSE_WPM 18
#define MIN_MORSE_WPM 16
#define MAX_MORSE_WPM 20

// Default morse keyer mode - should be set from the
// compiler command line
#ifndef KEYER_MODE
#define KEYER_MODE 0
#endif

// Morse paddle inputs
#define MORSE_PADDLE_DOT_PORT_REG   PORTB
#define MORSE_PADDLE_DOT_PIN_REG    PINB
#define MORSE_PADDLE_DOT_PIN        PB1
#define MORSE_PADDLE_DOT_PCINT      PCINT1
#define MORSE_PADDLE_DASH_PORT_REG  PORTB
#define MORSE_PADDLE_DASH_PIN_REG   PINB
#define MORSE_PADDLE_DASH_PIN       PB0
#define MORSE_PADDLE_DASH_PCINT     PCINT0

// Morse speed switch input
#define MORSE_SPEED_SWITCH_PORT_REG  PORTB
#define MORSE_SPEED_SWITCH_PIN_REG   PINB
#define MORSE_SPEED_SWITCH_PIN       PB3
#define MORSE_SPEED_SWITCH_PCINT     PCINT0

// Unused pins. Pull-ups will be enabled to
// prevent floating inputs that can cause
// high power consumption.
#define UNUSED_1_PORT_REG  PORTB
#define UNUSED_1_PIN       PB2
#define UNUSED_2_PORT_REG  PORTB
#define UNUSED_2_PIN       PB4

// I/O definitions
// Output pins
#define MORSE_OUTPUT_PORT_REG   PORTB
#define MORSE_OUTPUT_PIN_REG    PINB
#define MORSE_OUTPUT_DDR_REG    DDRB
#define MORSE_OUTPUT_PIN        PB4

// Bits for the power down mode
#define POWER_DOWN_MODE ((1<<SM1)|(0<<SM0))

#endif /* CONFIG_H_ */
