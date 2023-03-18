"""  [Problem]
        - Given the root of a binary tree, return the level order traversal of its nodes' values. 
        (i.e., from left to right, level by level).
*   [Idea]
        - Use queue that stores every nodes in the same level.
        - append to result list every layer .
    [Complexity]
        - Time : O(n), where n is the number of given nodes of the binary tree.
        - Space : O(n), store level-order result in a list.
"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root : return []
        queue = [root]
        res = []

        while queue:
            level = []
            next_queue = []
            for node in queue:
                level.append(node.val)
                if node.left : next_queue.append(node.left)
                if node.right : next_queue.append(node.right)
            queue = next_queue
            res.append(level)
        return res