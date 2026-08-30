/*
 * Platform: LeetCode
 * Submission: 2082319625
 * Problem: Richest Customer Wealth
 * Verdict: Compile Error
 * Date: 2026-07-26
 * URL: https://leetcode.com/problems/richest-customer-wealth/
 *  */

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int highest = 0;
        int N_rows = accounts.size();
        int N_columns = accounts[0].size();
        for(int i = 0; i < N_rows; i++){
            for(int j = 0; j < N_columns; j++){
                int sum = 0;
                sum += accounts[i][j]; 
            }
            if(sum > highest){
                highest = sum;
            }
        }
        return highest;
        return 0;
    }
};