"""  [Problem]
        - Given an array of strings strs, group the anagrams together. 
          You can return the answer in any order.
        - Example : Input: strs = ["eat","tea","tan","ate","nat","bat"]
                    Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

    [Idea]
        - Use dictionary in Python to store sorted unique word and its anagrams in the given list.
         (since it would be the same word if same group of anagrams get sorted)

    [Complexity]
        - Time : O( mlogm * n), where n=total number of words & m = max length among all strings.
        - Space : O(n * m), .
"""

class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        map = {}
        for word in strs:
            sortedWord = ''.join(sorted(word))
            if sortedWord not in map: 
                map[sortedWord] = [word]
            else : 
                map[sortedWord].append(word)
        
        return list(map.values())