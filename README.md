# MorseKeyer
 G4TGJ Morse Keyer

This is the software for the TGJ Morse Keyer (TMK) which was published in RadCom June 2021 and is described at [my website](https://g4tgj.github.io/Morse-Keyer/).

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

### Programming flash and EEPROM

There are many tools available for this including expensive "official" tools and the cheap (and effective) USBasp (which I use). Most of these are Chinese clones but they work
well. It is also possible to use an Arduino as a programmer.

The usual application for programming is [avrdude](https://www.nongnu.org/avrdude/). 
This has a GUI frontend available - [avrdudess](https://blog.zakkemble.net/avrdudess-a-gui-for-avrdude/). This is what I use and it is very good. I also have avrdude set up as
an external tool in Atmel Studio so I can program the flash directly from there.

#### Example avrdude commands

The exact command you need will depend on which programmer you have and your operating system. For example, on Linux you may need to prefix these commands with ``sudo``. Notice 
the subtle differences between the commands e.g. the flash file is in Intel hex format but the EEPROM is in raw binary.

Programming flash:

    avrdude -c usbasp -p t85 -U flash:w:keyer2.1.hex:i

Programming eeprom:

    avrdude -c usbasp -p t85 -U eeprom:w:keyer.eep:r
    
## Building the sofware

To compile from source you will need this repo and [TARL](https://github.com/G4TGJ/TARL).

### Windows Build

You can download the source as zip files or clone the repo using git. To do this install [Git for Windows](https://git-scm.com/download/win) or 
[GitHub Desktop](https://desktop.github.com/).

To build with [Atmel Studio 7](https://www.microchip.com/mplab/avr-support/atmel-studio-7) open TMK/TMK.atsln.

### Linux Build

To build with Linux you will need to install git, the compiler and library. For Ubuntu:

    sudo apt install gcc-avr avr-libc git
    
Clone this repo plus TARL:

    git clone https://github.com/G4TGJ/MorseKeyer.git
    git clone https://github.com/G4TGJ/TARL.git
    
Build:

    cd MorseKeyer/TMK/TMK
    ./build.sh

This creates Release/TMK.hex.
