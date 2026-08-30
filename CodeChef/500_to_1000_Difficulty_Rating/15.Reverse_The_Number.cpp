/*
 * CodeChef FLOW007 - Reverse The Number [588]
 *
 * @platform   CodeChef
 * @id         FLOW007
 * @title      Reverse The Number
 * @difficulty 588
 * @topics     Modular Arithmetic, Division, Implementation, Basic Programming
 * @pattern    Digit-by-digit reversal via mod/div
 * @url        https://www.codechef.com/problems/FLOW007
 * @solved     2026-06-26
 *
 * Problem
 * Given T test cases, each a positive integer N, print N with its digits reversed.
 *
 * Approach
 * A number in base 10 is a stack of digits. The units digit is the cheapest to reach: N %
 * 10 peels it off, N / 10 discards it.
 *
 * Complexity
 * Time: O(d) per test case, where d = number of digits in N (d = log10 N).
 * Space: O(1).
 *
 * Notes
 * - Trailing zeros disappear naturally: reversing 120 produces 21.
 * - Use long long if the reversed value can exceed int.
 */

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
