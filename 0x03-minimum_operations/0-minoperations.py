#!/usr/bin/python3
"""
Min Operations

In a text file, there is a single character H. Your text editor can execute
only two operations in this file: Copy All and Paste. Given a number n, write
a method that calculates the fewest number of operations needed to result in
exactly n H characters in the file.
"""


def minOperations(n):
    """
    Returns the number of operations needed to reach n number of H characters
    Returns 0 if n is impossible to achieve (n is less than 1)
    """
    operations = 0
    while n > 1:
        # Find largest factor
        for number in range(int(n / 2), 0, -1):
            if n % number == 0:
                largest_factor = number
                break
        # Add a number of operations equal to n divided by its largest factor
        operations += n / largest_factor

        # Set n equal to this largest_factor
        n = largest_factor
        # Loop to find number of operations required to get to this factor

    return int(operations)
