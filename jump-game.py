from typing import List


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        jump = 0

        for i in range(len(nums) - 1):
            jump = max(jump - 1, nums[i])
            if jump == 0:
                return False

        return True
