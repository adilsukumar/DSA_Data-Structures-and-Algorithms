/*
 * CodeChef CHEFBOTTLE - Chef and Water Bottles [662]
 *
 * @platform   CodeChef
 * @id         CHEFBOTTLE
 * @title      Chef and Water Bottles
 * @difficulty 662
 * @topics     Inbuilt functions, Integer Division
 * @pattern    Pending manual review
 * @url        https://www.codechef.com/problems/CHEFBOTTLE
 * @solved     2026-09-02
 *
 * Problem
 * Accepted solution for Chef and Water Bottles.
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
