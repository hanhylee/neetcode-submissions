"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""
from collections import deque

class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return node
        
        copy = Node(node.val)
        clones = {node: copy}
        q = deque()
        q.append(node)

        while q:
            curr = q.popleft()
            for neighbor in curr.neighbors:
                if neighbor not in clones:
                    q.append(neighbor)
                    clone = Node(neighbor.val)
                    clones[neighbor] = clone
                clones[curr].neighbors.append(clones[neighbor])
                
        return copy
        