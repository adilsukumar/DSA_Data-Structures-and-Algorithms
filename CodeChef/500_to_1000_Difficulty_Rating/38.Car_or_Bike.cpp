/*
 * CodeChef TRAVELFAST - Car or Bike [571]
 *
 * @platform   CodeChef
 * @id         TRAVELFAST
 * @title      Car or Bike
 * @difficulty 571
 * @topics     Basic Math
 * @pattern    Compare Travel Times
 * @url        https://www.codechef.com/problems/TRAVELFAST
 * @solved     2026-06-18
 *
 * Approach
 * Choose the vehicle with the smaller travel time; equal times mean either is equivalent.
 *
 * Complexity
 * O(1) time and O(1) space per test case.
 *
 * Notes
 * - Keep the equality branch separate so ties are not assigned to either vehicle.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T,X,Y;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> X >> Y;

	    if(X>Y){

	        cout << "CAR" << endl;

	    }

	    else if(Y>X){

	        cout << "BIKE" << endl;

	    }

	    else{

	        cout << "SAME" << endl;

	    }

	}

	return 0;

}
