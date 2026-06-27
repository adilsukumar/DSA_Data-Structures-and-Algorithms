/* ============================================================================
 * LeetCode 160 - Intersection of Two Linked Lists          [Difficulty: Easy]
 * ============================================================================
 * @platform   LeetCode
 * @id         160
 * @title      Intersection of Two Linked Lists
 * @difficulty Easy
 * @topics     Hash Table, Linked List, Two Pointers
 * @pattern    Two-Pointer Length Equalization
 * @url        https://leetcode.com/problems/intersection-of-two-linked-lists/
 * @solved     2026-06-27
 *
 * ----------------------------------------------------------------------------
 * PROBLEM
 * ----------------------------------------------------------------------------
 * Two singly-linked lists MAY share a common tail. If they do, return the
 * first node where they merge; otherwise return NULL. "Intersection" means the
 * same node by identity (same address), not merely the same value. Once two
 * lists join, they share every node afterward (a Y-shape, never an X).
 *
 *   A: 4 -> 1 \
 *              8 -> 4 -> 5       <- intersection node is the '8'
 *   B: 5 -> 6 -> 1 /
 *
 *   Here lenA = 5, lenB = 6. Answer: the node holding 8.
 *   If the two lists never touch, the answer is NULL.
 *
 * ----------------------------------------------------------------------------
 * INTUITION
 * ----------------------------------------------------------------------------
 * The obstacle is that the two lists can differ in length, so the shared tail
 * doesn't start at the same "step count" from each head. The trick removes
 * that offset without measuring anything.
 *
 * Let the non-shared prefixes have lengths p and q, and the shared tail have
 * length c. Pointer `a` walks list A then list B; pointer `b` walks list B
 * then list A. Each pointer therefore traverses exactly (p + q + c) nodes
 * before falling off the end the second time. Because both cover the SAME
 * total distance, after the switch they become perfectly aligned relative to
 * the shared tail and land on the first common node at the same instant.
 *
 * WHY the NULL case also works: if there is no intersection (c = 0), both
 * pointers reach the end after p + q steps and are simultaneously NULL. NULL
 * == NULL, so the loop exits and returns NULL. This is the elegance of using
 * `headB` / `headA` as the redirect targets rather than skipping to ->next:
 * the terminal NULL is itself a value both pointers reach together.
 *
 * ----------------------------------------------------------------------------
 * WALKTHROUGH (this code)
 * ----------------------------------------------------------------------------
 *   ListNode *a = headA;  ListNode *b = headB;   // start at the two heads
 *   while (a != b) {                             // compare by IDENTITY, not val
 *       a = a ? a->next : headB;                 // at end of A, jump to head B
 *       b = b ? b->next : headA;                 // at end of B, jump to head A
 *   }
 *   return a;                                    // meeting point, or NULL
 *
 * Note the redirect fires when the pointer IS NULL (having just stepped off
 * the end), not one node early -- so each pointer visits the trailing NULL
 * exactly once. That single shared NULL visit is what makes the no-intersection
 * case terminate instead of looping forever.
 *
 * DRY RUN on the example above (A: 4 1 8 4 5 ; B: 5 6 1 8 4 5), '@'=shared '8':
 *
 *   a-node   b-node   equal?
 *   4        5        no
 *   1        6        no
 *   8@       1        no      (note: this '1' in B is a DISTINCT node from A's)
 *   4        8@       no
 *   5        4        no
 *   NULL     5        no      (a fell off A; b on B's last node)
 *   5(=B hd) NULL     no      (a jumped to headB; b fell off B)
 *   6        4(=A hd) no      (b jumped to headA)
 *   1        1        no      (again, two different '1' nodes)
 *   8@       8@       YES  ->  return the shared node 8
 *
 * Both pointers walked 9 edges before meeting -- exactly lenA + lenB - c
 * relative to the join. The value-collisions on '1' don't fool it because the
 * comparison is pointer equality.
 *
 * ----------------------------------------------------------------------------
 * COMPLEXITY
 * ----------------------------------------------------------------------------
 * Time : O(m + n) -- each pointer takes at most m + n steps (one full pass of
 *                    each list) before meeting or both reaching NULL.
 * Space: O(1)     -- two pointers, no hash set, no length precomputation.
 *
 * ----------------------------------------------------------------------------
 * EDGE CASES
 * ----------------------------------------------------------------------------
 * - No intersection: both pointers hit NULL together after m + n steps; the
 *   loop condition a != b becomes false (NULL == NULL) and NULL is returned.
 *   This is the case people fear loops forever -- it does not, precisely
 *   because the redirect targets are the HEADS, giving equal total path length.
 * - Either list empty (headA or headB is NULL): if say headA is NULL, `a`
 *   starts NULL; the answer must be NULL, and the two pointers converge on NULL
 *   within one combined pass. Correct.
 * - Equal-length lists: they align on the very first pass, no switch needed for
 *   the match itself.
 * - Lists intersect at the head (fully shared): a == b is true immediately and
 *   headA is returned without entering the loop body.
 *
 * ----------------------------------------------------------------------------
 * This is already optimal: O(m + n) time and O(1) space, which beats the
 * hash-set approach (O(m + n) time but O(m) space) and the length-difference
 * approach (same complexity but two extra passes and more bookkeeping). No
 * improvement section needed.
 * ============================================================================
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
