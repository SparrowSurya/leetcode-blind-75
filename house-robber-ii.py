from typing import List

class Solution:
    def rob(self, nums: List[int]) -> int:
        return max(nums[0], self.rob1(nums[:-1]), self.rob1(nums[1:]))

    def rob1(self, nums: List[int]) -> int:
        prev1 = prev2 = 0
        for num in nums:
            prev1, prev2 = max(prev2 + num, prev1), prev1
        return prev1
