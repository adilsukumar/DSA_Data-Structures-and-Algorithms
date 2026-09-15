/*
 * CodeChef DNASTRAND - Complementary Strand in a DNA [660]
 *
 * @platform   CodeChef
 * @id         DNASTRAND
 * @title      Complementary Strand in a DNA
 * @difficulty 660
 * @topics     daanish_adm, june222
 * @pattern    Linear Scan
 * @url        https://www.codechef.com/problems/DNASTRAND
 * @solved     2026-09-02
 *
 * Problem
 * Accepted solution for Complementary Strand in a DNA.
 *
 * Approach
 * The algorithm iterates through the DNA string one character at a time. For each character, it applies a direct conditional check to map it to its complementary base (A to T, T to A, G to C, C to G). It immediately outputs the mapping without storing intermediate results, leveraging a constant-time lookup logic.
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

	    cin >> N >> S;

	    for(int j = 0; j < S.length(); j++){

	        if(S[j] == 'A'){

	            cout << 'T';

	        }

	        else if(S[j] == 'T'){

	            cout << 'A';

	        }

	        else if(S[j] == 'G'){

	            cout << 'C';

	        }

	        else{

	            cout << 'G';

	        }

	    }

	    cout << endl;

	}

    return 0;

}
