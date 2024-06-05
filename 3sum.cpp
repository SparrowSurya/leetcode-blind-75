#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> triplets;
    int len = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 0; i < len; ++i) {
      if ((i > 0) && (nums[i - 1] == nums[i]))
        continue;

      int lt = i + 1, rt = len - 1;
      while (lt < rt) {
        int total = nums[i] + nums[lt] + nums[rt];

        if (total < 0) {
          lt += 1;
        } else if (total > 0) {
          rt -= 1;
        } else {
          triplets.push_back({nums[i], nums[lt], nums[rt]});
          do {
            lt += 1;
          } while ((lt < rt) && (nums[lt - 1] == nums[lt]));
        }
      }
    }

    return triplets;
  }
};
