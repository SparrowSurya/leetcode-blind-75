#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		vector<vector<int>> ans;

		for (int i=0; i < intervals.size(); ++i) {
			int start = intervals[i][0];
			int end = intervals[i][1];
			int _start = newInterval[0];
			int _end = newInterval[1];

			if (_end < start) {
				ans.push_back(newInterval);
				for (int j=i; j < intervals.size(); ++j) {
					ans.push_back(intervals[j]);
				}
				return ans;
			} else if (_start > end) {
				ans.push_back(intervals[i]);
			} else {
				newInterval[0] = min(start, _start);
				newInterval[1] = max(end, _end);
			}
		}

		ans.push_back(newInterval);
		return ans;
	}
};
