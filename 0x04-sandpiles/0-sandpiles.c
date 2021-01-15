#include "sandpiles.h"
#include <stdio.h>

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: Sandpile 1
 * @grid2: Sandpile 2
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int row, col;

	add_grids(grid1, grid2);
	while (1)
	{
		if (is_stable(grid1))
			return;

		printf("=\n");
		row = 0;
		while (row < 3)
		{
			col = 0;
			while (col < 3)
			{
				printf("%d", grid1[row][col]);
				if (col < 2)
					printf(" ");
				else
					printf("\n");
				col++;
			}
			row++;
		}
		topple(grid1, grid2);
	}
}

/**
 * copy - Copies the contents of one grid into the other
 * @grid1: source grid
 * @grid2: destination grid
 */
void copy(int grid1[3][3], int grid2[3][3])
{
	int row = 0, col;

	while (row < 3)
	{
		col = 0;
		while (col < 3)
		{
			grid2[row][col] = grid1[row][col];
			col++;
		}
		row++;
	}
}

/**
 * topple - Performs one toppling round
 * @grid1: Source grid
 * @grid2: Destination grid
 */
void topple(int grid1[3][3], int grid2[3][3])
{
	int row = 0, col = 0;

	copy(grid1, grid2);
	while (row < 3)
	{
		col = 0;
		while (col < 3)
		{
			if (grid1[row][col] > 3)
			{
				grid2[row][col] -= 4;
				if (row + 1 < 3)
					grid2[row + 1][col] += 1;
				if (row - 1 >= 0)
					grid2[row - 1][col] += 1;
				if (col + 1 < 3)
					grid2[row][col + 1] += 1;
				if (col - 1 >= 0)
					grid2[row][col - 1] += 1;
			}
			col++;
		}
		row++;
	}
	copy(grid2, grid1);
}

/**
 * add_grids - Adds two grids together
 * @grid1: First grid
 * @grid2: Second grid, added into grid1
 */
void add_grids(int grid1[3][3], int grid2[3][3])
{
	int row = 0, col = 0;

	while (row < 3)
	{
		col = 0;
		while (col < 3)
		{
			grid1[row][col] += grid2[row][col];
			col++;
		}
		row++;
	}
}

/**
 * is_stable - Checks if a grid is stable or not
 * @grid: grid to check
 * Return: 1 if stable, 0 if not
 */
int is_stable(int grid[3][3])
{
	int row = 0, col = 0;

	while (row < 3)
	{
		col = 0;
		while (col < 3)
		{
			if (grid[row][col] > 3)
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}
