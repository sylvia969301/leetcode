"""  [Problem]
        - Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.
        - According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

    [Idea]
        - Set root as current node, compare p and q node each time.
        - Continuing compare with right sub-tree (curr = curr.right), if p and q both greater than curr.
        - Continuing compare with left sub-tree (curr = curr.left), if p and q both less than curr.

    [Complexity]
        - Time : O(log n), where n is the number of nodes of the given BST, and its tree height = logn.
        - Space : O(1), constant space.
"""

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """

        curr = root

        while curr:
            if p.val > curr.val and q.val > curr.val:
                curr = curr.right
            elif p.val < curr.val and q.val < curr.val:
                curr = curr.left
            else:
                return curr