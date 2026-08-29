/*
 * ============================================================================
 *  CodeChef OFFBY1 - Off By One                                 Difficulty: 271
 * ============================================================================
 *  @platform   CodeChef
 *  @id         OFFBY1
 *  @title      Off By One
 *  @difficulty 271
 *  @topics     Basic Programming, Implementation, Math
 *  @pattern    Two-integer input, print sum
 *  @url        https://www.codechef.com/problems/OFFBY1
 *  @solved     2026-06-06
 * ----------------------------------------------------------------------------
 *
 *  PROBLEM
 *    Read two integers A and B and print a single integer: their combined
 *    value. This is a beginner I/O + arithmetic task (rating 271, "Basic
 *    Programming Concepts"). The intended answer is one number, e.g.
 *        A = 2, B = 3   ->   5
 *    (Note: I could not re-fetch the live statement in this session. The
 *    "Off By One" title suggests the accepted answer may be A+B shifted by one,
 *    e.g. A+B+1 -> 6 for the example above. Either way the point below stands:
 *    whatever single integer is required, this code does NOT produce it.)
 *
 *  INTUITION
 *    A one-line problem: consume two integers, emit one. The only real skill
 *    tested is correctly wiring input to a single arithmetic output. The trap
 *    this solution falls into is a C++ language trap, not an algorithmic one.
 *
 *  WALKTHROUGH  (of THIS code, line by line)
 *    - `int A, B;`               declare the two operands.
 *    - `cin >> A; cin >> B;`     read them from stdin. This part is correct.
 *    - `cout << A+B << 1 << endl;`  THIS IS THE BUG. There is no bit-shift or
 *          "+1" happening here. In `cout << X`, `<<` is the stream-insertion
 *          operator, NOT the left-shift operator. The statement chains two
 *          insertions:
 *              (1) insert the value of (A+B)
 *              (2) insert the literal character '1'
 *          So the program prints A+B and then GLUES a '1' onto the end of it,
 *          as text. It never adds 1, and it never shifts bits.
 *
 *    Dry run on A=2, B=3:
 *          A+B          = 5              -> stream now holds "5"
 *          << 1         inserts '1'      -> stream now holds "51"
 *          << endl      newline + flush  -> OUTPUT:  51
 *      Expected output is 5 (or 6). Actual output is the string "51". Wrong.
 *
 *    Why the mistake is seductive: `<<` really IS left-shift on plain ints.
 *    `(A+B) << 1` in an arithmetic context would double the sum (multiply by
 *    2), because shifting left by one bit == *2. But inside a `cout << ...`
 *    chain the same token is overloaded to mean "insert into stream", so the
 *    `1` becomes data, not a shift amount. Operator overloading, not operator
 *    precedence, is what bites here.
 *
 *  COMPLEXITY
 *    Time  : O(1) - a fixed number of reads and one write, no loops.
 *    Space : O(1) - two ints, no allocation.
 *    (The complexity is fine; correctness is not.)
 *
 *  EDGE CASES / FAILURE MODES
 *    - It fails on EVERY input, not just edge cases: the trailing '1' is
 *      appended unconditionally, so no test can pass.
 *    - Concatenation, not addition: for large sums the "answer" balloons into
 *      an even longer wrong string (e.g. 1000000000 -> "10000000001").
 *    - Negatives: A=-1, B=-4 -> A+B = -5 -> prints "-51", clearly nonsense.
 *    - There is no multi-test loop; if OFFBY1 has T test cases on separate
 *      lines this reads only one pair and stops, a second latent bug.
 *
 *  CORRECT / OPTIMAL APPROACH
 *    The algorithm is already O(1); only the output expression is broken.
 *    Emit the single required integer with a normal arithmetic expression and
 *    no stray insertion:
 *
 *        int A, B;
 *        cin >> A >> B;
 *        cout << (A + B) << "\n";        // if the answer is the plain sum
 *        // cout << (A + B + 1) << "\n"; // use this if the task wants +1
 *
 *    If the judge feeds multiple test cases, wrap it:
 *
 *        int T; cin >> T;
 *        while (T--) { int A,B; cin>>A>>B; cout << (A+B) << "\n"; }
 *
 *    Key takeaway for revision: in a `cout << ...` chain, every `<<` is
 *    stream insertion. Do all arithmetic INSIDE parentheses first, then insert
 *    the finished value. `cout << A+B << 1` prints two things; it never
 *    computes "A+B then something with 1".
 * ============================================================================
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int A, B;

	cin >> A;

	cin >> B;

	cout << A+B << 1 << endl;



}
