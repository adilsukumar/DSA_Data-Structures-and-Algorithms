/*
 * Platform: CodeChef
 * Submission: 1366678100
 * Problem: FSQRT
 * Verdict: compilation error
 * Date: 2026-09-30
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
        cout << round(N ** 1/2) << endl;
    }
    return 0;
}
