/*
 * ============================================================================
 * CodeChef MOVIE2X - Watching Movies At 2x                    Difficulty: 628
 * ============================================================================
 *
 * @platform   CodeChef
 * @id         MOVIE2X
 * @title      Watching Movies At 2x
 * @difficulty 628
 * @topics     Math, Implementation
 * @pattern    Constant-time arithmetic formula
 * @url        https://www.codechef.com/problems/MOVIE2X
 * @solved     2026-07-19
 *
 * ----------------------------------------------------------------------------
 * PROBLEM
 * ----------------------------------------------------------------------------
 * A movie is X minutes long. Chef watches Y of those minutes at 2x speed and
 * the remaining (X - Y) minutes at normal 1x speed. Report how many minutes of
 * real (wall-clock) time it takes him to finish the movie.
 *
 * The constraints guarantee 0 <= Y <= X and Y is EVEN, so Y minutes of content
 * at 2x always consumes a whole number of real minutes.
 *
 * Worked example: X = 100, Y = 40.
 *   40 min of content at 2x  ->  40 / 2 = 20 real minutes
 *   60 min of content at 1x  ->  60      = 60 real minutes
 *   Total real time = 80 minutes.
 *
 * ----------------------------------------------------------------------------
 * INTUITION
 * ----------------------------------------------------------------------------
 * "Speed" scales content-per-minute, so real time = content / speed.
 *   - The (X - Y) minutes at 1x cost (X - Y) real minutes (speed 1).
 *   - The Y minutes at 2x cost Y / 2 real minutes (twice the content per
 *     real minute, so half the time).
 * Sum the two independent segments. There is no interaction between them, so a
 * single closed-form expression answers the whole problem -- no loop, no state.
 * WHY it works: real time is additive over disjoint chunks of the movie, and
 * each chunk's real time is just its content length divided by its play speed.
 *
 * ----------------------------------------------------------------------------
 * WALKTHROUGH (this code, line by line)
 * ----------------------------------------------------------------------------
 *   int X, Y;                 // X = movie length, Y = minutes watched at 2x
 *   cin >> X >> Y;            // read both from a single line of input
 *   cout << (X-Y) + (Y/2);   // 1x-segment time + 2x-segment time, printed raw
 *
 * The expression is evaluated in one shot:
 *   (X - Y)  = real minutes for the normal-speed part
 *   (Y / 2)  = real minutes for the double-speed part  (integer division)
 * Their sum is the answer. Note the output has NO trailing newline -- harmless
 * for a single test case here, but worth remembering if this were adapted to a
 * multi-test loop where each answer needs its own line.
 *
 * Dry run on X = 100, Y = 40:
 *   read       -> X = 100, Y = 40
 *   X - Y      -> 60
 *   Y / 2      -> 20
 *   60 + 20    -> 80   ---> prints "80"
 *
 * Second dry run on X = 30, Y = 30 (whole movie at 2x):
 *   X - Y = 0,  Y / 2 = 15,  sum = 15  ---> prints "15"
 *
 * ----------------------------------------------------------------------------
 * COMPLEXITY
 * ----------------------------------------------------------------------------
 * Time  : O(1) -- two reads and a fixed arithmetic expression, no loops.
 * Space : O(1) -- two int variables, no auxiliary structures.
 *
 * ----------------------------------------------------------------------------
 * EDGE CASES
 * ----------------------------------------------------------------------------
 * - Y = 0        : nothing sped up, answer = X. Handled: (X-0)+(0/2) = X.
 * - Y = X        : entire movie at 2x, answer = X/2. Handled as shown above.
 * - Odd Y        : Y/2 truncates toward zero (e.g. Y=5 -> 2, losing 0.5 min).
 *                  The code relies on the problem's guarantee that Y is even;
 *                  it does NOT round and would be off-by-a-half if that promise
 *                  were broken. Safe here only because the constraint holds.
 * - Y > X        : would make (X-Y) negative and give a nonsensical answer, but
 *                  constraints forbid it, so no guard is needed.
 * - Overflow     : X, Y are small (<= a few hundred), well within int range.
 *
 * This solution is already optimal -- O(1) time and space with the minimal
 * arithmetic the problem allows. No better approach exists.
 */

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	int X, Y;

	cin >> X >> Y;

	cout << (X-Y) + (Y/2);

    return 0;

}
