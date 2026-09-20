/*
 * Platform: CodeChef
 * Submission: 1359273635
 * Problem: EZSPEAK
 * Verdict: wrong answer
 * Date: 2026-09-18
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
	    cin >> S;
	    for(int j = 0; j < N; j++){
	        if((S[j] == 'a' || S[j] == 'e' || S[j] == 'i' || S[j] == 'o' || S[j] == 'u') && (S[j+1] == 'a' || S[j+1] == 'e' || S[j+1] == 'i' || S[j+1] == 'o' || S[j+1] == 'u') && (S[j+2] == 'a' || S[j+2] == 'e' || S[j+2] == 'i' || S[j+2] == 'o' || S[j+2] == 'u') && (S[j+3] == 'a' || S[j+3] == 'e' || S[j+3] == 'i' || S[j+3] == 'o' || S[j+3] == 'u') ){
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
