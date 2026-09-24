/*
 * Platform: LeetCode
 * Submission: 2038002101
 * Problem: Remove Duplicates from Sorted List
 * Verdict: Accepted
 * Submitted: 2026-06-19
 * Recorded in repository: 2026-09-24
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
        ListNode* current = head;
        while(current != nullptr && current->next != nullptr){
            if(current->val == current->next->val){
                current->next = current->next->next;
            }
            else{
                current = current->next;
            }
        }
        return head;
    }
};