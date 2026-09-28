/*
 * Platform: LeetCode
 * Submission: 2156317471
 * Problem: Best Time to Buy and Sell Stock
 * Verdict: Wrong Answer
 * Date: 2026-09-28
 * URL: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 *  */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = 1;
        int max = 0;
        while (min < max){
            for(int i = 1; i < prices.size(); i++){
                if(prices[i] < prices[i-1]){
                    min = i;
                }
                for(int j = 0; j < prices.size(); j++){
                    if(prices[j] < prices[j+1]){
                        max = j;
                    }
                }
            }
        }
        return max - min;
    }
};