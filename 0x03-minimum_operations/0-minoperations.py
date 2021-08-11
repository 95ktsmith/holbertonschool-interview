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
    if n <= 1:
        return 0

    # Find n's largest factor
    for number in range(int(n / 2), 0, -1):
        if n % number == 0:
            # Return a number of operations equal to n divided by its largest
            # factor, and the number of operations needed to reach that factor
            return int(n / number) + minOperations(number)
