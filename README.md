# Cub3D - 42 Network Project with Hamza Benfaddoul

## Introduction
Cub3D is a project that is part of the 42 Network projects, an educational network of coding schools. The project involves creating a simple 3D game engine using the Raycasting technique. It allows players to navigate through a maze-like environment and experience a basic first-person perspective.

## Features
Cub3D offers the following features:

1. **Raycasting Engine:** The project implements a basic Raycasting engine to render the 3D maze-like environment and create a pseudo-3D effect.

2. **Texture Mapping:** Cub3D supports texture mapping, allowing the walls of the maze to be textured and giving them a realistic appearance.

3. **Sprite Rendering:** The engine enables the rendering of sprites, adding dynamic elements to the scene, such as enemies or collectibles.

4. **User Interaction:** Players can move within the maze using the arrow keys or the WASD keys and look around using the mouse.

5. **Collision Detection:** Cub3D incorporates collision detection, preventing players from passing through walls or obstacles.

6. **Minimap:** The game displays a minimap in the corner of the screen, providing players with an overview of the maze.

## How to Use
1. Clone the Cub3D repository from the 42 Network:
   ```
   git clone <repository_url>
   ```

2. Change into the Cub3D directory:
   ```
   cd cub3d
   ```

3. Build the Cub3D executable using the provided build system:
   ```
   cd bonus && make
   ```

4. Run Cub3D:
   ```
   ./Cub3d map/map1.cub
   ```

5. Play the game, navigate the maze, and explore the environment.

## Map File
The game requires a map file in a specific format to define the maze layout and other game settings. The map file contains information about the maze layout, textures, sprite locations, and player starting position, among other parameters.

## Controls
- Move forward: Up arrow key / W key
- Move backward: Down arrow key / S key
- Strafe left: Left arrow key / A key
- Strafe right: Right arrow key / D key
- Look around: Move the mouse
- Exit the game: Press the "ESC" key or close the window

## Supported Platforms
Cub3D is designed to run on Unix-based systems, such as Linux and macOS.

## License
This project is open-source and distributed under the MIT License. Feel free to use, modify, and distribute it according to the terms specified in the LICENSE file.

## Contributions
Contributions to Cub3D are welcome. If you encounter any issues or have improvements to suggest, please open an issue or submit a pull request on the 42 Network repository.

## Acknowledgments
Cub3D is part of the 42 Network projects, an educational initiative that aims to provide students with hands-on coding experience and real-world projects.

---

Note: This README provides an overview of the Cub3D project as part of the 42 Network. Depending on the specific project requirements and guidelines of the 42 Network, you may need to customize and expand this README to provide more detailed information about the project, its structure, and additional features.
