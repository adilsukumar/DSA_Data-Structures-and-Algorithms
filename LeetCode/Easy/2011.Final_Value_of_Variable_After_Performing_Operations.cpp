/*
 * LeetCode 2011 - Final Value of Variable After Performing Operations [Easy]
 *
 * @platform   LeetCode
 * @id         2011
 * @title      Final Value of Variable After Performing Operations
 * @difficulty Easy
 * @topics     Array, String, Simulation
 * @pattern    Linear Scan Counter
 * @url        https://leetcode.com/problems/final-value-of-variable-after-performing-operations/
 * @solved     2026-07-27
 *
 * Problem
 * A variable X starts at 0.
 *
 * Approach
 * Order of application does not matter for the final value -- addition is commutative, so
 * X is just (count of increments) - (count of decrements). The only fact each string
 * carries is its SIGN.
 *
 * Complexity
 * Time: O(n * L) -- one pass over n operations; each string compare touches up to L = 3
 * characters, a constant, so effectively O(n).
 * Space: O(1) -- only the integer accumulator; no extra structures.
 *
 * Notes
 * - Empty operations list: the loop never runs, returns 0.
 */

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int X = 0;
        for(int i = 0; i < operations.size(); i++){
            if(operations[i] == "--X" || operations[i] == "X--"){
                X -= 1;
            }
            else{
                X += 1;
            }
        }
        return X;   
    }
};
