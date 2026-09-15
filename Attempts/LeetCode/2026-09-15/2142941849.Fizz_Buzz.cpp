/*
 * Platform: LeetCode
 * Submission: 2142941849
 * Problem: Fizz Buzz
 * Verdict: Compile Error
 * Date: 2026-09-15
 * URL: https://leetcode.com/problems/fizz-buzz/
 *  */

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answer;
        for(int i = 0; i < n; i++){
            if(i%3 == 0 && i%5 == 0){
                answer.push_front("FizzBuzz");
            }
            else if(i%3 == 0){
                answer.push_front("Fizz");
            }
            else if(i%5 == 0){
                answer.push_front("Buzz");
            }
            else{
                answer.push_front(to_string(i));
            }
        }
        return answer;
    }
};