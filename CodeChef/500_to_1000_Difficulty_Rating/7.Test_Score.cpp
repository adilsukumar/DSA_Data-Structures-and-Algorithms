/*
 * CodeChef CHEFSCORE - Test Score [610]
 *
 * @platform   CodeChef
 * @id         CHEFSCORE
 * @title      Test Score
 * @difficulty 610
 * @topics     Math, Basic Programming
 * @pattern    Divisibility + Range Check
 * @url        https://www.codechef.com/problems/CHEFSCORE
 * @solved     2026-06-30
 *
 * Problem
 * Chef sits N tests.
 *
 * Approach
 * If each test contributes either 0 or X, then after k aced tests (0 <= k <= N) the total
 * is exactly k*X. So the set of ALL reachable totals is: { 0, X, 2X, 3X, ..., N*X } A
 * target Y is reachable iff it lands on one of those points.
 *
 * Complexity
 * Time: O(T) overall - a fixed handful of arithmetic ops per test case.
 * Space: O(1) - four scalar ints reused across every iteration; nothing stored.
 *
 * Notes
 * - Y = 0: 0 % X == 0 and N*X >= 0, so YES (ace zero tests).
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, N, X, Y;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> N >> X >> Y;

	    if(N*X >= Y && Y%X == 0){

	        cout << "YES" << endl;

	    }

	    else{

	        cout << "NO" << endl;

	    }

	    

	}



}
