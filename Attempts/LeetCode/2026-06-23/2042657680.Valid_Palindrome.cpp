/*
 * Platform: LeetCode
 * Submission: 2042657680
 * Problem: Valid Palindrome
 * Verdict: Compile Error
 * Date: 2026-06-23
 * URL: https://leetcode.com/problems/valid-palindrome/
 *  */

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
            if(tolower(s[left]) != tolower(s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;

    }
};