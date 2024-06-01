from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxprofit = 0
        buy = 0

        for day, price in enumerate(prices):
            profit = price - prices[buy]
            if profit > maxprofit:
                maxprofit = profit
            if prices[buy] > price:
                buy = day

        return maxprofit
