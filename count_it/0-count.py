#!/usr/bin/python3
"""
Recursive Reddit hot titles keyword counter.

Usage from 0-main.py:
    count_words(subreddit, ['python', 'java', 'javascript'])
"""

import __future__ import annotations
import re
import requests
from typing import Dict, List, Optional


def count_words(subreddit: str,
                word_list: List[str],
                after: Optional[str] = None,
                counts: Optional[Dict[str, int]] = None,
                weights: Optional[Dict[str, int]] = None) -> None:
    """
    Recursively queries Reddit hot posts, parses titles, and prints a sorted
    count of given keywords (case-insensitive, exact word match).

    - Prints nothing on invalid subreddit or no matches.
    - Duplicates in word_list are summed (weight).
    - Results printed in desc count, then A->Z for ties.
    """
    if counts is None:
        counts = {}
    if weights is None:
        weights = {}
        for w in word_list:
            lw = w.lower()
            weights[lw] = weights.get(lw, 0) + 1
            counts.setdefault(lw, 0)

    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    headers = {"User-Agent": "holberton-count-it/1.0"}
    params = {"limit": 100}
    if after:
        params["after"] = after

    try:
        resp = requests.get(url, headers=headers, params=params,
                            allow_redirects=False, timeout=10)
    except requests.RequestException:
        return

    if resp.status_code != 200:
        return

    data = resp.json().get("data", {})
    children = data.get("children", [])
    next_after = data.get("after")

    token_re = re.compile(r"[A-Za-z]+")

    target = set(weights.keys())
    for child in children:
        title = child.get("data", {}).get("title", "")
        for tok in token_re.findall(title):
            lt = tok.lower()
            if lt in target:
                counts[lt] += weights[lt]

    if next_after:
        count_words(subreddit, word_list, next_after, counts, weights)
        return

    results = [(w, c) for w, c in counts.items() if c > 0]
    if not results:
        return

    results.sort(key=lambda x: (-x[1], x[0]))
    for w, c in results:
        print(f"{w}: {c}")
