#include <cstddef>
#include <vector>

using namespace std;

class Solution {
public:
  int combinationSum4(vector<int> &nums, int target) {
    vector<size_t> table(target + 1, 0);
    table[0] = 1;

    for (int total = 1; total <= target; ++total) {
      for (int num : nums) {
        if (total - num >= 0) {
          table[total] += table[total - num];
        }
      }
    }

    return table[target];
  }
};
