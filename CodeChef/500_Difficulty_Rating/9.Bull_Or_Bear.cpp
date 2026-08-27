/*
 * ============================================================================
 * CodeChef BULLBEAR - Bull or Bear                              Difficulty 300
 * ============================================================================
 * @platform   CodeChef
 * @id         BULLBEAR
 * @title      Bull Or Bear
 * @difficulty 300
 * @topics     Implementation, Conditionals, Basic Programming
 * @pattern    Three-way comparison per query
 * @url        https://www.codechef.com/problems/BULLBEAR
 * @solved     2026-06-10
 *
 * PROBLEM
 *   For each of T days you are given two prices: X (opening) and Y (closing).
 *   Report the market sentiment for that day:
 *     - "PROFIT"  if the closing price is higher than the opening (Y > X)
 *     - "LOSS"    if the closing price is lower than the opening (X > Y)
 *     - "NEUTRAL" if they are equal
 *   Example: T=3
 *     10 15  -> Y>X  -> PROFIT
 *     20 12  -> X>Y  -> LOSS
 *      7  7  -> X==Y -> NEUTRAL
 *
 * INTUITION
 *   There is nothing to compute or remember across days. Each day is a wholly
 *   independent question: "did the price go up, down, or stay flat?" That is a
 *   single sign comparison between two numbers. The only reason a loop exists
 *   is to repeat the same trivial decision T times. Because the three outcomes
 *   (up / down / equal) are mutually exclusive and cover every case, a plain
 *   if / else-if / else ladder is exactly the right tool -- it maps one branch
 *   to each possible relation of two integers, and one of them must fire.
 *
 * WALKTHROUGH
 *   - `cin >> T;` reads how many days follow.
 *   - The `for` loop runs once per day. Inside it, `cin >> X;` then `cin >> Y;`
 *     pull that day's opening and closing prices. (Note X, Y are declared once
 *     outside the loop and simply overwritten each iteration -- fine here, no
 *     state needs to survive between days.)
 *   - The ladder decides the label:
 *       * `if (Y > X)`      -> price rose  -> print "PROFIT"
 *       * `else if (X > Y)` -> price fell  -> print "LOSS"
 *       * `else`            -> only Y == X remains -> print "NEUTRAL"
 *     The `else` is safe precisely because the two prior conditions already
 *     excluded every "not equal" case, so reaching it guarantees equality.
 *   - `endl` flushes each line; correct, though "\n" would be marginally
 *     faster for large T (not a concern at this scale).
 *
 *   Dry run on T=3 with the example above:
 *     iter i=0: read X=10, Y=15 -> Y>X true            -> out: PROFIT
 *     iter i=1: read X=20, Y=12 -> Y>X false, X>Y true -> out: LOSS
 *     iter i=2: read X=7,  Y=7  -> both false, else     -> out: NEUTRAL
 *   Final output:
 *     PROFIT
 *     LOSS
 *     NEUTRAL
 *
 * COMPLEXITY
 *   Time  : O(T) -- constant work (two reads + up to two comparisons) per day.
 *   Space : O(1) -- three ints reused for all days; no arrays or accumulation.
 *
 * EDGE CASES
 *   - Equal prices (X == Y): handled by the `else`, never misreported as a
 *     profit or loss.
 *   - Negative or large values: comparison operators work on the full int
 *     range, so signs and magnitude don't matter as long as values fit in int.
 *   - T == 0: the loop body never runs and nothing is printed -- correct.
 *   - Watch-out: if prices could exceed the int range the type would need to
 *     be `long long`; at difficulty 300 int is safe, but worth remembering.
 *
 * This is already optimal: the problem is inherently O(T) (every day must be
 * read and answered) with O(1) space, and this code achieves exactly that.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X, Y;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> X;

	    cin >> Y;

	    if(Y>X){

	        cout << "PROFIT" << endl;

	    }

	    else if(X>Y){

	        cout << "LOSS"<< endl;

	    }

	    else{

	        cout << "NEUTRAL" << endl;

	    }

	}

	return 0;

}
