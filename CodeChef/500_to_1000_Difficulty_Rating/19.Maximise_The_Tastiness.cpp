/* ─────────────────────────────────────────────────────────────────────────
   CodeChef MAXTASTE - Maximise The Tastiness            Difficulty 627 (Easy)
   ─────────────────────────────────────────────────────────────────────────
   @platform   CodeChef
   @id         MAXTASTE
   @title      Maximise The Tastiness
   @difficulty 627
   @topics     Implementation, Basic Math
   @pattern    Max of each pair, summed
   @url        https://www.codechef.com/problems/MAXTASTE
   @solved     2026-07-19

   PROBLEM
     Chef must build one dish by choosing exactly one item from each of two
     shelves. The first shelf offers two items with tastiness A and B; the
     second offers two items with tastiness C and D. The dish's tastiness is
     the sum of the two chosen items. Maximise it.
     Answer per test = (better of A, B) + (better of C, D) = max(A,B) + max(C,D).

     Example: A=3 B=7 C=5 D=2  ->  max(3,7) + max(5,2) = 7 + 5 = 12.

   INTUITION
     The two choices are completely independent: which item you take from
     shelf 1 has no effect on shelf 2, and the total is just their sum. When
     two independent terms are added, each is maximised on its own — there is
     no trade-off to balance. So greedily take the larger of {A,B}, take the
     larger of {C,D}, and add them. No search over the 2x2 = 4 combinations is
     needed; the pairwise maxima already give the global optimum.

   WALKTHROUGH  (this code, line by line)
     - Read T, the number of test cases, then loop T times.
     - Each iteration reads A B C D into the same four ints (reused per test).
     - Outer branch on the first pair:
         if (A >= B)  -> the shelf-1 contribution is A
         else if (B >= A) -> the shelf-1 contribution is B
       These two conditions together cover every case (when A<B the second is
       always true), so the `else if` behaves as a plain `else`. Ties (A==B)
       fall into the first branch and correctly contribute A (== B).
     - Inside each branch, a nested if picks the shelf-2 contribution:
         if (C >= D) add C, else add D.
     - Print the sum with endl. Four leaf branches spell out the four
       (A-or-B) + (C-or-D) combinations explicitly instead of calling max().

     Dry run on T=1, A=3 B=7 C=5 D=2:
       A>=B ? 3>=7 -> false, so skip to `else if (B>=A)`: 7>=3 -> true.
         Now in the B-branch. C>=D ? 5>=2 -> true -> print B+C = 7+5 = 12.
       Output: 12   (correct)

     Dry run on ties, A=4 B=4 C=1 D=9:
       A>=B ? 4>=4 -> true, enter A-branch. C>=D ? 1>=9 -> false -> print A+D
       = 4+9 = 13. Correct (A and B are equal, so choosing A loses nothing).

   COMPLEXITY
     Time  : O(T) — a fixed amount of comparison/printing work per test case.
     Space : O(1) — four scalars reused across every test; no arrays.

   EDGE CASES
     - A == B (and/or C == D): handled. The first `>=` wins the tie and the
       equal value is added, which is correct since both options are equal.
     - The `else if (B >= A)` is logically redundant — a plain `else` would do,
       since A<B implies B>A. It is NOT a bug: no input reaches neither branch.
       Kept as-is it just reads as dead-conditional noise; a reviewer should
       know it can never fall through to "no output".
     - Negative tastiness: if the constraints ever allowed negatives, max()
       logic still holds (you still take the larger, e.g. -2 over -5), so the
       code stays correct — it never assumes positivity.
     - Large T: fine at O(T); the only real-world speed lever would be
       untying cin from stdout, not the algorithm.

   NOTE — already optimal, but simpler to write
     The four-way nested branching is correct and O(1) per test, so there is
     no faster approach. It can be collapsed to the intent in one line:

         cout << max(A, B) + max(C, D) << '\n';

     Same complexity, far less surface area for a copy-paste slip between the
     four leaves. (Using '\n' over endl also avoids a stream flush per test.)
   ───────────────────────────────────────────────────────────────────────── */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, A, B, C, D;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> A >> B >> C >> D;

	    if(A >= B){

	        if(C >= D){

	            cout << A+C << endl;

	        }

	        else{

	            cout << A+D << endl;

	        }

	    }

	    else if(B >= A){

	        if(C >= D){

	            cout << B+C << endl;

	        }

	        else{

	            cout << B+D << endl;

	        }

	    }

	}

	return 0;

}
