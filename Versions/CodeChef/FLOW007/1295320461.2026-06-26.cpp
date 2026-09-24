/*
 * Platform: CodeChef
 * Submission: 1295320461
 * Problem: FLOW007
 * Verdict: Accepted
 * Submitted: 2026-06-26
 * Recorded in repository: 2026-09-24
 * URL: https://www.codechef.com/problems/FLOW007
 *  */

#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        
        int ans = 0;

        while (N > 0) {
            int r = N % 10;
            N = N / 10;
            ans = ans * 10 + r;
        }

        cout << ans << endl;
    }

    return 0;
}