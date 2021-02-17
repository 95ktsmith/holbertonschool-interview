#!/usr/bin/python3
""" UTF-8 Validation """


def validUTF8(data):
    """
    Determines if a given data set represents a valid UTF-8 encoding
    data is a list of numbers representing ASCII characters
    Returns True of data is valid, False if not
    """
    return True not in map(lambda x: x > 255, data)
