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

class Solution:
    def countBits(self, n: int) -> List[int]:
        
        counter = [0]
        for i in range(1, n + 1):
                counter.append(counter[i // 2] + i % 2)
        return counter