#include <iostream>
#include <vector>
using namespace std;

/*  [Problem] Given releaseTimes and keyPressed, return the key of the keypress that had the longest duration.
*   [Idea]
        - Use a char to keep track of the key has the longest duration.
        - Update the key when iterating over the list of releaseTimes.
    [Complexity]
        - Time : O(n) as traversed the given list releaseTimes which has n elements.
        - Space : O(1) as only store the max duration and the longest key for returning.
*/

class Solution {
public:
    char slowestKey(vector<int> &releaseTimes, string keyPressed){
        int duration = 0;
        int max_duration = releaseTimes[0];
        char result_key = keyPressed[0];
        for (auto i = 1; i<releaseTimes.size(); i++){
            duration = releaseTimes[i] - releaseTimes[i-1];
            if (max_duration <= duration){
                if (max_duration == duration){
                    result_key = max(result_key, keyPressed[i]);
                }else {
                    result_key = keyPressed[i];
                    max_duration = duration;
                } 
            }
        }
        return result_key;
    }
};

int main(){
    vector<int> times = {9, 29, 49, 50};
    string keyPressed = "cbcd";
    Solution solution;
    char ans = solution.slowestKey(times, keyPressed);
    cout << ans << endl; // Should return c as the answer
    return 0;
}