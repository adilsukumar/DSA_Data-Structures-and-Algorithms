"""
LeetCode 21 - Merge Two Sorted Lists [Easy]

@platform   LeetCode
@id         21
@title      Merge Two Sorted Lists
@difficulty Easy
@topics     Linked List, Recursion, Two Pointers
@pattern    Dummy Head + Two Pointers
@url        https://leetcode.com/problems/merge-two-sorted-lists/
@solved     2026-06-09

Problem
Given the heads of two sorted linked lists, splice them into ONE sorted list and return
its head.

Approach
This is the merge step of merge sort. Both inputs are already sorted, so the smallest
remaining element overall is always at the FRONT of one list or the other -- never
buried in the middle.

Complexity
Time: O(n + m) -- every node is visited at most once; the leftover tail is attached in
O(1) rather than walked.
Space: O(1) -- only the dummy node and two pointers.

Notes
- If either list is empty, the remaining list can be attached directly.
"""

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        cur = dummy = ListNode()
        while list1 and list2:               
            if list1.val < list2.val:
                cur.next = list1
                list1, cur = list1.next, list1
            else:
                cur.next = list2
                list2, cur = list2.next, list2
                
        if list1 or list2:
            cur.next = list1 if list1 else list2
            
        return dummy.next
