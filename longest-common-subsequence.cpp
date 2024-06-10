#include <string>

using namespace std;

class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    int table[text1.size() + 1][text2.size() + 1];

    for (int i = 0; i <= text1.size(); ++i) {
      for (int j = 0; j <= text2.size(); ++j) {
        table[i][j] = 0;
      }
    }

    for (int i = text1.size() - 1; i >= 0; --i) {
      for (int j = text2.size() - 1; j >= 0; --j) {
        if (text1[i] == text2[j]) {
          table[i][j] = 1 + table[i + 1][j + 1];
        } else {
          table[i][j] = max(table[i + 1][j], table[i][j + 1]);
        }
      }
    }

    return table[0][0];
  }
};
