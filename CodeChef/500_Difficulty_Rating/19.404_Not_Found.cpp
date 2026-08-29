/*
 * ==============================================================================
 *  CodeChef ERROR404 - 404 Not Found            Difficulty: 267 (Beginner)
 * ==============================================================================
 *  @platform   CodeChef
 *  @id         ERROR404
 *  @title      404 Not Found
 *  @difficulty 267
 *  @topics     Implementation, Conditionals, Basic Programming
 *  @pattern    Direct Equality Check
 *  @url        https://www.codechef.com/problems/ERROR404
 *  @solved     2026-06-06
 * ------------------------------------------------------------------------------
 *
 *  PROBLEM
 *  -------
 *  Read a single integer X. If X equals 404, print "NOT FOUND"; otherwise
 *  print "FOUND". A tongue-in-cheek nod to the HTTP 404 status code, where the
 *  number 404 is precisely the value that means "not found".
 *
 *    Input:  404   -> Output: NOT FOUND
 *    Input:  200   -> Output: FOUND
 *    Input:  0     -> Output: FOUND
 *
 *  INTUITION
 *  ---------
 *  There is nothing to compute or search. The entire task collapses to a single
 *  equality test: is X the magic number 404? The output labels are deliberately
 *  inverted relative to intuition (matching 404 -> NOT FOUND), so the ONE thing
 *  that can trip you up is wiring the branches to the wrong string. Everything
 *  else is boilerplate I/O. This works because the condition partitions all
 *  possible inputs into exactly two disjoint classes with no overlap.
 *
 *  WALKTHROUGH
 *  -----------
 *  Line by line, this is what the code does:
 *
 *    int X; cin >> X;   reads the one integer from standard input into X.
 *    if (X == 404)      the single decision point. Note "==" (comparison),
 *                       not "=" (assignment) — a classic beginner trap that
 *                       this code avoids correctly.
 *    cout << "NOT FOUND"  taken only when X is exactly 404.
 *    else cout << "FOUND" taken for every other integer value.
 *    endl               emits a newline and flushes the stream.
 *
 *  Dry run on X = 404:
 *    - cin >> X          -> X = 404
 *    - X == 404 ?        -> true
 *    - prints "NOT FOUND\n", skips the else branch. Done.
 *
 *  Dry run on X = 200:
 *    - cin >> X          -> X = 200
 *    - X == 404 ?        -> false
 *    - else branch fires -> prints "FOUND\n". Done.
 *
 *  COMPLEXITY
 *  ----------
 *  Time  : O(1) — one read and one comparison, independent of the input value.
 *  Space : O(1) — a single int; no containers or recursion.
 *
 *  EDGE CASES
 *  ----------
 *  - Negative numbers, zero, or huge values: all handled — anything that isn't
 *    404 falls straight into the "FOUND" branch. No range assumptions are made
 *    beyond int fitting the value (CodeChef's constraints keep X within int).
 *  - Exactly 404 is the sole special case and is matched precisely by "==".
 *  - No trailing-whitespace or multi-token parsing issues: cin >> int skips
 *    leading whitespace automatically.
 *  - Minor style notes (not bugs): "#include <bits/stdc++.h>" is a GCC-only
 *    convenience header, and main() omits an explicit "return 0" (legal in C++
 *    — main implicitly returns 0). The commented "// your code goes here" is
 *    leftover template noise and could be deleted.
 *
 *  This solution is already optimal — O(1) time and space with a single
 *  comparison. There is no faster or simpler formulation, so no alternative
 *  approach is warranted.
 * ==============================================================================
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int X;

	cin >> X;

	if (X == 404){

	    cout << "NOT FOUND" << endl;

	}

	else{

	    cout << "FOUND" << endl;

	}



}
