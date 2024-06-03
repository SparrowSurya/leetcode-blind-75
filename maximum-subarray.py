from typing import List


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_sum = -(10**4)
        cur_sum = 0

        for num in nums:
            cur_sum += num
            if cur_sum > max_sum:
                max_sum = cur_sum
            if cur_sum < 0:
                cur_sum = 0

        return max_sum
