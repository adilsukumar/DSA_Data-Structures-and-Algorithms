/*
 * Platform: LeetCode
 * Submission: 2082294551
 * Problem: Richest Customer Wealth
 * Verdict: Compile Error
 * Date: 2026-07-26
 * URL: https://leetcode.com/problems/richest-customer-wealth/
 *  */

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int N = accounts.size();
        int sum_group1 = 0;
        int sum_group2 = 0;
        int sum = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                sum_group1 += accounts[i][j];  
            }
            if(sum_group1[i] > sum_group1[i+1]){
                sum += sum_group1[i];
            }
            else{
                sum += sum_group1[i+1];
            }
        }
        return sum;
        return 0;   
    }
};