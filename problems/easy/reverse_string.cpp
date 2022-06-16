#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
[Problem] 
        - Write a function that reverses a string. 
[Idea] 
        - Take 2 index variables (represent head & tail at first).
        - Swap their values until both index variables cross each other.
[Complexity] 
        - Time : O(n)
        - Space : O(1)

*/

class Solution{
public:
    void reverseString(vector<char>& s){
        
        if (s.size() == 0){
            return;
        }

        int head = 0;
        int tail = s.size() -1;
        while(head < tail){
            // swap(s[head], s[tail]);
            char tmp = s[head];
            s[head] = s[tail];
            s[tail] = tmp;
            head +=1;
            tail -=1;
        }
    }
};

int main(){
    
    vector<char> input = {'H', 'E', 'L', 'L', 'O'};
    cout << "Input : ";
    for(auto &c: input){
        cout << c << ", ";
    }
    
    cout << endl << "Output : ";
    Solution solution;
    solution.reverseString(input);
    for(auto &c: input){
        cout << c << ", ";
    }
    cout << endl;
    return 0;
}