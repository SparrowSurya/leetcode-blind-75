#include <vector>

using namespace std;

class Solution {
public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> table;
    for (int i = 0; i <= m; ++i) {
      vector<int> row(n + 1, 0);
      table.push_back(row);
    }

    table[1][1] = 1;
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        table[i][j] += table[i - 1][j] + table[i][j - 1];
      }
    }

    return table[m][n];
  }
};
