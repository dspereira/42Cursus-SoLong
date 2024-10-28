# 42Cursus-SoLong

## Map
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
