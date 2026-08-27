"""
─────────────────────────────────────────────────────────────────────────────
 LeetCode 21 · Merge Two Sorted Lists                                   Easy
─────────────────────────────────────────────────────────────────────────────
 @platform   LeetCode
 @id         21
 @title      Merge Two Sorted Lists
 @difficulty Easy
 @topics     Linked List, Recursion, Two Pointers
 @pattern    Dummy Head + Two Pointers
 @url        https://leetcode.com/problems/merge-two-sorted-lists/
─────────────────────────────────────────────────────────────────────────────

 PROBLEM
 -------
 Given the heads of two sorted linked lists, splice them into ONE sorted list
 and return its head. The result should reuse the existing nodes -- you are
 re-wiring pointers, not allocating new nodes.

     list1 = 1 -> 2 -> 4
     list2 = 1 -> 3 -> 4
     out   = 1 -> 1 -> 2 -> 3 -> 4 -> 4

 INTUITION
 ---------
 This is the merge step of merge sort. Both inputs are already sorted, so the
 smallest remaining element overall is always at the FRONT of one list or the
 other -- never buried in the middle. That means you never have to search: just
 compare the two heads, take the smaller, advance that list, repeat.

 The one genuine annoyance in linked-list problems is the head. The first node
 of the answer is a special case: there is no previous node to attach it to.
 Handling that with an `if result is None:` branch inside the loop is ugly and a
 classic source of bugs.

 THE DUMMY HEAD TRICK
 --------------------
     cur = dummy = ListNode()

 Create one throwaway node that sits BEFORE the real answer. Now every node --
 including the first real one -- is appended the same way: `cur.next = node`.
 The special case disappears entirely. At the end you return `dummy.next`,
 which skips the placeholder and hands back the true head.

 This is the single most reusable idea in linked-list problems. Any time the
 head might change or is awkward to establish, reach for a dummy node.

 WALKTHROUGH
 -----------
 cur = dummy = ListNode()          # both names point at the SAME new node.
                                   # `dummy` stays put as an anchor;
                                   # `cur` walks forward as we build.

 while list1 and list2:            # only while BOTH still have nodes, because
                                   # the comparison needs two values

     if list1.val < list2.val:
         cur.next = list1                       # link the smaller node in
         list1, cur = list1.next, list1         # advance both pointers
     else:
         cur.next = list2
         list2, cur = list2.next, list2

 The tuple assignment `list1, cur = list1.next, list1` is doing two things at
 once, and the ordering matters. Python evaluates the ENTIRE right-hand side
 first, so `list1` on the right is still the old node when it is assigned to
 `cur`. Written out longhand it is:

     old = list1
     list1 = list1.next     # step this input list forward
     cur = old              # move the build cursor onto the node we just linked

 if list1 or list2:                # one list is now exhausted, the other may
     cur.next = list1 if list1 else list2

 Because the remainder is ALREADY sorted and every one of its values is >= all
 values placed so far, we can attach the whole tail in one pointer assignment
 rather than looping through it. This is O(1), not O(n) -- a nice property of
 linked lists that arrays do not give you.

 return dummy.next                 # skip the placeholder, return the real head

 Dry run on 1->2->4 and 1->3->4:
     l1=1, l2=1 : 1 < 1 is False -> take list2's 1.   out: 1(from l2)
     l1=1, l2=3 : 1 < 3 True     -> take list1's 1.   out: 1,1
     l1=2, l2=3 : 2 < 3 True     -> take 2.           out: 1,1,2
     l1=4, l2=3 : 4 < 3 False    -> take 3.           out: 1,1,2,3
     l1=4, l2=4 : 4 < 4 False    -> take list2's 4.   out: 1,1,2,3,4
     l2 is now None -> loop exits
     tail: list1 (4) attached in one step             out: 1,1,2,3,4,4   ✔

 A NOTE ON STABILITY
 -------------------
 Using `<` (strict) with the tie going to the `else` branch means that on equal
 values, list2's node is taken first. Using `<=` would prefer list1. Either is
 accepted here since the values are identical, but in a merge sort built on this
 routine, `<=` is what preserves stability. Worth being deliberate about.

 COMPLEXITY
 ----------
 Time : O(n + m)  -- every node is visited at most once; the leftover tail is
                     attached in O(1) rather than walked.
 Space: O(1)      -- only the dummy node and two pointers. No new list is built;
                     the original nodes are re-linked in place.

 EDGE CASES
 ----------
 - Both lists empty -> the while loop and the if are both skipped, dummy.next is
   still None -> returns None. Correct.
 - One list empty -> loop never runs, the `if` attaches the non-empty list
   whole. Correct, and O(1).
 - Lists of very different lengths -> handled by the same tail attachment.

 ALTERNATIVE -- recursive
 ------------------------
     def mergeTwoLists(self, l1, l2):
         if not l1 or not l2: return l1 or l2
         if l1.val <= l2.val:
             l1.next = self.mergeTwoLists(l1.next, l2); return l1
         l2.next = self.mergeTwoLists(l1, l2.next);     return l2

 Shorter and expresses the recurrence directly, but it uses O(n+m) stack space
 and will hit Python's recursion limit on long lists. The iterative version here
 is the one to prefer in an interview.
─────────────────────────────────────────────────────────────────────────────
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
