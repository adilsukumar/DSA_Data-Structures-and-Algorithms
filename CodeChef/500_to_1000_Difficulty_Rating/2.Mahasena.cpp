/*
 * CodeChef AMR15A - Mahasena [533]
 *
 * @platform   CodeChef
 * @id         AMR15A
 * @title      Mahasena
 * @difficulty 533
 * @topics     Conditional Statements, Basic Math, Implementation
 * @pattern    Parity of Sum via Odd Count (BUGGY here)
 * @url        https://www.codechef.com/problems/AMR15A
 * @solved     2026-06-09
 *
 * Problem
 * An army has N weapons, each with an integer power A[i].
 *
 * Approach
 * You never need the actual sum, only its parity. Adding an even number never flips
 * parity; adding an odd number always flips it.
 *
 * Complexity
 * Time: O(N) - single pass reading and classifying each of the N values.
 * Space: O(1) - only two counters and scalars are kept, regardless of N.
 *
 * Notes
 * - Negative powers: C++ % can yield a negative remainder for negatives, but the != 0 vs
 *   == 0 split still classifies parity correctly, so tallying is safe.
 * - Only the parity of the odd count is needed; the even count can be removed.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int N, X;

	int even_no = 0;

	int odd_no = 0;

	cin >> N;

	for(int i = 0; i < N; i++){

	    cin >> X;

	    if(X%2 == 0){

	        even_no++;

	    }

	    else{

	        odd_no++;

	    }

	}

	if(even_no > odd_no){

	    cout << "READY FOR BATTLE";

	}

	else{

	    cout << "NOT READY";

	}

	return 0;

}
