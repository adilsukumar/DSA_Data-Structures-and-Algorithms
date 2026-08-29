/* =============================================================================
 * CodeChef LUDO - Chef Plays Ludo
 * Difficulty: 260 (rating)
 * -----------------------------------------------------------------------------
 * @platform   CodeChef
 * @id         LUDO
 * @title      Chef Plays Ludo
 * @difficulty 260
 * @topics     Basic Programming, Conditionals, Implementation
 * @pattern    Single Equality Check
 * @url        https://www.codechef.com/problems/LUDO
 * @solved     2026-06-05
 * -----------------------------------------------------------------------------
 *
 * PROBLEM
 *   In Ludo a token sits locked in its "yard" until the player rolls a 6 on the
 *   die; only a 6 unlocks a token and lets play begin. Given the number X that
 *   Chef rolled, decide whether Chef can move a token out. There are T
 *   independent test cases. Print "YES" if X == 6, otherwise "NO".
 *   (Case of the output is not significant on this problem.)
 *
 *   Example:
 *     T = 3
 *     X = 1  -> NO   (1 is not a 6, token stays locked)
 *     X = 6  -> YES  (a 6 unlocks the token)
 *     X = 3  -> NO
 *
 * INTUITION
 *   The entire rule collapses to one boolean fact: "did the die show 6?".
 *   Every roll from 1..5 is equivalent (all fail), and 6 is the only success.
 *   So there is nothing to compute or search -- the answer is exactly the
 *   truth value of the equality X == 6. This works because the problem places
 *   no other condition on the move (no board state, no token count); the roll
 *   value alone is both necessary and sufficient.
 *
 * WALKTHROUGH
 *   int T, X;                    // T = number of queries, X = the rolled value
 *   cin >> T;                    // read how many rolls to judge
 *   for(i = 0; i < T; i++){      // handle each roll independently
 *       cin >> X;                // read this roll
 *       if(X == 6)               // the one and only unlocking condition
 *           cout << "YES" << endl;
 *       else
 *           cout << "NO"  << endl;
 *   }
 *   The loop counter i is pure iteration control; nothing carries over between
 *   test cases, which is correct because the cases are independent.
 *
 *   Dry run on the example above (T = 3, rolls 1, 6, 3):
 *     iter 0: X=1 -> 1==6 is false -> prints "NO"
 *     iter 1: X=6 -> 6==6 is true  -> prints "YES"
 *     iter 2: X=3 -> 3==6 is false -> prints "NO"
 *   Output:
 *     NO
 *     YES
 *     NO
 *
 * COMPLEXITY
 *   Time:  O(T) -- one comparison and one print per test case, no inner work.
 *   Space: O(1) -- only two ints are held regardless of T; nothing is stored.
 *
 * EDGE CASES
 *   - X in 1..5:   all correctly map to "NO" (only 6 is special).
 *   - X = 6:       the sole "YES" branch; handled by the exact equality.
 *   - T = 0:       the loop body never runs and nothing is printed -- fine.
 *   - Out-of-range X (0 or >6): the die is stated to be 1..6, so this cannot
 *     occur under the constraints; the == 6 test would simply report "NO" for
 *     any such value anyway, so the code degrades safely.
 *   - Minor style note: each line is flushed with endl. For T up to a few
 *     thousand this is harmless, but "\n" avoids repeated stream flushes; not a
 *     correctness issue here.
 *
 * This solution is already optimal -- the answer is a single O(1) comparison
 * per query and there is no faster or simpler formulation.
 * =============================================================================
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X;

	cin >> T;

	for(int i = 0; i < T; i++){

	    cin >> X;

	    if(X == 6){

	        cout << "YES" << endl;

	    }

	    else{

	        cout << "NO" << endl;

	    }

	}



}
