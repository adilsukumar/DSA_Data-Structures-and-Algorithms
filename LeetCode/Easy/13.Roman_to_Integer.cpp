/*
 * ─────────────────────────────────────────────────────────────────────────────
 *  LeetCode 13 · Roman to Integer                                         Easy
 * ─────────────────────────────────────────────────────────────────────────────
 *  @platform   LeetCode
 *  @id         13
 *  @title      Roman to Integer
 *  @difficulty Easy
 *  @topics     Hash Table, Math, String
 *  @pattern    Explicit Subtractive-Pair Casework
 *  @url        https://leetcode.com/problems/roman-to-integer/
 * ─────────────────────────────────────────────────────────────────────────────
 *
 *  PROBLEM
 *  -------
 *  Convert a Roman numeral string to an integer.
 *
 *      I=1  V=5  X=10  L=50  C=100  D=500  M=1000
 *
 *  Roman numerals are normally written largest-to-smallest and simply added up
 *  (XXVII = 10+10+5+1+1 = 27). The wrinkle is SUBTRACTIVE notation: to avoid
 *  four repeated symbols, a smaller numeral placed BEFORE a larger one is
 *  subtracted. There are exactly six such pairs and no others:
 *
 *      IV = 4     IX = 9        (I before V or X)
 *      XL = 40    XC = 90       (X before L or C)
 *      CD = 400   CM = 900      (C before D or M)
 *
 *  INTUITION
 *  ---------
 *  Since there are only six special pairs, you can handle them head-on: walk the
 *  string left to right, and at each position first ask "do I and my neighbour
 *  form one of the six pairs?". If yes, add the pair's combined value and skip
 *  BOTH characters. If no, this character stands alone -- add its plain value
 *  and move on by one.
 *
 *  This is casework rather than cleverness, but it is easy to reason about and
 *  hard to get subtly wrong, which counts for something.
 *
 *  WALKTHROUGH
 *  -----------
 *  The if/else-if chain is ordered deliberately, and the order is load-bearing:
 *  all six TWO-character pairs are tested BEFORE any single character. If the
 *  single-character cases came first, `s[i] == 'I'` would match the "I" in "IV"
 *  and add 1 instead of 4.
 *
 *      if (s[i] == 'I' && s[i+1] == 'V') { sum += 4; i++; }   // pair -> +4
 *      ...
 *      else if (s[i] == 'I')             { sum += 1;        } // solo -> +1
 *
 *  The `i++` inside a pair branch is the key line. Combined with the loop's own
 *  `i++`, it advances TWO positions, consuming both characters of the pair so
 *  the second one is never counted a second time.
 *
 *  Dry run on "MCMXCIV" (= 1994):
 *      i=0  'M'          solo    sum = 1000
 *      i=1  'C','M'      pair    sum = 1900   i jumps to 3
 *      i=3  'X','C'      pair    sum = 1990   i jumps to 5
 *      i=5  'I','V'      pair    sum = 1994   i jumps to 7 -> loop ends
 *      return 1994   ✔
 *
 *  COMPLEXITY
 *  ----------
 *  Time : O(n)  -- each character is visited once; the if-chain is O(1) since it
 *                  is a fixed 13 comparisons, independent of input size.
 *  Space: O(1)  -- a handful of int variables, nothing that grows with n.
 *
 *  EDGE CASES
 *  ----------
 *  - READING s[i+1] AT THE LAST CHARACTER: this looks like an out-of-bounds read
 *    but is actually safe. Since C++11, `std::string::operator[](size())` is
 *    defined and returns a reference to a null character '\0'. So on the final
 *    character, `s[i+1]` yields '\0', every pair test fails, and the code
 *    correctly falls through to the solo branch. This would be genuine UB on a
 *    raw `char[]` or a `std::vector<char>` -- it is a guarantee specific to
 *    std::string. Worth knowing exactly why it is safe rather than assuming.
 *  - Single character "V" -> solo branch -> 5.
 *  - Repeated symbols "III" -> three solo hits -> 3.
 *
 *  ⚠ DEAD CODE
 *  -----------
 *  The variables I, V, X, L, C, D, M are declared and assigned but never read --
 *  every branch uses a hard-coded literal instead. They can be deleted with no
 *  change in behaviour. Also, `int sum, I, V, ...;` declares sum uninitialised
 *  and only sets it on the next line; prefer `int sum = 0;` so the variable is
 *  never briefly holding garbage.
 *
 *  ALTERNATIVE -- the "look right" trick, no casework
 *  --------------------------------------------------
 *  There is a neat reformulation that collapses all six special cases into one
 *  rule: a numeral is SUBTRACTED if the numeral to its right is larger than it,
 *  otherwise it is added.
 *
 *      int romanToInt(string s) {
 *          unordered_map<char,int> val = {{'I',1},{'V',5},{'X',10},{'L',50},
 *                                         {'C',100},{'D',500},{'M',1000}};
 *          int sum = 0;
 *          for (int i = 0; i < s.size(); i++) {
 *              if (i + 1 < s.size() && val[s[i]] < val[s[i+1]]) sum -= val[s[i]];
 *              else                                            sum += val[s[i]];
 *          }
 *          return sum;
 *      }
 *
 *  On "MCMXCIV": +1000 -100 +1000 -10 +100 -1 +5 = 1994. Same O(n) time, but ~10
 *  lines instead of ~45, and it cannot miss a pair because it never enumerates
 *  them. Recognising "the six exceptions all share one property" is the actual
 *  insight the problem is testing.
 * ─────────────────────────────────────────────────────────────────────────────
 */

class Solution {
public:
    int romanToInt(string s) {
        int sum, I, V, X, L, C, D, M;
        sum = 0;
        I = 1;
        V = 5;
        X = 10;
        L = 50;
        C = 100;
        D = 500;
        M = 1000;

        for(int i = 0; i < s.size(); i++) {
            if (s[i] == 'I' && s[i+1] == 'V') {
                sum += 4;
                i++;
            }
            else if (s[i] == 'I' && s[i+1] == 'X') {
                sum += 9;
                i++;
            }
            else if (s[i] == 'X' && s[i+1] == 'L') {
                sum += 40;
                i++;
            }
            else if (s[i] == 'X' && s[i+1] == 'C') {
                sum += 90;
                i++;
            }
            else if (s[i] == 'C' && s[i+1] == 'D') {
                sum += 400;
                i++;
            }
            else if (s[i] == 'C' && s[i+1] == 'M') {
                sum += 900;
                i++;
            }
            else if (s[i] == 'I') {
                sum += 1;
            }
            else if (s[i] == 'V') {
                sum += 5;
            }
            else if (s[i] == 'X') {
                sum += 10;
            }
            else if (s[i] == 'L') {
                sum += 50;
            }
            else if (s[i] == 'C') {
                sum += 100;
            }
            else if (s[i] == 'D') {
                sum += 500;
            }
            else if (s[i] == 'M') {
                sum += 1000;
            }
        }
        return sum;
    }
};
