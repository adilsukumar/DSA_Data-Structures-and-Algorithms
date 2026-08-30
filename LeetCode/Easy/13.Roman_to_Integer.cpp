/*
 * LeetCode 13 - Roman to Integer [Easy]
 *
 * @platform   LeetCode
 * @id         13
 * @title      Roman to Integer
 * @difficulty Easy
 * @topics     Hash Table, Math, String
 * @pattern    Explicit Subtractive-Pair Casework
 * @url        https://leetcode.com/problems/roman-to-integer/
 * @solved     2026-06-06
 *
 * Problem
 * Convert a Roman numeral string to an integer.
 *
 * Approach
 * Since there are only six special pairs, you can handle them head-on: walk the string
 * left to right, and at each position first ask "do I and my neighbour form one of the six
 * pairs?". If yes, add the pair's combined value and skip BOTH characters.
 *
 * Complexity
 * Time: O(n) -- each character is visited once; the if-chain is O(1) since it is a fixed
 * 13 comparisons, independent of input size.
 * Space: O(1) -- a handful of int variables, nothing that grows with n.
 *
 * Notes
 * - READING s[i+1] AT THE LAST CHARACTER: this looks like an out-of-bounds read but is
 *   actually safe.
 * - Simpler: subtract a symbol when the next symbol is larger; otherwise add it.
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
