/*
 * nvram.c
 * 
 * Maintains a non-volatile memory area which
 * is stored in the EEPROM.
 *
 * Created: 07/08/2019
 * Morse keyer version: 10/04/2020
 * Author : Richard Tomlinson G4TGJ
 */ 
 
#include <inttypes.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <ctype.h>

#include "config.h"
#include "eeprom.h"
#include "nvram.h"

// Magic number used to help verify the data is correct
// ASCII "TMK " in little endian format
#define MAGIC 0x204b4d54

// TMK A 16 30 Memory keyer text\n

// Cached version of the NVRAM - read from the EEPROM at boot time
static struct __attribute__ ((packed)) 
{
    uint32_t magic;         // Magic number to check data is valid
    char    keyer_mode;     // Character for the keyer mode
    char    space1;         // Expect this to be a space
    char    slow_wpm[2];    // Slow morse speed in wpm
    char    space2;         // Also expect this to be a space
    char    fast_wpm[2];    // Fast morse speed in wpm
} nvram_cache;

// Validated keyer mode, slow speed and fast speed as read from the EEPROM
static enum eMorseKeyerMode keyerMode;
static uint8_t slowSpeed, fastSpeed;

// Initialise the NVRAM - read it in and check valid.
// Must be called before any operations
void nvramInit()
{
    bool bValid = false;

    // Read from the EEPROM into the NVRAM cache
    for( int i = 0 ; i < sizeof( nvram_cache ) ; i++ )
    {
        ((uint8_t *) &nvram_cache)[i] = eepromRead(i);
    }
    
    // Check the magic numbers and spaces are correct
    if( (nvram_cache.magic == MAGIC) &&
        (nvram_cache.space1 == ' ') &&
        (nvram_cache.space2 == ' ') )
    {
        bValid = true;

        // Get the keyer mode
        if( nvram_cache.keyer_mode == 'A' )
        {
            keyerMode = morseKeyerIambicA;
        }
        else if( nvram_cache.keyer_mode == 'B' )
        {
            keyerMode = morseKeyerIambicB;
        }
        else if( nvram_cache.keyer_mode == 'U' )
        {
            keyerMode = morseKeyerUltimatic;
        }
        else
        {
            // Not valid
            bValid = false;
        }

        // Get the slow speed
        // First check both characters are decimal digits
        if( isdigit(nvram_cache.slow_wpm[0]) && isdigit(nvram_cache.slow_wpm[1]) )
        {
            // Convert from ASCII to decimal
            slowSpeed = (nvram_cache.slow_wpm[0]-'0')*10 + (nvram_cache.slow_wpm[1]-'0');

            // Check it is within range
            if( (slowSpeed < MIN_MORSE_WPM) || (slowSpeed > MAX_MORSE_WPM) )
            {
                bValid = false;
            }
        }
        else
        {
            bValid = false;
        }

        // Get the fast speed
        // First check both characters are decimal digits
        if( isdigit(nvram_cache.fast_wpm[0]) && isdigit(nvram_cache.fast_wpm[1]) )
        {
            // Convert from ASCII to decimal
            fastSpeed = (nvram_cache.fast_wpm[0]-'0')*10 + (nvram_cache.fast_wpm[1]-'0');

            // Check it is within range
            if( (fastSpeed < MIN_MORSE_WPM) || (fastSpeed > MAX_MORSE_WPM) )
            {
                bValid = false;
            }
        }
        else
        {
            bValid = false;
        }
    }

    // If any of it wasn't valid then set the defaults
    if( !bValid )
    {
        keyerMode = DEFAULT_KEYER_MODE;
        slowSpeed = DEFAULT_SLOW_WPM;
        fastSpeed = DEFAULT_FAST_WPM;
    }
}

// Functions to read and write parameters in the NVRAM
// Read is actually already read and validated
uint8_t nvramReadSlowWpm()
{
    return slowSpeed;
}

uint8_t nvramReadFastWpm()
{
    return fastSpeed;
}

enum eMorseKeyerMode nvramReadMorseKeyerMode()
{
    return keyerMode;
}

