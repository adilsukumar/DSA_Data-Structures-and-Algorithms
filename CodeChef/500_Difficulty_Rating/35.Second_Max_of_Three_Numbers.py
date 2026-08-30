"""
CodeChef SNDMAX - Second Max of Three Numbers [300]

@platform   CodeChef
@id         SNDMAX
@title      Second Max of Three Numbers
@difficulty 300
@topics     arjunarul_adm, largesecond, sorting
@pattern    Sort Three Values
@url        https://www.codechef.com/problems/SNDMAX
@solved     2026-06-10

Approach
After sorting three values, the second element is necessarily the second largest.

Complexity
O(1) time and O(1) auxiliary space because exactly three values are sorted.

Notes
- Duplicates are handled naturally; the middle sorted value is still the required
  answer.
"""

# cook your dish here

N = int(input())

for i in range(N):

    a, b, c = map(int, input().split())

    d = [a,b,c]

    d.sort()

    print(d[1])
