/* ============================================================================
 * CodeChef CNTWRD - Counting Words                          Difficulty: 296
 * ============================================================================
 * @platform   CodeChef
 * @id         CNTWRD
 * @title      Counting Words
 * @difficulty 296
 * @topics     Basic Programming Concepts, Basic Math
 * @pattern    Per-test read two ints, print product
 * @url        https://www.codechef.com/problems/CNTWRD
 * @solved     2026-06-07
 * ----------------------------------------------------------------------------
 *
 * ⚠️  HONESTY FLAG — READ THIS FIRST
 *     This code does NOT solve a word-counting problem. The body still carries
 *     the "// your code goes here" stub comment, and all it does is read two
 *     integers per test case and print their product. There is no string input,
 *     no tokenizing on spaces, no counting of words anywhere. This is almost
 *     certainly a leftover template (or a paste from a different "product of
 *     two numbers" problem) that was never replaced with the real solution.
 *     If it was ever "Accepted", that only means CNTWRD's actual answer happens
 *     to be expressible as N*M for the given constraints — which is not how a
 *     genuine word-count task behaves. Treat this file as a stub to REWRITE,
 *     not a reference to revise from. Re-open the statement before trusting it.
 *
 * PROBLEM (what this code actually implements, not the real CNTWRD statement):
 *     Read T. For each of T test cases, read two integers N and M and print
 *     N * M, one result per line.
 *
 *     Example (as the code behaves):
 *         Input : 2 / 3 4 / 5 6
 *         Output: 12 / 30
 *
 *     A real "Counting Words" task would instead hand you a line (or lines) of
 *     text and ask how many words it contains — i.e. read a string, split on
 *     whitespace, and count the non-empty tokens. None of that is here.
 *
 * INTUITION:
 *     The only "idea" present is the arithmetic identity: multiply the two
 *     numbers you were handed. It works as arithmetic, but it has no bearing on
 *     counting words, so there is no correctness argument to make for CNTWRD.
 *     The real intuition you'll need when you rewrite: word count = number of
 *     maximal runs of non-space characters, which C++ gives you for free —
 *     `cin >> word` skips whitespace and stops at the next blank, so counting
 *     successful extractions counts words.
 *
 * WALKTHROUGH (line by line, on the CURRENT code):
 *     - `int T, N, M;`            declares the loop counter and the two operands.
 *     - `cin >> T;`               reads how many test cases follow.
 *     - `for(i = 0; i < T; i++)`  standard fixed-count test loop.
 *         - `cin >> N;`           read first integer.
 *         - `cin >> M;`           read second integer.
 *         - `cout << N*M << endl;`print the product, flushing each line.
 *     - `return 0;`               normal exit.
 *
 *     Dry run on T=2, pairs (3,4) and (5,6):
 *         i=0: N=3, M=4  -> prints 12
 *         i=1: N=5, M=6  -> prints 30
 *     Intermediate state is trivial: no accumulator, no string buffer, nothing
 *     retained between iterations. That minimalism is exactly the tell that no
 *     word-counting logic exists.
 *
 * COMPLEXITY:
 *     Time : O(T) — constant work (one multiply, one print) per test case.
 *     Space: O(1) — three ints reused across all iterations; nothing scales.
 *     Note: `endl` flushes on every line; for large T prefer '\n' to avoid the
 *     flush cost. `int` overflows if N*M exceeds ~2.1e9 — use long long if the
 *     real constraints allow big operands.
 *
 * EDGE CASES:
 *     - Overflow: N*M is computed in `int`; large N,M silently wraps. Unhandled.
 *     - Non-integer / text input: `cin >> N` fails on a word, leaving N garbage
 *       and looping on a failed stream — this is precisely what breaks if the
 *       real problem feeds text. Unhandled.
 *     - The genuine CNTWRD edge cases (empty lines, multiple spaces, trailing
 *       spaces, punctuation-as-part-of-word) are not even reachable here because
 *       the code never reads a string.
 *
 * BETTER / CORRECT APPROACH (this solution does not solve the stated problem):
 *     Replace the arithmetic with actual word counting. If each test case is a
 *     single line of text, read the whole line and count whitespace-delimited
 *     tokens:
 *
 *         int T; cin >> T; cin.ignore();
 *         while (T--) {
 *             string line; getline(cin, line);
 *             stringstream ss(line);
 *             string w; long long count = 0;
 *             while (ss >> w) ++count;   // >> skips runs of whitespace for you
 *             cout << count << '\n';
 *         }
 *
 *     This is O(total characters) time, O(longest line) space, and correctly
 *     handles multiple/leading/trailing spaces and empty lines (count = 0).
 *     Confirm the exact input shape against the CNTWRD statement before using it.
 * ============================================================================
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, N, M;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> N;

	    cin >> M;

	    cout << N*M << endl;

	}

    return 0;

}
