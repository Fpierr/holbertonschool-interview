#!/usr/bin/python3
"""
0-pascal_triangle
Module that generates Pascal's triangle of size n.
"""


def pascal_triangle(n):
    """
    Returns a list of lists representing Pascal's triangle of n rows.

    Args:
        n (int): Number of rows in the triangle.

    Returns:
        list: Pascal's triangle as a list of lists of integers.
    """
    if n <= 0:
        return []

    triangle = [[1]]

    for i in range(1, n):
        prev_row = triangle[i - 1]
        row = [1]
        for j in range(1, i):
            row.append(prev_row[j - 1] + prev_row[j])
        row.append(1)
        triangle.append(row)

    return triangle
