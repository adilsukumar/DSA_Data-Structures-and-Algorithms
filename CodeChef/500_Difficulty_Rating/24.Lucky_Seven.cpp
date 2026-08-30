/*
 * CodeChef LUCKYSEVEN - Lucky Seven [213]
 *
 * @platform   CodeChef
 * @id         LUCKYSEVEN
 * @title      Lucky Seven
 * @difficulty 213
 * @topics     Basic Programming, Strings, Implementation
 * @pattern    Direct String Indexing (0-based)
 * @url        https://www.codechef.com/problems/LUCKYSEVEN
 * @solved     2026-06-04
 *
 * Problem
 * You are given a single string S.
 *
 * Approach
 * "The 7th character" is a fixed position, not something you have to search for. In C++ a
 * std::string is a 0-indexed array of chars, so the k-th character (1-based) lives at
 * index k-1.
 *
 * Complexity
 * Time: O(n) to read the string of length n (the indexed access itself is O(1)); the
 * "work" after reading is a single constant-time lookup.
 * Space: O(n) to store S.
 *
 * Notes
 * - String shorter than 7 chars: S[6] would be out-of-bounds (undefined behavior —
 *   operator[] does NOT bounds-check).
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	string S;

	cin >> S;

	cout << S[6];

	return 0;



}
