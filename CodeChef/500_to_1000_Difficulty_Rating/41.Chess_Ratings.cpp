/*
 * CodeChef C_RATING - Chess Ratings [651]
 *
 * @platform   CodeChef
 * @id         C_RATING
 * @title      Chess Ratings
 * @difficulty 651
 * @topics     Mathematics
 * @pattern    Pending manual review
 * @url        https://www.codechef.com/problems/C_RATING
 * @solved     2026-08-31
 *
 * Problem
 * Accepted solution for Chess Ratings.
 *
 * Approach
 * Pending manual review. The submitted code is preserved exactly below.
 *
 * Complexity
 * Pending manual review.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

    int T, X, Y;

    cin >> T;



    for(int i = 0; i < T; i++) {

        cin >> X >> Y;



        int remaining = Y - X;



        cout << (remaining + 7) / 8 << endl;

    }



    return 0;

}
