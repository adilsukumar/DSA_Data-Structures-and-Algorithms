/*
 * CodeChef MOVIE2X - Watching Movies At 2x [628]
 *
 * @platform   CodeChef
 * @id         MOVIE2X
 * @title      Watching Movies At 2x
 * @difficulty 628
 * @topics     Math, Implementation
 * @pattern    Constant-time arithmetic formula
 * @url        https://www.codechef.com/problems/MOVIE2X
 * @solved     2026-07-19
 *
 * Problem
 * A movie is X minutes long.
 *
 * Approach
 * "Speed" scales content-per-minute, so real time = content / speed. The (X - Y) minutes
 * at 1x cost (X - Y) real minutes (speed 1).
 *
 * Complexity
 * Time: O(1) -- two reads and a fixed arithmetic expression, no loops.
 * Space: O(1) -- two int variables, no auxiliary structures.
 *
 * Notes
 * - Y = 0 : nothing sped up, answer = X.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int X, Y;

	cin >> X >> Y;

	cout << (X-Y) + (Y/2);

    return 0;

}
