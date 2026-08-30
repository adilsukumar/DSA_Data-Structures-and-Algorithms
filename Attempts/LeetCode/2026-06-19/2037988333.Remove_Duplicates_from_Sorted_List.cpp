/*
 * Platform: LeetCode
 * Submission: 2037988333
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
        vector<int> newlist;
        int count = 0;
        for(int i = 0; i < head.size(); i++){
            count += 1
            if(count[i] != count[i+1]){
                newlist += i;
            }
        }
        return newlist;
    }
};