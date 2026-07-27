/*
================================================================================
 LeetCode 2011 - Final Value of Variable After Performing Operations   [Easy]
================================================================================
  @platform   LeetCode
  @id         2011
  @title      Final Value of Variable After Performing Operations
  @difficulty Easy
  @topics     Array, String, Simulation
  @pattern    Linear Scan Counter
  @url        https://leetcode.com/problems/final-value-of-variable-after-performing-operations/
  @solved     2026-07-27

--------------------------------------------------------------------------------
 PROBLEM
--------------------------------------------------------------------------------
  A variable X starts at 0. You are given a list of operations, each one of
  exactly four strings: "++X", "X++", "--X", or "X--". The "++" forms add 1
  to X; the "--" forms subtract 1. (Prefix vs. postfix is irrelevant here --
  there is no expression using the result, so ++X and X++ have the same effect.)
  Return X after applying every operation in order.

  Example: operations = ["--X","X++","X++"]
    --X -> X = -1
    X++ -> X =  0
    X++ -> X =  1
    Answer: 1

--------------------------------------------------------------------------------
 INTUITION
--------------------------------------------------------------------------------
  Order of application does not matter for the final value -- addition is
  commutative, so X is just (count of increments) - (count of decrements).
  The only fact each string carries is its SIGN. So we never need to build or
  evaluate an expression; we walk the list once and nudge a running counter
  +1 or -1 per operation. That is why a single integer accumulator suffices.

--------------------------------------------------------------------------------
 WALKTHROUGH
--------------------------------------------------------------------------------
  - int X = 0;                     start the accumulator at the problem's X.
  - for i in [0, size):            visit each operation exactly once.
  - if op == "--X" || op == "X--"  the two decrement forms -> X -= 1.
  - else                           every remaining string is an increment
                                   form ("++X" / "X++") -> X += 1.
  - return X;                      the net total.

  Note on the `else`: it does not test for "++X"/"X++" explicitly; it treats
  "anything that is not a decrement" as an increment. Given the guaranteed
  input alphabet (only the four valid strings), this is correct and slightly
  faster -- one string compare avoided per non-decrement op. If a malformed
  string ever appeared, it would be silently counted as +1, but the problem
  constraints forbid that.

  Dry run on ["X++","++X","X--"]:
    i=0  op="X++"  not a decrement -> X = 0 + 1 = 1
    i=1  op="++X"  not a decrement -> X = 1 + 1 = 2
    i=2  op="X--"  matches "X--"   -> X = 2 - 1 = 1
    return 1

--------------------------------------------------------------------------------
 COMPLEXITY
--------------------------------------------------------------------------------
  Time  : O(n * L)  -- one pass over n operations; each string compare touches
                       up to L = 3 characters, a constant, so effectively O(n).
  Space : O(1)      -- only the integer accumulator; no extra structures.

--------------------------------------------------------------------------------
 EDGE CASES
--------------------------------------------------------------------------------
  - Empty operations list: the loop never runs, returns 0. Correct.
  - All increments or all decrements: counter simply runs to +n or -n.
  - Result can be negative or zero: X is a signed int, handled naturally.
  - Prefix vs postfix ("++X" vs "X++"): treated identically, which is correct
    since the value is never used mid-expression.
  - Overflow: not a concern -- n is small per constraints, |X| <= n.

  This solution is already optimal: a single O(n) pass with O(1) space, which
  is the theoretical minimum since every operation must be read at least once.
*/

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int X = 0;
        for(int i = 0; i < operations.size(); i++){
            if(operations[i] == "--X" || operations[i] == "X--"){
                X -= 1;
            }
            else{
                X += 1;
            }
        }
        return X;   
    }
};
