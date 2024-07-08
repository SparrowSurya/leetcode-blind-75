#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
		for (int num: nums) {
			if (count.find(num) == count.end()) {
				count[num] = 1;
			} else {
				count[num] += 1;
			}
		}

		vector<vector<int>> freq;
		for (int i=0; i<=nums.size(); ++i) {
			freq.push_back(vector<int>());
		}
		for (auto item: count) {
			freq[item.second].push_back(item.first);
		}

		vector<int> ans;
		for (int i=nums.size(); i>=0; --i) {
			for (int num: freq[i]) {
				ans.push_back(num);
				if (ans.size() == k) return ans;
			}
		}
		return ans;
    }
};
