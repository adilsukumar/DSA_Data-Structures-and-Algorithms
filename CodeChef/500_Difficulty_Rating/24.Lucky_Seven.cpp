/* ============================================================================
 * CodeChef - Lucky Seven                                        difficulty 213
 * ----------------------------------------------------------------------------
 * @platform   CodeChef
 * @id         LUCKYSEVEN
 * @title      Lucky Seven
 * @difficulty 213
 * @topics     Basic Programming, Strings, Implementation
 * @pattern    Direct String Indexing (0-based)
 * @url        https://www.codechef.com/problems/LUCKYSEVEN
 * @solved     2026-06-04
 * ----------------------------------------------------------------------------
 *
 * PROBLEM
 *   You are given a single string S. Print its 7th character (counting from 1).
 *   The input is guaranteed long enough that a 7th character exists.
 *     Example:  S = "codechef"  ->  positions 1..8 are c o d e c h e f
 *               the 7th character is 'e', so the answer is 'e'.
 *
 * INTUITION
 *   "The 7th character" is a fixed position, not something you have to search
 *   for. In C++ a std::string is a 0-indexed array of chars, so the k-th
 *   character (1-based) lives at index k-1. The 7th character is therefore
 *   S[6]. No loop, no scan, no counting — the position is known ahead of time,
 *   so a single indexed read is the whole solution. This works because the
 *   mapping between "human position 7" and "array index 6" is a constant
 *   off-by-one shift, and the problem promises the string is long enough that
 *   index 6 is always valid.
 *
 * WALKTHROUGH  (this code, line by line)
 *   - string S;              declare the input string.
 *   - cin >> S;              read one whitespace-delimited token into S. Note
 *                            that >> stops at the first space, so this reads a
 *                            single word — which matches how this problem feeds
 *                            input (one contiguous string, no embedded spaces).
 *   - cout << S[6];          S[6] is a char (the 7th character). Streaming a
 *                            char prints exactly that one character, with no
 *                            newline. That single char IS the required answer.
 *   - return 0;              normal termination.
 *
 *   Dry run on S = "codechef":
 *     index:  0   1   2   3   4   5   6   7
 *     char:  'c' 'o' 'd' 'e' 'c' 'h' 'e' 'f'
 *     cin >> S    -> S = "codechef"
 *     S[6]        -> 'e'          (index 6 = 7th character)
 *     cout << 'e' -> prints: e
 *   Output: e   ✓
 *
 * COMPLEXITY
 *   Time  : O(n) to read the string of length n (the indexed access itself is
 *           O(1)); the "work" after reading is a single constant-time lookup.
 *   Space : O(n) to store S. If only S[6] were needed you could read fewer
 *           chars, but storing the whole token is simplest and fine here.
 *
 * EDGE CASES
 *   - String shorter than 7 chars: S[6] would be out-of-bounds (undefined
 *     behavior — operator[] does NOT bounds-check). The code relies entirely
 *     on the problem's guarantee that a 7th character exists; it does not
 *     defend against a short string. Safe here given the constraints, but
 *     worth remembering: for untrusted input use S.at(6) to get a checked
 *     throw instead of silent UB.
 *   - Input with spaces: cin >> S reads only up to the first whitespace. For
 *     this problem the input is a single space-free token, so that's correct;
 *     if the "string" could contain spaces you'd need getline(cin, S) instead.
 *   - Trailing newline: none is printed, which is generally accepted by the
 *     judge for a single-character answer.
 *
 * This solution is already optimal for the task: it does the minimum work
 * (one read + one constant-time index) and there is no faster asymptotic or
 * practical approach. No improved version is warranted.
 * ==========================================================================*/

#include <bits/stdc++.h>

using namespace std;



int main() {

	// your code goes here

	string S;

	cin >> S;

	cout << S[6];

	return 0;



}
