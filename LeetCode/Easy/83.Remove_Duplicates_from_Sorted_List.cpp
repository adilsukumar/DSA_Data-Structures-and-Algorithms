/* ============================================================================
 * LeetCode 83 - Remove Duplicates from Sorted List                    [Easy]
 * ============================================================================
 * @platform   LeetCode
 * @id         83
 * @title      Remove Duplicates from Sorted List
 * @difficulty Easy
 * @topics     Linked List
 * @pattern    In-Place Pointer Skip
 * @url        https://leetcode.com/problems/remove-duplicates-from-sorted-list/
 * @solved     2026-06-18
 *
 * PROBLEM
 *   Given the head of a SORTED singly-linked list, delete all duplicates so
 *   that each value appears only once. Return the head of the modified list.
 *   Example:  1 -> 1 -> 2 -> 3 -> 3   becomes   1 -> 2 -> 3
 *
 * INTUITION
 *   The list is already sorted, so any duplicates of a value are guaranteed to
 *   sit next to each other. That means we never need to search or use a hash
 *   set -- we only ever need to compare a node with its immediate neighbor.
 *   When two adjacent nodes are equal, we splice the second one out by pointing
 *   `current->next` past it. When they differ, we've locked in a unique value
 *   and can advance. Because we edit `next` pointers in place, no new list is
 *   built and the original head is always the answer (the first node is always
 *   kept -- there is nothing before it to duplicate).
 *
 * WALKTHROUGH
 *   - `current = head` starts at the first node; we treat `current` as the last
 *     confirmed-unique node whose forward link we may still rewrite.
 *   - The loop guard `current && current->next` stops one node from the end so
 *     that `current->next->val` is always safe to read.
 *   - If `current->val == current->next->val`: the next node is a duplicate, so
 *     `current->next = current->next->next` drops it out of the chain. NOTE we
 *     do NOT advance `current` here -- a value may repeat 3+ times (e.g. 1,1,1),
 *     and we must keep comparing the same `current` against each new successor
 *     until the run ends.
 *   - Else (values differ): the next value is new, so `current = current->next`
 *     moves forward to make it the new anchor.
 *   - When the loop ends, every duplicate run has collapsed to one node; `head`
 *     still points at the (unchanged) first node, so we return it.
 *
 *   Dry run on  1 -> 1 -> 2 -> 3 -> 3 -> nullptr :
 *     current=1[0], next=1  -> equal   -> skip:  1 -> 2 -> 3 -> 3   (current stays at 1[0])
 *     current=1[0], next=2  -> differ  -> move:  current = 2
 *     current=2,    next=3  -> differ  -> move:  current = 3[0]
 *     current=3[0], next=3  -> equal   -> skip:  ... 3 -> nullptr   (current stays at 3[0])
 *     current=3[0], next=nullptr       -> guard fails, loop ends
 *     Result: 1 -> 2 -> 3 -> nullptr
 *
 * COMPLEXITY
 *   Time  : O(n) -- each node is visited a constant number of times; every loop
 *           iteration either deletes a node or advances, so at most 2n steps.
 *   Space : O(1) -- only one pointer; edits happen in place, no extra structures.
 *
 * EDGE CASES
 *   - Empty list (head == nullptr): first half of the guard is false, loop never
 *     runs, returns nullptr. Handled.
 *   - Single node: `current->next` is nullptr, guard fails immediately, returns
 *     head unchanged. Handled.
 *   - Long run of identical values (1,1,1,1): correctly handled because we hold
 *     `current` fixed while skipping, collapsing the whole run to one node.
 *   - All identical (e.g. 1,1,1): collapses to a single 1. Handled.
 *   - Note: leaked memory. The skipped nodes are unlinked but not `delete`d.
 *     LeetCode's judge ignores this, but for production code you'd capture the
 *     dropped node in a temp and free it before rewiring.
 *
 * This is already optimal: sorted input allows a single O(n)/O(1) pass, which is
 * the best achievable since every node must be examined at least once.
 * ============================================================================
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
