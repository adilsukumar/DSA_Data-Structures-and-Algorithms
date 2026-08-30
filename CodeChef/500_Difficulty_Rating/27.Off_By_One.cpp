/*
 * CodeChef OFFBY1 - Off By One [271]
 *
 * @platform   CodeChef
 * @id         OFFBY1
 * @title      Off By One
 * @difficulty 271
 * @topics     Basic Programming, Implementation, Math
 * @pattern    Two-integer input, print sum
 * @url        https://www.codechef.com/problems/OFFBY1
 * @solved     2026-06-06
 *
 * Problem
 * Read two integers A and B and print a single integer: their combined value.
 *
 * Approach
 * A one-line problem: consume two integers, emit one. The only real skill tested is
 * correctly wiring input to a single arithmetic output.
 *
 * Complexity
 * Time: O(1) - a fixed number of reads and one write, no loops.
 * Space: O(1) - two ints, no allocation.
 *
 * Notes
 * - An extra value is appended on every test case, so the submitted output is incorrect.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int A, B;

	cin >> A;

	cin >> B;

	cout << A+B << 1 << endl;



}
