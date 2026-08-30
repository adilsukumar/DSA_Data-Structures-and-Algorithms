/*
 * LeetCode 1295 - Find Numbers With Even Number Of Digits [Easy]
 *
 * @platform   LeetCode
 * @id         1295
 * @title      Find Numbers With Even Number Of Digits
 * @difficulty Easy
 * @topics     Array, Math
 * @pattern    Digit Counting via Division
 * @url        https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
 * @solved     2026-07-27
 *
 * Problem
 * Given an array of integers `nums`, return how many of them contain an EVEN number of
 * digits.
 *
 * Approach
 * The number of digits of a positive integer is how many times you can strip off its last
 * digit before nothing is left. Integer division by 10 removes the trailing digit each
 * time (7896 -> 789 -> 78 -> 7).
 *
 * Complexity
 * Time: O(n * d) where n = nums.size() and d = max digit count.
 * Space: O(1).
 *
 * Notes
 * - Single-digit values (1..9): inner loop never runs, digits stays 1 (odd), correctly not
 *   counted.
 * - A range check such as [10,99] or [1000,9999] is shorter but less general.
 *   but it is not asymptotically faster and is harder to read.)
 */

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            int digits = 1;
            int num = nums[i];
            while(num / 10 != 0){
                digits += 1;
                num /= 10;
            }
            if(digits % 2 == 0){
                count += 1;
            }
        }
        return count;
    }
};
