"""
=============================================================================
CodeChef SNDMAX - Second Max of Three Numbers (Difficulty 300)
=============================================================================
@platform   CodeChef
@id         SNDMAX
@title      Second Max of Three Numbers
@difficulty 300
@topics     arjunarul_adm, largesecond, sorting
@pattern    Sort Three Values
@url        https://www.codechef.com/problems/SNDMAX
@solved     2026-06-10
-----------------------------------------------------------------------------
PROBLEM
Solve the stated task for each test case and print the required result.

INTUITION
After sorting three values, the second element is necessarily the second largest.

WALKTHROUGH
Put a, b, and c in a list, sort ascending, and print index 1.

WHY IT WORKS
The implementation follows the condition or formula above directly, so every possible input falls into exactly the required result case.

COMPLEXITY
O(1) time and O(1) auxiliary space because exactly three values are sorted.

EDGE CASES
Duplicates are handled naturally; the middle sorted value is still the required answer.
=============================================================================
"""

# cook your dish here

N = int(input())

for i in range(N):

    a, b, c = map(int, input().split())

    d = [a,b,c]

    d.sort()

    print(d[1])
