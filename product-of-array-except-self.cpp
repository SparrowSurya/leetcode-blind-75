#include <vector>

using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int product = 1;
    int length = nums.size();
    vector<int> products(length, 1);

    for (int i = 0; i < length; ++i) {
      products[i] = product;
      product *= nums[i];
    }

    product = 1;
    for (int i = length - 1; i >= 0; --i) {
      products[i] = products[i] * product;
      product *= nums[i];
    }

    return products;
  }
};
