/*
 * LeetCode 1 - Two Sum [Easy]
 *
 * @platform   LeetCode
 * @id         1
 * @title      Two Sum
 * @difficulty Easy
 * @topics     Array, Hash Table
 * @pattern    Brute-Force Pair Scan
 * @url        https://leetcode.com/problems/two-sum/
 * @solved     2026-06-04
 *
 * Problem
 * Given an array `nums` and an integer `target`, return the INDICES of the two numbers
 * that add up to `target`.
 *
 * Approach
 * The most direct reading of the problem is "try every pair". There are only n*(n-1)/2
 * pairs, so we can just look at all of them and stop at the first one that sums to the
 * target.
 *
 * Complexity
 * Time: O(n^2) -- every pair may be checked.
 * Space: O(1) -- only the two loop counters; the output doesn't count.
 *
 * Notes
 * - Duplicate values are safe because the two indices are always different.
 * - A value-to-index hash map reduces the search to O(n).
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    return {i, j};
                }
            }
        }
        return {};
    }
};
