/*
 * Platform: CodeChef
 * Submission: 1358171834
 * Problem: SUMM
 * Verdict: Accepted
 * Submitted: 2026-09-16
 * Recorded in repository: 2026-09-24
 * URL: https://www.codechef.com/problems/SUMM
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int T, A, B, C;
    cin >> T;
    
    for(int i = 0; i < T; i++){
        cin >> A >> B >> C;
        if(C == A+B){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}
