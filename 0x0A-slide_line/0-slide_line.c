#include "slide_line.h"

/**
 * slide_line - Moves and merges numbers in an array as per the game 2048
 * @line: Pointer to the array
 * @size: Length of the array
 * @direction: Direction to slide numbers. Should be used with either
 *		SLIDE_LEFT or SLIDE_RIGHT macros.
 * Return: 1 if successful, 0 if not.
 */
int slide_line(int *line, size_t size, int direction)
{
	if (line == NULL || size == 0)
		return (0);
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);
	if (size == 1)
		return (1);

	if (direction == SLIDE_LEFT)
	{
		merge_left(line, size);
		move_left(line, size);
	}
	else
	{
		merge_right(line, size);
		move_right(line, size);
	}
	return (1);
}

/**
 * merge_left - Merges numbers with identical numbers to their left
 * @line: Pointer to the array
 * @size: Size of the array
 */
void merge_left(int *line, size_t size)
{
	size_t current, dest = 0;

	while (dest < size)
	{
		if (line[dest] != 0)
		{
			current = dest + 1;
			while (current < size)
			{
				if (line[current] == line[dest])
				{
					line[dest] *= 2;
					line[current] = 0;
					break;
				}
				else
					current++;
			}
		}
		dest++;
	}
}

/**
 * merge_right - Merges numbers with identical numbers to their right
 * @line: Pointer to the array
 * @size: Size of the array
 */
void merge_right(int *line, size_t size)
{
	long int current, dest = ((long int)size - 1);

	while (dest >= 0)
	{
		if (line[dest] != 0)
		{
			current = dest - 1;
			while (current >= 0)
			{
				if (line[current] == line[dest])
				{
					line[dest] *= 2;
					line[current] = 0;
					break;
				}
				else
					current--;
			}
		}
		dest--;
	}

}

/**
 * move_left - Moves all numbers that aren't zeros to the left, keeping order
 * @line: Pointer to the array
 * @size: Size of the array
 */
void move_left(int *line, size_t size)
{
	size_t current, dest = 0;

	while (dest < size)
	{
		if (line[dest] == 0)
		{
			current = dest + 1;
			while (current < size)
			{
				if (line[current] != 0)
				{
					line[dest] = line[current];
					line[current] = 0;
					break;
				}
				else
					current++;
			}
		}
		dest++;
	}
}

/**
 * move_right - Moves all numbers that aren't zeros to the right, keeping order
 * @line: Pointer to the array
 * @size: Size of the array
 */
void move_right(int *line, size_t size)
{
	long int current, dest = ((long int)size - 1);

	while (dest >= 0)
	{
		if (line[dest] == 0)
		{
			current = dest - 1;
			while (current >= 0)
			{
				if (line[current] != 0)
				{
					line[dest] = line[current];
					line[current] = 0;
					break;
				}
				else
					current--;
			}
		}
		dest--;
	}
}
