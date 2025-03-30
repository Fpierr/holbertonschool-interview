#!/usr/bin/python3
"""N Queens"""

import sys


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


def solve_nqueens(N):
    """Liste for store solutions"""
    solutions = []

    def is_safe(board, row, col):
        """check colonnes and diagonale"""
        for i in range(row):
            if board[i] == col or \
               board[i] - i == col - row or \
               board[i] + i == col + row:
                return False
        return True

    def backtrack(board, row):
        """Find all possible solutions"""
        if row == N:
            solutions.append(board[:])
            return
        for col in range(N):
            if is_safe(board, row, col):
                board[row] = col
                backtrack(board, row + 1)
                board[row] = -1

    board = [-1] * N
    backtrack(board, 0)

    return solutions


solutions = solve_nqueens(N)

for solution in solutions:
    print([[i, solution[i]] for i in range(N)])
