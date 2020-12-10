#!/usr/bin/python3
""" Lockboxes """


def canUnlockAll(boxes):
    """ Will return True if all boxes can be unlocked, or False otherwise """
    if boxes is None:
        return False
    if len(boxes) == 0:
        return True
    return False not in unlock(0, boxes, [False for i in range(0, len(boxes))])


def unlock(box, boxes, unlocked):
    """ If not already unlocked, unlocks the current box and unlocks the boxes
        with the keys it contains.
    """
    if unlocked[box] is False:
        unlocked[box] = True
        for key in boxes[box]:
            if key < len(boxes):
                unlock(key, boxes, unlocked)
    return unlocked
