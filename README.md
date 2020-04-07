# MorseKeyer
 G4TGJ Morse Keyer

This is the software for the TGJ Morse Keyer (TMK) which is described at [xxx](). It is built using Atmel Studio 7. The project file is
TMK/TMK.atsln.

Configuration options are set in config.h. If for any reason you use different hardware pins they can be set in this file but the main
reason for changing this file is to set the keyer mode or the two speeds set by the keyer switch.

#define MIN_MORSE_WPM 16
#define MAX_MORSE_WPM 20

#define KEYER_MODE 0

The keyer mode can be set on the compiler command line. To make it easy to produce Iambic A, Iambic B and Ultimatic keyer software
the batch build can be used to build all these by one command.
