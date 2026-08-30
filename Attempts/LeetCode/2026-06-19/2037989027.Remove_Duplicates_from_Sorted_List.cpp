/*
 * Platform: LeetCode
 * Submission: 2037989027
 * Problem: Remove Duplicates from Sorted List
 * Verdict: Compile Error
 * Date: 2026-06-19
 * URL: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
 *  */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        auto k = unique(head.begin(), head.end());
        return k;
        
    }
};