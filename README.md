
# Cellular Automata : Conway's Game of Life

This is my implementation of [Conway's Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life), a sort of [cellular automaton](https://en.wikipedia.org/wiki/Cellular_automaton). It is a zero-player game meaning you don't have control over the game while its running. All you can do is tweak the initial state of the game cells.

## Rules of the Game 
The rules of Conway's Game of Life are;
- A cell can either be _live_ or _dead_. Those are the only two states of a cell.
- A cell can interact with its eight neighbours which are vertically, diagonally or horizontally oriented.
- A live cell having less than 2 neighbours dies (underpopulation).
- A live cell with 2 or 3 neighbours lives unto the next generation.
- A live cell with > 3 neighbours dies (overpopulation).
- A dead cell with exactly 3 neighbours comes alive (reproduction).
- The initial pattern is the seed of the system.

## Usage
First make sure you have raylib correctly setup on your machine.
This guide works for Windows only (but the Makefile can be adjusted with the right commands for other platforms)

Get raylib [here](https://www.raylib.com/)

Clone the repository locally
```shell
git clone https://github.com/JosiasAurel/cellular-automata.git
```

Now move into it with
```shell
cd cellular-automata
```
Run `make && game` to build and run the game.
If everything went right, you should be able to draw in the window by pressing your left mouse button and moving it in the grid.

Press **p** to start the _automata_ game.

Have fun!
