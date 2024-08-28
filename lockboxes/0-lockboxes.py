#!/usr/bin/python3

"""A method that determines if all the boxes can be opened."""


def canUnlockAll(boxes): 
    """
    Determines if all boxes can be opened.

    Parameters:
    boxes (list of list of int): A list where each element is a list of keys, each key is an integer.
    
    Returns:
    bool: True if all boxes can be opened, False otherwise.
    """
    n = len(boxes)
    unlocked = set([0])
    queue = [0]
    
    while queue: 
        current_box = queue.pop(0)
        
        for key in boxes[current_box]: 
            if key < n and key not in unlocked:
                unlocked.add(key)
                queue.append(key)
                
    return len(unlocked) == n
