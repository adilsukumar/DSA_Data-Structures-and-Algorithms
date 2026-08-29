/*
 * =============================================================================
 * CodeChef RIGHTTHERE - Right There (Difficulty 299)
 * =============================================================================
 * @platform   CodeChef
 * @id         RIGHTTHERE
 * @title      Right There
 * @difficulty 299
 * @topics     Conditional Statements
 * @pattern    Threshold Comparison
 * @url        https://www.codechef.com/problems/RIGHTTHERE
 * @solved     2026-06-10
 * -----------------------------------------------------------------------------
 * PROBLEM
 * Solve the stated task for each test case and print the required result.
 *
 * INTUITION
 * The answer is YES exactly when the available reach X is at least the required position N.
 *
 * WALKTHROUGH
 * Read N and X, test N <= X, and print YES for a reachable position; otherwise print NO.
 *
 * WHY IT WORKS
 * The implementation follows the condition or formula above directly, so every possible input falls into exactly the required result case.
 *
 * COMPLEXITY
 * O(1) time and O(1) space per test case.
 *
 * EDGE CASES
 * Equality is important: when N == X, the target is still reachable.
 * =============================================================================
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, N, X;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> N;

	    cin >> X;

	    if(N <= X){

	        cout << "YES" << endl;

	    }

	    else{

	        cout << "NO" << endl;

	    }

	}

    return 0;

}
