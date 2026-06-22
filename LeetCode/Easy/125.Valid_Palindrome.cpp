/* ============================================================================
 * LeetCode 125 - Valid Palindrome                                    [Easy]
 * ============================================================================
 * @platform   LeetCode
 * @id         125
 * @title      Valid Palindrome
 * @difficulty Easy
 * @topics     Two Pointers, String
 * @pattern    Converging Two Pointers
 * @url        https://leetcode.com/problems/valid-palindrome/
 * @solved     2026-06-22
 *
 * PROBLEM
 *   A string is a valid palindrome if, after (a) dropping every character that
 *   is not a letter or digit and (b) lowercasing the rest, it reads the same
 *   forwards and backwards.
 *     "A man, a plan, a canal: Panama" -> "amanaplanacanalpanama" -> true
 *     "race a car"                     -> "raceacar"              -> false
 *     ""                               -> ""                      -> true
 *
 * INTUITION
 *   You don't need to build the cleaned string at all. A palindrome is defined
 *   by symmetry around the center, so compare the string from both ends inward.
 *   Walk one pointer in from the left and one in from the right; whenever they
 *   land on a character that "doesn't count" (punctuation/space), skip it. The
 *   first mismatched pair of real characters proves it is NOT a palindrome; if
 *   the pointers cross without ever mismatching, every mirrored pair agreed, so
 *   it IS one. Skipping junk in place is what lets us avoid the extra string.
 *
 * WALKTHROUGH (this code)
 *   - left = 0, right = s.length()-1: the two ends of the string.
 *       NB: length() is unsigned; for "" it wraps to SIZE_MAX, but assigning it
 *       into the int `right` yields -1, so the outer loop is simply skipped and
 *       we correctly return true. (Fine here, but a subtle spot worth knowing.)
 *   - Outer `while(left < right)`: keep going until the pointers meet/cross.
 *   - Inner `while(... && !isalnum(s[left])) left++`: advance left past any
 *       non-alphanumeric char. The `left < right` guard inside stops us from
 *       running off the end when the tail is all punctuation.
 *   - The symmetric inner loop pulls `right` inward past junk.
 *   - `tolower(s[left]) != tolower(s[right])`: now both pointers sit on real
 *       characters; compare case-insensitively. Mismatch => return false early.
 *   - Otherwise this pair matched: step both inward (left++, right--) and repeat.
 *   - Fall out of the loop with no mismatch => return true.
 *
 *   DRY RUN on  s = "0P"  (expected: false; '0' vs 'p')
 *     left=0 ('0'), right=1 ('P'). Both already alnum, no skipping.
 *       tolower('0')='0', tolower('P')='p'. '0' != 'p' -> return false.  ✓
 *
 *   DRY RUN on  s = "a,a"
 *     left=0('a'), right=2('a'): match -> left=1, right=1.
 *     Outer test left<right is 1<1 = false -> return true.  ✓
 *     (The middle ',' is never even examined - it's on/inside the meeting point.)
 *
 * COMPLEXITY
 *   Time  O(n): each pointer moves strictly inward and they never overlap work,
 *               so every index is visited at most once across all loops.
 *   Space O(1): only two integer indices; the input is inspected in place.
 *
 * EDGE CASES
 *   - Empty string: outer loop never runs (see the length()-1 note) -> true.
 *   - All non-alphanumeric ("!!!"): inner loops skip everything, pointers cross,
 *       returns true (the cleaned string is empty, which is a palindrome).
 *   - Single real char surrounded by junk (".a."): pointers converge on 'a'
 *       with left==right, loop exits -> true.
 *   - Digits count as valid characters (isalnum), matching the problem spec.
 *   - Caution: isalnum/tolower from <cctype> have undefined behavior on values
 *       not representable as unsigned char (i.e. negative chars from non-ASCII
 *       bytes). Inputs here are plain ASCII so it's safe, but for arbitrary
 *       bytes you'd cast: isalnum((unsigned char)s[left]).
 *
 * This is already the optimal approach (O(n) time, O(1) space); no better
 * strategy applies.
 * ============================================================================
 */

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        while(left < right){
            while(left < right && !isalnum(s[left])){
                left++;
            }
            while(left < right && !isalnum(s[right])){
                right--;
            }
            if(tolower(s[left]) != tolower(s[right])){
                return false;
            }
            left++;
            right--;
        }
        return true;

    }
};
