from typing import List


class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        table = [False] * (len(s) + 1)
        table[len(s)] = True

        for i in range(len(s) - 1, -1, -1):
            for w in wordDict:
                if i + len(w) <= len(s) and s[i : i + len(w)] == w:
                    table[i] = table[i + len(w)]
                if table[i]:
                    break

        return table[0]
