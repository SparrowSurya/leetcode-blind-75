#include <cctype>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
		string str;
		for (char ch: s) {
			if (isalnum(ch)) str.push_back(tolower(ch));
		}

		int left = 0;
		int right = str.size() - 1;
		while (left <= right) {
			if (str[left] != str[right]) return false;
			++left;
			--right;
		}

		return true;
    }
};
