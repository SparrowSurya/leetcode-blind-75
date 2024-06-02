#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    unordered_map<int, int> hashmap;

    for (int num : nums) {
      if (hashmap.count(num) > 0) {
        return true;
      }
      hashmap[num] = 1;
    }

    return false;
  }
};
