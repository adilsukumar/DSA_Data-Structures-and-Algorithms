/*
 * LeetCode 412 - Fizz Buzz [Easy]
 *
 * @platform   LeetCode
 * @id         412
 * @title      Fizz Buzz
 * @difficulty Easy
 * @topics     Math, String, Simulation
 * @pattern    Pending manual review
 * @url        https://leetcode.com/problems/fizz-buzz/
 * @solved     2026-09-15
 *
 * Problem
 * Accepted solution for Fizz Buzz.
 *
 * Approach
 * Pending manual review. The submitted code is preserved exactly below.
 *
 * Complexity
 * Pending manual review.
 */

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answer;
        for(int i = 1; i <= n; i++){
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
