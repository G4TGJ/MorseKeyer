/*
 * io.c
 *
 * Created: 11/09/2019
 * Author : Richard Tomlinson G4TGJ
 */ 

#include <avr/io.h>
#include <avr/cpufunc.h>
#include <avr/interrupt.h>
#include <util/atomic.h>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "io.h"

// Functions to read and write inputs and outputs
// This isolates the main logic from the I/O functions making it
// easy to change the hardware e.g. we have the option to
// connect several inputs to a single ADC pin

// Functions to read morse paddle inputs
bool ioReadDotPaddle()
{
    return !(MORSE_PADDLE_DOT_PIN_REG & (1<<MORSE_PADDLE_DOT_PIN));
}

bool ioReadDashPaddle()
{
    return !(MORSE_PADDLE_DASH_PIN_REG & (1<<MORSE_PADDLE_DASH_PIN));
}

// Read the morse speed switch input
bool ioReadMorseSpeedSwitch()
{
    return !(MORSE_SPEED_SWITCH_PIN_REG & (1<<MORSE_SPEED_SWITCH_PIN));
}

// Disable/enable the pull up on the speed switch
// Needed to minimise power consumption in power down mode
void ioDisableMorseSpeedSwitchPullUp()
{
    MORSE_SPEED_SWITCH_PORT_REG &= ~(1<<MORSE_SPEED_SWITCH_PIN);
}

void ioEnableMorseSpeedSwitchPullUp()
{
    MORSE_SPEED_SWITCH_PORT_REG |= (1<<MORSE_SPEED_SWITCH_PIN);
}

void ioWriteMorseOutputHigh()
{
    MORSE_OUTPUT_PORT_REG |= (1<<MORSE_OUTPUT_PIN);
}

// Set the morse output low
void ioWriteMorseOutputLow()
{
    MORSE_OUTPUT_PORT_REG &= ~(1<<MORSE_OUTPUT_PIN);
}

// Interrupt handler for pin change
// Doesn't need to do anything but is needed to wake
// from power down mode
ISR (PCINT0_vect)
{
}

// Configure all the I/O we need
void ioConfigure()
{
	// Initialise morse output
    MORSE_OUTPUT_DDR_REG |= (1<<MORSE_OUTPUT_PIN);
    
    // Paddle dot and dash pins as inputs with pull-ups
    MORSE_PADDLE_DOT_PORT_REG |= (1<<MORSE_PADDLE_DOT_PIN);
    MORSE_PADDLE_DASH_PIN_REG |= (1<<MORSE_PADDLE_DASH_PIN);

    // Morse speed switch pin as input with pull-up
    MORSE_SPEED_SWITCH_PORT_REG |= (1<<MORSE_SPEED_SWITCH_PIN);

    // Set unused pins with pull-ups to minimise power consumption
    // (stops the inputs floating)
    UNUSED_1_PORT_REG |= (1<<UNUSED_1_PIN);
    UNUSED_2_PORT_REG |= (1<<UNUSED_2_PIN);

    // Set up pin change interrupts for the paddle
    PCMSK = (1<<MORSE_PADDLE_DOT_PCINT)|(1<<MORSE_PADDLE_DASH_PCINT);
    GIMSK = (1<<PCIE);

    /* Insert nop for synchronization*/
    _NOP();

    // Ensure the morse output is low
    ioWriteMorseOutputLow();
}

