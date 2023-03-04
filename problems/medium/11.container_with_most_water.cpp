#include <vector>
#include <algorithm>
using namespace std;

/* [Problem]
        - Given an integer array height of length n.
        - There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
        - Find two lines that together with the x-axis form a container, such that the container contains the most water.

    [Complexity]
        - Time : O(n), where n = len(height).
        - Space : O(1).
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int left = 0;
        int right = height.size() -1;
        while(left < right){
            int minHeight = min(height[left], height[right]);
            maxArea = max(maxArea, (right - left)*minHeight);

            if(height[left] < height[right]){
                left +=1;
            }else{
                right -=1;
            }
        }
        return maxArea;
    }
};