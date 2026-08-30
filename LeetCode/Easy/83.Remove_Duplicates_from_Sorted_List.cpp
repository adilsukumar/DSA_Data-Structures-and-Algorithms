/*
 * LeetCode 83 - Remove Duplicates from Sorted List [Easy]
 *
 * @platform   LeetCode
 * @id         83
 * @title      Remove Duplicates from Sorted List
 * @difficulty Easy
 * @topics     Linked List
 * @pattern    In-Place Pointer Skip
 * @url        https://leetcode.com/problems/remove-duplicates-from-sorted-list/
 * @solved     2026-06-18
 *
 * Problem
 * Given the head of a SORTED singly-linked list, delete all duplicates so that each value
 * appears only once.
 *
 * Approach
 * The list is already sorted, so any duplicates of a value are guaranteed to sit next to
 * each other. That means we never need to search or use a hash set -- we only ever need to
 * compare a node with its immediate neighbor.
 *
 * Complexity
 * Time: O(n) -- each node is visited a constant number of times; every loop iteration
 * either deletes a node or advances, so at most 2n steps.
 * Space: O(1) -- only one pointer; edits happen in place, no extra structures.
 *
 * Notes
 * - Empty list (head == nullptr): first half of the guard is false, loop never runs,
 *   returns nullptr.
 */

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
