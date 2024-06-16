from typing import List

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        ans = 0
        hashset = set(nums)

        for num in nums:
            if num - 1 not in hashset:
                length = 0
                while num in hashset:
                    length += 1
                    num += 1
                ans = max(ans, length)

        return ans
