/*
 * ============================================================================
 *  CodeChef MONOPOLY2 - Monopoly                              Difficulty: 578
 * ============================================================================
 *  @platform   CodeChef
 *  @id         MONOPOLY2
 *  @title      Monopoly
 *  @difficulty 578
 *  @topics     Conditional Statements, Basic Math, Implementation
 *  @pattern    Generalized Triangle Inequality (max vs rest)
 *  @url        https://www.codechef.com/problems/MONOPOLY2
 *  @solved     2026-06-21
 * ============================================================================
 *
 *  PROBLEM
 *  -------
 *  For each test case you are given four non-negative integers P, Q, R, S.
 *  You must print "YES" when ONE of the four values is strictly greater than
 *  the sum of the other three, and "NO" otherwise. (The four values are the
 *  four quantities the problem tracks; the "one dominates the rest" condition
 *  is what the code tests, so read the header through that lens.)
 *
 *  Worked example:
 *      P=10 Q=1 R=1 S=1  ->  10 > 1+1+1=3  ->  YES  (one dominates)
 *      P=2  Q=2 R=2 S=2  ->  no value beats the other three (2 < 6) -> NO
 *
 *  INTUITION
 *  ---------
 *  This is the generalized triangle inequality. Given four amounts, exactly
 *  one of two situations holds:
 *    - the largest value is <= the sum of the other three  (balanced), or
 *    - the largest value is  >  the sum of the other three  (one dominates).
 *  Only the MAXIMUM can ever exceed the sum of the rest: if x is not the max,
 *  some other value y >= x already lives in "the rest", so x can't outweigh a
 *  sum that contains y. That means you never truly need four comparisons - one
 *  test on the max suffices - but testing all four (as the code does) is
 *  logically identical and just as correct, because at most one of the four
 *  OR-branches can ever be true.
 *  WHY it works: the four conditions are mutually exclusive, so the OR fires
 *  precisely when the dominant-value case occurs, and never gives a false YES.
 *
 *  WALKTHROUGH (this code, line by line)
 *  -------------------------------------
 *    cin >> T;                         read the number of test cases
 *    for i in 0..T-1:                  loop once per test case
 *        cin >> P >> Q >> R >> S;      read the four values for THIS case
 *        if (P > Q+R+S ||             is P alone bigger than the other three?
 *            Q > P+R+S ||             ... or Q?
 *            R > P+Q+S ||             ... or R?
 *            S > P+Q+R)               ... or S?
 *            print "YES"               yes -> one value dominates
 *        else print "NO"               no  -> the four are balanced
 *
 *  Dry run on T=2 with cases (10 1 1 1) and (2 2 2 2):
 *    Case 1: P=10,Q=1,R=1,S=1
 *            P>Q+R+S? 10>3 -> TRUE, short-circuits the OR -> prints YES
 *    Case 2: P=2,Q=2,R=2,S=2
 *            2>6? F | 2>6? F | 2>6? F | 2>6? F -> whole OR FALSE -> prints NO
 *    Output:
 *            YES
 *            NO
 *
 *  COMPLEXITY
 *  ----------
 *  Time  : O(T) overall - each test case does a fixed set of 4 comparisons,
 *          i.e. O(1) work per query, independent of the magnitudes involved.
 *  Space : O(1) - five scalar ints are reused across every iteration; nothing
 *          scales with T or with the input values.
 *
 *  EDGE CASES
 *  ----------
 *  - Equality boundary: the test uses strict '>', so a value EQUAL to the sum
 *    of the other three (e.g. 3 1 1 1 -> 3 == 3) yields "NO". This matches the
 *    generalized-inequality reading where "can still balance" is NO.
 *  - All zeros (0 0 0 0): no value exceeds 0, prints "NO" - handled correctly.
 *  - Ties for the maximum (e.g. 5 5 1 1): neither 5 beats 5+1+1=7, prints "NO";
 *    the redundant four-way OR does not misfire because ties can't dominate.
 *  - Overflow watch: Q+R+S is computed in int. For the small constraints this
 *    problem uses that is safe, but if the values could approach INT_MAX the
 *    three-term sum could overflow - there it would be safer to compare the
 *    max against the sum of the rest using long long. Not a bug at these
 *    limits, just the one place the arithmetic is not future-proof.
 *  - `endl` flushes on every line; for very large T, "\n" would be faster,
 *    though it is not a correctness issue.
 *
 *  This solution is already optimal (O(1) per query, O(1) space); there is no
 *  asymptotically better approach, so no alternative is sketched.
 * ============================================================================
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, P, Q, R, S;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> P >> Q >> R >> S;

	    if(P > (Q+R+S) || Q > (P+R+S) || R > (P+Q+S) || S > (P+Q+R)){

	        cout << "YES" << endl;

	    }

	    else{

	        cout << "NO" << endl;

	    }

	}

    return 0;

}
