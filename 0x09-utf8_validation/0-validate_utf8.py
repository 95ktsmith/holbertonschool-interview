#!/usr/bin/python3
""" UTF-8 Validation """


def validUTF8(data):
    """
    Determines if a given data set represents a valid UTF-8 encoding
    data is a list of numbers representing ASCII characters
    Returns True of data is valid, False if not
    """
    bits = [number & 255 for number in data]
    try:
        bytesObj = bytes(bits)
        bytesObj.decode()
    except:
        return False
    return True
