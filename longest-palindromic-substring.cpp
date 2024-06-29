#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
		int start = 0;
		int max_len = 0;

		for (int i=0; i<s.size(); ++i) {
			int lt = i;
			int	rt = i;
			while ((0 <= lt) && (rt < s.size()) && (s[lt] == s[rt])) {
				int length = rt - lt + 1;
				if (length > max_len) {
					start = lt;
					max_len = length;
				}
				--lt;
				++rt;
			}
			
			lt = i;
			rt = i+1;
			while ((0 <= lt) && (rt < s.size()) && (s[lt] == s[rt])) {
				int length = rt - lt + 1;
				if (length > max_len) {
					start = lt;
					max_len = length;
				}
				--lt;
				++rt;
			}
		}

		return s.substr(start, max_len);
    }
};
