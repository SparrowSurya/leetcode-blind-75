#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    vector<int> table(nums.size(), 1);

    for (int i = nums.size() - 1; i >= 0; --i) {
      for (int j = i + 1; j < nums.size(); ++j) {
        if (nums[i] < nums[j]) {
          table[i] = max(table[i], 1 + table[j]);
        }
      }
    }

    return *max_element(table.begin(), table.end());
  }
};
