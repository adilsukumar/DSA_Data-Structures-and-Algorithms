/*
 * CodeChef TODOLIST - Problems in your to-do list [580]
 *
 * @platform   CodeChef
 * @id         TODOLIST
 * @title      Problems in your to-do list
 * @difficulty 580
 * @topics     Arrays
 * @pattern    Count Matching Elements
 * @url        https://www.codechef.com/problems/TODOLIST
 * @solved     2026-06-23
 *
 * Approach
 * Only difficulties of at least 1000 belong on the to-do list, so count values meeting
 * that threshold.
 *
 * Complexity
 * O(N) time and O(1) extra space per test case.
 *
 * Notes
 * - Resetting count inside each test-case loop prevents results from leaking between
 *   cases.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, N, D, count;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> N;

	    count = 0;

	    for(int j = 0; j < N; j++){

	        cin >> D;

	        if(D >= 1000){

	            count += 1;

	        }

	    }

	    cout << count << endl;

	}

}
