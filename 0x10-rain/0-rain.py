#!/usr/bin/python3
""" Rain """


def highest(l, offset=0):
    """
    Returns the index and valueo of the highest integer in list l
    """
    hi_i, hi = 0, 0
    for i in range(len(l)):
        if l[i] > hi:
            hi_i = i
            hi = l[i]

    return hi_i + offset, hi


def rain_collected(bucket, lo):
    """
    Returns the amount of rain collected between the first and last indexes
    of a list of walls
    """
    rain = lo * (len(bucket) - 2)
    for volume in bucket[1:-1]:
        rain -= volume
    return rain


def rain(walls):
    """
    Given a list of non-negative integers representing walls of width 1,
    calculates how much water will be retained after it rains.
    """
    # I did this without recursion and I hate it

    rain = 0
    if type(walls) is not list or len(walls) < 3:
        return rain

    # Left
    hi_i, hi = highest(walls)
    while len(walls[:hi_i]) > 2:
        lo_i, lo = highest(walls[:hi_i])
        rain += rain_collected(walls[lo_i:hi_i + 1], lo)
        hi_i = lo_i
        hi = lo

    # Right
    hi_i, hi = highest(walls)
    while len(walls[hi_i + 1:]) > 2:
        lo_i, lo = highest(walls[hi_i + 1:], offset=hi_i + 1)
        rain += rain_collected(walls[hi_i:lo_i + 1], lo)
        hi_i = lo_i
        hi = lo

    return rain
