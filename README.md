# MorseKeyer
 G4TGJ Morse Keyer

This is the software for the TGJ Morse Keyer (TMK) which is described at [my website](https://g4tgj.github.io/Morse-Keyer/). 
It is built using Atmel Studio 7. The project file is TMK/TMK.atsln.

Configuration options are set in config.h. If for any reason you use different hardware pins they can be set in this file but the main
reason for changing this file is to set the keyer mode or the two speeds set by the keyer switch.

    #define MIN_MORSE_WPM 16 // Speed when SW1 is open
    #define MAX_MORSE_WPM 20 // Speed when SW1 is closed

    // 0 for Iambic A, 1 for Iambic B or 2 for Ultimatic (defined by enum eMorseKeyerMode in morse.h)
    #define KEYER_MODE 0 

The keyer mode can be set on the compiler command line. To make it easy to produce Iambic A, Iambic B and Ultimatic keyer software
the batch build can be used to build all these by one command.
