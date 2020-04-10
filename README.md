# MorseKeyer
 G4TGJ Morse Keyer

This is the software for the TGJ Morse Keyer (TMK) which is described at [my website](https://g4tgj.github.io/Morse-Keyer/).

You can flash a pre-built hex file (look under the releases tab) or you can build it using Atmel Studio 7. The project file is TMK/TMK.atsln.

By default the keyer is in Iambic A mode with a slow speed of 16wpm and a fast speed of 20wpm but these can be overriden by writing to
the EEPROM. The file can be created in any text editor and written in Avrdudess - select raw binary as the format.

Data format:

    TMK x yy zz

    Always starts with TMK
    x is A for Iambic A, B for Iambic B or U for Ultimatic
    yy is the slow morse speed in wpm
    zz is the fast morse speed in wpm
 
For example:

    TMK U 14 28

If the format is incorrect or the slow and fast speeds are outside
the min (10wpm) and max (30wpm) limits defined in config.h then the default values are used.
