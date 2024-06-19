from typing import List

class Interval:
    def __init__(self, start: int, end: int):
        self.start = start
        self.end = end


class Solution:
    def canAttendMeetings(self, intervals: List[Interval]) -> bool:
        intervals.sort()

        for i in range(1, len(intervals)):
            i1 = intervals[i-1];
            i2 = intervals[i];

            if i2.start < i1.end:
                return False

        return True
