/*
 * Platform: LeetCode
 * Submission: 2156337034
 * Problem: Best Time to Buy and Sell Stock
 * Verdict: Accepted
 * Submitted: 2026-09-28
 * Recorded in repository: 2026-09-28
 * Variant: Optimized (inferred from submission order)
 * URL: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 *  */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;
        for(int i = 1; i < prices.size(); i++){
            int currentVal = prices[i];
            if(currentVal < minPrice){
                minPrice = currentVal;
            }
            if(maxProfit < currentVal-minPrice){
                maxProfit = currentVal-minPrice;
            }
        }
        return maxProfit;
    }
};