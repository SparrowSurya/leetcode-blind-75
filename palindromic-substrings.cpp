#include <string>

using namespace std;

class Solution {
public:
	int countSubstrings(string s) {
		int count = 0;

		for (int i=0; i<s.size(); ++i) {
			int lt = i;
			int	rt = i;
			while ((0 <= lt) && (rt < s.size()) && (s[lt] == s[rt])) {
				++count;
				--lt;
				++rt;
			}
			
			lt = i;
			rt = i+1;
			while ((0 <= lt) && (rt < s.size()) && (s[lt] == s[rt])) {
				++count;
				--lt;
				++rt;
			}
		}

		return count;
    }
};
