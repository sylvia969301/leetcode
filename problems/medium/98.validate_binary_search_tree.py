"""  [Problem]
        - Given the root of a binary tree, determine if it is a valid binary search tree (BST).
          A valid BST is defined as follows:        
            - The left subtree of a node contains only nodes with keys less than the node's key.
            - The right subtree of a node contains only nodes with keys greater than the node's key.
            - Both the left and right subtrees must also be binary search trees.
    [Idea]
        - Use Depth Firt Search(DFS) to traverse the BST and push nodes into stack.
        - Since stack is LIFO(Last In First Out), compare previous node with the one poped from stack.
        - NOT valid if the value of root <= the previous node.
    [Complexity]
        - Time : O(n), where the given BST has n nodes.
        - Space : O(n), use extra space to implement stack mechanism.
"""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        if root is None:
            return True

        stack = []
        prevN = float('-inf')

        while stack or root:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            if root.val <= prevN :
                return False
            prevN = root.val
            root = root.right
        return True

            