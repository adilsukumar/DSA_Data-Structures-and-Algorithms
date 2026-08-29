/*
 ============================================================================
 CodeChef MINCARS - Minimum Cars Required                    Difficulty: 608
 ============================================================================
 @platform   CodeChef
 @id         MINCARS
 @title      Minimum Cars Required
 @difficulty 608
 @topics     Math, Implementation
 @pattern    Ceiling Division (group into 4s)
 @url        https://www.codechef.com/problems/MINCARS
 @solved     2026-06-30

 PROBLEM
 -------
 There are N people who all need to travel. A single car seats at most 4
 people. Print the minimum number of cars needed to carry everyone.
 Repeat for T independent test cases.

   Example: N = 10  ->  3 cars  (4 + 4 + 2; two cars can't fit 10 people)
            N = 8   ->  2 cars  (4 + 4, exactly full)
            N = 4   ->  1 car
            N = 5   ->  2 cars  (a 5th person forces a second car)

 INTUITION
 ---------
 This is the classic "how many buckets do I need" question. With a fixed
 capacity of 4 per car, the answer is N divided by 4, rounded UP -- because
 any leftover people (a remainder of 1..3) still require one more, only
 partially-filled, car. Rounding up is exactly the ceiling function, so the
 answer is ceil(N / 4). That is why plain integer division (which rounds
 DOWN) would be wrong: it would drop the final partial car.

 WALKTHROUGH
 -----------
 - cin >> T;            read the number of test cases.
 - loop i = 0..T-1:     process each test case independently.
     - cin >> N;        read this case's passenger count.
     - if (N <= 4)      shortcut: print 1.
     - else             print ceil(N / 4.0).
 - Note the /4.0 (not /4): forcing floating-point division is what lets
   ceil() see the fractional part. If it were N/4 (integer), the division
   would already truncate to a whole number and ceil() would be a no-op --
   a common bug this code avoids.

 Dry run on N = 10 (the else branch):
     N / 4.0      = 2.5
     ceil(2.5)    = 3.0
     printed as   -> 3          correct.

 Dry run on N = 8:
     8 / 4.0      = 2.0
     ceil(2.0)    = 2.0         -> 2   (exact multiple, no rounding).

 Dry run on N = 3 (the if branch):
     N <= 4 is true -> prints 1 directly (never reaches ceil).

 COMPLEXITY
 ----------
 Time:  O(T)   -- constant work per test case, one arithmetic op each.
 Space: O(1)   -- only a few scalars; nothing scales with N or T.

 EDGE CASES
 ----------
 - N a multiple of 4 (4, 8, 12, ...): ceil returns the exact quotient, no
   phantom extra car. Handled correctly.
 - N in 1..4: handled by the explicit shortcut -> 1.
 - Remainder 1..3 (e.g. 5, 9): ceil bumps up by one car. Handled.
 - Large N: see the note below -- ceil() on a double can, in principle,
   misround once N grows large enough that N/4.0 is no longer exactly
   representable. For MINCARS's small constraints this never triggers, but
   it is a latent weakness.

 DEAD CODE / REDUNDANCY (honest note)
 ------------------------------------
 The `if (N <= 4) print 1` branch is REDUNDANT. For every N in 1..4,
 ceil(N/4.0) already equals 1, so the else branch alone would produce the
 same output. The special case adds nothing except (very slightly) guarding
 the N == 0 case, which the constraints make impossible anyway. It is
 harmless but not needed.

 A CLEANER / SAFER APPROACH
 --------------------------
 Prefer INTEGER ceiling division over floating-point ceil() -- it is exact
 at all magnitudes (no double-precision rounding risk) and removes the
 redundant branch entirely:

     int N; cin >> N;
     cout << (N + 3) / 4 << "\n";   // ceil(N/4) with pure integer math

 (N + 3) / 4 rounds up because adding 3 pushes any nonzero remainder past
 the next multiple of 4 before the truncating division. This is the
 idiomatic, fully optimal form; the current code is already O(1) but leans
 on floats and dead code that this version avoids.
*/

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, N;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> N;

	    if(N <= 4){

	        cout << 1 << endl;

	    }

	    else{

	        cout << ceil(N/4.0) << endl;

	    }

	}



}
