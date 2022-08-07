#include <iostream>
#include <vector>
using namespace std;

/*  [Problem] Given a non-empty array of integers, every element appears twice except for one.
              Find that single one with a linear runtime and use only constant extra space.
*   [Idea]
        - Using bitwise XOR operator
        - Traverse the array and atake the Bitwise XOR of each element
    [Complexity]
        - Time : O(N)
        - Space : O(1)
    [Reference]
        - https://leetcode.com/problems/single-number/discuss/1771720/C%2B%2B-EASY-SOLUTIONS-(SORTING-XOR-MAPS-(OR-FREQUENCY-ARRAY))
*/

class Solution {
public:
    int singleNumber(vector<int> &nums){
        int answer = 0;
        for(auto x : nums){
            answer ^= x;
        }
        return answer;
    }
};

int main(){
    // int test_array[] = {4,1,2,1,2};
    vector<int> test = {4,1,2,1,2};
    Solution sol;
    int ans = sol.singleNumber(test);
    cout << "Ans : " << ans << endl; //Should output 4
    return 0;

}