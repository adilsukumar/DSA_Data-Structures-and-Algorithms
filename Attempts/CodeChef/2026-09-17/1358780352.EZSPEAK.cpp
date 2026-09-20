/*
 * Platform: CodeChef
 * Submission: 1358780352
 * Problem: EZSPEAK
 * Verdict: wrong answer
 * Date: 2026-09-17
 * URL: https://www.codechef.com/problems/EZSPEAK
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	string S;
	int N, T;
	cin >> T;
	int count_vowel = 0;
	int count_const = 0;
	
	for(int i = 0; i < T; i++){
	    cin >> N;
	    for(int j = 0; j < N; j++){
	        if(S[j] == 'a' || S[j] == 'e' || S[j] == 'i' || S[j] == 'o' || S[j] == 'u'){
	            count_vowel += 1;
	        }
	        else{
	            count_const += 1;
	        }
	    }
	    if(count_vowel > 0){
	        cout << "YES\n";
	    }
	    else{
	        cout << "NO\n";
	    }
	}
    return 0;
}
