# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode(0)
        dummy.next = head
        currentNode = dummy
        endNode = dummy

        for i in range(0, n + 1):
            endNode = endNode.next

        while endNode != None:
            currentNode = currentNode.next
            endNode = endNode.next

        currentNode.next = currentNode.next.next

        return dummy.next