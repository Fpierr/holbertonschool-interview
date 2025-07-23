#!/usr/bin/python3
"""total square units of water will be retained after it rains"""


def rain(walls):
    """Calculate the total of water of walls"""
    if not walls or len(walls) < 3:
        return 0

    n = len(walls)
    total = 0

    left = [0] * n
    right = [0] * n

    left[0] = walls[0]
    for i in range(1, n):
        left[i] = max(left[i - 1], walls[i])

    right[-1] = walls[-1]
    for i in reversed(range(n - 1)):
        right[i] = max(right[i + 1], walls[i])

    for i in range(1, n - 1):
        water = min(left[i], right[i]) - walls[i]
        if water > 0:
            total += water

    return total
