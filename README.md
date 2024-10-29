# 42Cursus-SoLong
This project is a core part of the 42 Lisboa curriculum and aims to develop a simple 2D game (top-down view) written in C, utilizing the [MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx) graphics library.

The simple objective of the game is for the player to move around the map, collect all the coins without being caught by the enemy, and reach the treasure chest to end the game. For more information, see the [subject](https://github.com/dspereira/42Cursus-SoLong/blob/main/en.subject.pdf).

## Table of Content

* [Map](#map)
* [Controls](#controls)
* [Example](#example)
* [Installation / Usage](#installation--usage)
* [License](#license)

## Map
The map is an essential part of this project; it contains all the information needed to draw textures (which are images in XPM format), construct the maze, and set the starting positions of both the player and the enemies.

The map is a simple .ber file that is parsed into a two-dimensional array. With the map's information stored in this array, we can use it to check the positions of all elements on the map and perform validations, such as wall collisions, and collisions with enemies, collectibles, and the exit.

```
1111111111111
1C00000000001
10X000000X0C1
10000110X0001
1X000110000E1
10000P0X00001
1000000000001
1111111111111
```
The map can be composed of only these 5 characters:
- 0 -> empty space
- 1 -> wall
- C -> collectible
- E -> map exit
- P -> player’s starting position

## Controls
- W -> Up
- S -> Down
- A -> Left
- D -> Right
- ESC -> Exit

## Example
![so-long](https://github.com/user-attachments/assets/d5f77690-dceb-465c-9d9e-7ba2af4c2bf3)

## Installation / Usage
This project is designed to work on Debian-based Linux distributions.

MiniLibX requires xorg, x11, and zlib to work on Debian-based Linux systems. For more information, see [MiniLibX Getting Started Guide](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html).
```shell
sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
```

Clone repo:
```shell
git clone --recursive git@github.com:dspereira/42Cursus-SoLong.git so_long && cd so_long
```

Build:
```shell
make
```

Usage example:
```shell
./so_long maps/map2.ber
```
## License
This project is licensed under the [MIT License](https://github.com/dspereira/42Cursus-SoLong/blob/main/LICENSE).
