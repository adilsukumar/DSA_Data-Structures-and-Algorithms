/*
 * CodeChef DISCUS - Discus Throw [622]
 *
 * @platform   CodeChef
 * @id         DISCUS
 * @title      Discus Throw
 * @difficulty 622
 * @topics     Conditional Statements, Basic Programming, Implementation
 * @pattern    Max of Three via If/Else
 * @url        https://www.codechef.com/problems/DISCUS
 * @solved     2026-07-19
 *
 * Problem
 * A discus thrower gets three attempts with distances A, B, and C.
 *
 * Approach
 * "Best of three" is just "maximum of three numbers." A value is the answer exactly when
 * it is >= both of the other two. The code checks each candidate in turn: if A is >= B and
 * >= C, A is a maximum; else if B is >= A and >= C, B is a maximum; otherwise C must be
 * the maximum (nothing else was >= everything).
 *
 * Complexity
 * Time: O(T) - a fixed 2-4 comparisons per test case, T cases total.
 * Space: O(1) - four ints reused across all iterations; no arrays.
 *
 * Notes
 * - All three equal (5 5 5): first branch 5>=5 && 5>=5 is true -> prints 5.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, A, B, C;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> A >> B >> C;

	    if(A >= B && A >= C){

	        cout << A << endl;

	    }

	    else if(B >= A && B >= C){

	        cout << B << endl;

	    }

	    else{

	        cout << C << endl;

	    }

	}

	return 0;

}
