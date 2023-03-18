"""  [Problem]
        - Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
*   [Idea]
        - directly find the index of roman by calculating thousands, hundreds, tens, ones of the given number
        
    [Complexity]
        - Time : O(1).
        - Space : O(n).
"""

class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        ones = ["","I","II","III","IV","V","VI","VII","VIII","IX"]
        tens = ["","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"]
        hrns = ["","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"]
        ths = ["","M","MM","MMM"]

        return ths[num//1000] +hrns[(num%1000)//100] + tens[(num%100)//10] + ones[num%10]