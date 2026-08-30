/*
 * CodeChef NEARESTEXIT - Nearest Exit [585]
 *
 * @platform   CodeChef
 * @id         NEARESTEXIT
 * @title      Nearest Exit
 * @difficulty 585
 * @topics     Basic Programming, Implementation, Conditionals
 * @pattern    Midpoint Threshold Comparison
 * @url        https://www.codechef.com/problems/NEARESTEXIT
 * @solved     2026-06-24
 *
 * Problem
 * You are standing at some position X inside a corridor with 100 cells, numbered 1..100.
 *
 * Approach
 * With 100 cells and exits at both ends, the deciding factor is which side of the middle
 * you fall on. The middle lies between 50 and 51, so a single comparison against the
 * constant 50 fully classifies the position -- no distance arithmetic is needed.
 *
 * Complexity
 * Time: O(T) -- one read plus one comparison per query, no inner work.
 * Space: O(1) -- two scalars reused across all iterations; nothing stored.
 *
 * Notes
 * - Boundary value X = 50: handled by "<=", classified as LEFT.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

    int T, X;

    cin >> T;

    

    for(int i = 0; i < T; i++){

        cin >> X;

        if(X <= 50){

            cout << "LEFT" << endl;

        }

        else{

            cout << "RIGHT" << endl;

        }

    }

    return 0;

}
