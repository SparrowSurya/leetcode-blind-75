#include <vector>

using namespace std;

class Solution {
public:
  int findMin(vector<int> &nums) {
    int ans = 10'000;
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (nums[left] < nums[right]) {
        ans = min(ans, nums[left]);
        break;
      }

      if (nums[left] <= nums[mid]) {
        ans = min(ans, nums[left]);
        left = mid + 1;
      } else {
        ans = min(ans, nums[mid]);
        right = mid - 1;
      }
    }

    return ans;
  }
};
