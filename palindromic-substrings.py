class Solution:
    def countSubstrings(self, s: str) -> int:
        count = 0

        for i in range(len(s)):

            lt, rt = i, i
            while 0 <= lt and rt < len(s) and s[lt] == s[rt]:
                count += 1
                rt += 1
                lt -= 1
                
            lt, rt = i, i+1
            while 0 <= lt and rt < len(s) and s[lt] == s[rt]:
                count += 1
                rt += 1
                lt -= 1

        return count
