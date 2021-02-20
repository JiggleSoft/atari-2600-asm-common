# Atari 2600 - Algorithm - Aim (AIM)

This is an efficient algorithm to approximate a normalised and pre-scaled vector from one co-ordinate to another co-ordinate utilising a look up data table.
This will be useful in games where a computer opponent will fire a bullet towards the player.
There are no expensive multiplication (squaring and scaling) or finding square roots to normalise and optionally scale the vector using this method.
Only addition, subtraction, exclusive or, and shifting are used.
Although this version of the code is written for the Atari 2600 it could be used for other 65xx based systems.
Also the algorithms method could be migrated to other architectures / platforms.


## Problem

The original issue was posted to the Atari Age Discord channel programming as follows:

```
Ramosław 01/12/2020

I'm writing a homebrew game for the 2600 in assembly.
I want to have an enemy be able to fire a missile towards the player, in any direction.
The only way I can think of how to do this is using Q7.8 fixed point numbers, 
and normalize a vector from the enemy to the player to calculate the missile's X & Y velocity.
However, this seems kind of expensive, and not to mention I find working with signed fixed 
point numbers to be a headache. Are there any other methods to get almost omnidirectional aiming?
```

My initial response was as follows:-

```
Justin 12/12/2020

@Ramosław Did you get any help with your missile direction problem?  
I was thinking about this and think that if you get the absolute delta for X and Y and then while 
delta is say > 3 (or 7, or 15) then divide by 2 the delta X and Y until both are less than or 
equal 3 (or 7, or 15) then with the delta for X and Y use them as index into an array of missile 
direction magnitudes for X and Y to be applied for the direction. The array can be a power of 2 in 
one direction (index = X  + (Y<<3)). You then need no multiplication or division above shifting.
```

Subsequent communication was as follows:-

```
Ramosław 12/12/2020

that seems pretty clever. I think i'll try this out. Thanks for the suggestion!
```

```
Justin 14/12/2020
@Ramosław did you get anywhere with this yet. 
I created  an excel sheet with the data and I only need data for one quadrant (1/4) of the data 
and I can get the y data from x data table so could halve the remaining data size again. If you 
want my spreadsheet I can share it. I will probably knock up the code and stick it in a git repo 
anyway as I can see I will need it for something.
```

This has thus lead to this implementation.
Code is written for the CA65 (https://cc65.github.io/) assembler and can easily be ported to other assemblers.


## Solution

TODO

The spreadsheet used for calculating the data table can be found [here](a2k6algo-aim.xlsx).

TODO


### Input

aim_x1  unsigned byte, x co-ordinate where the direction the vector will be pointing from.\
aim_y1  unsigned byte, y co-ordinate where the direction the vector will be pointing from.

aim_x2  unsigned byte, x co-ordinate where the direction the vector will be pointing towards.\
aim_y2  unsigned byte, y co-ordinate where the direction the vector will be pointing towards.


### Working

aim_quad quadrant\
aim_dx   unsigned byte, absolute delta x, will be reduced to table range.\
aim_dy   unsigned byte, absolute delta y, will be reduced to table range.

### Output

aim_vx   signed 4.4 fixed point, x vector.\
aim_vy   signed 4.4 fixed point, y vector.


## Contact Us

Please email atari2600@jigglesoft.co.uk regarding this repository.
