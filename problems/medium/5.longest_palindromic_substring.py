### Expand Around the Center
"""  [Problem]
        - Given a string s, return the longest palindromic substring in s.
*   [Idea]
        - Using 中心擴張法(Expand Around the Center), expand if s[left]==s[right].
        - Check 2 chars (even) and 3 chars(odd) that contains longest palindrome each time.
    [Complexity]
        - Time : O(n^2), where n is the size of the given array.
        - Space : O(1), no need to maintain the DP table.
"""

class Solution:
    def longestPalindrome(self, s: str) -> str:
        longestPalindromeIdx = (0, 1)

        for i in range(1, len(s)):
            oddPalindrome = self.expandAroundTheCenter(s, i-1, i+1)
            evenPalindrome = self.expandAroundTheCenter(s, i-1, i)

            comparePalindrome = max(oddPalindrome, evenPalindrome, key=lambda x: x[1]-x[0])
            longestPalindromeIdx = max(longestPalindromeIdx, comparePalindrome, key=lambda x: x[1] - x[0])
        return s[longestPalindromeIdx[0]: longestPalindromeIdx[1]]


    def expandAroundTheCenter(self, s, left, right):
        while left >=0 and right < len(s) and s[left] == s[right]:
            left -= 1
            right +=1

        return [left+1, right]

### Dynamic Programing (DP) Method
"""
    [Idea]
        - Use DP method that reduce the big problem to a smaller one, check DP table each time.
        - Have to maintain DP table which space complexity is O(n^2).
        - tade-off between time and space (compare to O(n^3) brute force method.)
    [Complexity]
        - Time : O(n^2), where n is the size of the given array.
        - Space : O(n^2), use DP table(n*n) to store the information.
"""
class Solution_2 :
    def longestPalindrome(self, s: str) ->str:
        if len(s) <1:
            return s
        
        dp = [[False]*len(s) for _ in range(len(s))]
        for i in range(len(s)-1): dp[i][i] = True

        longestPalindrome = s[0]

        for i in range(len(s)):
            for j in range(i):
                if s[i] == s[j] :
                    if dp[j+1][i-1] or i-j==1:
                        dp[j][i] = True
                        if len(longestPalindrome) < i-j+1:
                            longestPalindrome = s[j:i+1]
        return longestPalindrome