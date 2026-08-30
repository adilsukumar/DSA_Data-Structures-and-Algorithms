/*
 * Platform: CodeChef
 * Submission: 1286588737
 * Problem: BTRYHLTH
 * Verdict: wrong answer
 * Date: 2026-06-07
 * URL: https://www.codechef.com/problems/BTRYHLTH
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int T, X;
    cin >> T;
    
    for (int i = 0; i < T; i++){
        if(X >= 80){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
