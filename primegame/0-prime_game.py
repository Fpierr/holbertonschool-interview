#!/usr/bin/python3
"""0-prime_game.py

Holberton School - Prime Game

Prototype: def isWinner(x, nums)
Return the name of the player that won the most rounds.
If the winner cannot be determined, return None.

Constraints:
- No imports
- Files are executed with python3
"""


def _sieve(n):
    """Return a list of booleans where index i is True if i is prime.

    Uses the Sieve of Eratosthenes. Handles n < 2 correctly.
    """
    if n < 2:
        return [False] * (n + 1)
    sieve = [True] * (n + 1)
    sieve[0] = False
    sieve[1] = False
    p = 2
    while p * p <= n:
        if sieve[p]:
            multiple = p * p
            while multiple <= n:
                sieve[multiple] = False
                multiple += p
        p += 1
    return sieve


def isWinner(x, nums):
    """Determine the winner of the Prime Game.

    x is the number of rounds (must equal len(nums)).
    nums is a list of integers (each "n" for a round).

    Returns "Maria" or "Ben" or None if the winner cannot be
    determined (invalid input or tie).
    """
    if not isinstance(x, int) or x <= 0 or not isinstance(nums, list):
        return None
    if x != len(nums):
        return None

    # Precompute primes up to the maximum n in nums
    max_n = 0
    for n in nums:
        if not isinstance(n, int) or n < 0:
            return None
        if n > max_n:
            max_n = n

    sieve = _sieve(max_n)

    maria_wins = 0
    ben_wins = 0

    for n in nums:
        # Count primes <= n
        if n < 2:
            primes_count = 0
        else:
            # sum over sieve[2:n+1]
            primes_count = 0
            i = 2
            while i <= n:
                if sieve[i]:
                    primes_count += 1
                i += 1

        if primes_count % 2 == 1:
            maria_wins += 1
        else:
            ben_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    if ben_wins > maria_wins:
        return "Ben"
    return None
