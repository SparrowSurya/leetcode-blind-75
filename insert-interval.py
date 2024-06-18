from typing import List

class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        ans = []

        for i in range(len(intervals)):
            start, end = intervals[i]
            _start, _end = newInterval

            if _end < start:
                ans.append(newInterval)
                return ans + intervals[i:]
            elif _start > end:
                ans.append(intervals[i])
            else:
                newInterval = [
                    min(start, _start),
                    max(end, _end),
                ]

        ans.append(newInterval)
        return ans
