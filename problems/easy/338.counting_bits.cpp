#include <vector>
using namespace std;
/*
### Dynamic Programming (DP)
"""  [Problem]
        - Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n),
          ans[i] is the number of 1's in the binary representation of i.
*   [Idea]
        - DP method
    [Complexity]
        - Time : O(n), where n is the size of the given array.
        - Space : O(n), need to maintain the DP table.
"""
*/

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> counter( n + 1 );
        counter[0] = 0;

        for(int i=1 ; i <= n; ++i){
            counter[i] = counter[i/2] + i%2;
        }
        return counter;
    }
};