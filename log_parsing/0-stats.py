#!/usr/bin/python3
"""
Script that reads standard input line by line and computes statistics.
"""

import sys

if __name__ == "__main__":
    stats = {"200": 0, "301": 0, "400": 0,
             "401": 0, "403": 0, "404": 0,
             "405": 0, "500": 0}

    line_count = 0
    total_size = 0

    def parse_line(line):
        """Parses a log line and updates statistics."""
        try:
            elements = line.split()
            if len(elements) < 7:
                return 0
            status_code = elements[-2]
            if status_code in stats:
                stats[status_code] += 1
            return int(elements[-1])
        except (IndexError, ValueError):
            return 0

    def print_stats():
        """Displays log statistics in ascending order."""
        print(f"File size: {total_size}")
        for code in sorted(stats.keys()):
            if stats[code]:
                print(f"{code}: {stats[code]}")

    try:
        for line in sys.stdin:
            total_size += parse_line(line)
            line_count += 1
            if line_count % 10 == 0:
                print_stats()
    except KeyboardInterrupt:
        print_stats()
        sys.exit(0)

    print_stats()
