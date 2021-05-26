#!/usr/bin/python3
""" Rotate 2D Matrix """


def rotate_2d_matrix(matrix):
    """
    Rotates a square 2d matrix 90 degrees clockwise
    """
    n = len(matrix)
    rotated = [[0 for col in range(n)] for row in range(n)]
    for row in range(n):
        for col in range(n):
            rotated[col][n - row - 1] = matrix[row][col]
    for row in range(n):
        for col in range(n):
            matrix[row][col] = rotated[row][col]
