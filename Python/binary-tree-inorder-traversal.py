# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getInorderTraversalValues(self, root, result):
        if root == None:
            return

        self.getInorderTraversalValues(root.left, result)
        result.append(root.val)
        self.getInorderTraversalValues(root.right, result)

    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        self.getInorderTraversalValues(root, result)

        return result