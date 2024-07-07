from typing import List, Tuple

class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_word = False

    def add_word(self, word: str):
        node = self
        for ch in word:
            if ch not in node.children:
                node.children[ch] = TrieNode()
            node = node.children[ch]
        node.is_word = True

    def remove_word(self, word) -> None:
        node = self
        nodes: List[Tuple[TrieNode, str]] = []
        for ch in word:
            nodes.append((node, ch))
            node = node.children[ch]

        for parent, child in reversed(nodes):
            target = parent.children[child]
            if len(target.children) == 0:
                del parent.children[child]
            else:
                return

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        root = TrieNode()
        for word in words:
            root.add_word(word)

        rows, cols = len(board), len(board[0])
        ans = []
        visited = set()

        def dfs(r: int, c: int, node: TrieNode, word: str):
            if (
                r not in range(rows)
                or c not in range(cols)
                or (r, c) in visited
                or board[r][c] not in node.children
            ):
                return
            
            visited.add((r, c))
            node = node.children[board[r][c]]
            word += board[r][c]
            if node.is_word:
                node.is_word = False
                ans.append(word)
                root.remove_word(word)
            dfs(r+1, c, node, word)
            dfs(r, c+1, node, word)
            dfs(r-1, c, node, word)
            dfs(r, c-1, node, word)
            visited.remove((r, c))

        for r in range(rows):
            for c in range(cols):
                dfs(r, c, root, "")

        return ans
