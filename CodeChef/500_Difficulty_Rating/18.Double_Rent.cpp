/*
 * CodeChef DOUBLERENT - Double Rent [234]
 *
 * @platform   CodeChef
 * @id         DOUBLERENT
 * @title      Double Rent
 * @difficulty 234
 * @topics     Math, Implementation
 * @pattern    O(1) Arithmetic (multiply by 2)
 * @url        https://www.codechef.com/problems/DOUBLERENT
 * @solved     2026-06-05
 *
 * Problem
 * Read a single integer X (the base rent) and report the "double rent" for it -- i.e.
 *
 * Approach
 * "Double" is the whole task, so the answer is literally 2 * X. The only thing worth
 * thinking about is representation: doubling is exact in integer arithmetic (no rounding,
 * no fractions), so a single multiply is both correct and optimal.
 *
 * Complexity
 * Time: O(1) -- one read, one multiply, one write; independent of X.
 * Space: O(1) -- a single int variable; no containers allocated.
 *
 * Notes
 * - Large X: the result is stored in an int.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int X;

	cin >> X;

	cout << X*2;



}
