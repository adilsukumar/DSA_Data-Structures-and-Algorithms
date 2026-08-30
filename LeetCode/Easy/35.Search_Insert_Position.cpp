/*
 * LeetCode 35 - Search Insert Position [Easy]
 *
 * @platform   LeetCode
 * @id         35
 * @title      Search Insert Position
 * @difficulty Easy
 * @topics     Array, Binary Search
 * @pattern    Linear Scan (should be Binary Search)
 * @url        https://leetcode.com/problems/search-insert-position/
 * @solved     2026-06-13
 *
 * Problem
 * Given a SORTED array of distinct integers and a target, return the index of the target
 * if found.
 *
 * Approach
 * The answer is the first index whose value is at least target. This code finds it with
 * a linear scan, though the sorted input also allows binary search.
 *
 * Complexity
 * Time: O(n) -- worst case (target at the end or beyond) touches every element.
 * Space: O(1)
 *
 * Notes
 * - Target smaller than everything -> returns 0 on the first comparison.
 * - Binary search would meet the requested O(log n) time bound.
 */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target){
                return i;
            }
            else{
                if(target < nums[i]){
                    return i;
                }
            }
        }
        return nums.size();
    }
};
