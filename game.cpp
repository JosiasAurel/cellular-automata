
#include "raylib.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

// screen size
const int WIDTH = 1200;
const int HEIGHT = 600;

const int GRID_WIDTH = WIDTH;
const int GRID_HEIGHT = HEIGHT;

void prefillGrid();
void drawGrid();
int cellsFate(int i, int j);

int cellsGrid[GRID_WIDTH][GRID_HEIGHT];

// This function decides the fate of a cell
int cellsFate(int i, int j)
{
	int liveNeighbours = 0;

	const int neighbours[8][2] = {
		{i-1, j-1},
		{i-1, j},
		{i-1, j+1},
		{i, j-1},
		{i, j+1},
		{i+1, j-1},
		{i+1, j},
		{i+1, j+1}
	};

	for (int ne = 0; ne < 8; ne++) 
	{
		int x = neighbours[ne][0];
		int y = neighbours[ne][1];
		// std::cout << cellsGrid[x][y] << std::endl;
		if (!(x < 0 || x > GRID_WIDTH || y < 0 || y > GRID_HEIGHT))
		{
			if (cellsGrid[x][y] == 1) liveNeighbours++;
			// std::cout << "Live Neighbours : "<< liveNeighbours << std::endl;
		}
	}

	// Evil society
	if (cellsGrid[i][j] == 1)
	{
		if (liveNeighbours > 3 || liveNeighbours < 2)
		{
			// overpopulation or underpopulation
			cellsGrid[i][j] = 0;
			return 0;
		}
		return 1;
	} else if (cellsGrid[i][j] == 0) {
		if (liveNeighbours == 3) 
		{
			cellsGrid[i][j] = 1;
			return 1;
		}
		return 0;
	} else return 0;

}

void prefillGrid() 
{
	for (int i = 0; i < GRID_WIDTH; i++)
	{
		for (int j = 0; j < GRID_HEIGHT; j++) 
		{
			cellsGrid[i][j] = 0;
		}
	}
}

void drawGrid()
{

	for (int i = 0; i < GRID_WIDTH; i++)
	{
		for (int j = 0; j < GRID_HEIGHT; j++)
		{
			if (cellsGrid[i][j] == 1) DrawRectangle(i+64, j+64, 4, 4, PURPLE);
		}
	}
}


int main(void)
{
	prefillGrid();
	/*	
	// samples
	cellsGrid[20][89] = 1;
	cellsGrid[123][45] = 1;
	cellsGrid[430][89] = 1;
	cellsGrid[453][45] = 1;
	cellsGrid[32][89] = 1;
	cellsGrid[353][45] = 1;
	*/
	InitWindow(WIDTH, HEIGHT, "Cellular Automata");
	// init seed
	// srand(time(NULL));
	// init random points
	/*
	for (int i = 0; i < 150; i++)	
	{
		int randI = GetRandomValue(0, GRID_WIDTH); // rand() % (GRID_WIDTH);
		int randJ = GetRandomValue(0, GRID_HEIGHT); //rand() % (GRID_HEIGHT);
		// int offset = rand() % 10;
		cellsGrid[randI][randJ] = 1;
		// std::cout << cellsGrid[randI][randJ] << std::endl;
	}
	*/
	int generation = 0;
	char genMsg[40]; // ~40+ just in case someone plays hard ;)
		
	SetTargetFPS(60);
	int play = 0;
	while(!WindowShouldClose())
	{

		BeginDrawing();
		ClearBackground(WHITE);
		// draw all the cells in the array
		sprintf(genMsg, "Generation : %d ", generation);
		DrawText(genMsg, 20, 40, 30, MAROON);
		if (IsMouseButtonDown(0))
		{		
			Vector2 mousePosition = GetMousePosition();
			cellsGrid[(int)mousePosition.x][(int)mousePosition.y] = 1;
			// DrawRectangle(mousePosition.x+2, mousePosition.y+2, 3, 3, PURPLE);
			// std::cout << mousePosition.x << " " << mousePosition.y << std::endl;
		}

		if (IsKeyPressed(KEY_P))
		{
			play = !play;
		}

		if (play) {	
			generation++;
			for (int i = 0; i < GRID_WIDTH; i++)
			{
				for (int j = 0; j < GRID_HEIGHT; j++) {
					int shouldDraw = cellsFate(i, j);
					if (shouldDraw)
					{
						DrawRectangle(i+64, j+64, 4, 4, PURPLE);
					}
				}
			}	
		} else {
			drawGrid();
		}
		EndDrawing();
	}

	CloseWindow();
	return 0;
}


