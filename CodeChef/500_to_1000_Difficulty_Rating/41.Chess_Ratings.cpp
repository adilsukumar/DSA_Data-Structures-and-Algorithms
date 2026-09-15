/*
 * CodeChef C_RATING - Chess Ratings [651]
 *
 * @platform   CodeChef
 * @id         C_RATING
 * @title      Chess Ratings
 * @difficulty 651
 * @topics     Mathematics
 * @pattern    Mathematical Formula
 * @url        https://www.codechef.com/problems/C_RATING
 * @solved     2026-08-31
 *
 * Problem
 * Accepted solution for Chess Ratings.
 *
 * Approach
 * The solution calculates the difference Y - X to determine the rating gap. It
 * then computes the number of units of size 8 needed to cover this gap. The
 * expression (remaining + 7) / 8 effectively performs a ceiling division, rounding
 * up to the nearest integer when remaining is not a multiple of 8.
 *
 * Complexity
 * Time: O(T) Space: O(1)
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
