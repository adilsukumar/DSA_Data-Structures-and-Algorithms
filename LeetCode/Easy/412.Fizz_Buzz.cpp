/*
 * LeetCode 412 - Fizz Buzz [Easy]
 *
 * @platform   LeetCode
 * @id         412
 * @title      Fizz Buzz
 * @difficulty Easy
 * @topics     Math, String, Simulation
 * @pattern    Linear Loop
 * @url        https://leetcode.com/problems/fizz-buzz/
 * @solved     2026-09-15
 *
 * Problem
 * Accepted solution for Fizz Buzz.
 *
 * Approach
 * The solution iterates through numbers from 1 to n using a simple for loop. It
 * checks each number's divisibility by 3 and 5 using modulo operations and appends
 * the corresponding string to the result vector. This approach directly maps each
 * integer to its FizzBuzz representation in order.
 *
 * Complexity
 * Time: O(n) Space: O(n)
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
