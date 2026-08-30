"""
LeetCode 118 - Pascal's Triangle [Easy]

@platform   LeetCode
@id         118
@title      Pascal's Triangle
@difficulty Easy
@topics     Array, Dynamic Programming
@pattern    Zero-Padded Row Convolution
@url        https://leetcode.com/problems/pascals-triangle/
@solved     2026-06-20

Problem
Given an integer numRows, return the first numRows of Pascal's Triangle.

Approach
Pad the previous row with a zero on both sides. Each value in the next row is the sum of
two adjacent values in that padded row.

Complexity
Time: O(numRows^2).
Space: O(numRows^2) for the output (unavoidable - it's the answer).

Notes
- numRows = 1 : res is seeded with [[1]], the loop body never runs, and [[1]] is
  returned.
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
