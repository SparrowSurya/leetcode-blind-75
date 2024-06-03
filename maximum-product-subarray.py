from typing import List


class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        ans = max(nums)
        cur_min, cur_max = 1, 1

        for num in nums:
            if num == 0:
                cur_min, cur_max = 1, 1
            else:
                new_min, new_max = num * cur_min, num * cur_max
                cur_min = min(new_min, new_max, num)
                cur_max = max(new_min, new_max, num)
                ans = max(ans, cur_max)

        return ans
