from typing import List

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        MAX = amount + 1
        table = [MAX] * (amount + 1)
        
        table[0] = 0
        for amt in range(1, amount+1):
            for coin in coins:
                if amt - coin >= 0:
                    table[amt] = min(table[amt], 1 + table[amt - coin])

        return table[amount] if table[amount] != MAX else -1
