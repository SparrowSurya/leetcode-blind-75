#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> groups;
		vector<vector<string>> ans;

		for (string s: strs) {
			string key(s.begin(), s.end());
			sort(key.begin(), key.end());
			
			if (groups.find(key) != groups.end()) {
				groups[key].push_back(s);
			} else {
				vector<string> v = { s };
				groups[key] = v;
			}
		}

		for (auto& it: groups) {
			ans.push_back(it.second);
		}

		return ans;
    }
};
