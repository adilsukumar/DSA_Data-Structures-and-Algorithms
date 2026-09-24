/*
 * Platform: LeetCode
 * Submission: 2082320017
 * Problem: Richest Customer Wealth
 * Verdict: Accepted
 * Submitted: 2026-07-26
 * Recorded in repository: 2026-09-24
 * URL: https://leetcode.com/problems/richest-customer-wealth/
 *  */

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int highest = 0;
        int N_rows = accounts.size();
        int N_columns = accounts[0].size();
        for(int i = 0; i < N_rows; i++){
            int sum = 0;
            for(int j = 0; j < N_columns; j++){
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