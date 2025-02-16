#!/usr/bin/python3
"""
Script that reads standard input line by line and computes statistics.
"""

import sys


def print_statistics(stats, total_size):
    """Displays log statistics."""
    print(f"File size: {total_size}")
    for code, count in sorted(stats.items()):
        if count > 0:
            print(f"{code}: {count}")


def parse_line(line, stats):
    """Parses a log line and updates statistics."""
    try:
        elements = line.split()
        status_code = elements[-2]
        if status_code in stats:
            stats[status_code] += 1
        return int(elements[-1])
    except (IndexError, ValueError):
        return 0


# Initialize counters
statistics = {"200": 0, "301": 0, "400": 0,
              "401": 0, "403": 0, "404": 0, "405": 0, "500": 0}
line_count = 0
total_size = 0

try:
    for line in sys.stdin:
        total_size += parse_line(line, statistics)
        line_count += 1

        if line_count % 10 == 0:
            print_statistics(statistics, total_size)

    print_statistics(statistics, total_size)

except KeyboardInterrupt:
    print_statistics(statistics, total_size)
    raise
