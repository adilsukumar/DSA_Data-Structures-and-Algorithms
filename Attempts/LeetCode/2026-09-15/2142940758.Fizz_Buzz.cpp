/*
 * Platform: LeetCode
 * Submission: 2142940758
 * Problem: Fizz Buzz
 * Verdict: Wrong Answer
 * Date: 2026-09-15
 * URL: https://leetcode.com/problems/fizz-buzz/
 *  */

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answer;
        for(int i = 0; i < n; i++){
            if(i%3 == 0 && i%5 == 0){
                answer.push_back("FizzBuzz");
            }
            else if(i%3 == 0){
                answer.push_back("Fizz");
            }
            else if(i%5 == 0){
                answer.push_back("Buzz");
            }
            else{
                answer.push_back(to_string(i));
            }
        }
        return answer;
    }
};