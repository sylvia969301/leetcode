"""  [Problem]
        - Given the root of an n-ary tree, return the preorder traversal of its nodes' values.
          Preorder traversal means : ROOT -> LEFT CHILD -> RIGHT CHILD .
          ( Inorder : LEFT -> ROOT -> RIGHT, 
            Postorder : LEFT -> RIGHT -> ROOT )

*   [Idea]
        - Use DFS and Stack (implement by List pop(), append() in Python) to store nodes of the given n-ary tree.
        - Pop the node from stack (Last In First Out manner) and extend reversed order of its children into stack,
          so it could pop() the last item from stack in the next iteration.
        
    [Complexity]
        - Time : O(N), where N is the number of nodes in the given n-ary tree.
        - Space : O(N), use stack (implemented by List in Python) for extra space.
"""

"""
# Definition for a Node.
"""
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children


class Solution(object):
    def preorder(self, root):
        """
        :type root: Node
        :rtype: List[int]
        """

        if root is None : return []
        # use List in Python to implement stack (LIFO), if implementing queue, use deque instead(append() and popleft())
        stack = [root] 
        output = [] 
        
        while stack : 
            curr = stack.pop()
            output.append(curr.val)
            stack.extend(curr.children[:: -1 ])
        
        return output