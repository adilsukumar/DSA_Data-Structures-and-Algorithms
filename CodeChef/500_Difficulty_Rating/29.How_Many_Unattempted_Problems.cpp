/*
 * CodeChef PRACLIST - How Many Unattempted Problems [264]
 *
 * @platform   CodeChef
 * @id         PRACLIST
 * @title      How Many Unattempted Problems
 * @difficulty 264
 * @topics     Basic Programming, Implementation, Math
 * @pattern    Single Subtraction
 * @url        https://www.codechef.com/problems/PRACLIST
 * @solved     2026-06-05
 *
 * Problem
 * A practice list contains X problems in total.
 *
 * Approach
 * Every problem is in exactly one of two buckets: attempted or not. The two buckets
 * partition the whole list, so |unattempted| = |total| - |attempted|.
 *
 * Complexity
 * Time: O(1) -- a fixed amount of I/O and one arithmetic operation, no loops.
 * Space: O(1) -- just the two integers X and Y.
 *
 * Notes
 * - Y == X (attempted everything): prints 0.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int X, Y;

	cin >> X;

	cin >> Y;

	cout << X-Y;

	return 0;



}
