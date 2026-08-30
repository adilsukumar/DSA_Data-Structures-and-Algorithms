/*
 * Platform: CodeChef
 * Submission: 1319712395
 * Problem: BULLET
 * Verdict: wrong answer
 * Date: 2026-07-27
 * URL: https://www.codechef.com/problems/BULLET
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int T, X, Y, Z;
    cin >> T;
    
    for(int i = 0; i < T; i++){
        cin >> X >> Y >> Z;
        int seconds = Y/X;
        cout << Z - seconds << endl;
    }
    return 0;
}
