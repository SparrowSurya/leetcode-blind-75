#include <vector>

using namespace std;

class Solution {
public:
  vector<int> countBits(int n) {
    vector<int> counts(n+1, 0);

    for (int i=1; i<=n; ++i) {
      counts[i] = counts[i >> 1] + (i & 1);
    }

    return counts;
  }
};
