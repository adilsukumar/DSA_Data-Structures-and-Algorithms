/*
 * LeetCode 1342 - Number of Steps to Reduce a Number to Zero [Easy]
 *
 * @platform   LeetCode
 * @id         1342
 * @title      Number of Steps to Reduce a Number to Zero
 * @difficulty Easy
 * @topics     Math, Bit Manipulation
 * @pattern    Simulation
 * @url        https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/
 * @solved     2026-09-16
 *
 * Problem
 * Accepted solution for Number of Steps to Reduce a Number to Zero.
 *
 * Approach
 * The solution iteratively reduces the number to zero by either dividing by 2 if
 * the number is even or subtracting 1 if it is odd. A counter tracks the number of
 * operations performed until the number becomes zero. Each operation corresponds
 * to a step in the reduction process as defined by the problem statement.
 *
 * Complexity
 * Time: O(log n) Space: O(1)
 */

class Solution {
public:
    int numberOfSteps(int num) {
        int count = 0;
        while(num > 0){
            if(num%2 == 0){
                num /= 2;
                count += 1;
            }
            else{
                num -= 1;
                count += 1;
            }
        }
        return count;
    }
};
