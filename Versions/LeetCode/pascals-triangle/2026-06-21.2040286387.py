"""
Platform: LeetCode
Submission: 2040286387
Problem: Pascal's Triangle
Verdict: Accepted
Submitted: 2026-06-21
Recorded in repository: 2026-09-24
URL: https://leetcode.com/problems/pascals-triangle/
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