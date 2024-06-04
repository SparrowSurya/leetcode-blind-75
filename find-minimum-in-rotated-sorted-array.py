from typing import List


class Solution:
    def findMin(self, nums: List[int]) -> int:
        ans = 10_000
        left, right = 0, len(nums) - 1

        while left <= right:
            mid = (left + right) // 2

            if nums[left] <= nums[right]:
                ans = min(ans, nums[left])
                break

            if nums[left] <= nums[mid]:
                ans = min(ans, nums[left])
                left = mid + 1
            else:
                ans = min(ans, nums[mid])
                right = mid - 1

        return ans
