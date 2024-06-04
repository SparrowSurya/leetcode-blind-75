#include <algorithm>
#include <vector>

using namespace std;

__int128_t min3(__int128_t a, __int128_t b, __int128_t c) {
  return min(a, min(b, c));
}

__int128_t max3(__int128_t a, __int128_t b, __int128_t c) {
  return max(a, max(b, c));
}

class Solution {
public:
  int maxProduct(vector<int> &nums) {
    __int128_t ans = *max_element(nums.begin(), nums.end());
    __int128_t cur_min = 1, cur_max = 1;

    for (int num : nums) {
      if (num == 0) {
        cur_min = 1;
        cur_max = 1;
      } else {
        __int128_t new_min = num * cur_min;
        __int128_t new_max = num * cur_max;

        cur_min = min3(new_min, new_max, num);
        cur_max = max3(new_min, new_max, num);

        ans = max(ans, cur_max);
      }
    }

    return ans;
  }
};
