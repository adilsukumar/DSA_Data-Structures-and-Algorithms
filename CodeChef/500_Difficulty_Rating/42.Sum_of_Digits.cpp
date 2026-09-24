/*
 * CodeChef FLOW006 - Sum of Digits [455]
 *
 * @platform   CodeChef
 * @id         FLOW006
 * @title      Sum of Digits
 * @difficulty 455
 * @topics     Basic Math, Implementation
 * @pattern    Arithmetic Iteration
 * @url        https://www.codechef.com/problems/FLOW006
 * @solved     2026-09-24
 *
 * Problem
 * Accepted solution for Sum of Digits.
 *
 * Approach
 * The program converts the integer to a string representation to easily access
 * each digit. It then iterates through the string, converting each character back
 * to an integer and adding it to a running sum. Finally, it outputs the computed
 * sum for each test case.
 *
 * Complexity
 * Time: O(D) Space: O(D)
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, N;

	cin >> T;

	for(int i = 0; i < T; i++){

	    cin >> N;

	    int sum = 0;

	    string s = to_string(N);

	    for(int j = 0; j < s.size(); j++){

	        sum += s[j]-'0'; 

	    }

	    cout << sum << "\n";

	}

	return 0;



}
