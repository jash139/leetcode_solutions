# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        carry = 0
        newHead = ListNode(0)
        currNode = newHead

        while l1 != None or l2 != None or carry != 0:
            currSum = carry
            currSum += l1.val if l1 != None else 0
            currSum += l2.val if l2 != None else 0

            newNode = ListNode(currSum % 10)
            carry = currSum // 10
            currNode.next = newNode
            currNode = currNode.next

            l1 = l1.next if l1 != None else None
            l2 = l2.next if l2 != None else None

        return newHead.next