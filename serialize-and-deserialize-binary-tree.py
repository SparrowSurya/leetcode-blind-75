from typing import Tuple, List

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Codec:

    def serialize(self, root: TreeNode) -> str:
        
        def dfs(root: TreeNode, values: List[str]):
            if root is None:
                values.append("N")
                return values
            values.append(str(root.val))
            dfs(root.left, values)
            dfs(root.right, values)
            return values

        return ",".join(dfs(root, []))

    def deserialize(self, data: str) -> TreeNode:
        
        def dfs(i: int) -> Tuple[TreeNode, int]:
            if data[i] == "N":
                return None, i+2
            
            j = i
            while data[j] != ",":
                j += 1
            root = TreeNode(int(data[i:j]))
            i = j + 1
            root.left, i = dfs(i)
            root.right, i = dfs(i)
            return root, i

        return dfs(0)[0]
