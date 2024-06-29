class Solution:
    def longestPalindrome(self, s: str) -> str:
        start = 0
        max_len = 0

        for i in range(len(s)):
            lt, rt = i, i
            while 0 <= lt and rt < len(s) and s[lt] == s[rt]:
                length = rt - lt + 1
                if length > max_len:
                    start, max_len = lt, length
                rt += 1
                lt -= 1
                
            lt, rt = i, i+1
            while 0 <= lt and rt < len(s) and s[lt] == s[rt]:
                length = rt - lt + 1
                if length > max_len:
                    start, max_len = lt, length
                rt += 1
                lt -= 1

        return s[start:start+max_len]
