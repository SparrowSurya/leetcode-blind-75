#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int numDecodings(string s) {
    vector<int> table(s.size() + 1, 0);

    table[0] = 1;
    if (s[0] == '0') {
      return 0;
    } else {
      table[1] = 1;
    }

    for (int i = 2; i <= s.size(); ++i) {
      if (s[i - 1] != '0') {
        table[i] += table[i - 1];
      }
      if ((s[i - 2] == '1') || (s[i - 2] == '2' && s[i - 1] <= '6')) {
        table[i] += table[i - 2];
      }
    }

    return table[s.size()];
  }
};
