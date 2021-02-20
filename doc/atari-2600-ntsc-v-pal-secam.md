# JiggleSoft's Atari 2600 Common Reference Documentation

## Video Display: NTSC v PAL / SECAM


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


### Atari Standard Video

| ITEM                      | NTSC           | PAL/SECAM      | Notes                                     |
| ------------------------- | -------------- | -------------- | ----------------------------------------- |
| Atari Display Lines       | 262            | 312            | Atari uses 'a fake progressive' display.  |
| Atari Display Refresh     | 60 Hz          | 50 Hz          | NTSC is actually 59.97 Hz.                |
| Atari Vertical Blank      | 40             | 40             | Made up of 3 lines VSYNC and 37 VBLANK.   |
| Atari Overscan Blank      | 30             | 30             | 30 lines of VBLANK.                       |
| Atari Visible Lines       | 192            | 242            | Also known as the KERNEL.                 |
| Horiz. TIA Clocks / Line  | 228            | 228            | Same value for all video display formats. |
| Horiz. Blank TIA Clocks   | 68             | 68             | Same value for all video display formats. |
| Horiz. Visible TIA Clocks | 160            | 160            | Same value for all video display formats. |
| Horiz. CPU Clocks / Line  | 76             | 76             | Same value for all video display formats. |
| Horiz. Blank CPU Clocks   | 22.66          | 22.66          | Same value for all video display formats. |
| Horiz. Visible CPU Clocks | 54.33          | 54.33          | Same value for all video display formats. |

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


## Other Video Displays


### Additional Video

The following chart contains the NTSC, PAL, and SECAM values for comparison to PALX and PAL60.

| ITEM                      | NTSC           | PAL60          | PAL/SECAM      | PALX           | Notes                                     |
| ------------------------- | -------------- | -------------- | -------------- | -------------- | ----------------------------------------- |
| Atari Display Lines       | 262            | 262            | 312            | 312            | Atari uses 'a fake progressive' display.  |
| Atari Display Refresh     | 60 Hz          | 60 Hz          | 50 Hz          | 50 Hz          | NTSC is actually 59.97 Hz.                |
| Atari Vertical Blank      | 40             | 40             | 48             | 40             | Top 3 lines are VSYNC within the VBLANK.  |
| Atari Overscan Blank      | 30             | 30             | 36             | 30             | VBLANK below the visible display.         |
| Atari Visible Lines       | 192            | 192            | 228            | 242            | Also known as the KERNEL.                 |
| Horiz. TIA Clocks / Line  | 228            | 228            | 228            | 228            | Same value for all video display formats. |
| Horiz. Blank TIA Clocks   | 68             | 68             | 68             | 68             | Same value for all video display formats. |
| Horiz. Visible TIA Clocks | 160            | 160            | 160            | 160            | Same value for all video display formats. |
| Horiz. CPU Clocks / Line  | 76             | 76             | 76             | 76             | Same value for all video display formats. |
| Horiz. Blank CPU Clocks   | 22.66          | 22.66          | 22.66          | 22.66          | Same value for all video display formats. |
| Horiz. Visible CPU Clocks | 54.33          | 54.33          | 54.33          | 54.33          | Same value for all video display formats. |

Note:-

 * Standard PAL keeps the visible display aspect ratio in-line with NTSC. This then provides additional clock cycles per frame for Vertical Blank, Visible Display, and Overscan regions.
 * The Standard PAL details are as described in the 'Stella Programmers Guide'. PALX is my designation for the details found in an Atari Programmers Guide.
 * PALX keeps the Vertical Blank and Overscan lines the same NTSC but provides additional Visible Display lines.
 * PAL60 is PAL video hardware (colours) but running with NTSC timings (NTSC game with PAL colours running on PAL hardware). 
 * NTSC50 is not detailed as very few NTSC displays can display a 50Hz display.


### Minimum and Maximum Displayable Lines

Thanks to Thomas Jentzsch and everyone who contributed to the following summary.
Please refer to: https://atariage.com/forums/topic/261266-testing-crt-screen-size/


#### 100%

| Standard | Item     | Min.  | Avg.  | Max.  |
| -------- | -------- | ----- | ----- | ----- |
| NTSC     | VBLANK   |  19   |  26.7 |  41   |
| NTSC     | VISIBLE  | 190   | 217.8 | 234   |
| NTSC     | OVERSCAN |   8   |  17.9 |  31   |
| PAL      | VBLANK   |  24   |  31.4 |  37   |
| PAL      | VISIBLE  | 234   | 263.1 | 280   |
| PAL      | OVERSCAN |   7   |  18.1 |  42   |


#### 60%

| Standard | Item     | Min.  | Avg.  | Max.  |
| -------- | -------- | ----- | ----- | ----- |
| NTSC     | VBLANK   |  16   |  23.3 |  30   |
| NTSC     | VISIBLE  | 215   | 224.2 | 239   |
| NTSC     | OVERSCAN |   6   |  14.5 |  22   |
| PAL      | VBLANK   |  21   |  29.1 |  36   |
| PAL      | VISIBLE  | 255   | 269.1 | 283   |
| PAL      | OVERSCAN |   7   |  14.5 |  24   |
