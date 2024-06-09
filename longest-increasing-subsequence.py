from typing import List

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        table = [1] * len(nums)

        for i in range(len(nums) - 1, -1, -1):
            for j in range(i+1, len(nums)):
                if nums[i] < nums[j]:
                    table[i] = max(table[i], 1 + table[j])

        return max(table)
