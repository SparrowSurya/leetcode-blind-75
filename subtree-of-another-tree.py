from __future__ import annotations
from typing import Optional

class TreeNode:
    def __init__(self, val: int = 0, left: Optional[TreeNode] = None, right: Optional[TreeNode] = None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:

        def match(root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
            if root is None and subRoot is None:
                return True
            if root is None or subRoot is None:
                return False
            return root.val == subRoot.val and match(root.left, subRoot.left) and match(root.right, subRoot.right)

        def find(root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
            if root is None and subRoot is None:
                return True
            if root is None or subRoot is None:
                return False

            if root.val == subRoot.val and (match(root.left, subRoot.left) and match(root.right, subRoot.right)):
                return True
            return find(root.left, subRoot) or find(root.right, subRoot)

        return find(root, subRoot)
