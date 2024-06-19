#include <vector>
#include <algorithm>

using namespace std;

class Interval {
public:
	int start;
	int end;
	Interval(int start, int end) {
		start = start;
		end = end;
	}
};

class Solution {
public:
	bool canAttendMeetings(vector<Interval>& intervals) {
		sort(intervals.begin(), intervals.end());

		for (int i=1; i < intervals.size(); ++i) {
			Interval i1 = intervals[i-1];
			Interval i2 = intervals[i];

			if (i2.start < i1.end) {
				return false;
			}
		}

		return true;
};
