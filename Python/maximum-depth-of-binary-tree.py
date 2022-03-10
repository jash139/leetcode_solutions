# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getMaximumDepth(self, root, currentDepth, maxDepth):
        if root == None:
            return 0

        newDepth = currentDepth + 1

        leftMaxDepth = self.getMaximumDepth(root.left, newDepth, maxDepth)
        rightMaxDepth = self.getMaximumDepth(root.right, newDepth, maxDepth)

        maxDepth = max(maxDepth, newDepth, leftMaxDepth, rightMaxDepth)
        return maxDepth

    def maxDepth(self, root: Optional[TreeNode]) -> int:
        return self.getMaximumDepth(root, 0, 0)