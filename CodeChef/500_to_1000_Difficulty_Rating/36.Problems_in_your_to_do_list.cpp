/*
 * =============================================================================
 * CodeChef TODOLIST - Problems in your to-do list (Difficulty 580)
 * =============================================================================
 * @platform   CodeChef
 * @id         TODOLIST
 * @title      Problems in your to-do list
 * @difficulty 580
 * @topics     Arrays
 * @pattern    Count Matching Elements
 * @url        https://www.codechef.com/problems/TODOLIST
 * @solved     2026-06-23
 * -----------------------------------------------------------------------------
 * PROBLEM
 * Solve the stated task for each test case and print the required result.
 *
 * INTUITION
 * Only difficulties of at least 1000 belong on the to-do list, so count values meeting that threshold.
 *
 * WALKTHROUGH
 * Reset count for each test case, scan all N difficulties, increment for D >= 1000, and print the final count.
 *
 * WHY IT WORKS
 * The implementation follows the condition or formula above directly, so every possible input falls into exactly the required result case.
 *
 * COMPLEXITY
 * O(N) time and O(1) extra space per test case.
 *
 * EDGE CASES
 * Resetting count inside each test-case loop prevents results from leaking between cases.
 * =============================================================================
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, N, D, count;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> N;

	    count = 0;

	    for(int j = 0; j < N; j++){

	        cin >> D;

	        if(D >= 1000){

	            count += 1;

	        }

	    }

	    cout << count << endl;

	}

}
