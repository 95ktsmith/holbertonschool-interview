#!/usr/bin/env python3
""" Making change """


def makeChange(coins, total):
    """
    Determines the fewest number of coins needed to meet a given amount total
    coins: List of the values of the coins in your possession
    total: The total value to meet
    Returns the fewest number of coins
    """
    if total <= 0:
        return -1

    coins = sorted(coins, reverse=True)
    coinCount = 0

    for coin in coins:
        coinCount += int(total / coin)
        total = total % coin

    if total != 0:
        return -1

    return coinCount
