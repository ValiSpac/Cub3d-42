# cub3D

## Introduction
**cub3D** is a project that involves creating a 3D graphical representation of a maze using **ray casting**. The goal is to render a first-person perspective of the maze using **MiniLibX**, handling textures, colors, and player movement.

## Features
- **Raycasting-based 3D rendering**
- **MiniLibX** for graphics
- **Custom map parsing from .cub files**
- **Wall textures for different directions (N, S, E, W)**
- **Customizable floor and ceiling colors**
- **Smooth movement and camera rotation**
- **Error handling for incorrect maps**

## Mandatory Functionalities
- **Rendering a maze in first-person** using ray casting
- **Movement control**: 
  - `W` / `S` - Move forward/backward
  - `A` / `D` - Strafe left/right
  - Left/Right Arrow - Look left/right
- **Exit handling**:
  - `ESC` - Close window and exit
  - Clicking the red cross also exits cleanly
- **Parsing .cub configuration file**:
  - Identifiers for textures: `NO`, `SO`, `WE`, `EA`
  - RGB colors for floor & ceiling: `F` and `C`
  - Map is composed of `0`, `1`, and `N/S/E/W` for player spawn point
  - Map must be fully enclosed by walls
- **Error handling**:
  - Invalid maps must return `Error\n` with a message

## Bonus Features
- **Wall collision detection**
- **Minimap display**
- **Mouse-controlled camera rotation**

## Installation
```bash
make
```
This will compile the **cub3D** program and its dependencies (libft and MiniLibX).

## Usage
```bash
./cub3D maps/example.cub
```
Replace `maps/example.cub` with your own `.cub` map file.

## Makefile Targets
| Command | Description |
|---------|-------------|
| `make`  | Compile the program |
| `make clean` | Remove object files |
| `make fclean` | Remove executable and object files |
| `make re` | Recompile everything |


## Dependencies
- **MiniLibX** (included in `minilibx/`)
- **libft** (included in `libft/`)
- **math library (`-lm`)**
- **X11 library (`-lX11`, `-lXext`)**

## Example `.cub` File
```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 225,30,0
111111
100001
1010N1
100001
111111
```
