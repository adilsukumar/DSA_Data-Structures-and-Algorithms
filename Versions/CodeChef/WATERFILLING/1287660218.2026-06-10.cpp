/*
 * Platform: CodeChef
 * Submission: 1287660218
 * Problem: WATERFILLING
 * Verdict: Accepted
 * Submitted: 2026-06-10
 * Recorded in repository: 2026-09-24
 * URL: https://www.codechef.com/problems/WATERFILLING
 *  */

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
