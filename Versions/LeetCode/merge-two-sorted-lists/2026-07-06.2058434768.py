"""
Platform: LeetCode
Submission: 2058434768
Problem: Merge Two Sorted Lists
Verdict: Accepted
Submitted: 2026-07-06
Recorded in repository: 2026-09-24
URL: https://leetcode.com/problems/merge-two-sorted-lists/
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