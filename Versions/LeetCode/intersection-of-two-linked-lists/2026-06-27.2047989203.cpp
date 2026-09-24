/*
 * Platform: LeetCode
 * Submission: 2047989203
 * Problem: Intersection of Two Linked Lists
 * Verdict: Accepted
 * Submitted: 2026-06-27
 * Recorded in repository: 2026-09-24
 * URL: https://leetcode.com/problems/intersection-of-two-linked-lists/
 *  */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA;
        ListNode *b = headB;
        
        while (a != b) {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        
        return a;
    }
};