#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
		unordered_map<char, int> count;
		int ans = 0;
		int lt = 0;
		int maxf = 0;

		for (int rt=0; rt<s.size(); ++rt) {
			char ch = s[rt];
			count[ch] = (count.find(ch) != count.end())? count[ch]+1 : 1;
			maxf = max(maxf, count[ch]);
			
			while ((rt-lt+1) - maxf > k) {
				count[s[lt]] -= 1;
				lt += 1;
			}

			ans = max(ans, rt-lt+1);
		}

		return ans;
    }
};
