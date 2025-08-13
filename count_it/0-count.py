#!/usr/bin/python3
"""
Recursive Reddit hot titles keyword counter.

Usage from 0-main.py:
    count_words(subreddit, ['python', 'java', 'javascript'])
"""

from __future__ import annotations
import re
import requests


def count_words(subreddit, word_list):
    """
    Recursively queries Reddit hot posts, parses titles, and prints a sorted
    count of given keywords (case-insensitive, exact word match).
    """
    def _count_words(
            subreddit,
            word_list,
            after=None,
            counts=None,
            weights=None
        ):
        if counts is None:
            counts = {}
        if weights is None:
            weights = {}
            for word in word_list:
                lw = word.lower()
                weights[lw] = weights.get(lw, 0) + 1
                counts.setdefault(lw, 0)

        url = f"https://www.reddit.com/r/{subreddit}/hot.json"
        headers = {"User-Agent": "holberton-count-it/1.0"}
        params = {"limit": 100}
        if after:
            params["after"] = after

        try:
            response = requests.get(url, headers=headers, params=params,
                                    allow_redirects=False, timeout=10)
        except requests.RequestException:
            return

        if response.status_code != 200:
            return

        data = response.json().get("data", {})
        children = data.get("children", [])
        next_after = data.get("after")

        token_pattern = re.compile(r"[A-Za-z]+")
        targets = set(weights.keys())

        for child in children:
            title = child.get("data", {}).get("title", "")
            for token in token_pattern.findall(title):
                lt = token.lower()
                if lt in targets:
                    counts[lt] += weights[lt]

        if next_after:
            _count_words(subreddit, word_list, next_after, counts, weights)
            return

        results = [(word, count) for word, count in counts.items() if count > 0]
        if not results:
            return

        results.sort(key=lambda x: (-x[1], x[0]))
        for word, count in results:
            print(f"{word}: {count}")

    _count_words(subreddit, word_list)
