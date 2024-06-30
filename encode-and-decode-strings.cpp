#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string encode(vector<string> strs) {
		string ans;
		for (string s: strs) {
			ans.push_back(to_string(s.size()));
			ans.push_back("#");
			ans.push_back(s);
		}
		return ans;
	}

	vector<string> decode(string str) {
		vector<string> ans;
		int i = 0;

		while (i < len(str)) {
			int j = i;
			while ((48 <= str[j]) && (str[j] <= 57)) {
				++j;
			}

			int length = stoi(str.substr(i, j-i));
			ans.append(str.substr(j+1, length));
			i = j + 1 + length;
		}

		return ans;
	}
};
