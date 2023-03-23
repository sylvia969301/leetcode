
"""  [Problem]
        - You are given two binary trees root1 and root2.
        - Imagine that when you put one of them to cover the other, 
          some nodes of the two trees are overlapped while the others are not. 
          You need to merge the two trees into a new binary tree. 
        - The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node.
          Otherwise, the NOT null node will be used as the node of the new tree.
*   [Idea]
        - Use DFS (Depth First Search) begin from root of two binary trees, merge left-subtrees first, then merge right-subtrees recursively.
        - If nodes overlap, sum node values up as the new value.
    [Complexity]
        - Time :  O(m), a total of m nodes need to be traversed, where m is the minimum nodes of two given binary trees.
        - Space : Space : O(m) need extra space to store tree nodes.
"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution(object):
    def mergeTrees(self, root1, root2):
        """
        :type root1: TreeNode
        :type root2: TreeNode
        :rtype: TreeNode
        """
        if root1 and root2:
            root = TreeNode(root1.val + root2.val)
            root.left = self.mergeTrees(root1.left, root2.left)
            root.right = self.mergeTrees(root1.right, root2.right)
            return root
        else:
            return root1 or root2