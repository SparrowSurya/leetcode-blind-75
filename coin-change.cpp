#include <vector>

using namespace std;

class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    int MAX = amount + 1;
    vector<int> table(amount + 1, MAX);

    table[0] = 0;
    for (int amt = 1; amt <= amount; ++amt) {
      for (int coin : coins) {
        if (amt - coin >= 0) {
          table[amt] = min(table[amt], 1 + table[amt - coin]);
        }
      }
    }

    return table[amount] == MAX ? -1 : table[amount];
  }
};
