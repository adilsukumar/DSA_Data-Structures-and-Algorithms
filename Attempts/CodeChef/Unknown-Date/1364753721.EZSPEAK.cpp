/*
 * Platform: CodeChef
 * Submission: 1364753721
 * Problem: EZSPEAK
 * Verdict: wrong answer
 * Date: Unknown-Date
 * URL: https://www.codechef.com/problems/EZSPEAK
 *  */

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, N;
	string S;
	int consecutive = 0;
	cin >> T;
	for(int i = 0; i < T; i++){
	    cin >> N;
	    cin >> S;
	    for(int j = 0; j < N; j++){
	        if(S[j] != 'a' && S[j] != 'e' && S[j] != 'i' && S[j] != 'o' && S[j] != 'u'){
	            consecutive++;
	        }
	        else{
	            consecutive=0;
	        }
	    }
	    if(consecutive >= 4){
	        cout << "NO" << endl;
	    }
	    else{
	        cout << "YES" << endl;
	    }
	    
	}
}
