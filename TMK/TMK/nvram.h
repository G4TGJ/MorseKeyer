/*
 * nvram.h
 *
 * Created: 10/04/2020
 * Author : Richard Tomlinson G4TGJ
 */ 
 

#ifndef NVRAM_H
#define NVRAM_H

#include <inttypes.h>
#include "morse.h"

void nvramInit();

uint8_t nvramReadSlowWpm();
uint8_t nvramReadFastWpm();
enum eMorseKeyerMode nvramReadMorseKeyerMode();

#endif //NVRAM_H
