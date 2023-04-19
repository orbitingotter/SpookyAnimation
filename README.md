# SpookyAnimation
Legacy OpenGL animation - college project

## Preview
![AnimationGIF](https://user-images.githubusercontent.com/112700146/232974513-43507ec7-6bfd-40da-9681-2782fc06d137.gif)


## Working

### Setup -

Setup a basic legacy opengl project with a main loop with variable fps using glutTimerFunc(), draw pixels within.

### Upscaling -

Pixel art usually has small canvas sizes 96x96 or 120x120, so i am upscaling the animation screen size to 768x768 - implemented within PutPixel() which converts canvas coordinates to screen coordinates and i also increase the pixel size using glPointSize to fill the space.

### Animation Control -

Animation is controlled by calling a seperate function each frame (frame001 called on first iteration of main loop, frame002 on second, ... so on), implemented using an array of function pointers at 10 FPS(usual fps for pixel art in general). Within each of these frames, i draw a pixel using its coordinates for position and hexcode for color with PutPixel() function.

Animation Controller goes through each phase of the animation - intro, laugh, spell, attack ... and loops back after reaching end.

### Animation -

Each frame is drawn using data available from previous frame - for eg - after drawing first frame001, copy paste data into frame002 make small changes, copy paste frame002 into frame003 and make small changes and so on.


## Removed files

I removed the main animation files - Pumpkin.h and Menu.h - because this project has credits and i dont want people to just clone it without implementing it themselves - if you still want those files - contact me



## Credits

Pumpking animation - Game dev - Necrobouncer - u/NecroBouncer

Main menu - Pixel artist - u/strokemylegs
