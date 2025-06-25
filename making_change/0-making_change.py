#!/usr/bin/python3
"""list of Coins and tota
"""


def makeChange(coins, total):
    """Function to Determine the fewest number of coins needed to meet
        a given amount total.
    """
    if total <= 0:
        return 0

    dp = [total + 1] * (total + 1)
    dp[0] = 0

    for s in range(1, total + 1):
        for c in coins:
            if c <= s:
                dp[s] = min(dp[s], dp[s - c] + 1)

    return dp[total] if dp[total] <= total else -1
