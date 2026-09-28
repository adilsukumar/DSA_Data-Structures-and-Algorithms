/*
 * CodeChef EZSPEAK - Easy Pronunciation [1000]
 *
 * @platform   CodeChef
 * @id         EZSPEAK
 * @title      Easy Pronunciation
 * @difficulty 1000
 * @topics     String, Loops
 * @pattern    Linear Scan
 * @url        https://www.codechef.com/problems/EZSPEAK
 * @solved     2026-09-29
 *
 * Problem
 * Accepted solution for Easy Pronunciation.
 *
 * Approach
 * Iterate through the string to count consecutive consonants. Reset the count upon
 * encountering a vowel. If the count of consecutive consonants reaches 4, output
 * "NO"; otherwise, output "YES".
 *
 * Complexity
 * Time: O(N) Space: O(1)
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, N;

	string S;

	cin >> T;

	for(int i = 0; i < T; i++){

	    int consecutive = 0;

	    bool xyz = false;

	    cin >> N;

	    cin >> S;

	    for(int j = 0; j < N; j++){

	        if(S[j] != 'a' && S[j] != 'e' && S[j] != 'i' && S[j] != 'o' && S[j] != 'u'){

	            consecutive++;

	            if(consecutive >= 4){

	                xyz = true;

	            }

	        }

	        else{

	            consecutive=0;

	        }

	    }

	    if(xyz){

	        cout << "NO" << endl;

	    }

	    else{

	        cout << "YES" << endl;

	    }

	}

}
