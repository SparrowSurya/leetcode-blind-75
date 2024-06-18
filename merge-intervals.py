from typing import List

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda x: x[0])
        ans = [intervals[0]]

        for (start, end) in intervals[1:]:
            prev_end = ans[-1][1]

            if prev_end >= start:
                ans[-1][1] = max(prev_end, end)
            else:
                ans.append([start, end])

        return ans
