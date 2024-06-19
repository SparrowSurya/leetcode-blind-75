#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end());
		int count = 0;
		int prev_end = intervals[0][1];

		for (int i=1; i<intervals.size(); ++i) {
			int start = intervals[i][0];
			int end = intervals[i][1];
			
			if (start >= prev_end) {
				prev_end = end;
			} else {
				count += 1;
				prev_end = min(end, prev_end);
			}
		}

		return count;
    }
};
