/*
 * CodeChef CLEARDAY - Clear Day [233]
 *
 * @platform   CodeChef
 * @id         CLEARDAY
 * @title      Clear Day
 * @difficulty 233
 * @topics     Math, Implementation, Basic Programming
 * @pattern    Constant-time arithmetic (7 - X - Y)
 * @url        https://www.codechef.com/problems/CLEARDAY
 * @solved     2026-06-05
 *
 * Problem
 * A week has exactly 7 days.
 *
 * Approach
 * The week is partitioned into three disjoint buckets: rainy, snowy, clear. Because they
 * are disjoint and together cover all 7 days, the three counts must sum to 7: X + Y +
 * clear = 7.
 *
 * Complexity
 * Time: O(1) — a fixed number of reads and one arithmetic expression, independent of the
 * input values.
 * Space: O(1) — two int variables, no containers.
 *
 * Notes
 * - X = 0, Y = 0 -> 7 - 0 - 0 = 7 (whole week clear).
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int X, Y;

	cin >> X;

	cin >> Y;

	cout << 7 - X - Y;



}
