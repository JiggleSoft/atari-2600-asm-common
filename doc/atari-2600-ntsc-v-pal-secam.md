# JiggleSoft's Atari 2600 Common Reference Documentation

## Video Display: NTSC v PAL/SECAM


### Atari Crystal / Clock Frequencies

| ITEM                     | NTSC           | PAL/SECAM      | Notes                                    |
| ------------------------ | -------------- | -------------- | ---------------------------------------- |
| Video Crystal Frequency  | System Clock   | 4.43361875 MHz | 4.43 MHz on the Atari 2600 schematics.   |
| System Crystal Frequency | 3.579575 MHz   | 3.546894 MHz   | 3.54 MHz on the Atari 2600 schematics.   |
| TIA Clock Relationship   | System Clock   | System Clock   | Driven 1:1 by the system clock.          |
| TIA Clock                | 3.579575 MHz   | 3.546894 MHz   |                                          |
| CPU Clock Relationship   | 1/3 TIA Clock  | 1/3 TIA Clock  | TIA divides the system clock by 3 and output phi0 to the CPU, and the CPU creates and outputs phi2 from it. |
| CPU Clock                | 1.193192 MHz   | 1.182298 MHz   | NTSC actually 1.193191667 MHz.           |

 * Note
   * Crystals at 4.43361875 MHz for PAL video and 3.579545 MHz (30 Hz difference) for NTSC video and TIA system clock are still readily available.
   * PAL system crystal (Atari part# CO16112) 3.546894 MHz are harder to obtain.


## Atari Standard Video

| ITEM                      | NTSC           | PAL/SECAM      | Notes                                     |
| ------------------------- | -------------- | -------------- | ----------------------------------------- |
| Atari Display Lines       | 262            | 312            | Atari uses 'a fake progressive' display.  |
| Atari Display Refresh     | 60 Hz          | 50 Hz          | NTSC is actually 59.97 Hz.                |
| Atari Vertical Blank      | 40             | 40             | Made up of 3 lines VSYNC and 37 VBLANK.   |
| Atari Overscan Blank      | 30             | 30             | 30 lines of VBLANK.                       |
| Atari Visible Lines       | 192            | 242            | Also known as the KERNEL.                 |
| Horiz. TIA Clocks / Line  | 228            | 228            |                                           |
| Horiz. Blank TIA Clocks   | 68             | 68             |                                           |
| Horiz. Visible TIA Clocks | 160            | 160            |                                           |
| Horiz. CPU Clocks / Line  | 76             | 76             |                                           |
| Horiz. Blank CPU Clocks   | 22.66          | 22.66          |                                           |
| Horiz. Visible CPU Clocks | 54.33          | 54.33          |                                           |

The Atari uses a 'fake progressive' display utilising one frame of the interlaced display. This halves the vertical resolution. 

Visible display lines may be safely rediced. Increasing the visible display lines will increase display KERNEL time and reduce available processing time for game logic. Also the display hardware may not be able to safely display the expanded visible lines.

It is important that the total display lines is an even number for the display to be enabled.

The total number of colours available for each TV standard is as follows:-

  * NTSC = 128 unique colours.
  * PAL = 104 unique colours.
  * SECAM = 8 unique colours.

SECAM systems have the Colour/B&W switch hardwired to B&W. The PAL B&W values are assigned a fixed color to each luminance of B&W as per the following table:

| LUM |	COLOUR |
| --- | ------ |
| 0   | Black |
| 2   | Blue |
| 4   | Red |
| 6   | Magenta |
| 8   | Green |
| A   | Cyan |
| C   | Yellow |
| E   | White |


### Video Standards

| ITEM                     | NTSC           | PAL/SECAM      | Notes                                   |
| ------------------------ | -------------- | -------------- | --------------------------------------- |
| Display Lines            | 525            | 625            |                                         |
| Display Visible Lines    | 480            | 576            | NTSC technically known as EIA 525/60 (480i). PAL technically known as CCIR 625/50 (576i).  |
| Display Interlaced       | Yes            | Yes            |                                         |
| Display Frequency        | 60 Hz          | 50 Hz          | NTSC is actually 59.97 Hz.              |


### Links for Further Information

 * https://www.randomterrain.com/atari-2600-memories-tutorial-andrew-davie-07.html
 * https://en.wikipedia.org/wiki/NTSC
 * https://en.wikipedia.org/wiki/PAL
 * https://en.wikipedia.org/wiki/SECAM
 * http://blog.retroleum.co.uk/electronics-articles/pal-tv-timing-and-voltages/
 * http://www.batsocks.co.uk/readme/video_timing.htm
 * https://en.wikipedia.org/wiki/Colorburst

