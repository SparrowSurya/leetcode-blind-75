from __future__ import annotations
from typing import Optional

class TreeNode:
    def __init__(self, val: int = 0, left: Optional[TreeNode] = None, right: Optional[TreeNode] = None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        path_sum = -float("inf")

        def sum_without_split(node: Optional[TreeNode]) -> int:
            nonlocal path_sum
            if node is None: return 0

            left = max(sum_without_split(node.left), 0)
            right = max(sum_without_split(node.right), 0)

            path_sum = max(path_sum, left + node.val + right)
            return node.val + max(left, right)

        sum_without_split(root)
        return path_sum
