#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*  [Problem] Given an array of integers 'nums' and an target integer 'target', return indices of the two numbers such that they add up to 'target'.
*   [Idea] 
        - Use hash table (map in C++) to store the pair of answer variables.
    [Complexity]
        - Time : O(n) for the given array which has n values, since the look-up time of a hash table is O(1). 
        - Space : O(n), since the need of extra space for storing key-value pair of the hash map.
*/

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target){
        vector<int> answer;
        map<int, int> search_map;
        for (int i = 0; i< nums.size(); i++){
            int gap  = target - nums[i];
            if(search_map.find(nums[i]) != search_map.end()){
                answer.push_back(search_map[nums[i]]);
                answer.push_back(i);
                return answer;
            }else{
                search_map[gap] = i;
            }
        }
        return answer;
    }
};

int main (){
    Solution s;
    vector<int> nums = {2, 7, 11, 15};
    int target = 26;
    vector<int>  answer = s.twoSum(nums, target);
    cout << "Required indices : " ;
    for (auto &idx : answer){
        cout << idx << " ";
    }
    cout << endl;
    return 0;
}