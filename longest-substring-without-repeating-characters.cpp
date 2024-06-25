#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		unordered_set<char> chars;
		int ans = 0;
		int lt = 0;

		for (int rt=0; rt < s.size(); ++rt) {
			char ch = s[rt];
			while (chars.find(ch) != chars.end()) {
				chars.erase(s[lt]);
				++lt;
			}
			chars.insert(ch);
			ans = max(ans, rt-lt+1);
		}

		return ans;
    }
};
