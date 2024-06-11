from typing import List


class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        table = [0] * (target + 1)
        table[0] = 1

        for total in range(1, target + 1):
            for num in nums:
                if total - num >= 0:
                    table[total] += table[total - num]

        return table[target]
