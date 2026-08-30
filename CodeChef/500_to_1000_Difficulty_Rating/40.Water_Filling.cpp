/*
 * CodeChef WATERFILLING - Water Filling [541]
 *
 * @platform   CodeChef
 * @id         WATERFILLING
 * @title      Water Filling
 * @difficulty 541
 * @topics     admin, start92
 * @pattern    Count Empty Bottles
 * @url        https://www.codechef.com/problems/WATERFILLING
 * @solved     2026-06-10
 *
 * Approach
 * Water must be filled when at least two of the three bottles are empty (represented by
 * zero).
 *
 * Complexity
 * O(1) time and O(1) space per test case.
 *
 * Notes
 * - All three empty bottles also satisfy the first pair check, as required.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, B1, B2, B3;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> B1;

	    cin >> B2;

	    cin >> B3;

	    

	    if(B1 == 0 && B2 == 0){

	        cout << "Water filling time" << endl;

	    }

	    else if(B1 == 0 && B3 == 0){

	        cout << "Water filling time" << endl;

	    }

	    else if(B2 == 0 && B3 == 0){

	        cout << "Water filling time" << endl;

	    }

	    else{

	        cout << "Not now" << endl;

	    }

	}

	return 0;

}
