/*
 * CodeChef LUDO - Chef Plays Ludo [260]
 *
 * @platform   CodeChef
 * @id         LUDO
 * @title      Chef Plays Ludo
 * @difficulty 260
 * @topics     Basic Programming, Conditionals, Implementation
 * @pattern    Single Equality Check
 * @url        https://www.codechef.com/problems/LUDO
 * @solved     2026-06-05
 *
 * Problem
 * In Ludo a token sits locked in its "yard" until the player rolls a 6 on the die; only a
 * 6 unlocks a token and lets play begin.
 *
 * Approach
 * The entire rule collapses to one boolean fact: "did the die show 6?". Every roll from
 * 1..5 is equivalent (all fail), and 6 is the only success.
 *
 * Complexity
 * Time: O(T) -- one comparison and one print per test case, no inner work.
 * Space: O(1) -- only two ints are held regardless of T; nothing is stored.
 *
 * Notes
 * - X in 1..5: all correctly map to "NO" (only 6 is special).
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X;

	cin >> T;

	for(int i = 0; i < T; i++){

	    cin >> X;

	    if(X == 6){

	        cout << "YES" << endl;

	    }

	    else{

	        cout << "NO" << endl;

	    }

	}



}
