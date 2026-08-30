/*
 * CodeChef 1 - Cricket World Cup Qualifier [500]
 *
 * @platform   CodeChef
 * @id         1
 * @title      Cricket World Cup Qualifier
 * @difficulty 500
 * @topics     Implementation, Conditionals, Basic I/O
 * @pattern    Single Threshold Comparison
 * @url        https://www.codechef.com/practice
 *
 * Problem
 * A team qualifies for the World Cup if it finishes the league stage with at least 12
 * points.
 *
 * Approach
 * There is no algorithm here; the whole problem is translating one English sentence into
 * one comparison. The only thing that can go wrong is the boundary: "at least 12" means >=
 * 12, not > 12.
 *
 * Complexity
 * Time: O(1)
 * Space: O(1)
 *
 * Notes
 * - X exactly 12 -> YES.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	int X;
	cin >> X;
	if(X >= 12){
	    cout << "YES";
	}
	else{
	    cout << "NO";
	}
	
}
