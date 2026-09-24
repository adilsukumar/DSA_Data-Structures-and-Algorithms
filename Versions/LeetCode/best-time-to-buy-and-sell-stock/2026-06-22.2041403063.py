"""
Platform: LeetCode
Submission: 2041403063
Problem: Best Time to Buy and Sell Stock
Verdict: Accepted
Submitted: 2026-06-22
Recorded in repository: 2026-09-24
URL: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
"""

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        buy_price = prices[0]
        profit = 0

        for current_price in prices[1:]:
            profit = max(profit, current_price-buy_price)

            if current_price < buy_price:
                buy_price = current_price

        return profit