#include <vector>

using namespace std;

class Solution {
public:
  int rob(vector<int> &nums) {
    vector<int> v1(nums.begin() + 1, nums.end());
    vector<int> v2(nums.begin(), nums.end() - 1);
    int ans = max(this->rob1(v1), this->rob1(v2));
    return max(nums[0], ans);
  }

  int rob1(vector<int> &nums) {
    int prev1 = 0, prev2 = 0;
    for (int num : nums) {
      int tmp = prev1;
      prev1 = max(prev2 + num, prev1);
      prev2 = tmp;
    }
    return prev1;
  }
};
