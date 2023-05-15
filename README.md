## Lights off

A fun, but simple brain puzzle game

### How to play
The goal of the game is to turn off all the lights on the board in as few moves as possible. You toggle a light by
clicking it. When toggled, it will change the state of that light and all four adjacent lights (if they exist). That is
what makes this a brain puzzle. You have to figure out which lights to toggle in order to achieve the goal of turning
off all the lights. In this "lights off" game, the stage is randomized, so the difficulty varies. If you get stuck or
complete the game you can generate a new board by pressing "r". Have fun!

### How is it made
The game is made by using [Threepp](https://github.com/markaren/threepp/), the cpp version of the very popular
javaScript library, [three.js](https://github.com/mrdoob/three.js/). It is therefore highly recommended to look into
the [Threepp](https://github.com/markaren/threepp/) library to understand this code. A lot of this code is made from
the examples in the library, so looking into examples like
[snake](https://github.com/markaren/threepp/tree/master/examples/projects/snake) and
[decal](https://github.com/markaren/threepp/blob/master/examples/objects/decal.cpp) might give a greater understanding
of how this game works.

### How to build
- First you will have to install [Threepp](https://github.com/markaren/threepp/), witch is easiest built in conjunction
  with [vcpkg](https://vcpkg.io/en/index.html).
- Then call CMake with `-DCMAKE_TOOLCHAIN_FILE=[path to vcpkg]/scripts/buildsystems/vcpkg.cmake`

### Visual illustration
![lightsoff.gif](Doc%2Flightsoff.gif)

### Known bugs:
- The text that appears when you win is small and behind the boxes in the top left corner

### Credits:
- Threepp: https://github.com/markaren/threepp/
- This project is based on the game Lights Out, invented by Tiger Electronics in 1995.

#### Candidates:
10008 and 10038