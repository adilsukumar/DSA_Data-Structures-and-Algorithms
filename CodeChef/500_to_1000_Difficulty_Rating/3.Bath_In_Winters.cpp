/* ============================================================================
 * CodeChef  - Bath In Winters
 * Difficulty: 643
 *
 *   @platform   CodeChef
 *   @id         BATH
 *   @title      Bath In Winters
 *   @difficulty 643
 *   @topics     Math, Implementation, Integer Division
 *   @pattern    Count how many times 2Y fits in X
 *   @url        https://www.codechef.com/problems/BATH
 *   @solved     2026-07-26
 *
 * ----------------------------------------------------------------------------
 * PROBLEM
 *   For each test case you are given two integers X and Y. A single "unit"
 *   of the task consumes 2*Y out of the X available (think: one bath needs
 *   Y hot + Y cold = 2*Y of your total X supply). Report how many complete
 *   units you can perform, i.e. how many times 2*Y fits wholly into X.
 *
 *   Worked example:  X = 10, Y = 3  ->  2*Y = 6, and 6 fits into 10 once
 *                    (12 would not), so the answer is 1.
 *                    X = 5,  Y = 3  ->  2*Y = 6 > 5, nothing fits, answer 0.
 *
 * ----------------------------------------------------------------------------
 * INTUITION
 *   Each unit costs a fixed 2*Y. With a fixed budget X and a fixed per-unit
 *   cost, the maximum number of whole units is just the floor division
 *   X / (2*Y). Floor division is exactly "how many whole 2*Y chunks are in
 *   X, discarding the leftover", which is precisely what the problem asks.
 *   That is the entire idea -- no loop or search is needed.
 *
 * ----------------------------------------------------------------------------
 * WALKTHROUGH  (this code, line by line)
 *   - `cin >> T;`              read the number of test cases.
 *   - `while(T--)`             loop once per test case, decrementing T.
 *   - `cin >> X >> Y;`         read the budget X and the half-cost Y.
 *   - `if(Y*2 > X) print 0`    guard: if one unit already costs more than
 *                              the whole budget, zero units are possible.
 *   - `else print X/(2*Y)`     otherwise print the integer division result.
 *
 *   NOTE / honesty check: the `if` branch is REDUNDANT. When 2*Y > X, the
 *   integer division X/(2*Y) already evaluates to 0, so the `else` branch
 *   alone would produce the identical output for every input. The explicit
 *   guard is dead code -- harmless, but not needed.
 *
 *   Also note: X, Y are `int`, so `X/(2*Y)` is already INTEGER division
 *   (the fractional part is truncated before `floor` ever sees it). Wrapping
 *   it in `floor(...)` is a no-op here; it operates on an already-integral
 *   value and only forces a needless int->double->int round trip. It happens
 *   to give the right answer for the non-negative inputs this problem uses.
 *
 *   Dry run on input:  T=2 / (10 3) / (5 3)
 *     T=2
 *     iter 1: X=10, Y=3 -> Y*2=6, 6>10? no -> else -> 10/6 = 1 -> prints 1
 *     iter 2: X=5,  Y=3 -> Y*2=6, 6>5?  yes -> if  -> prints 0
 *   Output: 1 then 0.
 *
 * ----------------------------------------------------------------------------
 * COMPLEXITY
 *   Time : O(T). Each test case is a constant amount of arithmetic; total
 *          work scales linearly with the number of test cases.
 *   Space: O(1). Only a handful of scalar variables, reused every iteration.
 *
 * ----------------------------------------------------------------------------
 * EDGE CASES
 *   - 2*Y > X  (can't afford even one unit): handled -> outputs 0, both by
 *     the explicit guard and, redundantly, by the division itself.
 *   - X exactly a multiple of 2*Y (e.g. X=12, Y=3): 12/6 = 2, correct; no
 *     off-by-one because floor division drops nothing when the remainder is 0.
 *   - Y = 0: this code would divide by zero (undefined behavior). The problem
 *     constraints presumably guarantee Y >= 1, so it is never exercised, but
 *     the code does NOT defend against it.
 *   - Large X, Y: safe as long as X and 2*Y fit in `int`; if constraints ever
 *     pushed 2*Y past ~2.1e9, `2*Y` would overflow -- use `long long` then.
 *
 * ----------------------------------------------------------------------------
 * CLEANER / EQUIVALENT APPROACH  (same complexity, less noise)
 *   The solution is already optimal in time and space; this is only a tidy-up
 *   removing the dead branch and the pointless floor():
 *
 *     int T; cin >> T;
 *     while (T--) {
 *         long long X, Y; cin >> X >> Y;   // long long guards against overflow
 *         cout << X / (2 * Y) << '\n';     // integer division already floors
 *     }
 *
 *   Prefer '\n' over endl to avoid an unnecessary stream flush per line.
 * ============================================================================ */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X, Y;

	cin >> T;

	

	while(T--){

	    cin >> X >> Y;

	    if(Y*2 > X){

	        cout << 0 << endl;

	    }

	    else{

	        cout << floor(X/(2*Y)) << endl;

	    }

	}

	return 0;

}
