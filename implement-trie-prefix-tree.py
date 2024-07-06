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

class Trie:

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        node = self.root
        for ch in word:
            node = node.get_or_create(ch)
        node.end = True

    def search(self, word: str) -> bool:
        node = self.root
        for ch in word:
            node = node.get(ch) 
            if node is None:
                return False
        return node.end

    def startsWith(self, prefix: str) -> bool:
        node = self.root
        for ch in prefix:
            node = node.get(ch) 
            if node is None:
                return False
        return True
