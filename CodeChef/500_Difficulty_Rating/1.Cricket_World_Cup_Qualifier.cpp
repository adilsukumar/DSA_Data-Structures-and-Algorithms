/*
 * ─────────────────────────────────────────────────────────────────────────────
 *  CodeChef · Cricket World Cup Qualifier                        Rating ~500
 * ─────────────────────────────────────────────────────────────────────────────
 *  @platform   CodeChef
 *  @id         1
 *  @title      Cricket World Cup Qualifier
 *  @difficulty 500
 *  @topics     Implementation, Conditionals, Basic I/O
 *  @pattern    Single Threshold Comparison
 *  @url        https://www.codechef.com/practice
 * ─────────────────────────────────────────────────────────────────────────────
 *
 *  PROBLEM
 *  -------
 *  A team qualifies for the World Cup if it finishes the league stage with at
 *  least 12 points. Given the team's points X, print "YES" if they qualify and
 *  "NO" otherwise.
 *
 *      X = 14  ->  YES
 *      X = 12  ->  YES   (the boundary -- "at least" includes 12)
 *      X = 11  ->  NO
 *
 *  INTUITION
 *  ---------
 *  There is no algorithm here; the whole problem is translating one English
 *  sentence into one comparison. The only thing that can go wrong is the
 *  boundary: "at least 12" means >= 12, not > 12. Getting that backwards is the
 *  single most common way to fail a problem like this, and it is worth building
 *  the habit now of reading threshold wording carefully -- "at least", "at
 *  most", "more than" and "strictly less" all map to different operators.
 *
 *  WALKTHROUGH
 *  -----------
 *  #include <bits/stdc++.h>     // GCC-specific catch-all header. Convenient in
 *                               // competitive programming, but non-standard --
 *                               // it does not exist on MSVC or Clang/libc++.
 *  using namespace std;         // also standard CP practice; avoid both of
 *                               // these in production code.
 *
 *  int main() {
 *      int X;
 *      cin >> X;                // read the single integer from stdin
 *      if(X >= 12) cout << "YES";
 *      else        cout << "NO";
 *  }
 *
 *  Note this reads exactly ONE value with no test-case loop, so it is written
 *  for the single-input version of the problem. Many CodeChef problems begin
 *  with a count T of test cases instead -- see the pattern note below.
 *
 *  COMPLEXITY
 *  ----------
 *  Time : O(1)
 *  Space: O(1)
 *
 *  EDGE CASES
 *  ----------
 *  - X exactly 12 -> YES. This is the case the >= (rather than >) exists for.
 *  - X = 0 -> NO.
 *  - Output casing matters: CodeChef's checker for this problem accepts any
 *    case, but many problems do not. Matching the statement exactly costs
 *    nothing and avoids a needless Wrong Answer.
 *
 *  THE STANDARD CODECHEF TEMPLATE
 *  ------------------------------
 *  Most CodeChef problems wrap the logic in a test-case loop. The shape to have
 *  memorised, so it costs you no thinking time in a contest:
 *
 *      int main() {
 *          ios_base::sync_with_stdio(false);   // unhook C++ streams from C stdio
 *          cin.tie(NULL);                      // stop cin flushing cout each read
 *
 *          int T;
 *          cin >> T;
 *          while (T--) {
 *              int X;
 *              cin >> X;
 *              cout << (X >= 12 ? "YES" : "NO") << "\n";
 *          }
 *      }
 *
 *  The two lines at the top are the standard competitive-programming I/O speed-up
 *  and they matter: on problems with 10^5+ lines of input, unsynchronised streams
 *  are several times faster and are often the difference between Accepted and
 *  Time Limit Exceeded. Also prefer "\n" over endl -- endl forces a flush on
 *  every single line, which is the other classic CP timing trap.
 * ─────────────────────────────────────────────────────────────────────────────
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	int X;
	cin >> X;
	if(X >= 12){
	    cout << "YES";
	}
	else{
	    cout << "NO";
	}
	
}
