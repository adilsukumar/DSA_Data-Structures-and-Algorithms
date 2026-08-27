/* =====================================================================
 * CodeChef CREDCOINS - CRED Coins
 * Difficulty: 539 (rating)
 * ---------------------------------------------------------------------
 * @platform   CodeChef
 * @id         CREDCOINS
 * @title      CRED Coins
 * @difficulty 539
 * @topics     Math, Basic Programming, Implementation
 * @pattern    Integer Division (floor total/100)
 * @url        https://www.codechef.com/problems/CREDCOINS
 * @solved     2026-06-10
 * ---------------------------------------------------------------------
 *
 * PROBLEM
 *   For every 100 rupees a user pays, CRED rewards exactly 1 CRED coin
 *   (fractional coins are not awarded). A bill is described by two
 *   integers X and Y; the amount paid is their product X*Y. Report how
 *   many whole CRED coins the user earns for that bill.
 *   There are T independent test cases.
 *
 *   Example: X = 40, Y = 3  -> amount = 120  -> 120/100 = 1 coin.
 *            X = 4,  Y = 5  -> amount = 20   -> 0 coins (under 100).
 *
 * INTUITION
 *   Coins earned = floor(amount / 100), because you only get a coin once
 *   a *full* block of 100 rupees is spent. Integer division in C++ already
 *   truncates toward zero, and since amount = X*Y is non-negative here,
 *   truncation IS the floor we want. So the whole answer is one division:
 *   (X*Y) / 100. No loop over hundreds, no manual rounding needed.
 *
 * WALKTHROUGH (line by line on THIS code)
 *   - `cin >> T;`            read the number of bills to process.
 *   - `for i in [0, T)`      iterate once per bill.
 *   - `cin >> X; cin >> Y;`  read the two factors of the current bill.
 *   - `if (X*Y >= 100)`      guard: is the bill at least one coin's worth?
 *       - if yes: print (X*Y)/100, the number of whole coins.
 *       - else:   print 0.
 *   NOTE: the if/else here is redundant. When X*Y < 100, integer division
 *   (X*Y)/100 already evaluates to 0. So `cout << (X*Y)/100` on its own,
 *   with no branch, produces identical output for every input. The guard
 *   is dead logic — harmless, but not needed. Kept as-is it still passes.
 *
 *   Dry run on T=2, then (40 3), (4 5):
 *     iter 0: X=40, Y=3 -> X*Y=120 -> 120>=100 true -> print 120/100 = 1
 *     iter 1: X=4,  Y=5 -> X*Y=20  -> 20>=100 false -> print 0
 *     output:
 *       1
 *       0
 *
 * COMPLEXITY
 *   Time:  O(T) — a constant amount of work (one multiply, one divide,
 *          one compare) per test case.
 *   Space: O(1) — only the scalars T, X, Y are held; no arrays.
 *
 * EDGE CASES
 *   - Bill under 100 (e.g. X*Y = 99): prints 0. Handled by the guard, and
 *     also handled implicitly by integer division alone.
 *   - Exactly 100: 100/100 = 1. The `>= 100` is inclusive, so correct.
 *   - X or Y = 0: product 0 -> 0 coins. Correct.
 *   - OVERFLOW WATCH: X*Y is computed in `int`. If the constraints ever let
 *     X and Y each reach ~1e5+, the product can exceed the ~2.1e9 `int`
 *     range and overflow (undefined behavior / wrong answer). For CREDCOINS
 *     the stated bounds keep X*Y within int, so it is safe here — but if
 *     reusing this pattern, promote to `long long` to be robust.
 *
 * OPTIMALITY / CLEANER VERSION
 *   Already optimal in time and space (O(T), O(1)). The only improvement is
 *   clarity — drop the redundant branch and widen the type:
 *
 *       int T; cin >> T;
 *       while (T--) {
 *           long long X, Y;
 *           cin >> X >> Y;
 *           cout << (X * Y) / 100 << '\n';   // floor handles the <100 case
 *       }
 *
 * ===================================================================== */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X, Y;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> X;

	    cin >> Y;

	    

	    if(X*Y >= 100){

	        cout << (X*Y)/100 << endl;

	    }

	    else{

	        cout << 0 << endl;

	    }

	}

    return 0;   

}
