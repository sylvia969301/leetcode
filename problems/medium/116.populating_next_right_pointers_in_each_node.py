"""  [Problem]
        - Populate each next pointer to point to its next right node. 
        - If there is no next right node, the next pointer should be set to NULL.
*   [Idea]
        - Use recursive method.
        - Start from the root, set root.left.next = root.right, if have root.right.
        - set root.right.next = root.next.left, if have root.next(cross the left and right subtrees)
    [Complexity]
        - Time : O(N), where N is the number of nodes of the given complete binary tree.
        - Space : O(1), since changing pointers of linked list( Not include the recursive calls in stack).
"""


"""
# Definition for a Node.
"""
class Node(object):
    def __init__(self, val=0, left=None, right=None, next=None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next


class Solution(object):
    def connect(self, root):
        """
        :type root: Node
        :rtype: Node
        """
        if not root : return None

        if root.right: 
            root.left.next = root.right
            if root.next:
                root.right.next = root.next.left
        
        self.connect(root.left)
        self.connect(root.right)
        return root