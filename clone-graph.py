from __future__ import annotations
from typing import Dict, Optional

class Node:
    def __init__(self, val: int = 0, neighbors: Optional[Node] = None):
        self.val = val
        self.neighbors = neighbors or []

class Solution:
    def cloneGraph(self, node: Optional[Node]) -> Optional[Node]:
        if node is None:
            return None
        
        def clone(node: Optional[Node], hashmap: Dict[int, Node]) -> Optional[Node]:
            if node is None:
                return None

            copy = Node(node.val)
            hashmap[node.val] = copy
            
            for neighbor in node.neighbors:
                if neighbor.val not in hashmap.keys():
                    clone(neighbor, hashmap)
                copy.neighbors.append(hashmap[neighbor.val])

            return copy

        return clone(node, {})
