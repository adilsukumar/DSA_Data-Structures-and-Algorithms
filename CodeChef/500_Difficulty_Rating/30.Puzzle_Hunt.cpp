/*
 * CodeChef PUZHUNT - Puzzle Hunt [279]
 *
 * @platform   CodeChef
 * @id         PUZHUNT
 * @title      Puzzle Hunt
 * @difficulty 279
 * @topics     Conditional Statements, Implementation
 * @pattern    Range Check with if/else
 * @url        https://www.codechef.com/problems/PUZHUNT
 * @solved     2026-06-07
 *
 * Problem
 * You are given a single integer N (a count of participants, hours, or similar, depending
 * on the story).
 *
 * Approach
 * The entire task is a membership test on a closed interval. A value is inside [6, 8]
 * exactly when it is simultaneously >= 6 AND <= 8.
 *
 * Complexity
 * Time: O(1) -- one read and at most two integer comparisons, no loops.
 * Space: O(1) -- a single int; no allocation that scales with input.
 *
 * Notes
 * - Boundaries 6 and 8: both are included because the comparisons are `>=` and `<=`
 *   (inclusive), not strict `>`/`<`.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int N;

	cin >> N;

	if(N >= 6 && N <= 8){

	    cout << "Yes";

	}

	else{

	    cout << "No";

	}



}
