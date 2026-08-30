/*
 * LeetCode 160 - Intersection of Two Linked Lists [Easy]
 *
 * @platform   LeetCode
 * @id         160
 * @title      Intersection of Two Linked Lists
 * @difficulty Easy
 * @topics     Hash Table, Linked List, Two Pointers
 * @pattern    Two-Pointer Length Equalization
 * @url        https://leetcode.com/problems/intersection-of-two-linked-lists/
 * @solved     2026-06-27
 *
 * Problem
 * Two singly-linked lists MAY share a common tail.
 *
 * Approach
 * The obstacle is that the two lists can differ in length, so the shared tail doesn't
 * start at the same "step count" from each head. The trick removes that offset without
 * measuring anything.
 *
 * Complexity
 * Time: O(m + n) -- each pointer takes at most m + n steps (one full pass of each list)
 * before meeting or both reaching NULL.
 * Space: O(1) -- two pointers, no hash set, no length precomputation.
 *
 * Notes
 * - No intersection: both pointers hit NULL together after m + n steps; the loop condition
 *   a != b becomes false (NULL == NULL) and NULL is returned.
 */

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
