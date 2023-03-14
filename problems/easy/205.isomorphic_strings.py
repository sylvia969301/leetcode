"""  [Problem]
        - Given two strings s and t, determine if they are isomorphic.
        - Two strings s and t are isomorphic if the characters in s can be replaced to get t.
    
    [Idea]
        - Append the first occur index of digit in each string, compare two results.

    [Complexity]
        - Time : O(n), where n is the number of elements of the given array.
        - Space : O(n).
"""


class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        # return (len(set(s)) == len(set(zip(s, t))) == len(set(t)))
        map1, map2 = [], []
        for char in s:
            map1.append(s.index(char))
        for char in t:
            map2.append(t.index(char))
        return map1 == map2
        