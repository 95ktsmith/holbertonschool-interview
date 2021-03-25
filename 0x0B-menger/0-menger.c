#include "menger.h"
#include <math.h>
#include <stdio.h>

/**
 * menger - Prints a 2D menger sponge of a given size
 * @level: Size of the sponge
 */
void menger(int level)
{
	int row, col, size = pow(3, level);

	if (level < 0)
		return;

	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
			putchar(get_char(row, col, pow(3, level - 1)));
		putchar('\n');
	}
}

/**
 * get_char - Recursive function to decide if a hashtag or space is printed
 * @row: Row index
 * @col: Column index
 * @level: Highest level of the cube
 * Return: Character to print
 */
char get_char(int row, int col, int level)
{
	if (level == 0)
		return ('#');
	if ((row / level) % 3 == 1 && (col / level) % 3 == 1)
		return (' ');
	if (row % level == 1 && col % level == 1)
		return (' ');
	return (get_char(row, col, level / 3));
}
