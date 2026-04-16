# cub3D - 3D Raycasting Engine in C

![cub3D Gameplay Demo](docs/demo.gif)

## Overview
**cub3D** is a custom-built 3D first-person game engine developed entirely in **C**. Inspired by the pioneering mechanics of the 90s classic *Wolfenstein 3D*, this project explores the mathematical fundamentals of 2D to 3D projection without relying on modern, pre-built game engines. 

It utilizes the **Raycasting** technique and the **Digital Differential Analyzer (DDA)** algorithm to render a 3D environment dynamically from a 2D grid map.

## Technical Features
* **Raycasting & DDA Algorithm:** Efficient mathematical calculations for fast ray-grid intersection and wall detection.
* **Directional Texturing:** Dynamic rendering of distinct `.xpm` textures based on wall orientation (North, South, East, West).
* **Environment Parsing:** Robust parsing of `.cub` configuration files to set custom RGB values for ceiling and floor, along with map layout validation.
* **Collision Detection:** Smooth mathematical boundary checks to prevent the player from phasing through walls.
* **Custom Memory Management:** Strict memory leak prevention and resource handling.

## Installation & Compilation

The project is compiled using a standard `Makefile`. It requires `cc` and the miniLibX graphics library dependencies (X11 and Xext on Linux).

1. Clone the repository:
```bash
git clone [https://github.com/akdilsude/Cub3D](https://github.com/akdilsude/Cub3D)
cd cub3d
```

2. Compile the executable:
```bash
make
```

## How to Play

To launch the engine, you must provide a valid map file (`.cub`) as an argument. The repository includes several maps for testing.

```bash
./cub3d maps/valid/default.cub
```

### Controls
* **W** : Move Forward
* **S** : Move Backward
* **A** : Strafe Left
* **D** : Strafe Right
* **Left Arrow** : Rotate Camera Left
* **Right Arrow** : Rotate Camera Right
* **ESC** : Exit the game cleanly

## Directory Structure
```text
cub3D/
├── srcs/         # Core engine logic, rendering, and parsing files
├── inc/          # Header files
├── maps/         # Configuration files (.cub)
│   ├── valid/    # Playable environments
│   └── invalid/  # Maps designed to test error handling and edge cases
├── textures/     # Wall texture assets (.xpm)
├── libft/        # Custom standard C library implementation
├── minilibx-linux/ # Git Submodule: miniLibX graphics library
├── .gitmodules     # Submodule configuration file
├── Makefile      # Build automation
└── README.md     # Project documentation
```

## Architecture
The engine is structured around a continuous game loop managed by `miniLibX`. For every vertical stripe on the screen, a ray is cast from the player's position. The DDA algorithm calculates the exact point where the ray hits a wall on the 2D map. Based on the distance of this hit, the engine calculates the height of the vertical line to draw, creating the illusion of 3D depth. Texture coordinates are then mapped mathematically to these vertical lines.