/*
 * ============================================================================
 *  CodeChef - Nearest Exit                                    Difficulty: 585
 * ============================================================================
 *  @platform   CodeChef
 *  @id         NEARESTEXIT
 *  @title      Nearest Exit
 *  @difficulty 585
 *  @topics     Basic Programming, Implementation, Conditionals
 *  @pattern    Midpoint Threshold Comparison
 *  @url        https://www.codechef.com/problems/NEARESTEXIT
 *  @solved     2026-06-24
 * ----------------------------------------------------------------------------
 *
 *  PROBLEM
 *  -------
 *  You are standing at some position X inside a corridor with 100 cells,
 *  numbered 1..100. There is an exit just beyond each end: a LEFT exit past
 *  cell 1 and a RIGHT exit past cell 100. For each query you must print which
 *  exit is nearer. The corridor's midpoint sits between cells 50 and 51, so
 *  cells 1..50 are (weakly) closer to the left and 51..100 closer to the right.
 *  There are T independent queries.
 *
 *  Example:  X = 30  -> "LEFT"   (30 is in the left half)
 *            X = 80  -> "RIGHT"  (80 is in the right half)
 *            X = 50  -> "LEFT"   (the boundary cell resolves to LEFT here)
 *
 *  INTUITION
 *  ---------
 *  With 100 cells and exits at both ends, the deciding factor is which side of
 *  the middle you fall on. The middle lies between 50 and 51, so a single
 *  comparison against the constant 50 fully classifies the position -- no
 *  distance arithmetic is needed. Everything at or below 50 is left-leaning;
 *  everything above 50 is right-leaning. That is exactly the branch this code
 *  uses (X <= 50). The "<=" is what fixes the tie at the boundary in favour of
 *  LEFT; the problem's expected output must agree with that choice for the
 *  code to be correct (it does for the standard version of this task).
 *
 *  WALKTHROUGH
 *  -----------
 *    int T, X;                 // T = number of queries, X = current position
 *    cin >> T;                 // read how many test cases follow
 *    for (i = 0; i < T; i++) { // handle each query independently
 *        cin >> X;             // read this query's position
 *        if (X <= 50)          // in (or at the boundary of) the left half...
 *            cout << "LEFT";   //   ...the left exit is nearest
 *        else                  // otherwise strictly past the midpoint...
 *            cout << "RIGHT";  //   ...the right exit is nearest
 *    }                         // endl also flushes after each line (fine here)
 *
 *  Dry run on:   T = 3,  X = 30, 50, 75
 *    - i=0: X=30 -> 30 <= 50 is true  -> print "LEFT"
 *    - i=1: X=50 -> 50 <= 50 is true  -> print "LEFT"   (boundary -> LEFT)
 *    - i=2: X=75 -> 75 <= 50 is false -> print "RIGHT"
 *  Output:
 *    LEFT
 *    LEFT
 *    RIGHT
 *
 *  COMPLEXITY
 *  ----------
 *  Time  : O(T)  -- one read plus one comparison per query, no inner work.
 *  Space : O(1)  -- two scalars reused across all iterations; nothing stored.
 *
 *  EDGE CASES
 *  ----------
 *  - Boundary value X = 50: handled by "<=", classified as LEFT. If the judge
 *    ever expected RIGHT (or a "either" tie) at the exact middle, this branch
 *    would be the one to revisit -- it is the single assumption baked in.
 *  - Extremes X = 1 and X = 100: 1 <= 50 -> LEFT, 100 > 50 -> RIGHT, correct.
 *  - T = 0: the loop body never runs and the program prints nothing, which is
 *    the right behaviour for an empty query set.
 *  - The code assumes X always lands in 1..100 as the constraints promise; it
 *    does no validation, which is acceptable for a fixed-range problem.
 *
 *  NOTE ON OPTIMALITY
 *  ------------------
 *  This is already optimal: each query is answered in constant time with a
 *  single comparison, and the whole program is O(T) time / O(1) space, which
 *  cannot be beaten for T independent point queries. The only stylistic tweak
 *  worth noting is that `endl` flushes the stream on every line; using '\n'
 *  avoids that flush, but at these input sizes it makes no measurable
 *  difference. No algorithmic improvement is available.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

    int T, X;

    cin >> T;

    

    for(int i = 0; i < T; i++){

        cin >> X;

        if(X <= 50){

            cout << "LEFT" << endl;

        }

        else{

            cout << "RIGHT" << endl;

        }

    }

    return 0;

}
