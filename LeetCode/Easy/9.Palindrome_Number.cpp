/*
 * ─────────────────────────────────────────────────────────────────────────────
 *  LeetCode 9 · Palindrome Number                                         Easy
 * ─────────────────────────────────────────────────────────────────────────────
 *  @platform   LeetCode
 *  @id         9
 *  @title      Palindrome Number
 *  @difficulty Easy
 *  @topics     Math
 *  @pattern    Digit Reversal
 *  @url        https://leetcode.com/problems/palindrome-number/
 * ─────────────────────────────────────────────────────────────────────────────
 *
 *  PROBLEM
 *  -------
 *  Return true if integer `x` reads the same forwards and backwards.
 *
 *      121   -> true
 *      -121  -> false   (reads "121-" backwards)
 *      10    -> false   (reads "01" backwards)
 *
 *  The follow-up asks you to do it WITHOUT converting the number to a string.
 *  This solution honours that follow-up.
 *
 *  INTUITION
 *  ---------
 *  A number is a palindrome exactly when reversing its digits gives you the same
 *  number back. So: build the reverse arithmetically, then compare.
 *
 *  Reversing digits without strings rests on two operations:
 *      x % 10   peels off the LAST digit          (1234 % 10 == 4)
 *      x / 10   removes the last digit (int div)  (1234 / 10 == 123)
 *
 *  So we can repeatedly pull digits off the back of x and push them onto the
 *  back of a new number `rev`. Pushing onto the back means "shift everything
 *  left one place, then add" -- which is exactly `rev * 10 + digit`.
 *
 *  WALKTHROUGH
 *  -----------
 *  if (x < 0) return false;
 *      Negatives are never palindromes: the minus sign is only on the front.
 *      This guard also spares the loop from dealing with negative remainders,
 *      which in C++ are themselves negative (-121 % 10 == -1).
 *
 *  int original = x;
 *      The loop DESTROYS x by dividing it down to 0, so we must save a copy to
 *      compare against at the end. Forgetting this is the classic bug here.
 *
 *  long long rev = 0;
 *      See EDGE CASES -- this type choice is the important one.
 *
 *  while (x != 0) {
 *      rev = rev * 10 + x % 10;   // shift rev left, append x's last digit
 *      x = x / 10;                // drop that digit from x
 *  }
 *
 *  Dry run on x = 121:
 *      start        x = 121   rev = 0
 *      iteration 1  rev = 0*10   + 1 = 1      x = 12
 *      iteration 2  rev = 1*10   + 2 = 12     x = 1
 *      iteration 3  rev = 12*10  + 1 = 121    x = 0   -> loop ends
 *      original (121) == rev (121)  ->  true   ✔
 *
 *  Dry run on x = 10:
 *      iteration 1  rev = 0*10 + 0 = 0        x = 1
 *      iteration 2  rev = 0*10 + 1 = 1        x = 0
 *      original (10) == rev (1)     ->  false  ✔
 *      Leading zeros vanish during reversal, which is precisely why 10 is
 *      correctly rejected. Any number ending in 0 (other than 0 itself) fails
 *      for this reason -- and it should.
 *
 *  COMPLEXITY
 *  ----------
 *  Time : O(log10 x)  -- one iteration per digit, so ~10 iterations at 32-bit max.
 *  Space: O(1)        -- three scalars, no array or string allocated.
 *
 *  EDGE CASES
 *  ----------
 *  - x = 0        -> loop body never runs, rev stays 0, 0 == 0 -> true. Correct.
 *  - Any negative -> caught by the early return.
 *  - OVERFLOW: this is why `rev` is `long long` and not `int`. The reverse of a
 *    valid int can exceed INT_MAX (2147483647). For example x = 1999999999
 *    reverses to 9999999991, which overflows a 32-bit int -- and signed integer
 *    overflow in C++ is undefined behaviour, not a wrap-around you can rely on.
 *    Widening to long long sidesteps it entirely. Good instinct.
 *
 *  ALTERNATIVE -- reverse only half the digits
 *  -------------------------------------------
 *  You can avoid the overflow concern altogether by building the reverse of just
 *  the back half and stopping when it meets the front half:
 *
 *      if (x < 0 || (x % 10 == 0 && x != 0)) return false;
 *      int half = 0;
 *      while (x > half) { half = half * 10 + x % 10; x /= 10; }
 *      return x == half || x == half / 10;   // second case: odd digit count
 *
 *  The `half / 10` discards the middle digit, which belongs to neither side.
 *  Same O(log n) time, but half the iterations and no wide type needed.
 * ─────────────────────────────────────────────────────────────────────────────
 */

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        int original = x;
        long long rev = 0;

        while (x != 0) {
            rev = rev * 10 + x % 10;
            x = x / 10;
        }

        return original == rev;
    }
};
