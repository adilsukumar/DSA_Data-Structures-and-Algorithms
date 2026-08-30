/*
 * Platform: CodeChef
 * Submission: 1289327986
 * Problem: CHEFGAMES
 * Verdict: wrong answer
 * Date: 2026-06-14
 * URL: https://www.codechef.com/problems/CHEFGAMES
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, R1, R2, R3, R4;
	cin >> T;
	
	for(int i = 0; i < T; i++){
	    cin >> R1;
	    cin >> R2;
	    cin >> R3;
	    cin >> R4;
	    
	    if(R1 == R2 == R3 == R4 == 0){
	        cout << "IN" << endl;
	    }
	    else{
	        cout << "OUT" << endl;
	    }
	}
    return 0;
}
