/*
 * Platform: LeetCode
 * Submission: 2030163016
 * Problem: Remove Element
 * Verdict: Accepted
 * Submitted: 2026-06-12
 * Recorded in repository: 2026-09-24
 * Variant: Brute Force (inferred from submission order)
 * URL: https://leetcode.com/problems/remove-element/
 *  */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto snehal = remove(nums.begin(), nums.end(), val);
        return snehal - nums.begin();

    }
};