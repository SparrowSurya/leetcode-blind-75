#include <vector>

using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int max_sum = -10000, cur_sum = 0;
    for (int num : nums) {
      cur_sum += num;
      if (cur_sum > max_sum)
        max_sum = cur_sum;
      if (cur_sum < 0)
        cur_sum = 0;
    }
    return max_sum;
  }
};
