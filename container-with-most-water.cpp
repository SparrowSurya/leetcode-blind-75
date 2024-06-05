#include <vector>

using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    int max_area = 0;
    int lt = 0, rt = height.size() - 1;

    while (lt < rt) {
      int lh = height[lt];
      int rh = height[rt];
      max_area = max(max_area, (rt - lt) * min(lh, rh));

      if (lh <= rh)
        ++lt;
      else
        --rt;
    }

    return max_area;
  }
};
