from typing import Optional, Self

class TrieNode:
    def __init__(self):
        self.children = {}
        self.end = False

    def get_or_create(self, char: str) -> Self:
        if char in self.children:
            return self.children[char]
        node = TrieNode()
        self.children[char] = node
        return node

    def get(self, char: str) -> Optional[Self]:
        return self.children.get(char, None)

class WordDictionary:

    def __init__(self):
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        node = self.root
        for ch in word:
            node = node.get_or_create(ch)
        node.end = True

    def search(self, word: str) -> bool:
        return self._search(self.root, word, 0)

    def _search(self, node: TrieNode, word: str, i: int) -> bool:
        if i >= len(word):
            return node is None or node.end

        ch = word[i]
        if ch == ".":
            for child_node in node.children.values():
                if self._search(child_node, word, i+1):
                    return True
            return False

        node = node.get(ch)
        return False if node is None else self._search(node, word, i+1)
