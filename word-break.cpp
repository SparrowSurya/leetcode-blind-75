#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    vector<bool> table(s.size() + 1, false);
    table[s.size()] = true;

    for (int i = s.size() - 1; i >= 0; --i) {
      for (string w : wordDict) {
        string ss = s.substr(i, w.size());

        if ((i + w.size() <= s.size()) &&
            count(wordDict.begin(), wordDict.end(), ss)) {
          table[i] = table[i + w.size()];
        }

        if (table[i])
          break;
      }
    }

    return table[0];
  }
};
