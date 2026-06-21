"""
================================================================================
LeetCode 121 - Best Time to Buy and Sell Stock                      (Easy)
================================================================================
@platform   LeetCode
@id         121
@title      Best Time to Buy and Sell Stock
@difficulty Easy
@topics     Array, Dynamic Programming
@pattern    Single-Pass Min Tracking
@url        https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
@solved     2026-06-21

PROBLEM
    You are given an array `prices` where prices[i] is the price of a stock on
    day i. You may buy on ONE day and sell on ONE LATER day (buy before sell).
    Return the maximum profit possible; if no profitable trade exists, return 0.

    Example:  prices = [7, 1, 5, 3, 6, 4]
        Buy on day 1 (price 1), sell on day 4 (price 6) -> profit = 5.
        You cannot buy at 1 and sell at 7 because 7 comes earlier (day 0).

INTUITION
    The profit of selling on day i is (price[i] - lowest price seen so far).
    To maximize profit we want, for every possible sell day, the cheapest buy
    day that occurred at or before it. So as we scan left to right we only need
    to remember ONE number: the smallest price seen so far. At each new day we
    ask "what if I sell today, having bought at that cheapest earlier day?" and
    keep the best answer.

    WHY it works: any optimal (buy, sell) pair has the sell day come last in the
    scan. When we reach that sell day, `buy_price` already holds the minimum of
    all earlier prices -- which is exactly the best buy for that sell day. So the
    optimal pair is guaranteed to be considered. The buy-before-sell constraint
    is respected automatically: `buy_price` is only ever updated from days we
    have already passed.

WALKTHROUGH
    buy_price = prices[0]          -> seed the running minimum with day 0's price
    profit    = 0                  -> best profit found so far (0 = "do nothing")

    for current_price in prices[1:]        -> scan days 1..n-1 as candidate sells
        profit = max(profit, current_price - buy_price)
                                   -> could we do better by selling today against
                                      the cheapest earlier day? Record it.
        if current_price < buy_price:
            buy_price = current_price
                                   -> today is a new cheapest buy for FUTURE days

    Note the ordering: profit is computed BEFORE buy_price is possibly lowered.
    This is deliberate and correct -- if today is a new minimum, selling today at
    that same minimum yields <= 0 anyway, so updating first would not gain
    anything, and computing profit first keeps buy strictly on an earlier day.

    Dry run on [7, 1, 5, 3, 6, 4]:
        start: buy_price=7, profit=0
        p=1: profit=max(0, 1-7=-6)=0 ; 1<7 -> buy_price=1
        p=5: profit=max(0, 5-1=4)=4  ; 5<1? no
        p=3: profit=max(4, 3-1=2)=4  ; 3<1? no
        p=6: profit=max(4, 6-1=5)=5  ; 6<1? no
        p=4: profit=max(5, 4-1=3)=5  ; 4<1? no
        return 5   (buy at 1, sell at 6)

COMPLEXITY
    Time  : O(n) -- one linear pass; each day does O(1) work.
    Space : O(1) -- only two scalars (buy_price, profit); the prices[1:] slice
            in Python does allocate a copy, but iterating with an index or
            enumerate would remove even that, so the algorithm itself is O(1).

EDGE CASES
    - Prices strictly decreasing, e.g. [7,6,4,3,1]: no positive difference is
      ever found, profit stays 0 (the "make no trade" answer). Correct.
    - Single day, e.g. [5]: the loop body never runs, returns profit=0. Correct.
    - Empty prices []: prices[0] raises IndexError. LeetCode's constraints
      guarantee length >= 1, so this is not hit here, but be aware of it.
    - Duplicate/flat prices, e.g. [3,3,3]: differences are 0, profit stays 0.
      Correct -- a zero-profit trade is no better than not trading.

    This solution is already optimal (single pass, constant extra state); there
    is no faster approach, so no alternative is sketched.
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
