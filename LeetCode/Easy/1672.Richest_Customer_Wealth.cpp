/*
 * ============================================================================
 * LeetCode 1672 - Richest Customer Wealth                          [Easy]
 * ============================================================================
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
 * ----------------------------------------------------------------------------
 * PROBLEM
 * ----------------------------------------------------------------------------
 * You are given an m x n grid `accounts`, where accounts[i][j] is the amount
 * of money the i-th customer holds in the j-th bank. A customer's WEALTH is
 * the sum of their row. Return the wealth of the RICHEST customer (the single
 * largest row sum). Note: it is the max of the row sums, not the max cell.
 *
 *   accounts = [[1,5],        row 0 -> 1+5   = 6
 *               [7,3],        row 1 -> 7+3   = 10
 *               [3,5]]        row 2 -> 3+5   = 8
 *   answer = 10   (customer 1 is richest)
 *
 * ----------------------------------------------------------------------------
 * INTUITION
 * ----------------------------------------------------------------------------
 * There is no clever trick to find here: wealth is defined per row, and any
 * row could be the richest, so every cell must be visited at least once. The
 * only real decision is how to track "the best so far." Rather than build a
 * list of all row sums and take its max afterward, we fold the two operations
 * into one pass: sum each row as we go, and immediately compare that sum to a
 * running maximum `highest`. This keeps memory flat — we never store more than
 * one row's sum and one champion value at a time. It works because max is
 * associative: the max over all rows equals repeatedly max-ing each new row
 * sum into the champion, in any order.
 *
 * ----------------------------------------------------------------------------
 * WALKTHROUGH (this code, line by line)
 * ----------------------------------------------------------------------------
 *   int highest = 0;                 // champion wealth seen so far
 *   int N_rows = accounts.size();    // number of customers (rows)
 *   int N_columns = accounts[0].size(); // banks per customer (cols)
 *
 *   for i in 0..N_rows:              // walk one customer at a time
 *       int sum = 0;                 // reset accumulator per row (important!)
 *       for j in 0..N_columns:       // walk that customer's banks
 *           sum += accounts[i][j];   // accumulate this customer's wealth
 *       if (sum > highest)           // did this customer beat the record?
 *           highest = sum;           // if so, they are the new richest
 *   return highest;                  // best row sum over the whole grid
 *   return 0;                        // DEAD CODE: unreachable, never runs
 *
 * Note the second `return 0;` can never execute — control always leaves at
 * `return highest;`. It is harmless (most compilers just drop it) but it is
 * noise; delete it. Initializing `highest = 0` is safe here only because the
 * constraints guarantee accounts[i][j] >= 1, so every real wealth is >= 1 and
 * will overtake the initial 0. If negative balances were allowed, seeding with
 * 0 would be a bug and you'd want INT_MIN or the first row's sum instead.
 *
 * DRY RUN on accounts = [[1,5],[7,3],[3,5]]:
 *   start: highest = 0
 *   i=0: sum = 0 -> +1 =1 -> +5 =6 ; 6 > 0  -> highest = 6
 *   i=1: sum = 0 -> +7 =7 -> +3 =10; 10 > 6 -> highest = 10
 *   i=2: sum = 0 -> +3 =3 -> +5 =8 ; 8 > 10 -> (no change)
 *   return 10   ✓ matches expected
 *
 * ----------------------------------------------------------------------------
 * COMPLEXITY
 * ----------------------------------------------------------------------------
 * Time  : O(m * n) — every cell is read exactly once; unavoidable, since the
 *                    answer depends on all balances.
 * Space : O(1)     — only two scalars (`sum`, `highest`) beyond the input; no
 *                    auxiliary array of row sums is built.
 *
 * ----------------------------------------------------------------------------
 * EDGE CASES
 * ----------------------------------------------------------------------------
 * - Single customer / single bank: loops still run once; sum = that value,
 *   which beats 0 and is returned. Handled.
 * - All balances equal: first row sets `highest`, ties never satisfy the
 *   strict `>`, so the (equal) first max is kept. Correct — value is the same.
 * - accounts[0].size() on an empty grid: `accounts[0]` would be out-of-bounds
 *   if m == 0. LeetCode constraints guarantee m,n >= 1, so this is safe here,
 *   but the code would crash on a truly empty input — worth knowing.
 * - Overflow: max n is 200 and max balance 100, so a row sum caps at 20000,
 *   well within int. No overflow risk under the stated constraints.
 *
 * ----------------------------------------------------------------------------
 * OPTIMALITY
 * ----------------------------------------------------------------------------
 * This is already optimal: O(m*n) time is the theoretical floor (each balance
 * must be inspected), and O(1) space cannot be beaten. The only change worth
 * making is cosmetic — remove the unreachable `return 0;`. No better algorithm
 * exists for this problem.
 * ============================================================================
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
