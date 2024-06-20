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
	int minMeetingRooms(vector<Interval> intervals) {
		vector<int> start, end;

		for (Interval i: intervals) {
			start.push_back(i.start);
			end.push_back(i.end);
		}

		sort(start.begin(), start.end());
		sort(end.begin(), end.end());

		int ans = 0, count = 0;
		int s = 0, e = 0;

		while (s < len(intervals)) {
			if (start[s] < end[e]) {
				s += 1;
				count += 1;
			} else {
				e += 1;
				count -= 1;
			}
			ans = max(ans, count);
		}

		return ans;
	}
};
