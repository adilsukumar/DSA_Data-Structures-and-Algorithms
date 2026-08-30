/*
 * CodeChef BNE_APT - Bone Appetit [280]
 *
 * @platform   CodeChef
 * @id         BNE_APT
 * @title      Bone Appetit
 * @difficulty 280
 * @topics     Math, Implementation
 * @pattern    Weighted Sum (two-item linear combination)
 * @url        https://www.codechef.com/problems/BNE_APT
 * @solved     2026-06-07
 *
 * Problem
 * There are two kinds of items.
 *
 * Approach
 * No search, no data structure — just distributivity. The contribution of a group of
 * identical items is (count * per-unit value), and disjoint groups simply add.
 *
 * Complexity
 * Time: O(1) -- a fixed number of reads and two multiplications.
 * Space: O(1) -- four scalars, no allocation.
 *
 * Notes
 * - Leading blank line (the stray `cout << endl;`): output becomes "\n<ans>" instead of
 *   "<ans>".
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int N, M, X, Y;

	cin >> N;

	cin >> M;

	cout << endl;

	cin >> X;

	cin >> Y;

	

	cout << (N*X) + (M*Y);

	return 0;



}
