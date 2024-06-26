class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        count = {}
        ans = 0
        lt = 0
        maxf = 0

        for rt in range(len(s)):
            count[s[rt]] = count.get(s[rt], 0) + 1
            maxf = max(maxf, count[s[rt]])
            
            while (rt-lt+1) - maxf > k:
                count[s[lt]] -= 1
                lt += 1

            ans = max(ans, rt-lt+1)

        return ans
