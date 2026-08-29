/*
 * ============================================================================
 *  CodeChef NOTEBOOK - Count The Notebooks            Difficulty: 563 (Easy)
 * ============================================================================
 *  @platform   CodeChef
 *  @id         NOTEBOOK
 *  @title      Count The Notebooks
 *  @difficulty 563
 *  @topics     Basic Math, Implementation
 *  @pattern    Direct closed-form formula (10*N)
 *  @url        https://www.codechef.com/problems/NOTEBOOK
 *  @solved     2026-06-17
 *
 * ----------------------------------------------------------------------------
 *  PROBLEM
 * ----------------------------------------------------------------------------
 *  For each of T independent test cases you are given one integer N. The
 *  quantity of interest scales as N thousand of some unit (N * 1000), and each
 *  notebook accounts for 100 of that unit, so the answer is how many notebooks
 *  that comes to: (N * 1000) / 100.
 *
 *  Because (N * 1000) is always an exact multiple of 100, this is simply:
 *
 *        answer = 10 * N
 *
 *  Worked example:  N = 5  ->  5 * 1000 = 5000  ->  5000 / 100 = 50.
 *                   N = 3  ->  3 * 1000 = 3000  ->  3000 / 100 = 30.
 *
 * ----------------------------------------------------------------------------
 *  INTUITION
 * ----------------------------------------------------------------------------
 *  There is nothing to search or iterate: the output is a fixed linear
 *  function of the input. The only "idea" is recognizing the arithmetic
 *  collapses to a single multiplication. The code keeps the *1000 then /100
 *  form (probably to mirror the problem's wording of "thousands" and "per 100
 *  notebook"), but algebraically 1000/100 = 10, so each answer is just N*10.
 *  It works because integer division here is exact -- 1000 is divisible by 100,
 *  so no remainder is ever lost regardless of N.
 *
 * ----------------------------------------------------------------------------
 *  WALKTHROUGH (this code, line by line)
 * ----------------------------------------------------------------------------
 *    cin >> T;                 // number of test cases
 *    for i in 0..T-1:
 *        cin >> N;             // read this case's value
 *        a = N * 1000;         // scale up
 *        cout << a/100 << endl;// scale back down by 100  ==  print 10*N
 *
 *  Note: `a` is reused each iteration; it is fully overwritten by `N * 1000`
 *  before it is read, so no stale state leaks between test cases. The `i`
 *  loop variable is only a counter -- its value is never used in the math.
 *
 *  Dry run on T=2, N=[5, 3]:
 *      iter 0: N=5 -> a = 5000 -> print 5000/100 = 50
 *      iter 1: N=3 -> a = 3000 -> print 3000/100 = 30
 *  Output:
 *      50
 *      30
 *
 * ----------------------------------------------------------------------------
 *  COMPLEXITY
 * ----------------------------------------------------------------------------
 *  Time  : O(T)  -- one read and one O(1) arithmetic step per test case.
 *  Space : O(1)  -- only the scalars T, N, a, i; nothing scales with input.
 *
 * ----------------------------------------------------------------------------
 *  EDGE CASES / CORRECTNESS NOTES
 * ----------------------------------------------------------------------------
 *  - Exact division: (N*1000) is always a multiple of 100, so a/100 never
 *    truncates away a real value. The intermediate *1000 is therefore harmless
 *    to correctness (just not necessary).
 *  - N = 0 -> prints 0, which is the correct degenerate answer.
 *  - INTEGER OVERFLOW is the one genuine risk. `a` is an `int`; N*1000 exceeds
 *    the 32-bit signed range (~2.147e9) once N > ~2,147,483. If the real
 *    constraints keep N small (typical for a 563-rated problem, e.g. N <= 1e6),
 *    this is fine. But the *1000-then-/100 detour makes overflow possible where
 *    computing N*10 directly would survive 10x larger inputs. Prefer `long long`
 *    (or just `N*10`) if constraints are ever unclear.
 *  - `endl` flushes every line; for large T, "\n" is faster, though at these
 *    sizes it does not matter.
 *
 * ----------------------------------------------------------------------------
 *  OPTIMAL / CLEANER APPROACH
 * ----------------------------------------------------------------------------
 *  Already optimal in time and space (O(T), O(1)); the only improvement is
 *  removing the unnecessary scale-up so overflow headroom is 10x larger and the
 *  intent is obvious:
 *
 *      int T; cin >> T;
 *      while (T--) {
 *          long long N; cin >> N;      // long long is cheap insurance
 *          cout << N * 10 << '\n';     // 1000/100 == 10, done in one step
 *      }
 *
 *  Same answers, no throwaway intermediate, no 32-bit overflow cliff.
 * ============================================================================
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, N, a;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> N;

	    a = N * 1000;

	    cout << a/100 << endl;

	}

	return 0;

}
