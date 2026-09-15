/*
 * CodeChef CHEFBOTTLE - Chef and Water Bottles [662]
 *
 * @platform   CodeChef
 * @id         CHEFBOTTLE
 * @title      Chef and Water Bottles
 * @difficulty 662
 * @topics     Inbuilt functions, Integer Division
 * @pattern    Greedy Logic
 * @url        https://www.codechef.com/problems/CHEFBOTTLE
 * @solved     2026-09-02
 *
 * Problem
 * Accepted solution for Chef and Water Bottles.
 *
 * Approach
 * The solution checks if the total number of bottles times the water per bottle is
 * sufficient to meet requirement K. If yes but X < K, it calculates how many full
 * bottles can be used (K / X). Otherwise, it uses all N bottles or zero depending
 * on constraints.
 *
 * Complexity
 * Time: O(1) Space: O(1)
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, N, X, K;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> N >> X >> K;

	    if(N*X >= K){

	        if(X < K){

	            cout << K / X << endl;

	        }

	        else{

	            cout << 0 << endl;

	        }

	    }

	    else{

	        cout << N << endl;

	    }

	}

	return 0;

}
