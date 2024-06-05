from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        triplets = []
        nums.sort()

        for i in range(len(nums)):

            if i > 0 and nums[i - 1] == nums[i]:
                continue

            lt, rt = i + 1, len(nums) - 1
            while lt < rt:
                total = nums[i] + nums[lt] + nums[rt]
                if total > 0:
                    rt -= 1
                elif total < 0:
                    lt += 1
                else:
                    triplets.append([nums[i], nums[lt], nums[rt]])
                    lt += 1
                    while lt < rt and nums[lt - 1] == nums[lt]:
                        lt += 1

        return triplets
