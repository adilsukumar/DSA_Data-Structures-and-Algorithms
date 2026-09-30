/*
 * Platform: CodeChef
 * Submission: 1366678885
 * Problem: FSQRT
 * Verdict: Accepted
 * Submitted: 2026-09-30
 * Recorded in repository: 2026-09-30
 * URL: https://www.codechef.com/problems/FSQRT
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int T, N;
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> N;
        cout << round(sqrt(N)) << endl;
    }
    return 0;
}
