#!/usr/bin/python3
""" N Queens """
import sys


def nqueens(row, N, queens, blockedCols, blockedDiags, blockedRevDiags):
    """
    Places N non-attacking queens on an NxN chessboard
    Prints each solution
    """
    if row == N:
        if len(queens) == N:
            print(queens)
        return

    possibleMoves = []
    for col in range(N):
        if col in blockedCols:
            continue
        if row - col in blockedDiags or N - col - row in blockedRevDiags:
            continue
        if [row, col] not in queens:
            possibleMoves.append(col)

    for col in possibleMoves:
        nqueens(
            row + 1,
            N,
            queens + [[row, col]],
            blockedCols + [col],
            blockedDiags + [row - col],
            blockedRevDiags + [N - col - row]
        )

if len(sys.argv) != 2:
    print("Usage: nqueens N")
    sys.exit(1)

try:
    N = int(sys.argv[1])
except ValueError:
    print("N must be a number")
    sys.exit(1)

if N < 4:
    print("N must be at least 4")
    sys.exit(1)

nqueens(0, N, [], [], [], [])
