/*
 * CodeChef DNASTRAND - Complementary Strand in a DNA [660]
 *
 * @platform   CodeChef
 * @id         DNASTRAND
 * @title      Complementary Strand in a DNA
 * @difficulty 660
 * @topics     daanish_adm, june222
 * @pattern    Pending manual review
 * @url        https://www.codechef.com/problems/DNASTRAND
 * @solved     2026-09-02
 *
 * Problem
 * Accepted solution for Complementary Strand in a DNA.
 *
 * Approach
 * Pending manual review. The submitted code is preserved exactly below.
 *
 * Complexity
 * Pending manual review.
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
