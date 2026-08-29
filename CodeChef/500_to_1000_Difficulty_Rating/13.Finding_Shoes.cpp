/*
 ============================================================================
  CodeChef FINDSHOES - Finding Shoes          Difficulty: 646 (Beginner)
 ============================================================================
  @platform   CodeChef
  @id         FINDSHOES
  @title      Finding Shoes
  @difficulty 646
  @topics     Arithmetic, Inbuilt Functions
  @pattern    Closed-form arithmetic per query
  @url        https://www.codechef.com/problems/FINDSHOES
  @solved     2026-07-25

 ----------------------------------------------------------------------------
  PROBLEM
 ----------------------------------------------------------------------------
  T independent test cases. Each gives two integers N and M, and the answer
  is a single closed-form value that depends on how N compares to M.

  NOTE TO FUTURE-ME: I could not re-verify the exact narrative wording of the
  statement while writing this header (page fetch was unavailable). What is
  100% certain is the arithmetic this accepted code computes, described below.
  If you revisit, map the story's quantities onto N and M using it.

  The value produced per test case is:

        answer = max(N, 2*N - M)   which equals   N + max(0, N - M)

  Worked examples:
     N=5, M=3  (N >= M) -> N-M+N = 2 + 5 = 7   (= 2*5 - 3)
     N=4, M=9  (N <  M) -> N     = 4
     N=6, M=6  (N == M) -> N-M+N = 0 + 6 = 6   (= N, boundary is consistent)

 ----------------------------------------------------------------------------
  INTUITION
 ----------------------------------------------------------------------------
  There is nothing to search or iterate over: each query is a single number
  decided by one comparison. The key observation is that the two printed
  formulas are one function in disguise.

    * When N >= M, the surplus (N - M) is non-negative, so you add it on top
      of N, giving N + (N - M) = 2N - M.
    * When N < M, the surplus would be negative, so you clamp it to 0 and the
      answer is just N.

  Folding both cases together: answer = N + max(0, N - M). This is exactly why
  the topic tag mentions "Inbuilt functions" - the model solution is meant to
  be one line using max(), and the if/else here is the hand-rolled equivalent.
  Recognizing that the branch is just a clamp is the whole lesson.

 ----------------------------------------------------------------------------
  WALKTHROUGH (this code, line by line)
 ----------------------------------------------------------------------------
    cin >> T;                    read the number of test cases
    for i in 0..T-1:             one iteration per test case
      cin >> N >> M;             read the pair
      if (N >= M)                surplus branch
        cout << N-M + N;         prints (N-M)+N == 2N-M   (see PRECEDENCE note)
      else                       deficit branch
        cout << N;               prints N unchanged
      endl                       flush + newline after each answer

  PRECEDENCE note: `N-M + N` parses as `(N - M) + N`; binary + and - have the
  same precedence and associate left-to-right, so it is unambiguous here.

  Dry run on T=3 with (5,3), (4,9), (6,6):
     read T=3
     iter0: N=5 M=3 -> 5>=3 true  -> print (5-3)+5 = 7
     iter1: N=4 M=9 -> 4>=9 false -> print 4
     iter2: N=6 M=6 -> 6>=6 true  -> print (6-6)+6 = 6
  Output lines: 7 / 4 / 6

 ----------------------------------------------------------------------------
  COMPLEXITY
 ----------------------------------------------------------------------------
  Time  : O(T) overall, O(1) per test case - a comparison and a subtraction,
          no loop over the values themselves.
  Space : O(1) - three int variables reused across all test cases.

 ----------------------------------------------------------------------------
  EDGE CASES
 ----------------------------------------------------------------------------
  * N == M : handled correctly. Enters the `>=` branch and prints 2N-M = N,
    the same value the else branch would give, so no off-by-one at the seam.
  * N <  M : the clamp; prints N and never produces a negative number.
  * OVERFLOW (the one genuine risk): N and M are `int`. The `>=` branch
    evaluates 2N-M in int arithmetic. If the constraints allow N near 1e9,
    then 2N exceeds INT_MAX (~2.147e9) and this silently overflows to garbage.
    Verify the real bound: if N can exceed ~1e9, switch N/M/the expression to
    `long long`. For small constraints (<= ~1e6) the current code is safe.
  * endl flushes every iteration; for very large T prefer "\n" to avoid the
    flush cost (not a correctness issue, just throughput).

 ----------------------------------------------------------------------------
  CLEANER / SAFER VERSION (same logic, overflow-proof, uses the inbuilt fn)
 ----------------------------------------------------------------------------
  The algorithm is already optimal (O(1) per query). This is only a style /
  safety tightening that also matches the intended "Inbuilt functions" tag:

      int T;  cin >> T;
      while (T--) {
          long long N, M;  cin >> N >> M;
          cout << max(N, 2*N - M) << '\n';   // == N + max(0LL, N - M)
      }
 ============================================================================
*/

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int T, N, M;

	cin >> T;

	

	for(int i = 0; i < T; i++){

	    cin >> N >> M;

	    if(N >= M){

	        cout << N-M + N << endl;

	    }

	    else{

	        cout << N << endl;

	    }

	}

	return 0;

}
