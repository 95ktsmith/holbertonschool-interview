#!/usr/bin/python3
""" Pascal's Triangle """


def pascal_triangle(n):
    """
    Returns a list of lists of integers representing the Pascal's triangle
    of height n
    Returns an empty list if n <= 0
    """
    if n <= 0:
        return []

    triangle = [[1]]
    for layer in range(1, n):
        triangle.append([])
        triangle[layer].append(1)
        for i in range(layer - 1):
            sum = triangle[layer - 1][i] + triangle[layer - 1][i + 1]
            triangle[layer].append(sum)
        triangle[layer].append(1)
    return triangle
