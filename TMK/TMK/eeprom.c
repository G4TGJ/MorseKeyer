/*
 * eeprom.c
 * 
 * Read and write to the AVR's internal EEPROM.
 * Based on sample code in the data sheet.
 * 
 * Generally we shouldn't call this code directly
 * but via the nvram code.
 *
 * Created: 07/08/2019
 * Author : Richard Tomlinson G4TGJ
 */ 
 
#include <inttypes.h>
#include <avr/io.h>
#include <avr/pgmspace.h>

uint8_t eepromRead(uint16_t uiAddress)
{
    /* Wait for completion of previous write */
    while(EECR & (1<<EEPE));
    
    /* Set up address register */
    EEAR = uiAddress;
    
    /* Start eeprom read by writing EERE */
    EECR |= (1<<EERE);
    
    /* Return data from Data Register */
    return EEDR;
}

void eepromWrite(uint16_t uiAddress, uint8_t ucData)
{
    /* Wait for completion of previous write */
    while(EECR & (1<<EEPE));
    
    /* Set up address and Data Registers */
    EEAR = uiAddress;
    EEDR = ucData;
    
    /* Write logical one to EEMPE */
    EECR |= (1<<EEMPE);
    
    /* Start eeprom write by setting EEPE */
    EECR |= (1<<EEPE);
}
