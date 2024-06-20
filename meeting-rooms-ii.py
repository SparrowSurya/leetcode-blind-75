from typing import List


class Interval:
    def __init__(self, start: int, end: int):
        self.start = start
        self.end = end


class Solution:
    def minMeetingRooms(self, intervals: List[Interval]):
        start = sorted(i.start for i in intervals)
        end = sorted(i.end for i in intervals)

        count, ans = 0, 0
        s, e = 0, 0

        while s < len(intervals):
            if start[s] < end[e]:
                s += 1
                count += 1
            else:
                e += 1
                count -= 1

            ans = max(ans, count)

        return ans
