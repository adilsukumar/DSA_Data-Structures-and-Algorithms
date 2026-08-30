/*
 * LeetCode 1672 - Richest Customer Wealth [Easy]
 *
 * @platform   LeetCode
 * @id         1672
 * @title      Richest Customer Wealth
 * @difficulty Easy
 * @topics     Array, Matrix
 * @pattern    Row-Sum Running Maximum
 * @url        https://leetcode.com/problems/richest-customer-wealth/
 * @solved     2026-07-26
 *
 * Problem
 * You are given an m x n grid `accounts`, where accounts[i][j] is the amount of money the
 * i-th customer holds in the j-th bank.
 *
 * Approach
 * There is no clever trick to find here: wealth is defined per row, and any row could be
 * the richest, so every cell must be visited at least once. The only real decision is how
 * to track "the best so far." Rather than build a list of all row sums and take its max
 * afterward, we fold the two operations into one pass: sum.
 *
 * Complexity
 * Time: O(m * n) — every cell is read exactly once; unavoidable, since the answer depends
 * on all balances.
 * Space: O(1) — only two scalars (`sum`, `highest`) beyond the input; no auxiliary array
 * of row sums is built.
 *
 * Notes
 * - Single customer / single bank: loops still run once; sum = that value, which beats 0
 *   and is returned.
 */

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
