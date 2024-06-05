from typing import List


class Solution:
    def maxArea(self, height: List[int]) -> int:
        max_area = 0
        lt, rt = 0, len(height) - 1

        while lt < rt:
            lh, rh = height[lt], height[rt]
            area = (rt - lt) * min(lh, rh)
            max_area = max(max_area, area)

            if lh <= rh:
                lt += 1
            else:
                rt -= 1

        return max_area
