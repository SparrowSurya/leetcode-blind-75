#include <vector>

using namespace std;

class Solution {
public:
  bool canJump(vector<int> &nums) {
    int jump = 0;

    for (int i = 0; i < nums.size() - 1; ++i) {
      jump = max(jump - 1, nums[i]);
      if (jump == 0) {
        return false;
      }
    }

    return true;
  }
};
