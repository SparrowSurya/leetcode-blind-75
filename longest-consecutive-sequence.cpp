#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> hashset(nums.begin(), nums.end());

        for (int num: nums) {
            if (hashset.find(num-1) == hashset.end()) {
                int len = 0;
                while (hashset.find(num) != hashset.end()) {
                    ++num;
                    ++len;
                }
                ans = max(ans, len);
            }
        }

        return ans;
    }
};
