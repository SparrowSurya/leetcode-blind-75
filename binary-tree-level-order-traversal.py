from __future__ import annotations
from typing import Optional

class TreeNode:
    def __init__(self, val: int = 0, left: Optional[TreeNode] = None, right: Optional[TrrrNode] = None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        ans = []
        queue = [root]

        while len(queue) != 0:
            values = []
            next_queue = []
            
            for node in queue:
                if node is None: continue
                values.append(node.val)
                next_queue.append(node.left)
                next_queue.append(node.right)
            
            if values: ans.append(values)
            queue = next_queue

        return ans
