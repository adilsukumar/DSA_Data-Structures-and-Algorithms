/*
 * CodeChef RIGHTTHERE - Right There [299]
 *
 * @platform   CodeChef
 * @id         RIGHTTHERE
 * @title      Right There
 * @difficulty 299
 * @topics     Conditional Statements
 * @pattern    Threshold Comparison
 * @url        https://www.codechef.com/problems/RIGHTTHERE
 * @solved     2026-06-10
 *
 * Approach
 * The answer is YES exactly when the available reach X is at least the required position
 * N.
 *
 * Complexity
 * O(1) time and O(1) space per test case.
 *
 * Notes
 * - Equality is important: when N == X, the target is still reachable.
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
