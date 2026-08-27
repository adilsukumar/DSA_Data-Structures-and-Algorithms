/*
 ============================================================================
 CodeChef BNE_APT - Bone Appetit                              Difficulty: 280
 ============================================================================
  @platform   CodeChef
  @id         BNE_APT
  @title      Bone Appetit
  @difficulty 280
  @topics     Math, Implementation
  @pattern    Weighted Sum (two-item linear combination)
  @url        https://www.codechef.com/problems/BNE_APT
  @solved     2026-06-07

 ----------------------------------------------------------------------------
 PROBLEM
 ----------------------------------------------------------------------------
   There are two kinds of items. You have N of the first kind, each carrying
   a value/price X, and M of the second kind, each carrying a value/price Y.
   Report the combined total: how much the whole lot is worth.

   The four numbers arrive on the input as N, M, then X, Y.

   Worked example: N=2, M=3, X=10, Y=4
       first kind : 2 items * 10 = 20
       second kind: 3 items *  4 = 12
       total      = 32

   (Note: the exact cover story of the problem is a dog/bones/menu framing,
    but arithmetically every version of this reduces to the two-item
    weighted sum below — that is precisely what the code computes.)

 ----------------------------------------------------------------------------
 INTUITION
 ----------------------------------------------------------------------------
   No search, no data structure — just distributivity. The contribution of a
   group of identical items is (count * per-unit value), and disjoint groups
   simply add. So the answer is N*X + M*Y, a single expression. It "works"
   because there is no interaction between the two groups; nothing constrains
   or discounts one based on the other.

 ----------------------------------------------------------------------------
 WALKTHROUGH
 ----------------------------------------------------------------------------
   Line by line through THIS code:

     int N, M, X, Y;      -> four 32-bit signed integers.
     cin >> N;            -> read count of first item.
     cin >> M;            -> read count of second item.
     cout << endl;        -> ** DEAD / HARMFUL LINE ** prints a blank line to
                             stdout BEFORE any answer. It does no computation;
                             it only injects a leading '\n' into the output.
                             See EDGE CASES — this is the one real risk here.
     cin >> X;            -> read per-unit value of first item.
     cin >> Y;            -> read per-unit value of second item.
     cout << (N*X)+(M*Y); -> print the weighted sum. No trailing newline.

   Dry run on N=2, M=3, X=10, Y=4:
     after reads: N=2, M=3, X=10, Y=4
     N*X = 20 ; M*Y = 12 ; sum = 32
     stdout produced:  "\n32"   (a blank line, then 32)

   The order of reading (N, M come before X, Y) matches the interleaved
   input layout; the whitespace-skipping of >> makes newlines vs spaces
   between the tokens irrelevant.

 ----------------------------------------------------------------------------
 COMPLEXITY
 ----------------------------------------------------------------------------
   Time : O(1)  -- a fixed number of reads and two multiplications.
   Space: O(1)  -- four scalars, no allocation.

 ----------------------------------------------------------------------------
 EDGE CASES
 ----------------------------------------------------------------------------
   * Leading blank line (the stray `cout << endl;`): output becomes "\n<ans>"
     instead of "<ans>". Many CodeChef checkers trim surrounding whitespace,
     which is likely why this still got AC — but on a strict diff it is a
     Wrong Answer. Fix: delete that line.
   * Integer overflow: N, M, X, Y and the products are `int`. If the
     constraints allow values where N*X or the total exceeds ~2.1e9, this
     overflows to garbage. At a 280 rating the bounds are almost certainly
     tiny, so it is safe here — but `long long` would be the defensive choice.
   * Zero counts/values are handled naturally (a term just contributes 0).
   * Negative inputs are not expected for this kind of problem.

 ----------------------------------------------------------------------------
 CLEANER VERSION (same O(1), removes the two flaws above)
 ----------------------------------------------------------------------------
     long long N, M, X, Y;
     cin >> N >> M >> X >> Y;
     cout << N*X + M*Y << "\n";   // no stray blank line, overflow-safe
 ============================================================================
*/

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int N, M, X, Y;

	cin >> N;

	cin >> M;

	cout << endl;

	cin >> X;

	cin >> Y;

	

	cout << (N*X) + (M*Y);

	return 0;



}
