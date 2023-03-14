
"""  [Problem]
        - Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n),
          ans[i] is the number of 1's in the binary representation of i.
*   [Idea]
        - DFS : 
            - preorder : root -> left -> right
            - inorder : left -> root -> right  
            - postorder : left -> right -> roots

        - Use recurssion method
        - combine left sub tree + root + right sub tree
    [Complexity]
        - Time : O(n), where n is the number of nodes of the given binary tree.
        - Space : O(1).
"""



# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
		# left -> root -> right
        if root is not None:
            return self.inorderTraversal(root.left) + [root.val] + self.inorderTraversal(root.right) 
        else:
            return []
            
            