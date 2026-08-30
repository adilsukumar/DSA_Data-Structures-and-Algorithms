/*
 * CodeChef MINCARS - Minimum Cars Required [608]
 *
 * @platform   CodeChef
 * @id         MINCARS
 * @title      Minimum Cars Required
 * @difficulty 608
 * @topics     Math, Implementation
 * @pattern    Ceiling Division (group into 4s)
 * @url        https://www.codechef.com/problems/MINCARS
 * @solved     2026-06-30
 *
 * Problem
 * There are N people who all need to travel.
 *
 * Approach
 * This is the classic "how many buckets do I need" question. With a fixed capacity of 4
 * per car, the answer is N divided by 4, rounded UP -- because any leftover people (a
 * remainder of 1..3) still require one more, only partially-filled, car.
 *
 * Complexity
 * Time: O(T) -- constant work per test case, one arithmetic op each.
 * Space: O(1) -- only a few scalars; nothing scales with N or T.
 *
 * Notes
 * - N a multiple of 4 (4, 8, 12, ...): ceil returns the exact quotient, no phantom extra
 *   car.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, N;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> N;

	    if(N <= 4){

	        cout << 1 << endl;

	    }

	    else{

	        cout << ceil(N/4.0) << endl;

	    }

	}



}
