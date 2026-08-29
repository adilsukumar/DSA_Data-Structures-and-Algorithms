/*
 * =============================================================================
 * CodeChef SST - Sasta Shark Tank (Difficulty 592)
 * =============================================================================
 * @platform   CodeChef
 * @id         SST
 * @title      Sasta Shark Tank
 * @difficulty 592
 * @topics     Basic Math
 * @pattern    Compare Scaled Valuations
 * @url        https://www.codechef.com/problems/SST
 * @solved     2026-06-26
 * -----------------------------------------------------------------------------
 * PROBLEM
 * Solve the stated task for each test case and print the required result.
 *
 * INTUITION
 * The two offers are worth 10*A and 5*B; dividing both by 5 reduces the comparison to 2*A versus B.
 *
 * WALKTHROUGH
 * Compare 2*A with B and print FIRST, SECOND, or ANY for greater, smaller, or equal valuations.
 *
 * WHY IT WORKS
 * The implementation follows the condition or formula above directly, so every possible input falls into exactly the required result case.
 *
 * COMPLEXITY
 * O(1) time and O(1) space per test case.
 *
 * EDGE CASES
 * The equality branch is essential because either offer is acceptable when both valuations match.
 * =============================================================================
 */

#include <iostream>

using namespace std;



int main() {

    int t;

    cin >> t;

    while (t--) {

        int a, b;

        cin >> a >> b;

        

        // Valuation 1: 10 * a

        // Valuation 2: 5 * b

        // Comparison: 10 * a vs 5 * b

        // Simplified: 2 * a vs b

        

        if (2 * a > b) {

            cout << "FIRST" << endl;

        } else if (2 * a < b) {

            cout << "SECOND" << endl;

        } else {

            cout << "ANY" << endl;

        }

    }

    return 0;

}
