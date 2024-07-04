from typing import Optional, Self

class TreeNode:
    def __init__(self, val: int = 0, left: Optional[Self] = None, right: Optional[Self] = None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        if len(preorder) == 0 or len(inorder) == 0: return None

        imap = {val: i for i, val in enumerate(inorder)}

        def build(pstart: int, pend: int, istart: int, iend: int) -> TreeNode:
            if pend < pstart or iend < istart: return None

            root_val = preorder[pstart]
            root = TreeNode(root_val)
            
            imid = imap[root_val]
            left_len = imid - istart

            root.left = build(pstart+1, pstart+left_len, istart, istart + left_len)
            root.right = build(pstart+left_len+1, pend, imid+1, iend)

            return root

        return build(0, len(preorder)-1, 0, len(inorder)-1)
