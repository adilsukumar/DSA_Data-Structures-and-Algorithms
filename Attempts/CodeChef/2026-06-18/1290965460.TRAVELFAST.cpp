/*
 * Platform: CodeChef
 * Submission: 1290965460
 * Problem: TRAVELFAST
 * Verdict: wrong answer
 * Date: 2026-06-18
 * URL: https://www.codechef.com/problems/TRAVELFAST
 *  */

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
	    else{
	        cout << "BIKE" << endl;
	    }
	}
	return 0;
}
