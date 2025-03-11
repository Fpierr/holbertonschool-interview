#!/usr/bin/python3
"""Validate utf8 encoding"""


def validUTF8(data):
    """validate utf8 data"""
    nbyte = 0

    for num in data:
        num = num & 0xFF
        if 191 >= num >= 128:
            if not nbyte:
                return False
            nbyte -= 1
        else:
            if nbyte:
                return False
            if num < 128:
                continue
            elif num < 224:
                nbyte = 1
            elif num < 240:
                nbyte = 2
            elif num < 248:
                nbyte = 3
            else:
                return False
    return nbyte == 0
