/*
 * Platform: CodeChef
 * Submission: 1364750213
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
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> N >> S;
        for(int j = 0; j < N; j=j+4){
            if(S[j] == 'a' || S[j] == 'e' || S[j] == 'i' || S[j] == 'o' || S[j] == 'u'){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
        
    }
}
