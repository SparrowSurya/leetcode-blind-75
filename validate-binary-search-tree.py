from typing import Optional, Self

class TreeNode:
    def __init__(self, val: int = 0, left: Optional[Self] = None, right: Optional[Self] = None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        
        def isValid(node: TreeNode, left: int, right: int) -> bool:
            if node is None: return True
            if node.val > right or left > node.val: return False

            return valid(node.left, left, node.val) and valid(node.right, node.val, right)

        return isValid(root, -float("inf"), float("inf"))
