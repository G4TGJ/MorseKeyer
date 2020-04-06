/*
 * io.h
 *
 * Created: 11/09/2019
 * Author : Richard Tomlinson G4TGJ
 */ 
 
#ifndef IO_H
#define IO_H

// Configure all IO ports
void ioConfigure();

// Read the morse dot and dash paddles
bool ioReadDotPaddle();
bool ioReadDashPaddle();

// Read the morse speed switch
bool ioReadMorseSpeedSwitch();

// Disable/enable the pull up on the speed switch
void ioDisableMorseSpeedSwitchPullUp();
void ioEnableMorseSpeedSwitchPullUp();

// Set the morse output high or low
void ioWriteMorseOutputHigh();
void ioWriteMorseOutputLow();

#endif //IO_H
