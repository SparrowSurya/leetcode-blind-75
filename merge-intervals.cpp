#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> ans;
		sort(intervals.begin(), intervals.end());
		ans.push_back(intervals[0]);

		for (int i=1; i < intervals.size(); ++i) {
			int start = intervals[i][0];
			int end = intervals[i][1];
			int prev_end = ans[ans.size()-1][1];

			if (prev_end >= start) {
				ans[ans.size()-1][1] = max(prev_end, end);
			} else {
				vector<int> v = {start, end};
				ans.push_back(v);
			}
		}

		return ans;
	}
};
