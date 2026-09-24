/*
 * Platform: LeetCode
 * Submission: 2083348510
 * Problem: Final Value of Variable After Performing Operations
 * Verdict: Accepted
 * Submitted: 2026-07-27
 * Recorded in repository: 2026-09-24
 * URL: https://leetcode.com/problems/final-value-of-variable-after-performing-operations/
 *  */

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