*This project has been created as part of the 42 curriculum by gujarry.*

# so_long

## Description
**so_long** is a small 2D game project built with **MiniLibX**. The objective is to create a playable game using a tile-based map, handle user input, and manage a basic game loop with rendering.

In this implementation, the game is a **minimal Pac-Man–style** experience:
- the player moves on a grid-based map,
- the goal is to **collect all collectibles** and then reach the exit,
- collectibles have a simple **animation** (they rotate).

**Main objectives:**
- load and validate a map (`.ber`) and its rules,
- render sprites/images with MiniLibX,
- handle keyboard input and collisions,
- implement a move counter and win condition,
- manage memory and properly close the program.

---

## Instructions

### Requirements
- Unix system (Linux/macOS)
- `make`
- `gcc` or `clang`
- **MiniLibX** (the version required by your campus / subject)

> On Linux, MiniLibX often requires additional packages (X11). Follow your 42 setup guide if needed.

### Build
From the repository root:
```bash
make
```

Common Makefile targets (if available):
```bash
make clean
make fclean
make re
```

### Run
General format:
```bash
./so_long maps/map.ber
```

Example:
```bash
./so_long maps/pacman.ber
```

### Controls (typical)
> Adjust if your project uses different keys.
- `W`, `A`, `S`, `D` (or arrow keys): move
- `ESC`: quit

### Notes / expected behavior
- The map must follow the subject rules (commonly):
  - rectangular map
  - surrounded by walls
  - contains exactly one player start (`P`)
  - contains at least one collectible (`C`)
  - contains exactly one exit (`E`)
  - no invalid characters
  - must be solvable (path validation)
- The program should cleanly exit on window close and free allocated resources.

---

## Resources

### Classic references (MiniLibX / graphics / game loop)
- MiniLibX docs / campus resources (recommended as primary reference)
- Linux man pages (useful for debugging and cleanup):
  - `man malloc`, `man free`, `man exit`
  - `man open`, `man close`, `man read`
- General concepts:
  - game loop (update/render)
  - sprite rendering / tile maps
  - basic animation with frame timing

Helpful links (general references):
- Wikipedia — Tile-based video game: https://en.wikipedia.org/wiki/Tile-based_video_game
- Wikipedia — Game loop: https://en.wikipedia.org/wiki/Game_loop

### How AI was used
AI was used **only as assistance** for:
- **Writing and structuring** this `README.md` (sections, clarity, command examples).
- **Proofreading** descriptions of gameplay and project goals.
- **High-level guidance** about organizing code (parsing, validation, rendering loop, animation timing), without copying ready-made code.

AI was **not** used to:
- fully generate the final source code automatically,
- copy/paste complete implementations without understanding,
- bypass the learning goals of the project.

---

## Gameplay overview (this implementation)
- The game is a **minimal Pac-Man–inspired** project: you navigate a maze-like map and collect items.
- **Collectibles are animated**: they rotate (frame-based animation).
- The game ends when:
  - all collectibles are gathered, and
  - the player reaches the exit.

Optional additions you may have (add/remove based on your project):
- move counter displayed in the terminal or window
- simple enemy-free gameplay (focus on movement + collection)
- different sprites for walls/floor/player/exit/collectibles

---

## Author
- gujarry