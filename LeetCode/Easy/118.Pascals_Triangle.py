"""
==============================================================================
LeetCode 118 - Pascal's Triangle                                         Easy
==============================================================================
@platform   LeetCode
@id         118
@title      Pascal's Triangle
@difficulty Easy
@topics     Array, Dynamic Programming
@pattern    Zero-Padded Row Convolution
@url        https://leetcode.com/problems/pascals-triangle/
@solved     2026-06-20

PROBLEM
    Given an integer numRows, return the first numRows of Pascal's Triangle.
    Row 0 is [1]. Every other entry is the sum of the two entries directly
    above it; the two outer edges are always 1.

        numRows = 5  ->  [ [1],
                           [1, 1],
                           [1, 2, 1],
                           [1, 3, 3, 1],
                           [1, 4, 6, 4, 1] ]

INTUITION
    Each row is built entirely from the row above it. If you imagine the
    previous row flanked by an invisible 0 on each side, then every new
    entry is just the sum of two neighbours in that padded row:

        prev            = [1, 2, 1]
        padded (dummy)  = [0, 1, 2, 1, 0]
                             \_+_/\_+_/\_+_/\_+_/
        new row         = [ 1,   3,   3,   1 ]

    Why the padding trick works: the first and last entries of the new row
    should be 1. Padding with 0 makes them "0 + edge" automatically, so the
    edges need no special-case handling - the same sum formula covers the
    whole row, including its two ends. This turns row generation into a
    simple sliding sum-of-pairs (a length-2 convolution).

WALKTHROUGH
    res = [[1]]
        Seed the result with row 0. This is why the loop runs numRows - 1
        times rather than numRows - the first row is already present.

    for _ in range(numRows - 1):
        Produce one new row per iteration, appending to res.

        dummy_row = [0] + res[-1] + [0]
            Take the most recent row (res[-1]) and pad both sides with 0.
            A row of length k becomes a padded row of length k + 2.

        row = []
        for i in range(len(res[-1]) + 1):
            The new row has exactly len(prev) + 1 entries. Each is the sum
            of the pair (dummy_row[i], dummy_row[i+1]) - adjacent cells in
            the padded row. i ranges over every such adjacent pair.
            row.append(dummy_row[i] + dummy_row[i+1])

        res.append(row)

    return res

    DRY RUN (numRows = 5)
        start:        res = [[1]]
        iter 1: prev=[1]        dummy=[0,1,0]        row=[1,1]
        iter 2: prev=[1,1]      dummy=[0,1,1,0]      row=[1,2,1]
        iter 3: prev=[1,2,1]    dummy=[0,1,2,1,0]    row=[1,3,3,1]
        iter 4: prev=[1,3,3,1]  dummy=[0,1,3,3,1,0]  row=[1,4,6,4,1]
        result: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

COMPLEXITY
    Time  : O(numRows^2). Row r costs O(r) work, and summed over all rows
            that is 1 + 2 + ... + numRows = O(numRows^2). This is optimal -
            the triangle itself contains O(numRows^2) numbers, so no
            algorithm can produce it in less time.
    Space : O(numRows^2) for the output (unavoidable - it's the answer).
            Extra working space per row (dummy_row) is O(numRows) and is
            discarded each iteration, so auxiliary space is only O(numRows).

EDGE CASES
    numRows = 1 : res is seeded with [[1]], the loop body never runs, and
                  [[1]] is returned. Correct.
    numRows = 0 : LeetCode guarantees numRows >= 1, so this is out of the
                  stated input range. If it were passed, the seed [[1]]
                  would still be returned - i.e. the code would wrongly emit
                  one row instead of an empty list. Harmless here only
                  because the constraints forbid it; worth noting for reuse.
    The padding removes any need to special-case the first/last element,
    so there are no off-by-one risks at the row edges.

NOTE
    This solution is already time-optimal for the problem. The only thing a
    "cleaner" variant changes is style, not complexity - e.g. building each
    row in place with row[j] = prev[j-1] + prev[j] and hard-coded 1s at the
    ends avoids allocating dummy_row, but the padding version here is
    arguably easier to reason about and reads without edge special-cases.
"""

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        res = [[1]]

        for _ in range(numRows - 1):
            dummy_row = [0] + res[-1] + [0]
            row = []

            for i in range(len(res[-1]) + 1):
                row.append(dummy_row[i] + dummy_row[i+1])
            res.append(row)
        
        return res
