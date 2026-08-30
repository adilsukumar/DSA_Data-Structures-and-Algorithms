/*
 * Platform: CodeChef
 * Submission: 1310810656
 * Problem: SEATNUMBER
 * Verdict: compilation error
 * Date: 2026-07-19
 * URL: https://www.codechef.com/problems/SEATNUMBER
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes 
	int N, T;
	cin >> T;
	
	for(int i = 0; i < T; i++){
	    cin >> N;
	    if(N <= 10){
	        cout << "Lower Double" << cout;
	    }
	    else if(N >= 10 && N <= 15){
	        cout << "Lower Single" << cout;
	    }
	    else if(N >= 16 && N <= 25){
	        cout << "Upper Double" << cout;
	    }
	    else{
	        cout << "Upper Single" << cout;
	    }
	}
    return 0;
}
