/*
 ============================================================================
 CodeChef - Best Of Two                                    Difficulty: 284
 ============================================================================
 @platform   CodeChef
 @id         BESTOFTWO
 @title      Best Of Two
 @difficulty 284
 @topics     Implementation, Basics
 @pattern    Max Of Two Values
 @url        https://www.codechef.com/problems/BESTOFTWO
 @solved     2026-06-07

 PROBLEM
 -------
 Chef has two scores, X and Y, for a subject: one from an assignment and one
 from an exam. His final grade is the BETTER of the two. Given T independent
 test cases, each a pair (X, Y), print the larger of the two numbers.

   Example: X = 3, Y = 7  ->  print 7   (7 is the better score)
            X = 9, Y = 4  ->  print 9

 INTUITION
 ---------
 "Best of two" is literally the maximum of the pair. There is no state to
 carry across test cases, no combination of the values -- each answer depends
 only on its own X and Y. A single comparison X > Y decides which to print.
 It works because max(X, Y) equals X when X > Y and Y otherwise, and the
 else-branch cleanly absorbs the tie case (X == Y): printing Y is correct
 since both values are equal.

 WALKTHROUGH
 -----------
 - `cin >> T;`            read how many test cases follow.
 - `for (i = 0; i < T; i++)`  loop once per test case; the counter i is only
                          a repeat count -- it never enters the logic.
 - `cin >> X; cin >> Y;`  read the two scores for THIS case.
 - `if (X > Y) print X;`  X is strictly greater, so it is the better score.
 - `else print Y;`        covers both X < Y and X == Y; printing Y is correct
                          in each (in the tie, X and Y are the same number).
 - `endl` flushes after every line -- harmless here given tiny input.

 Dry run on:
     T = 2
     3 7
     9 4

   read T = 2
   i = 0:  read X = 3, Y = 7.  3 > 7 ? no  -> else -> print 7
   i = 1:  read X = 9, Y = 4.  9 > 4 ? yes -> if   -> print 9
   loop ends (i = 2 == T)
   Output:
     7
     9

 COMPLEXITY
 ----------
 Time  : O(T)  -- a fixed amount of work (one compare, one print) per case.
 Space : O(1)  -- three ints reused every iteration; nothing scales with T.

 EDGE CASES
 ----------
 - X == Y (a tie): the else-branch prints Y, which equals X. Correct.
 - Negative values: `>` compares signed ints correctly, so negatives are fine.
 - Large values: X, Y fit in `int` for this problem's constraints; if the
   constraints allowed values beyond ~2.1e9, `int` would overflow and
   `long long` would be needed -- not a concern at this difficulty.
 - This is already optimal: you cannot decide the larger of two numbers with
   fewer than one comparison, and I/O is linear in the input size.

 NOTE
 ----
 The whole if/else could be replaced by `cout << max(X, Y) << "\n";`, which is
 shorter and communicates intent directly, but it is not faster -- the current
 code is already optimal in both time and space.
*/

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, X, Y;

	cin >> T;

	

	for (int i = 0; i < T; i++){

	    cin >> X;

	    cin >> Y;

	    if(X>Y){

	        cout << X << endl;

	    }

	    else{

	        cout << Y << endl;

	    }

	}

    return 0;

}
