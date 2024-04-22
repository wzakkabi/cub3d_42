# Cube3D Project README
## Description
Welcome to the Cube3D project from the 42 cursus!
This project is part of the graphics branch and focuses on creating a simple raycasting engine to render a 3D maze.
The goal is to explore the fundamentals of computer graphics and gain a deeper understanding of how 3D rendering works with the help of MiniLibX library.

<img width="1198" alt="Screen Shot 2024-04-22 at 8 40 12 PM" src="https://github.com/wzakkabi/cub3d_42/assets/114888333/876592ad-5d7f-40c4-bbc8-43686ecedaf9">

## Features
- Implements a basic raycasting engine for rendering 3D environments.
- Supports loading and parsing of map files in a custom format.
- Renders walls, sprites, and other objects in the 3D environment.
- Handles player movement and collision detection within the maze.
- Includes basic game elements such as textures, colors, and lighting effects.
- Provides options for configuring game settings such as screen resolution and texture quality.

## Getting Started
To use "cub3d", follow these steps:

1. Clone the repository to your local machine:
```shell
git clone https://github.com/wzakkabi/cub3d_42.git
```

2. Compile the source files:
##install MLX42 library
```shell
make MLX
```
run
```shell
make bonus
```
3. Run the executable with a map file as an argument:\
```shell
./bonus/cub3d_bonus ./bonus/maps/map_test.cub
```
## Controls
- Use the arrow keys or WASD keys to move the player character.
- Use the left and right arrow keys to rotate the player's view.
- Press Esc to exit the game.
## Map Format
Maps in "cub3d" are stored in `.cub` files and consist of the following elements:
- Resolution: Specifies the screen resolution.
- Texture paths: Specifies the paths to textures for walls, sprites, etc.
- Map layout: Specifies the layout of the 3D maze using characters such as 1 (wall), 0 (empty space), 2 (sprite), etc.
- Colors: Specifies colors for elements such as floor, ceiling, etc.

## Credits
The "cub3d" project was created by [walid zakkabi](https://github.com/wzakkabi) and [Mouad Bousbaa](https://github.com/mou4d). Special thanks to [(https://www.1337.ma/en/) and (https://www.42network.org)] for their contributions and support.

## Contact
If you have any questions, suggestions, or issues regarding "cub3d", feel free to contact us or open an issue on the GitHub repository.

