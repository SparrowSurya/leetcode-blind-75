from collections import defaultdict

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
            
        d1, d2 = defaultdict(int), defaultdict(int)
        for c1, c2 in zip(s, t):
            d1[c1] += 1
            d2[c2] += 1
        return d1 == d2
