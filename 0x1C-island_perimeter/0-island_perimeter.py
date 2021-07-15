#!/usr/bin/python3
""" Island Perimeter """


def island_perimeter(grid):
    """
    Returns the perimeter of the island described in @grid
    grid: a list of lists of integers
        0 represents water
        1 represents land
        Each cell is a square, with a side length of 1
        Cells are connected verically and horizontally (not diagonally)
        grid is rectangular, with its width and height not exceeding 100
    """
    height, width = len(grid), len(grid[0])
    perimeter = 0

    for row in range(0, height):
        for col in range(0, width):

            # If cell is land
            if grid[row][col] == 1:

                # Add four to perimeter, subtract one for each adjacent land
                perimeter += 4

                # Cell above
                if row > 0:
                    if grid[row - 1][col] == 1:
                        perimeter -= 1

                # Cell below
                if row < height - 1:
                    if grid[row + 1][col] == 1:
                        perimeter -= 1

                # Cell left
                if col > 0:
                    if grid[row][col - 1] == 1:
                        perimeter -= 1

                # Cell right
                if col < width - 1:
                    if grid[row][col + 1] == 1:
                        perimeter -= 1

    return perimeter
