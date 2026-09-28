/*
 * Platform: CodeChef
 * Submission: 1364750586
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
    int yes = 0;
    int no = 0;
    string S;
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> N >> S;
        for(int j = 0; j < N; j=j+4){
            if(S[j] == 'a' || S[j] == 'e' || S[j] == 'i' || S[j] == 'o' || S[j] == 'u'){
                yes += 1;
            }
            else{
                no += 1;
            }
        }
        if(yes > 1){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
        
    }
}
