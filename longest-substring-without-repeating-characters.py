from typing import List

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        chars = set()
        left = 0
        ans = 0

        for right, char in enumerate(s):
            while char in chars:
                chars.remove(s[left])
                left += 1
            chars.add(char)
            ans = max(ans, right-left+1)
        return ans

