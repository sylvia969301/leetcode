"""  [Problem]
        - Given the root of a binary tree, invert the tree, and return its root.
*   [Idea]
        - Invert left sub-tree first, and then invert right sub-tree.
        - Finnally invert left child and right child.
    [Complexity]
        - Time : O(n), where n = #tree nodes.
        - Space : O(1).
"""

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if not root:
            return None
        
        root.left = self.invertTree(root.left)
        root.right = self.invertTree(root.right)

        root.left, root.right = root.right, root.left

        return root