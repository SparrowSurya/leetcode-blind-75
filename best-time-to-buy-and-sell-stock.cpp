#include <vector>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int maxprofit = 0;
    int buy = 0;
    int len = prices.size();

    for (int i = 0; i < len; ++i) {
      int profit = prices[i] - prices[buy];
      if (profit > maxprofit) {
        maxprofit = profit;
      }
      if (prices[buy] > prices[i]) {
        buy = i;
      }
    }

    return maxprofit;
  }
};
