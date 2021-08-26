#!/usr/bin/python3
""" Prime Game """


def isWinner(x, nums):
    """
    Decides a winner between two players (Maria and Ben)
    x is the number of rounds
    nums is an array of n
    Returns the name of the player that won the most rounds
    """
    maria = 0
    ben = 0

    for round in range(x):
        prime_numbers = 0
        for n in range(1, nums[round] + 1):
            if n in [1, 2, 3] or n % 6 == 1 or n % 6 == 5:
                prime_numbers += 1

        if prime_numbers % 2 == 1:
            ben += 1
        else:
            maria += 1

    return "Maria" if maria > ben else "Ben"
