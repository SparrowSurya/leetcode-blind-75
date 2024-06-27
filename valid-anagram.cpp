#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
		if (s.size() != t.size()) return false;

		int arr1[26] = {0};
		int arr2[26] = {0};

		for (int i=0; i<s.size(); ++i) {
			int a = s[i] - 'a';
			int b = t[i] - 'a';
			arr1[a] += 1;
			arr2[b] += 1;
		}

		for (int i=0; i<26; ++i) {
			if (arr1[i] != arr2[i]) return false;
		}

		return true;
    }
};
