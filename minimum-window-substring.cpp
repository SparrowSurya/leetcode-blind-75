#include <string>
#include <climits>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() == 0) return t;

		unordered_map<char, int> target, window;

		for (char ch: t) {
			target[ch] = (target.find(ch) != target.end())? target[ch]+1: 1;
		}
		
		int have = 0;
		int need = target.size();
		int ileft = -1;
		int iright = -1;
		int length = INT_MAX;
		int left = 0;

		for (int right=0; right<s.size(); ++right) {
			char ch = s[right];
			window[ch] = (window.find(ch) != window.end())? window[ch]+1: 1;

			if ((target.find(ch) != target.end()) && (window[ch] == target[ch])) {
				have += 1;
			}

			while (have == need) {
				if ((right-left+1) < length) {
					ileft = left;
					iright = right;
					length = right - left + 1;
				}
				
				window[s[left]] -= 1;
				char ch = s[left];
				
				if ((target.find(ch) != target.end()) && (window[ch] < target[ch])) {
					have -= 1;
				}
				
				left += 1;
			}
		}

		return (length != INT_MAX)? s.substr(ileft, length): "";
    }
};
