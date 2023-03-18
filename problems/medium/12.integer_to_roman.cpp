#include <string>
using namespace std;
/*
"""  [Problem]
        - Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
*   [Idea]
        - directly find the index of roman by calculating thousands, hundreds, tens, ones of the given number
        
    [Complexity]
        - Time : O(1).
        - Space : O(n).
"""
*/

class Solution {
public:
    string intToRoman(int num) {
        string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hrns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string ths[] = {"","M","MM","MMM"};

        return ths[num/1000] + hrns[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
    }
};