"""
LeetCode 121 - Best Time to Buy and Sell Stock [Easy]

@platform   LeetCode
@id         121
@title      Best Time to Buy and Sell Stock
@difficulty Easy
@topics     Array, Dynamic Programming
@pattern    Single-Pass Min Tracking
@url        https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
@solved     2026-06-21

Problem
You are given an array `prices` where prices[i] is the price of a stock on day i.

Approach
The profit of selling on day i is (price[i] - lowest price seen so far). To maximize
profit we want, for every possible sell day, the cheapest buy day that occurred at or
before it.

Complexity
Time: O(n) -- one linear pass; each day does O(1) work.
Space: O(n) as written because prices[1:] creates a copy; indexed iteration would use
O(1) extra space.

Notes
- A decreasing array returns 0 because no profitable sale exists.
- Iterate by index to avoid copying prices[1:].
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
