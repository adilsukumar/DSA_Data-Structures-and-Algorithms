/*
 * LeetCode 217 - Contains Duplicate [Easy]
 *
 * @platform   LeetCode
 * @id         217
 * @title      Contains Duplicate
 * @difficulty Easy
 * @topics     Array, Hash Table, Sorting
 * @pattern    Hash set size comparison
 * @url        https://leetcode.com/problems/contains-duplicate/
 * @solved     2026-07-27
 *
 * Problem
 * Given an integer array `nums`, return true if ANY value appears at least twice, and
 * false if every element is distinct.
 *
 * Approach
 * A set stores only distinct keys: inserting a value that is already present is silently
 * ignored. So if you dump the whole array into a set, the set's final size equals the
 * number of DISTINCT values.
 *
 * Complexity
 * Time: O(n) average -- one pass, each insert is expected O(1).
 * Space: O(n) -- in the all-distinct case the set holds every element.
 *
 * Notes
 * - Empty array: loop runs 0 times, both sizes are 0, 0==0 -> false.
 * - Return immediately when set insertion reports a duplicate.
 */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int i = 0; i < nums.size(); i++){
            s.insert(nums[i]);
        }
        if(nums.size() == s.size()){
            return false;
        }
        else{
            return true;
        }
    }
};
