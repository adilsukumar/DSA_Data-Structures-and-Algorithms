/*
 * ─────────────────────────────────────────────────────────────────────────────
 *  LeetCode 20 · Valid Parentheses                                        Easy
 * ─────────────────────────────────────────────────────────────────────────────
 *  @platform   LeetCode
 *  @id         20
 *  @title      Valid Parentheses
 *  @difficulty Easy
 *  @topics     Stack, String, Hash Table
 *  @pattern    Stack Matching (LIFO)
 *  @url        https://leetcode.com/problems/valid-parentheses/
 *  @solved     2026-06-08
 * ─────────────────────────────────────────────────────────────────────────────
 *
 *  PROBLEM
 *  -------
 *  Given a string of only ()[]{}, decide whether the brackets are valid. Valid
 *  means every opener is closed by the matching type, and closed in the correct
 *  order (properly nested).
 *
 *      "()[]{}"  -> true
 *      "(]"      -> false   (wrong type)
 *      "([)]"    -> false   (wrongly nested -- crossed, not contained)
 *      "{[]}"    -> true    (properly nested)
 *
 *  INTUITION
 *  ---------
 *  This is THE textbook stack problem, and the reason is worth stating plainly:
 *
 *      When you meet a closing bracket, the only opener it is allowed to match
 *      is the MOST RECENT unmatched opener.
 *
 *  "Most recent first" is precisely Last-In-First-Out, which is the definition
 *  of a stack. So: push every opener; on every closer, pop and check the pair.
 *
 *  This is also exactly why "([)]" must fail. When we reach ')', the most recent
 *  unmatched opener is '[', not '('. Brackets must nest like Russian dolls --
 *  fully contained -- never cross. A counter would not catch this; you genuinely
 *  need the stack to remember the ORDER, not just the counts.
 *
 *  WALKTHROUGH
 *  -----------
 *  stack<char> st;                       // unmatched openers, newest on top
 *
 *  unordered_map<char, char> mp = {      // opener -> the closer it expects
 *      {'(', ')'}, {'[', ']'}, {'{', '}'}
 *  };
 *
 *  for(char c : s) {
 *      if (c is an opener)  st.push(c);  // defer it; we cannot judge it yet
 *
 *      else {                            // c is a closer, so judge it now
 *          if (st.empty()) return false;         // closer with nothing open
 *          else if (c == mp[st.top()]) st.pop();  // correct match -> consume
 *          else return false;                     // type mismatch
 *      }
 *  }
 *
 *  return st.empty();                    // leftover openers were never closed
 *
 *  The map lookup `mp[st.top()]` reads as: "take the newest unmatched opener,
 *  ask what closer it is waiting for, and check that c is that closer." Using a
 *  map here instead of three nested if-statements is what keeps the loop short.
 *
 *  Dry run on "{[]}":
 *      '{'  opener  -> push          st = [ { ]
 *      '['  opener  -> push          st = [ {, [ ]
 *      ']'  closer  -> top is '[', mp['['] == ']' ✓ -> pop    st = [ { ]
 *      '}'  closer  -> top is '{', mp['{'] == '}' ✓ -> pop    st = [ ]
 *      loop ends, st.empty() -> true   ✔
 *
 *  Dry run on "([)]":
 *      '('  push                     st = [ ( ]
 *      '['  push                     st = [ (, [ ]
 *      ')'  closer  -> top is '[', mp['['] == ']' != ')'  -> return false  ✔
 *
 *  THE THREE WAYS A STRING CAN FAIL
 *  --------------------------------
 *  It is worth noticing the code has exactly one check for each failure mode --
 *  that is what makes it complete rather than merely passing the tests:
 *      1. A closer arrives with no opener waiting  ->  `st.empty()` inside loop
 *         e.g. ")("  -- the ')' fails immediately.
 *      2. A closer arrives for the wrong opener    ->  the `else return false`
 *         e.g. "(]"
 *      3. Openers are left over at the end          ->  the final `st.empty()`
 *         e.g. "(("
 *  Miss any one of the three and you get a wrong answer on some input.
 *
 *  COMPLEXITY
 *  ----------
 *  Time : O(n)  -- each character is pushed at most once and popped at most once.
 *  Space: O(n)  -- worst case "((((((" pushes every character onto the stack.
 *
 *  EDGE CASES
 *  ----------
 *  - Empty string "" -> loop never runs, st is empty -> true. (Vacuously valid.)
 *  - Odd length -> cannot possibly pair up; caught naturally by one of the three
 *    checks, so no explicit length test is needed. (An `if (n % 2) return false;`
 *    at the top is a valid micro-optimisation, not a correctness fix.)
 *  - Since the problem promises only bracket characters, the final `else if` is
 *    a safe way to detect closers. If arbitrary characters were allowed, the
 *    explicit closer test already written here keeps them from being misread --
 *    they would simply fall through both branches and be ignored.
 *
 *  ONE SMALL POLISH
 *  ----------------
 *  `mp[st.top()]` uses operator[] on the map, which INSERTS a default entry if
 *  the key is missing. It cannot happen here (the stack only ever holds the
 *  three openers), but the habit is worth breaking early: `mp.at(...)` throws on
 *  a missing key instead of silently inserting, and marking `mp` as `static
 *  const` avoids rebuilding the map on every call.
 * ─────────────────────────────────────────────────────────────────────────────
 */

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        unordered_map<char, char> mp = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'}
        };

        for(char c : s) {
            if(c == '(' || c == '[' || c == '{') {
                st.push(c);
            }
            else if(c == ')' || c == ']' || c == '}') {
                if(st.empty()) {
                    return false;
                }
                else if(c == mp[st.top()]) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};
